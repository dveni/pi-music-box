/*
 *  File name	: piMusicBox_1.c
 *  Created on	: 14 de feb. de 2018
 *  Authors		: Eduardo Quiroga Bradshaw & Daniel Vera Nieto
 *  Description	: Main progrma body
 */

/* Includes --------------------------------------------------------------*/

#include "piMusicBox_1.h"

/*
 * Array de frecuencias y duraciones de las notas de las distintas melodías
 *
 */

int frecuenciaDespacito[160] = {0,1175,1109,988,740,740,740,740,740,740,988,988,988,988,880,988,784,0,784,784,784,784,784,988,988,988,988,1109,1175,880,0,880,880,880,880,880,1175,1175,1175,1175,1318,1318,1109,0,1175,1109,988,740,740,740,740,740,740,988,988,988,988,880,988,784,0,784,784,784,784,784,988,988,988,988,1109,1175,880,0,880,880,880,880,880,1175,1175,1175,1175,1318,1318,1109,0,1480,1318,1480,1318,1480,1318,1480,1318,1480,1318,1480,1568,1568,1175,0,1175,1568,1568,1568,0,1568,1760,1568,1480,0,1480,1480,1480,1760,1568,1480,1318,659,659,659,659,659,659,659,659,554,587,1480,1318,1480,1318,1480,1318,1480,1318,1480,1318,1480,1568,1568,1175,0,1175,1568,1568,1568,1568,1760,1568,1480,0,1480,1480,1480,1760,1568,1480,1318};
int tiempoDespacito[160] = {1200,600,600,300,300,150,150,150,150,150,150,150,150,300,150,300,343,112,150,150,150,150,150,150,150,150,300,150,300,300,150,150,150,150,150,150,150,150,150,300,150,300,800,300,600,600,300,300,150,150,150,150,150,150,150,150,300,150,300,343,112,150,150,150,150,150,150,150,150,300,150,300,300,150,150,150,150,150,150,150,150,150,300,150,300,450,1800,150,150,150,150,300,150,300,150,150,150,300,150,300,450,450,300,150,150,225,75,150,150,300,450,800,150,150,300,150,150,300,450,150,150,150,150,150,150,150,150,300,300,150,150,150,150,150,150,450,150,150,150,300,150,300,450,450,300,150,150,150,300,150,300,450,800,150,150,300,150,150,300,450};
int frecuenciaGOT[518] = {1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,1175,0,1397,0,932,0,1244,0,1175,0,1397,0,932,0,1244,0,1175,0,1046,0,831,0,698,0,523,0,349,0,784,0,523,0,523,0,587,0,622,0,698,0,784,0,523,0,622,0,698,0,784,0,523,0,622,0,698,0,587,0,698,0,466,0,622,0,587,0,698,0,466,0,622,0,587,0,523,0,523,0,587,0,622,0,698,0,784,0,523,0,622,0,698,0,784,0,523,0,622,0,698,0,587,0,698,0,466,0,622,0,587,0,698,0,466,0,622,0,587,0,523,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1175,0,587,0,622,0,587,0,523,0,587,0,784,0,880,0,932,0,1046,0,1175,0,0,1397,0,0,932,0,0,1244,0,0,1175,0,0,1397,0,0,932,0,0,1244,0,0,1175,0,0,1046,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1175,0,880,0,784,0,932,0,1244,0,0,1397,0,0,932,0,0,1175,0,0,1244,0,0,1175,0,0,932,0,0,1046,0,0,2093,0,622,0,831,0,932,0,1046,0,622,0,831,0,1046,0,0,1865,0,622,0,784,0,831,0,932,0,622,0,784,0,932,0,0,1661,0,523,0,698,0,784,0,831,0,523,0,698,0,831,0,0,1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,0,0,1661,0,1046,0,1175,0,1244,0,831,0,1175,0,1244,0,0,0,0,2489,0,0,0,0,2794,0,0,0,0,3136,0,0,2093,0,622,0,831,0,932,0,1046,0,622,0,831,0,1046,0,0,1865,0,622,0,784,0,831,0,932,0,622,0,784,0,932,0,0,1661,0,523,0,698,0,784,0,831,0,523,0,698,0,831,0,0,1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,0,0,1661,0,1046,0,1175,0,1244,0,831,0,1175,0,1244,0,0,0,0,2489,0,1397,0,0,0,2350,0,0,0,2489,0,0,0,2350,0,0,0,0,2093,0,392,0,415,0,466,0,523,0,392,0,415,0,466,0,523,0,392,0,415,0,466,0,2093,0,1568,0,1661,0,1865,0,2093,0,1568,0,1661,0,1865,0,2093,0,1568,0,1661,0,1865};
int tiempoGOT[518] = {900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1400,1400,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,116,267,28,267,28,267,28,900,89,900,89,1400,89,69,7,69,7,69,7,69,7,900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1800,1800,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,2400,69,7,69,7,69,7,69,7,900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1800,1800,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,2400,3600,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,600,59,600,133,13,150,133,13,150,1200,400,69,7,69,7,69,7,69,7,267,28,400,45,133,13,267,28,267,28,267,28,300,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,900,89,900,133,13,150,133,13,150,1200,1800,3600,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,600,59,600,133,13,150,133,13,150,1200,400,267,28,1200,400,133,13,133,13,150,900,89,900,900,89,900,600,59,600,267,28,300,600,59,600,267,28,300,1200,2400,3600,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,133,13,267,28,267,28,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,150,600,59,133,13,133,13,267,28,267,28,133,13,133,13,150,150,150,900,89,900,900,900,900,89,900,900,900,1200,2400,3600,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,150,600,59,133,13,133,13,267,28,267,28,133,13,133,13,150,150,150,600,212,133,13,150,150,267,28,300,300,400,45,450,450,133,13,150,150,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,267,28,267,28,133,13,2400,116,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,267,28,267,28,133,13,2400};
int frecuenciaTetris[55] = {1319,988,1047,1175,1047,988,880,880,1047,1319,1175,1047,988,988,1047,1175,1319,1047,880,880,0,1175,1397,1760,1568,1397,1319,1047,1319,1175,1047,988,988,1047,1175,1319,1047,880,880,0,659,523,587,494,523,440,415,659,523,587,494,523,659,880,831};
int tiempoTetris[55] = {450,225,225,450,225,225,450,225,225,450,225,225,450,225,225,450,450,450,450,450,675,450,225,450,225,225,675,225,450,225,225,450,225,225,450,450,450,450,450,450,900,900,900,900,900,900,1800,900,900,900,900,450,450,900,1800};
int frecuenciaStarwars[59] = {523,0,523,0,523,0,698,0,1046,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,1760,0,0,784,0,523,0,0,523,0,0,523,0};
int tiempoStarwars[59] = {134,134,134,134,134,134,536,134,536,134,134,134,134,134,134,536,134,402,134,134,429,357,134,134,134,134,536,134,402,134,134,429,357,134,134,134,134,536,134,402,134,134,429,357,134,134,134,429,357,1071,268,67,67,268,67,67,67,67,67};

