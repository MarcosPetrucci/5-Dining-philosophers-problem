#include <pthread.h>
#include <semaphore.h>
#define TRUE 1
#define FALSE 0

#ifndef MONITOR_H
#include "monitor.h"
#endif

//Semáforo usado no monitor
sem_t semaforo;

//Variavel de condição para os filofos
filo Filosofo[5];

//Função que resolve um filosofo ocioso
void ocioso(int i)
{
  //Filósofo com fome, mas impossibilitado de comer
  sem_post(&semaforo); //Libera semaforo
}

//Muda o estado do filósofo para comendo se os palitos estiverem disponíveis
void verifica_disponibilidade(int i)
{
  //Verifica se os filosofos do lado estao comendo
  if(Filosofo[i].estado == FAMINTO && Filosofo[(i+4)%5].estado != COMENDO 
     && Filosofo[(i+1)%5].estado != COMENDO)
  {
    //Os palitos estão disponíveis, comer
    Filosofo[i].estado = COMENDO;
  }
}

//Função que organiza a pegada dos palitos
void pegar_palitos(int i)
{
  //Esperar a disponibiliade do semáforo
  sem_wait(&semaforo);

  //O Filósofo fica faminto
  Filosofo[i].estado = FAMINTO;

  //Verifica se o filosofo i pode começar a comer
  verifica_disponibilidade(i);

  while(Filosofo[i].estado == FAMINTO)
  {
    //Os palitos não estão disponíveis, então o filosofo esta ocioso
    ocioso(i);
  }

  //O filósofo está comendo, incrementar semáforo
  sem_post(&semaforo);
}

//Função que organiza a devolução dos palitos
void devolve_palitos(int i)
{
  //Esperar pela disponibilidade do semáforo
  sem_wait(&semaforo);

  //O filósofo terminou de comer, 
  Filosofo[i].estado = PENSANDO;

  //Notifica os filosofos do lado que o atual acabou de comer
  //Se eles estiverem com fome e for possível, eles vão comer!
  verifica_disponibilidade((i+4)%5);
  verifica_disponibilidade((i+1)%5);

}

//Função que inicia o monitor e suas variáveis
void iniciar_monitor()
{
  //Inicia o semáforo com valor 1
	sem_init(&semaforo,0,1); 
	
  int i;
  for(i = 0;i < 5;i++)
	{
    //Inicia todos os filósofos no estado pensando
		Filosofo[i].estado = PENSANDO;
	}
}
