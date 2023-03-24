#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUMTHRDS 10

typedef struct s_dati
{
	int data;
	int i;
	pthread_mutex_t mutexdata;
} t_dati;

void *routine(t_dati *var)
{
	if (var->i % 2 == 0) // Se vero mette in pausa l'esecuzione del thread per i millisecondi indicati.
		usleep(500000);	
	pthread_mutex_lock(&var->mutexdata);
	if(var->data > 0) 
		var->data--;
	printf("Processo n: %d\nValore data: %d\n\n", var->i , var->data);
	pthread_mutex_unlock(&var->mutexdata);
	pthread_exit(NULL);
}

int main (void)
{
	pthread_t callThd[NUMTHRDS];
	t_dati var;
	int status;
	int error_state;
	
	pthread_mutex_init(&var.mutexdata, NULL);	// Inizializzazzione della variabile mutex.
	var.data = 4;
	error_state = 0;
	var.i = -1;
	while (++var.i < NUMTHRDS)   
		error_state = pthread_create(&callThd[var.i], NULL, routine, &var);  // Di default i thread consentono il join
	var.i = -1;
	while (++var.i < NUMTHRDS)
		pthread_join(callThd[var.i], (void **)&status); // Aspetta la fine dei thread.
	printf ("data =  %d \n", var.data);
	pthread_mutex_destroy (&var.mutexdata);
	pthread_exit(NULL);
}