/* Defines -----------------------------------------------*/

#define PIN_MELODIA	18			//PIN de la Raspberry Pi de salida de la señal cuadrada

/*
 * Estados de la máquina de estados
 */
 enum fsm_state {
   WAIT_START,
   WAIT_NEXT,
   WAIT_END,
   WAIT_START_LECTOR,
   WAIT_CARD,
   WAIT_CHECK,
   WAIT_PLAY,
   };

/*
 * Global variable: flags
 * ----------------------
 * Varibale con los distintos flags de nuestro sistema que se inicializa a 0
 */

  volatile int flags = 0;
  volatile int estado_flanco = 1;
  volatile int debounceTime = 0;

  /*
   * Function:  delay_until
   * --------------------
   * Añade un tiempo de espera al TMR
   *
   * next: tiempo en milisegundos
   *
   */

  void delay_until (unsigned int next) {
 	unsigned int now = millis();

 	if (next > now) {
 		delay (next - now);
     }
 }

  /*
   * Function:  flagStart
   * --------------------
   * Activa el flag FLAG_PLAYER_START
   *
   */

 /*void flagStart(){
	 printf("\n COMIENZA MELODIA...\n");
	 	fflush (stdout);
	 	piLock (FLAGS_KEY);
	 	flags |= FLAG_PLAYER_START;
	 	piUnlock (FLAGS_KEY);
 }
*/
 /*
   * Function:  flagStop
   * --------------------
   * Activa el flag FLAG_PLAYER_STOP
   *
   */

 /*void flagStop(){
	 printf("\n PARA MELODIA...\n");
	fflush (stdout);
	 piLock (FLAGS_KEY);
	flags |= FLAG_PLAYER_STOP;
	piUnlock (FLAGS_KEY);
 }
*/

  void compruebaFlanco(){
	  if (millis () < debounceTime)
	  {
	  debounceTime = millis () + DEBOUNCE_TIME ;
	  return;
	  }

	  if(estado_flanco){
		printf("\n COMIENZA MELODIA...\n");
		fflush (stdout);
		piLock (FLANCO_KEY);
		flags |= FLAG_PLAYER_START;
		estado_flanco =0;
		piUnlock (FLANCO_KEY);
	  }else{
		printf("\n PARA MELODIA...\n");
		fflush (stdout);
		piLock (FLANCO_KEY);
		flags |= FLAG_PLAYER_STOP;
		estado_flanco =1;
		piUnlock (FLANCO_KEY);
	  }
	  debounceTime = millis () + DEBOUNCE_TIME ;

  }

 //--------------------------------------------------------------------------------------------------------
 // FUNCIONES DE LA MAQUINA DE ESTADOS
 //--------------------------------------------------------------------------------------------------------


 // FUNCIONES DE ENTRADA O COMPROBACION DE LA MAQUINA DE ESTADOS ------------------------------------------

 /*
  * Function:  compruebaPlayerStart
  * --------------------
  * Informa de la activación del flag FLAG_PLAYER_START
  *
  *  this: puntero a la máquina de estados en la que se comprueba el flag
  *
  *  returns: devuelve 1 si se ha activado FLAG_PLAYER_START o 0 en caso contrario
  */

 int compruebaPlayerStart (fsm_t* this) {
 	int result;

 	piLock (FLAGS_KEY);
 	result = (flags & FLAG_PLAYER_START);
 	piUnlock (FLAGS_KEY);

 	return result;
 }

 /*
   * Function:  compruebaNotaTimeout
   * --------------------
   * Informa de la activación del flag FLAG_NOTA_TIMEOUT
   *
   *  this: puntero a la máquina de estados en la que se comprueba el flag
   *
   *  returns: devuelve 1 si se ha activado FLAG_NOTA_TIMEOUT o 0 en caso contrario
   */

 int compruebaNotaTimeout (fsm_t* this) {
 	int result;

 	piLock (FLAGS_KEY);
 	result = (flags & FLAG_NOTA_TIMEOUT);
 	piUnlock (FLAGS_KEY);

 	return result;
 }

 /*
    * Function:  compruebaNuevaNota
    * --------------------
    * Informa de la activación del flag FLAG_PLAYER_END
    *
    *  this: puntero a la máquina de estados en la que se comprueba el flag
    *
    *  returns: devuelve 1 si se ha activado FLAG_PLAYER_END o 0 en caso contrario
    */

 int compruebaNuevaNota (fsm_t* this) {
 	int result;

 	piLock (FLAGS_KEY);
 	result = (flags & FLAG_PLAYER_END);
 	piUnlock (FLAGS_KEY);

 	return result;
 }

 /*
     * Function:  compruebaPlayerStop
     * --------------------
     * Informa de la activación del flag FLAG_PLAYER_STOP
     *
     *  this: puntero a la máquina de estados en la que se comprueba el flag
     *
     *  returns: devuelve 1 si se ha activado FLAG_PLAYER_STOP o 0 en caso contrario
     */

 int compruebaPlayerStop (fsm_t* this) {
 	int result;

 	piLock (FLAGS_KEY);
 	result = (flags & FLAG_PLAYER_STOP);
 	piUnlock (FLAGS_KEY);

 	return result;
 }
 /*
     * Function:  compruebaFinalMelodia
     * --------------------
     * Informa de la activación del flag FLAG_PLAYER_END cuando ha finalizado la melodia
     *
     *  this: puntero a la máquina de estados en la que se comprueba el flag
     *
     *  returns: devuelve 1 si se ha activado FLAG_PLAYER_END y se ha alcanzado el numero total de notas o 0 en caso contrario
     */

 int compruebaFinalMelodia (fsm_t* this) {
 	int result;
 	TipoPlayer* player = this -> user_data;

    if(player->posicion_nota_actual == player->melodia->num_notas){
 		piLock (FLAGS_KEY);
 		result = (flags & FLAG_PLAYER_END);
 		piUnlock (FLAGS_KEY);
    }else {
 		result = 0;
 	}
 	return result;
 }

