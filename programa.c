#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#ifndef MONITOR_H
#include "monitor.h"
#endif

void *thread_filosofo(void *i)
{
	int indc;
	int tempo;

	//Variavel que armazena indice do filósofo
	indc = * (int*) i;

	while(TRUE)
	{
		//Tempo que o filósofo ficara pensando
		tempo = (1 + rand())  % 10;

		//Imprime mensagem indicativa
		printf("\nFilosofo %d pensa por %ds", indc, tempo);
		sleep(tempo);

		//Após acordar, o filósofo tentará pegar os palitos
		pegar_palitos(indc);

		//Tempo que o filósofo ficara comendo
		tempo = (1 + rand())  % 10;
		
		printf("\nFilosofo %d come por %ds", indc, tempo);
		sleep(tempo);
		printf("\nFilosofo %d terminou de comer", indc);

		//O filósofo, após comer, devolve os palitos
		devolve_palitos(indc);
	}

	return NULL;
}


int main()
{
	//Criar 5 threads, uma para cada filósofo
	pthread_t filosofo[5];

	//Inicia o monitor
	iniciar_monitor();

	//Preparar as threads
	int i;
	for(i = 0; i < 5 ; i++)
	{
		pthread_create(&filosofo[i], NULL, thread_filosofo, &i);
	}
	for(i = 0; i < 5 ; i++)
	{
		pthread_join(filosofo[i], NULL);
	}


	return 0;
}