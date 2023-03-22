#include <pthread.h>
#include <stdio.h>
# include <stdlib.h>
#define NUM_THREADS 5
int N = 0;

void *start_routine(void *threadid) // Viene eseguite all'interno di ogni thread creato. 
{
	printf("\n%d: Hello World! N=%d\n", threadid, N);
	pthread_exit (NULL);	// La stessa funzione chiamata nella funzione passata al thread, chiude il thread e libera la memoria, solo all'intenro del thread nel quale viene chiamata. 
	N++;
}
int main()
{
	pthread_t threads[NUM_THREADS];		// Array contenente gli indirizzi dei rispettivi thread creati. Esso viene passato come indirizzo "t-esimo" al primo parametro alla funzione "pthread_create(...)". 
	int *taskids[NUM_THREADS];
	int rc;
	int t;

	t = 0;
	while (t < NUM_THREADS)
	{
		taskids[t] = (int *)malloc(sizeof(int));
		if (!taskids[t])
			return (EXIT_FAILURE);
		*taskids[t] = t;
		printf("Creating thread %d\n", t);
		rc = pthread_create(&threads[t], NULL, start_routine, (void *)&taskids[t]);		// "pthread_create(...)" crea un thread ad ogni giro del ciclo, all'interno del quale viene eseguita la funzione passatale come terzo argomento. 
		if (rc)																			//L'inizialiazione del secondo parametro a NULL esegue le impostazione di default della funzione.
		{	// Se il la funzione "pthread_create(...)" incorre in un errore, essa restituisce un identificatore dell'errore incorso diverso da 0. In caso di successo essa restituisce 0.
			printf("ERROR; return code from pthread_create(...) is %d\n",rc);
			exit(-1);
		}
		t++;
	}
	pthread_exit (NULL);	// Questa funzione, se chiamata all'interno del main mantiene in vita i thread creati precedentemente fintanto che le loro operazioni non siano state eseguite tutte. 
}							// Altrimnti tutti li termina a prescindere dal loro stato di esecuzione.
