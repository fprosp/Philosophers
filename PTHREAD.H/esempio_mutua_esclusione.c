#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMTHRDS 10

pthread_t callThd[NUMTHRDS];
pthread_mutex_t mutexdata;    
int data;

void *decremento(void *i)
{
	pthread_mutex_lock(&mutexdata);  
	if(data > 0) 
		data--;
	usleep(5500000);	// Alla sua chiamata mette in pausa l'esecuzione del processo per il numero di millisecondi indicato tra ().
	printf("Processo n: %d\nValore data: %d\n\n", (int)i , data);
	pthread_mutex_unlock(&mutexdata);
	pthread_exit(NULL);
}

int main (void)
{
	int status;
	int i;
	int error_state;
	
	pthread_mutex_init(&mutexdata, NULL);
	data = 4;
	error_state = 0;
	i = 0;
	while (i < NUMTHRDS)   
	{
		error_state = pthread_create(&callThd[i], NULL, decremento, (void *)i);  // per default i thread consentono il join
		i++;
	}
	i = 0;
	while (i < NUMTHRDS)
	{
		pthread_join(callThd[i], (void **)&status); // Aspetta la fine dei thread.
		i++;
	}
	printf ("data =  %d \n", data);
	pthread_mutex_destroy (&mutexdata);
	pthread_exit(NULL);
}