int compruebaComienzo (fsm_t* this){
	int result;
	piLock (FLAGS_KEY);
	 	result = (flags & FLAG_SYSTEM_START);
	 	piUnlock (FLAGS_KEY);

	 	return result;

}

int tarjetaNoDisponible(fsm_t* this){
	int result;
	piLock (FLAGS_KEY);
	 	result = ~(flags & FLAG_CARD_IN);
	 	piUnlock (FLAGS_KEY);

	 	return result;

}

int tarjetaDisponible(fsm_t* this){
	int result;
	piLock (FLAGS_KEY);
	 	result = (flags & FLAG_CARD_IN);
	 	piUnlock (FLAGS_KEY);

	 	return result;

}

int tarjetaNoValidada(fsm_t* this){
	int result;
	piLock (FLAGS_KEY);
	 	result = ~(flags & FLAG_VALID_CARD);
	 	piUnlock (FLAGS_KEY);

	 	return result;

}

int tarjetaValidada(fsm_t* this){
	int result;
	piLock (FLAGS_KEY);
	 	result = (flags & FLAG_VALID_CARD);
	 	piUnlock (FLAGS_KEY);

	 	return result;

}

int compruebaFinalReproduccion(fsm_t* this){
	int result;
	piLock (FLAGS_KEY);
	 	result = (flags & FLAG_SYSTEM_END);
	 	piUnlock (FLAGS_KEY);

	 	return result;

}
// FUNCIONES DE SALIDA ------------------------------------------------------------------------------------

 /*
     * Function:  inicializaPlayer
     * --------------------
     * Inicializa los parámetros del TipoPlayer y da comienzo a la melodía imprimiendo un mensaje de información
     *
     *  fsm: puntero a la máquina de estados
     *
     */

 void inicializaPlayer(fsm_t* fsm){

	 TipoPlayer* player = fsm -> user_data;		// Se extrae el player de la máquina de estados

	 player -> posicion_nota_actual = -1;
	 player ->duracion_nota_actual = player->melodia->duraciones[player->posicion_nota_actual];
	 player ->frecuencia_nota_actual = player->melodia->frecuencias[player->posicion_nota_actual];

	 piLock (FLAGS_KEY);
	 flags &= ~FLAG_PLAYER_START;
	 flags &= ~FLAG_PLAYER_STOP;
	 flags &= ~FLAG_PLAYER_END;
	 flags |= FLAG_NOTA_TIMEOUT;				// Se activa el FLAG_NOTA_TIMEOUT para dar paso a la siguiente nota
	 piUnlock (FLAGS_KEY);

	 piLock (STD_IO_BUFFER_KEY);
	 printf("\[PLAYER][InicializaPlayer][CanciÃ³n: %s]\n", player->melodia->nombre);
	 piUnlock (STD_IO_BUFFER_KEY);

 }

 /*
     * Function:  actualizaPlayer
     * --------------------
     * Actualiza los parámetros del TipoPlayer e informa de que ha finalizado la nota.
     * Imprime un mensaje informando del estado.
     *
     *  fsm: puntero a la máquina de estados
     *
     */

 void actualizaPlayer(fsm_t* fsm){

	 TipoPlayer* player = fsm -> user_data;		// Se extrae el player de la máquina de estados

	 player ->posicion_nota_actual++;
	 player ->duracion_nota_actual = player ->melodia->duraciones[player ->posicion_nota_actual];
	 player ->frecuencia_nota_actual = player ->melodia->frecuencias[player ->posicion_nota_actual];

	 piLock (FLAGS_KEY);
	 flags &= ~FLAG_PLAYER_START;
	 flags &= ~FLAG_PLAYER_STOP;
	 flags |= FLAG_PLAYER_END;					// Activa el FLAG_PLAYER_END para informar de que ha finalizado la nota
	 flags &= ~FLAG_NOTA_TIMEOUT;
	 piUnlock (FLAGS_KEY);

	 // Se comprueba si ha finalizado la melodía o no

	 piLock (STD_IO_BUFFER_KEY);
	 if (player->posicion_nota_actual == player->melodia->num_notas){
		 printf("\n[PLAYER][ActualizaPlayer][REPRODUCIDAS TODAS LAS NOTAS]\n");
	 } else {
		 printf("\n[PLAYER][ActualizaPlayer][NUEVA NOTA (%d DE %d)]\n", player->posicion_nota_actual+1, player->melodia->num_notas);
	 }
	 piUnlock (STD_IO_BUFFER_KEY);
 }

 /*
     * Function:  comienzaNuevaNota
     * --------------------
     * Toca la nota correspondiente generando una frecuencia determinada durante un tiempo determinado.
     * Escribe un mensaje informando del estado.
     *
     *  fsm: puntero a la máquina de estados
     *
     */

  void comienzaNuevaNota (fsm_t* fsm){

	  TipoPlayer* player = fsm -> user_data;		// Se extrae el player de la máquina de estados
	  tmr_t* tmr = fsm ->user_data2;				// Se extrae el timer de la máquina de estados

	  piLock (FLAGS_KEY);
	  flags &= ~FLAG_PLAYER_START;
	  flags &= ~FLAG_PLAYER_STOP;
	  flags &= ~FLAG_PLAYER_END;
	  flags &= ~FLAG_NOTA_TIMEOUT;
	  piUnlock (FLAGS_KEY);

	  piLock (STD_IO_BUFFER_KEY);
	  printf("\n[PLAYER][ComienzaNuevaNota][NOTA %d][FREC %d][DURA %d]\n", player->posicion_nota_actual+1, player->frecuencia_nota_actual, player->duracion_nota_actual);
	  piUnlock (STD_IO_BUFFER_KEY);

	  tmr_startms(tmr, player->duracion_nota_actual);				// Comienza el TMR durante el tiempo de la nota
	  softToneWrite (PIN_MELODIA, player->frecuencia_nota_actual);	// Genera una señal a la frecuencia de la nota
  }

  /*
      * Function:  stopPlayer
      * --------------------
      * Finaliza la reproducción de la melodía. Escribe un mensaje informando del estado
      *
      *  fsm: puntero a la máquina de estados
      *
      */

  void stopPlayer (fsm_t* fsm){

	  TipoPlayer* player = fsm -> user_data;		//Extrae el pplayer de la máquina de estados
	  player->posicion_nota_actual = player->melodia->num_notas - 1;	//Pone la posición actual a la última
	  softToneWrite (PIN_MELODIA, 0);		// Cesa la generación de la señal cuadrada

	  piLock (FLAGS_KEY);
	  flags &= ~FLAG_PLAYER_START;
	  flags &= ~FLAG_PLAYER_STOP;
	  flags &= ~FLAG_PLAYER_END;
	  flags &= ~FLAG_NOTA_TIMEOUT;
	  piUnlock (FLAGS_KEY);

	  piLock (STD_IO_BUFFER_KEY);
	  printf("\n[PLAYER][STOP PLAYER]\n");
	  piUnlock (STD_IO_BUFFER_KEY);
  }

  /*
       * Function:  finalMelodia
       * --------------------
       * Finaliza la reproducción de la melodía. Escribe un mensaje informando del estado
       *
       *  fsm: puntero a la máquina de estados
       *
       */

  void finalMelodia (fsm_t* fsm){

	  softToneWrite (PIN_MELODIA, 0);	//Cesa la generación de la señal cuadrada

	  piLock (FLAGS_KEY);
	  flags &= ~FLAG_PLAYER_START;
	  flags &= ~FLAG_PLAYER_STOP;
	  flags &= ~FLAG_PLAYER_END;
	  flags &= ~FLAG_NOTA_TIMEOUT;
	  piUnlock (FLAGS_KEY);

	  piLock (STD_IO_BUFFER_KEY);
	  printf("\n[PLAYER][FinalMelodia][FLAG_PLAYER_END]\n");
	  piUnlock (STD_IO_BUFFER_KEY);
  }

 //--------------------------------------------------------------------------------------------------------
 // FUNCIONES DE INICIALIZACION
 //--------------------------------------------------------------------------------------------------------

  /*
   * Function:  inicializaMelodia
   * --------------------
   * Inicializa la melodía a reproducir
   *
   *  melodia: puntero al TipoMelodia escogido
   *  nombre: puntero al nombre de la melodia
   *  array_frecuencias: puntero al array con las frecuencias de cada nota
   *  array_duraciones: puntero al array con las duraciones de cada nota
   *  num_notas: numero total de notas
   *
   *  returns: numero de notas
   */

  int inicializaMelodia (TipoMelodia *melodia, char *nombre, int *array_frecuencias, int *array_duraciones, int num_notas) {
	 int i;
	 strcpy(melodia ->nombre,nombre);
	 for (i=0; i<num_notas;i++){
		 melodia->frecuencias[i] = array_frecuencias[i]; //*(array_frecuencias+i);
		 melodia->duraciones[i] = array_duraciones[i];
	 }
	 melodia->num_notas=num_notas;
	 return melodia->num_notas;
 }

  /*
    * Function:  system_setup
    * --------------------
    * Inicializa los parametros del sistema
    *
    *  returns: 1 si toda ha ido bien
    */

 int system_setup (void) {
 	int x = 0;			//variable utilizada para comprobar la correcta inicialización de thread_explora_teclado
 	int y =0;			//variable utilizada para comprobar la correcta inicialización de thread_explora_tarjeta

 	piLock (STD_IO_BUFFER_KEY);

 	// sets up the wiringPi library

 	if (wiringPiSetupGpio () < 0) {
 		printf ("Unable to setup wiringPi\n");
 		piUnlock (STD_IO_BUFFER_KEY);
 		return -1;
     }

	pinMode (PIN_MELODIA, OUTPUT) ;
 	softToneCreate (PIN_MELODIA);

 	// Lanzamos thread para exploracion del teclado convencional del PC
 	x = piThreadCreate (thread_explora_teclado);

 	// Lanzamos thread para exploracion del modulo de detección de tarjetas
 	y = piThreadCreate (thread_explora_tarjeta);

 	// Comprobacion de la correcta inicializacion de thread_explora_teclado
 	if (x != 0) {
 		printf ("thread_explora_teclado didn't start!!!\n");
 		piUnlock (STD_IO_BUFFER_KEY);
 		return -1;
     }

 	// Comprobacion de la correcta inicializacion de thread_explora_tarjeta
 	if (y != 0) {
 	 		printf ("thread_explora_tarjeta didn't start!!!\n");
 	 		piUnlock (STD_IO_BUFFER_KEY);
 	 		return -1;
 	     }

 	// Se inicilizan las funciones encargadas de lanzar interrupciones según la información proporcionada por el
 	// modulo de deteccion de tarjetas

// 	wiringPiISR (21, INT_EDGE_FALLING, &flagStart) ;
 	wiringPiISR (20, INT_EDGE_BOTH,&compruebaFlanco) ;

 	piUnlock (STD_IO_BUFFER_KEY);

 	return 1;
 }

 /*
     * Function:  fsm_setup
     * --------------------
     * Inicializa la máquina de estados
     *
     */

 void fsm_setup(fsm_t* pi_fsm) {
 	piLock (FLAGS_KEY);
 	flags = 0;
 	piUnlock (FLAGS_KEY);

 	piLock (STD_IO_BUFFER_KEY);
 	printf("\nINICIE PLAYER\n");
 	piUnlock (STD_IO_BUFFER_KEY);
 }

 //------------------------------------------------------
 // PI_THREAD (thread_explora_teclado): Thread function for keystrokes detection and interpretation
 //------------------------------------------------------

 PI_THREAD (thread_explora_teclado) {
 	int teclaPulsada;

 	while(1) {
 		delay(10); // Wiring Pi function: pauses program execution for at least 10 ms

 		piLock (STD_IO_BUFFER_KEY);

 		if(kbhit()) {
 			teclaPulsada = kbread();


 			switch(teclaPulsada) {
 				case 's':
 					printf("\n[KBIT][s]\n");
 					piLock (FLAGS_KEY);
 					flags |= FLAG_PLAYER_START;
 					piUnlock (FLAGS_KEY);
 					break;

 				case 't':
 					printf("\n[KBIT][t]\n");
 					piLock (FLAGS_KEY);
 					flags |= FLAG_PLAYER_STOP;
 					piUnlock (FLAGS_KEY);

 					break;
 				case 'q':
 					printf("\n[KBIT][q]\n");
 					exit(0);
 					break;
 				default:
 					printf("\nINVALID KEY!!!\n");
 					break;
 			}
 		}

 		piUnlock (STD_IO_BUFFER_KEY);
 	}
 }

 //------------------------------------------------------
 // PI_THREAD (thread_explora_tarjeta): Thread function for card detection
 //------------------------------------------------------

 PI_THREAD (thread_explora_tarjeta){
	 while(1){
	 delay(10);		//// Wiring Pi function: pauses program execution for at least 10 ms
	 }

 }

 /*
      * Function:  timer_isr
      * --------------------
      * Funcion de WiringPi que activa el FLAG_NOTA_TIMEOUT cuando vence el timer
      *
      */

 void timer_isr (union sigval value) {flags |= FLAG_NOTA_TIMEOUT; }

 /*
      * Function:  main
      * --------------------
      * Funcion principal del programa. Inicializa el sistema y comienza a funcionar en un bucle infinito
      *
      */

 int main () {

	 /* Local Variables */

	 unsigned int next;			// variable utilizada para calcular el tiempo entre estados

 	TipoSistema sistema;
 	TipoMelodia GOT;

 	sistema.player.melodia =& (sistema.tarjetas_activas[0].melodia);	// El puntero melodia del sistema
 																		// se apunta a la melodia de la tarjeta

 	// Inicializacion de las distintas variables del sistema

 	if (inicializaMelodia(&GOT, "GOT",frecuenciaGOT,tiempoGOT, 518) < 0){
 		printf("\n [ERROR] [INICIALIZAMELODIA]\n");
 		fflush(stdout);
 	}
 	sistema.player.melodia = &GOT;

 	// Maquina de estados: lista de transiciones
 	// {EstadoOrigen,FuncionDeEntrada,EstadoDestino,FuncionDeSalida}
 	fsm_trans_t estados[] = {
 			{ WAIT_START,   compruebaPlayerStart,  WAIT_NEXT, inicializaPlayer },
 			{ WAIT_NEXT, compruebaPlayerStop, WAIT_START, stopPlayer },
			{ WAIT_NEXT, compruebaNotaTimeout, WAIT_END, actualizaPlayer },
			{ WAIT_END, compruebaFinalMelodia, WAIT_START, finalMelodia },
			{ WAIT_END, compruebaNuevaNota, WAIT_NEXT, comienzaNuevaNota },
 			{ -1, NULL, -1, NULL },
 	};

 	fsm_trans_t estados_tarjeta[]={
 			{ WAIT_START_LECTOR, compruebaComienzo, WAIT_CARD, comienzaSistema},
			{WAIT_CARD, tarjetaNoDisponible, WAIT_CARD, esperaTarjeta},
			{WAIT_CARD, tarjetaDisponible, WAIT_CHECK, leerTarjeta},
			{WAIT_CHECK, tarjetaNoValidada, WAIT_CARD, descartaTarjeta},
			{WAIT_CHECK, tarjetaValidada, WAIT_PLAY, comienzaReproduccion},
			{WAIT_PLAY, tarjetaDisponible, WAIT_PLAY, comprueboTarjeta},
			{WAIT_PLAY, compruebaFinalReproduccion, WAIT_START, finalizaReproduccion},
			{WAIT_PLAY, tarjetaNoDisponible, WAIT_START, cencelaReproduccion},
			{-1, NULL, -1, NULL},
 	};


 	tmr_t* tmr = tmr_new (timer_isr);

 	//Se crea la máquina de estados

 	fsm_t* sistema_fsm = fsm_new (WAIT_START, estados, &(sistema.player), tmr);

 	fsm_t* deteccion_tarjetas_fsm = fsm_new(WAIT_START_LECTOR, estados_tarjeta, &(sistema), tmr);

 	// Configuracion e inicializacion del sistema
 	system_setup();

 	// Configuracion e inicializacion de la maquina de estados
 	fsm_setup (sistema_fsm);


 	next = millis();

 	//Bucle infinito en el funciona la maquina de estados
 	while (1) {
 		fsm_fire (sistema_fsm);
 		fsm_fire(deteccion_tarjetas_fsm);
 		next += CLK_MS;
 		delay_until (next);
 	}

 	// Liberacion de memoria tras finalizar el funcionamiento del sistema
 	tmr_destroy(tmr);
 	fsm_destroy (sistema_fsm);
 }
