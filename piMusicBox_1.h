/*
 * piMusicBox_1.h
 *
 *  Created on: 11 de sep. de 2017
 *      Author: FFM
 */

#ifndef PIMUSICBOX_1_H_
#define PIMUSICBOX_1_H_

#include <stdlib.h> // para poder usar NULL
#include <stdio.h> // para poder usar printf
#include <time.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>
#include <wiringPi.h>
#include <softTone.h>
#include "tmr.h"
#include "kbhit.h" // para poder detectar teclas pulsadas sin bloqueo y leer las teclas pulsadas

#include "fsm.h" // para poder crear y ejecutar la máquina de estados

#define CLK_MS 10 // PERIODO DE ACTUALIZACION DE LA MAQUINA ESTADOS

// FLAGS DEL SISTEMA
#define FLAG_PLAYER_START			0x01
#define FLAG_PLAYER_STOP 			0x02
#define FLAG_PLAYER_END				0x04
#define FLAG_NOTA_TIMEOUT			0x08


#define FLAG_SYSTEM_START			0x16
#define FLAG_CARD_IN				0x32
#define FLAG_VALID_CARD				0x64
#define FLAG_SYSTEM_END				0x128

// A 'key' which we can lock and unlock - values are 0 through 3
//	This is interpreted internally as a pthread_mutex by wiringPi
//	which is hiding some of that to make life simple.
#define	FLAGS_KEY	1
#define FLANCO_KEY	3
#define	STD_IO_BUFFER_KEY	2

#define PIN_MELODIA	18

#define DEBOUNCE_TIME 100
//------------------------------------------------------
// FUNCIONES DE ENTRADA O DE TRANSICION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------
// Prototipos de funciones de entrada
int compruebaPlayerStart (fsm_t* this);
int compruebaNotaTimeout (fsm_t* this);
int compruebaNuevaNota (fsm_t* this);
int compruebaPlayerStop (fsm_t* this);
int compruebaFinalMelodia (fsm_t* this);
//------------------------------------------------------
// FUNCIONES DE SALIDA O DE ACCION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------
void ledEncender(fsm_t*);
void ledApagar(fsm_t*);


//------------------------------------------------------
// SUBRUTINAS DE ATENCION A LAS INTERRUPCIONES
//------------------------------------------------------
PI_THREAD (thread_explora_teclado);
PI_THREAD (thread_explora_tarjeta);



extern int frecuenciaDespacito[];
extern int tiempoDespacito[];
extern int frecuenciaGOT[];
extern int tiempoGOT[];
extern int frecuenciaTetris[];
extern int tiempoTetris[];
extern int frecuenciaStarwars[];
extern int tiempoStarwars[];

/*typedef enum {
	WAIT_START,
	WAIT_PUSH,
	WAIT_END} TipoEstadosSistema;*/

#define MAX_NUM_TARJETAS	5
#define MAX_NUM_NOTAS 		600
#define MAX_NUM_CHAR_NOMBRE	100
#define MAX_NUM_CHAR_UID	100

typedef struct {
	char nombre[MAX_NUM_CHAR_NOMBRE]; // String con el nombre de la melodia
	int frecuencias[MAX_NUM_NOTAS]; // Array con las frecuencias de las notas de la melodia
	int duraciones[MAX_NUM_NOTAS]; // Array con las duraciones de las notas de la melodia
	int num_notas; // Numero de notas de que consta la melodia
} TipoMelodia;

typedef struct {
	int posicion_nota_actual;	// Valor correspondiente a la posicion de la nota actual en los arrays de frecuencias y duraciones
	int frecuencia_nota_actual; // Valor correspondiente a la frecuencia de la nota actual
	int duracion_nota_actual; // Valor correspondiente a la duracion de la nota actual

	TipoMelodia* melodia;

	// A completar por el alumno
	// ...
} TipoPlayer;

typedef struct {
	//Uid uid;  // Identificador correspondiente a la tarjeta (tipo de datos complejo definido en liberia control RFID)
	TipoMelodia melodia;
} TipoTarjeta;

typedef struct {
	TipoPlayer player; // Reproductor de melodias

	int num_tarjetas_activas; // Numero de tarjetas validas

	TipoTarjeta tarjetas_activas[MAX_NUM_TARJETAS]; // Array con todas las tarjetas validas

	//Uid uid_tarjeta_actual; // Identificador de la tarjeta actual (tipo de datos complejo definido en liberia control RFID)

	int pos_tarjeta_actual; // Posicion de la tarjeta actual en el array de tarjetas validas

	char uid_tarjeta_actual_string[MAX_NUM_CHAR_UID]; // Identificador de la tarjeta actual a modo de string de caracteres

	//TipoEstadosSistema estado; // Variable que almacena el estado actual del sistema

	char teclaPulsada; // Variable que almacena la ultima tecla pulsada

	int debug; // Variable que habilita o deshabilita la impresion de mensajes por salida estandar
} TipoSistema;

int InicializaMelodia (TipoMelodia *melodia, char *nombre, int *array_frecuencias, int *array_duraciones, int num_notas);
void inicializaPlayer(fsm_t*);
void actualizaPlayer(fsm_t*);
void stopPlayer (fsm_t*);
void comienzaNuevaNota (fsm_t*);
void finalMelodia(fsm_t*);
int systemSetup (void);
void softToneWrite (int pin, int freq) ;


#endif /* PIMUSICBOX_1_H_ */
