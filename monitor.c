#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <semaphore.h>
#define TRUE 1
#define FALSE 0
//Semáforo usado no monitor
sem_t mutex;

//Variavel de condição para os filofos
typedef struct
{
  //Semáforo de cada filofo
	sem_t sem; //Recebe uma "notificacao" quando o vizinho para de comer

  //Variavel indica se o filosofo está parado esperando para comer
  int parado;

  //Mapeia o estado do filosofo
  enum {PENSANDO,FAMINTO,COMENDO} estado;

}filo;
filo Filosofo[5];

//Função que resolve um filosofo ocioso
void ocioso(int i)
{

  Filosofo[i].parado = TRUE;
  
  //Filósofo com fome, mas impossibilitado de comer
  sem_post(&mutex); //Libera mutex
	
  //Filosofo aguarda liberação dos palitos do lado
  sem_wait(&Filosofo[i].sem);
	
  Filosofo[i].parado = FALSE;
}
