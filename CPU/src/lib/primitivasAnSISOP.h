#ifndef LIB_PRIMITIVASANSISOP_H_
#define LIB_PRIMITIVASANSISOP_H_

#include "globalesCPU.h"
#include "secundariasCPU.h"

/** PROTOTIPO PRIMITIVAS ANSISOP **/
t_puntero definirVariable(t_nombre_variable identificador_variable);
t_puntero obtenerPosicionVariable(t_nombre_variable identificador_variable);
t_valor_variable dereferenciar(t_puntero direccion_variable);
void asignar(t_puntero direccion_variable, t_valor_variable valor);
t_puntero_instruccion irAlLabel(t_nombre_etiqueta t_nombre_etiqueta);
void llamarConRetorno(t_nombre_etiqueta etiqueta, t_puntero donde_retornar);
void retornar(t_valor_variable retorno);
void imprimir(t_valor_variable valor_mostrar);
void imprimirTexto(char* texto);
t_valor_variable obtenerValorCompartida(t_nombre_compartida variable);
t_valor_variable asignarValorCompartida(t_nombre_compartida variable, t_valor_variable valor);
void entradaSalida(t_nombre_dispositivo dispositivo, int tiempo);
void s_wait(t_nombre_semaforo identificador_semaforo);
void s_signal(t_nombre_semaforo identificador_semaforo);
void finalizar();
#endif /* LIB_PRIMITIVASANSISOP_H_ */