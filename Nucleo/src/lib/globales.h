#ifndef NUCLEOVIEJOMALDITO_SRC_LIB_GLOBALES_H_
#define NUCLEOVIEJOMALDITO_SRC_LIB_GLOBALES_H_

#include <utilidades/comunicaciones.h>
#include <pthread.h>
#include <commons/collections/queue.h>
#include <semaphore.h>
#include <sys/inotify.h>

//#define EVENT_SIZE (sizeof(struct inotify_event) + strlen(RUTA_CONFIG_NUCLEO) + 1)
#define EVENT_SIZE (sizeof( struct inotify_event ))
#define EVENT_BUF_LEN (1024 * (EVENT_SIZE + 16))
#define CONEXIONES_PERMITIDAS 10
#define DESCONEXION_UMC 2
#define RUTA_CONFIG_NUCLEO "configNucleo.txt"
#define logearError(msg){log_error(logger, msg); return FALSE;}

typedef struct {
	int puertoPrograma, puertoCPU, puertoUMC, quantum, retardoQuantum, cantidadPaginasStack;
	char * ipUMC;
	char ** semaforosID;
	char ** semaforosValInicial;
	char ** ioID;
	char ** retardosIO;
	char ** variablesCompartidas;
} t_configuracion;

typedef struct {
	int id, fd_consola, pid;
} consola;

typedef enum {
	LIBRE = 1, OCUPADO
} disponibilidadCPU;

typedef struct {
	int id, fd_cpu, disponibilidad, pid;
} cpu;

typedef struct{
	char* nombre;
	pthread_mutex_t mutex_io;
	sem_t sem_io;
	int retardo;
	t_queue *bloqueados;
} dataDispositivo;

typedef struct{
	pthread_t hiloID;
	dataDispositivo dataHilo;
} hiloIO;

typedef struct{
	pcb* proceso;
	int espera;
} proceso_bloqueadoIO;

typedef struct {
	char *nombre;
	int valor;
	t_queue *bloqueados;
} t_semaforo;

// VARIABLES GLOBALES:

t_configuracion * config;
int fd_UMC, tamanioPagina, fdEscuchaConsola, fdEscuchaCPU;
t_log * logger;
int max_fd;
fd_set readfds; // conjunto maestro de descriptores de fichero para select()
// Inotify:
int fd_inotify, watch_descriptor;

t_list * listaProcesos; // Lista de todos los procesos en el sistema
t_list * listaCPU; // Lista de todos las CPU conectadas
t_list * listaConsolas;  // Lista de todos las Consolas conectadas
t_list * listaCPU_SIGUSR1;  // Lista de CPUs que enviaron señal SIGUSR1
t_list * listaProcesosAbortivos; // Lista de PCBs cuya Consola se deconectó

t_queue * colaListos; // Lista de todos los procesos listos para ejecutar

t_dictionary * diccionarioIO; // Diccionario de todos los dispositivos IO
t_dictionary * diccionarioSemaforos; // Diccionario de todos los semáforos
t_dictionary * diccionarioVarCompartidas; // Diccionario de todos las variables compartidas

pthread_mutex_t mutex_planificarProceso;

#endif /* NUCLEOVIEJOMALDITO_SRC_LIB_GLOBALES_H_ */
