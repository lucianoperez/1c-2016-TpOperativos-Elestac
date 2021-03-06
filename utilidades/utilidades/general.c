#include "general.h"
#include <stdlib.h>
#include <stdio.h>

// -- OPERACIONES CON MEMORIA --
void* reservarMemoria(int size) {
	void *puntero = malloc(size);
	if(puntero == NULL) {
		fprintf(stderr, "Lo imposible sucedió. Error al reservar %d bytes de memoria\n", size);
		exit(ERROR);
	}
	return puntero;
}

// -- ARCHIVO DE CONFIGURACIÓN --
void leerArchivoDeConfiguracion(char * ruta) {
	t_config * archivoConfig;

	if (comprobarQueExistaArchivo(ruta) == ERROR){
		manejarError("Error: Archivo de configuración no encontrado\n");
	}else{

	archivoConfig = config_create(ruta);

	setearValores_config(archivoConfig); // Redefinido en cada proceso

	config_destroy(archivoConfig); // Libero la estructura archivoConfig

	printf("El archivo de configuración ha sido leído correctamente\n");
	}
}

int comprobarQueExistaArchivo(char * ruta) {
	if( access(ruta, F_OK ) != ERROR ) {
	    return TRUE;
	} else {
	    return ERROR;
	}
}

// -- CONEXIONES ENTRE MÓDULOS --
int handshake_servidor(int sockCliente, char *mensaje) {

	enviarPorSocket(sockCliente, mensaje, HANDSHAKE_SIZE);

	char *buff = (char*)reservarMemoria(HANDSHAKE_SIZE);
	int status = recibirPorSocket(sockCliente, buff, HANDSHAKE_SIZE);

	if( validar_recive(status, 0) == TRUE ) { // El cliente envió un mensaje

		buff[HANDSHAKE_SIZE-1] = '\0';
		if (validar_cliente(buff)) {
			printf("Hice el handshake y me respondieron: %s\n", buff);
			free(buff);
			return TRUE;
		} else {
			free(buff);
			return FALSE;
		}

	} else { // Hubo algún error o se desconectó el cliente

		free(buff);
		return FALSE;
	}
	return FALSE; // No debería llegar acá pero lo pongo por el warning
}

void handshake_cliente(int sockClienteDe, char *mensaje) {

	char *buff = (char*)reservarMemoria(HANDSHAKE_SIZE);
	int status = recibirPorSocket(sockClienteDe, buff, HANDSHAKE_SIZE);
	validar_recive(status, 1); // Es terminante ya que la conexión es con el servidor

	buff[HANDSHAKE_SIZE-1] = '\0';
	if( validar_servidor(buff) == FALSE) {
		free(buff);
		exit(ERROR);
	} else {
		printf("Handshake recibido: %s\n", buff);
		free(buff);
		enviarPorSocket(sockClienteDe, mensaje, HANDSHAKE_SIZE);
	}
}

int validar_conexion(int ret, int modo) {

	if(ret == ERROR) {

		if(modo == 1) { // Modo terminante
			exit(ERROR);
		} else { // Sino no es terminante
			return FALSE;
		}
	} else { // No hubo error
		printf("Alguien se conectó\n");
		return TRUE;
	}
}

int validar_recive(int status, int modo) {

	if( (status == ERROR) || (status == 0) ) {

		if(modo == 1) { // Modo terminante
			exit(ERROR);
		} else { // Modo no terminante
			return FALSE;
		}

	} else {
		return TRUE;
	}
}

// -- FUNCIONES EXTRA --
void dormir(float miliseconds) {
	usleep(miliseconds * 1000);
}

void liberarRegistroStack(registroStack* reg){

	if(reg != NULL){

		int a, b;

		if(reg->args != NULL){

			for(a = 0; a < list_size(reg->args); a++){
				variable* arg = list_remove(reg->args, a);
				if(arg != NULL){
					free(arg); arg = NULL;
				}
			}
			free(reg->args); reg->args = NULL;
		}

		if(reg->vars != NULL){

			for(b = 0; b < list_size(reg->vars); b++){
				variable* var = list_remove(reg->vars, b);
				if(var != NULL){
					free(var); var = NULL;
				}
			}
			free(reg->vars); reg->vars = NULL;
		}

		free(reg); reg = NULL;
	}
}
