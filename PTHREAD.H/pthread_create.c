#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 5


/* Questo è un esempio di creazione di sottoprocessi-thread tramite la funzione thread_create(...) ed il passaggio di strutture
dati alla funzione routine */

int N = 0;

void *start_routine(void *i_data) // Viene eseguite all'interno di ogni thread creato. 
{
	printf("\n%d: Hello World! N=%d\n", i_data, N);
	pthread_exit (NULL);	// La stessa funzione chiamata nella funzione passata al thread, chiude il thread e libera la memoria.
	N++;					// Solo all'intenro del thread nel quale viene chiamata. 
}

int main(void)
{
	pthread_t threads[NUM_THREADS];		// Array contenente gli indirizzi dei rispettivi thread creati. 
	int *data[NUM_THREADS];			// Esso viene passato come indirizzo "i-esimo" al primo parametro alla funzione "pthread_create(...)". 
	int rc;
	int i;

	i = 0;
	while (i < NUM_THREADS)
	{
		data[i] = (int *)malloc(sizeof(int));  // Per il passaggio di strutture alla funzione eseguire nel i-esimo pthread creato.
		if (!data[i])
			return (EXIT_FAILURE);
		*data[i] = i;
		printf("Creating thread %d\n", i);
		rc = pthread_create(&threads[i], NULL, start_routine, (void *)&data[i]);	// "pthread_create(...)" crea un thread ad ogni giro del ciclo, all'interno del quale viene eseguita la funzione passatale come terzo argomento. 
		if (rc)		//L'inizialiazione del secondo parametro a NULL esegue le impostazione di default della funzione.
		{			// Se il la funzione "pthread_create(...)" incorre in un errore, essa restituisce un identificatore dell'errore incorso diverso da 0. 
			printf("ERROR; return code from pthread_create(...) is %d\n",rc); // In caso di successo essa restituisce 0.
			exit(-1);
		}
		i++;
	}
	pthread_exit (NULL);	// Questa funzione, se chiamata all'interno del main mantiene in vita i thread creati precedentemente fintanto che le loro operazioni non siano state eseguite tutte. 
}							// Altrimnti tutti li termina a prescindere dal loro stato di esecuzione.
