#include "entradaSalida.h"

void bloquearProcesoPorIO(hiloIO* dispositivoIO, proceso_bloqueadoIO* unPcb){
	pthread_mutex_lock(&dispositivoIO->dataHilo.mutex_io);
	queue_push(dispositivoIO->dataHilo.bloqueados, unPcb);
	pthread_mutex_unlock(&dispositivoIO->dataHilo.mutex_io);
	sem_post(&dispositivoIO->dataHilo.sem_io);
}

proceso_bloqueadoIO* esperarPorProceso(dataDispositivo* datos){
	sem_wait(&datos->sem_io);
	pthread_mutex_lock(&datos->mutex_io);
	proceso_bloqueadoIO* proceso = queue_pop(datos->bloqueados);
	pthread_mutex_unlock(&datos->mutex_io);

	return proceso;
}

void realizarEntradaSalida(pcb* pcbEjecutada, pedidoIO* datos){

	proceso_bloqueadoIO* pcbIO = malloc(sizeof *pcbIO);
	hiloIO* dispositivoIO = dictionary_get(diccionarioIO, datos->nombreDispositivo);
		pcbIO->espera = datos->tiempo;
		pcbIO->proceso = copiarPcb(pcbEjecutada);

		// Bloqueo al proceso por IO:
		pthread_mutex_lock(&dispositivoIO->dataHilo.mutex_io);
		queue_push(dispositivoIO->dataHilo.bloqueados, pcbIO);
		pthread_mutex_unlock(&dispositivoIO->dataHilo.mutex_io);
		sem_post(&dispositivoIO->dataHilo.sem_io);
}

void* entradaSalidaThread(void* dataHilo){
	int tiempoDeEspera;

		dataDispositivo *datos = dataHilo;
		proceso_bloqueadoIO* proceso;

		while (TRUE){

			proceso = esperarPorProceso(datos);
			tiempoDeEspera = (datos->retardo * proceso->espera) * 1000;
			usleep(tiempoDeEspera);
			encolarPcbAListos(proceso->proceso);
			free(proceso);
		}
		return NULL ;
}

/*** Planificación a corto plazo (PCP) ****/

hiloIO* crearHiloIO(int index){
  hiloIO *hilo = malloc(sizeof(hiloIO));

  hilo->dataHilo.retardo = atoi(config->retardosIO[index]);
  sem_init(&hilo->dataHilo.sem_io, 0, 0);
  pthread_mutex_init(&hilo->dataHilo.mutex_io, NULL );
  hilo->dataHilo.bloqueados = queue_create();
  hilo->dataHilo.nombre = strdup(config->ioID[index]);

  return hilo;
}
