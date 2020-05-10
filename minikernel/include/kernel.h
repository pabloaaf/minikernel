/*
 *  minikernel/include/kernel.h
 *
 *  Minikernel. Versión 1.0
 *
 *  Fernando Pérez Costoya
 *
 */

/*
 *
 * Fichero de cabecera que contiene definiciones usadas por kernel.c
 *
 *      SE DEBE MODIFICAR PARA INCLUIR NUEVA FUNCIONALIDAD
 *
 */

#ifndef _KERNEL_H
#define _KERNEL_H

#include "const.h"
#include "HAL.h"
#include "llamsis.h"

/*
 *
 * Definicion del tipo que corresponde con el BCP.
 * Se va a modificar al incluir la funcionalidad pedida.
 *
 */
typedef struct BCP_t *BCPptr;

typedef struct BCP_t {
        int id;				/* ident. del proceso */
        int estado;			/* TERMINADO|LISTO|EJECUCION|BLOQUEADO*/
        contexto_t contexto_regs;	/* copia de regs. de UCP */
        void * pila;			/* dir. inicial de la pila */
	BCPptr siguiente;		/* puntero a otro BCP */
	void *info_mem;			/* descriptor del mapa de memoria */
	unsigned int segundos_bloqueo; // actualizar segundos de bloqueo
	int n_int_reloj_usuario; // tiempos_ejec usuario
	int n_int_reloj_sistema; // tiempos_ejec sistema
} BCP; 


/*
 *
 * Definicion del tipo que corresponde con la cabecera de una lista
 * de BCPs. Este tipo se puede usar para diversas listas (procesos listos,
 * procesos bloqueados en semáforo, etc.).
 *
 */

typedef struct{
	BCP *primero;
	BCP *ultimo;
} lista_BCPs;

struct tiempos_ejec {
    int usuario;
    int sistema;
};

/*
 * Variable global que identifica el proceso actual
 */

BCP * p_proc_actual=NULL;

/*
 * Variable global que representa la tabla de procesos
 */

BCP tabla_procs[MAX_PROC];

/*
 * Variable global que representa la cola de procesos listos
 */
lista_BCPs lista_listos= {NULL, NULL};

/*
 * Variable global que representa la cola de procesos esperando plazos
	Definir una lista de procesos esperando plazos.
 */
lista_BCPs lista_esperando_plazos= {NULL, NULL};

int n_int_reloj = 0; // Contar numero int reloj

/*
 *
 * Definición del tipo que corresponde con una entrada en la tabla de
 * llamadas al sistema.
 *
 */
typedef struct{
	int (*fservicio)();
} servicio;

/*
 * Prototipos de las rutinas que realizan cada llamada al sistema
 */
int sis_crear_proceso();
int sis_terminar_proceso();
int sis_escribir();
// Añadir rutinas nuevas
int sis_obtener_id_pr(); // Apartado 1
int sis_dormir(); // Apartado 2
int sis_tiempos_proceso(); // Apartado 3


/*
 * Variable global que contiene las rutinas que realizan cada llamada
 */
servicio tabla_servicios[NSERVICIOS]={	{sis_crear_proceso},
										{sis_terminar_proceso},
										{sis_escribir},
										{sis_obtener_id_pr}, // Añadir las nuevas llamadas de arriba
										{sis_dormir},
										{sis_tiempos_proceso}};

#endif /* _KERNEL_H */

