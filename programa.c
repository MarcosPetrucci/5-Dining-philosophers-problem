#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#include "monitor.h"

void *thread_filosofo(void *i)
{
	
}


int main()
{
	//Criar 5 threads, uma para cada filósofo
	pthread_t filosofo[5];

	//Inicia o monitor
	iniciar_monitor();

	int i;
	for(i = 0; ; i < 5; i++)
	{
		pthread_create(&filosofo[i], NULL, thread_filosofo, i);
	}

	return 0;
}