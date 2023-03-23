#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#define NUM_THREADS 5

int N = 0;

void *routine(void *threadid) // Viene eseguite all'interno di ogni thread creato. 
{
	printf("\n%d: Hello World! N=%d\n", threadid, N);
	pthread_exit (NULL);	// La stessa funzione chiamata nella funzione passata al thread, chiude il thread e libera la memoria, solo all'intenro del thread nel quale viene chiamata. 
	N++;
}
int main()
{
	pthread_t threads[NUM_THREADS];		// Array contenente gli indirizzi dei rispettivi thread creati. Esso viene passato come indirizzo "i-esimo" al primo parametro alla funzione "pthread_create(...)". 
	int *taskids[NUM_THREADS];	// Argomento passato alla funzione routine. 
	int rc;
	int i;

	i = 0;
	while (i < NUM_THREADS)
	{
		taskids[i] = (int *)malloc(sizeof(int));
		if (!taskids[i])
			return (EXIT_FAILURE);
		*taskids[i] = i;
		printf("Creating thread %d\n", i);
		rc = pthread_create(&threads[i], NULL, routine, (void *)&taskids[i]);		// "pthread_create(...)" crea un thread ad ogni giro del ciclo, all'interno del quale viene eseguita la funzione passatale come terzo argomento. 
		if (rc)		//L'inizialiazione del secondo parametro a NULL esegue le impostazione di default della funzione.
		{	// Se il la funzione "pthread_create(...)" incorre in un errore, essa restituisce un codice dell'errore incorso != a 0. In caso di successo restituisce 0.
			printf("ERROR; return code from pthread_create(...) is %d\n",rc);
			exit(-1);
		}
		i++;
	}
	pthread_exit (NULL);	// Se chiamata nel main tiene in vita i thread fintanto che le loro operazioni siano state eseguite tutte. 
}	// Altrimnti termina tutti i processi subito.


