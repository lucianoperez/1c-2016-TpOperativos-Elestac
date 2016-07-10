#ifndef LIB_FUNCIONES_H_
#define LIB_FUNCIONES_H_

#include "globales.h"

/**** FUNCIONES SECUNDARIAS ****/
int setearValoresDeConfig(t_config * archivoConfig);
void actualizarPcbEjecutada(cpu * unCPU, pcb * pcbEjecutada, int estado);
void inicializarIndices(pcb* pcb, t_metadata_program* metaData);
int asignarPid(t_list * procesos);
pcb* buscarProcesoPorPid(int pid, int* index);
pcb* crearPcb(char* programa);
void salvarProcesoEnCPU(int cpuId);
void planificarProceso();
void finalizarPrograma(int pid, int index);
void limpiarColecciones();
void liberarSemaforo(t_semaforo * sem);
void liberarVarCompartida(var_compartida * var);
void liberarConsola(consola * consola);
void liberarCPU(cpu * cpu);
void limpiarArchivoConfig();
int solicitarSegmentosAUMC(pcb * nuevoPcb, char* programa);
pcb* copiarPcb(pcb* proceso);
void encolarPcbAListos(pcb* proceso);
int pcbListIndex(int pid);

#endif /* LIB_FUNCIONES_H_ */
