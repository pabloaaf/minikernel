/*
 *  minikernel/kernel/include/llamsis.h
 *
 *  Minikernel. Versión 1.0
 *
 *  Fernando Pérez Costoya
 *
 */

/*
 *
 * Fichero de cabecera que contiene el numero asociado a cada llamada
 *
 * 	SE DEBE MODIFICAR PARA INCLUIR NUEVAS LLAMADAS
 *
 */

#ifndef _LLAMSIS_H
#define _LLAMSIS_H

/* Numero de llamadas disponibles */
#define NSERVICIOS 6 // tamaño del array empezando en 1

#define CREAR_PROCESO 0
#define TERMINAR_PROCESO 1
#define ESCRIBIR 2
#define OBTENER_ID_PR 3 // Apartado 1
#define DORMIR 4 // Apartado 2
#define TIEMPOS_PROCESO 5 // Apartado 3
#endif /* _LLAMSIS_H */

