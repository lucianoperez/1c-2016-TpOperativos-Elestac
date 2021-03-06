#ifndef NUCLEOVIEJOMALDITO_SRC_LIB_FUNCIONES_H_
#define NUCLEOVIEJOMALDITO_SRC_LIB_FUNCIONES_H_

#include "globales.h"
#include <parser/metadata_program.h>

// Configuración y setting:
void iniciarEscuchaDeInotify();
int setearValoresDeConfig(t_config * archivoConfig);
t_semaforo* semaforo_create(char*nombre, int valor);
void registrarSemaforo(char* name, int value);
var_compartida* crearVariableCompartida(char* nombre, int valorInicial);
// Lanzar hilos IO:
void registrarVariableCompartida(char* name, int value);
hiloIO* crearHiloIO(int index);
int validar_cliente();
int validar_servidor();
proceso_bloqueadoIO* esperarPorProcesoIO(dataDispositivo* datos);
void* entradaSalidaThread(void* dataHilo);
// Función select + Planificación:
int obtenerSocketMaximoInicial();
void setearQuantumYQuantumSleep();
void planificarProceso();
pcb* buscarProcesoPorPid(int pid);
int asignarPid();
int solicitarSegmentosAUMC(pcb * nuevoPcb, char* programa);
pcb* crearPcb(char* programa);
void aceptarConexionEntranteDeConsola();
void aceptarConexionEntranteDeCPU();
void tratarCPUDesconectada(cpu* unCpu, int index);
void atenderCambiosEnArchivoConfig();
void salvarProcesoEnCPU(int cpu_pid, int cpu_id);
int seDesconectoConsolaAsociada(int quantum_pid);
int envioSenialCPU(int id_cpu);
void finalizarPrograma(int pid, int index);
int pcbListIndex(int pid);
void realizarEntradaSalida(pcb* procesoEjecutando, pedidoIO* datos);
void semaforo_signal(t_semaforo* semaforo);
int semaforo_wait(t_semaforo* semaforo);
void semaforoBloquearProceso(t_queue* colaBloqueados, pcb* proceso);
void tratarPcbDeConsolaDesconectada(int pid);
void verificarDesconexionEnConsolas();
void quitarCpuPorSenialSIGUSR1(cpu* unCpu, int index);
void recorrerListaCPUsYAtenderNuevosMensajes();
// Liberar recursos:
void liberarPcbNucleo(pcb* unPcb);
void liberarCPU(cpu * cpu);
void liberarConsola(consola * consola);
void liberarSemaforo(t_semaforo * sem);
void liberarVarCompartida(var_compartida * var);
void limpiarColecciones();
void limpiarArchivoConfig();
void mostrarEstadoDeLasColas();
void quitarProcesoDelSistema(int pid);

extern bool seDesconectoUMC;

#endif /* NUCLEOVIEJOMALDITO_SRC_LIB_FUNCIONES_H_ */
