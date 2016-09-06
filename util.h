#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <pthread.h>

int w[100];

void *set_w();

void print_elements(int argc, char **argv){
	int i;
	
	assert(sizeof(argv) <= 100);//Garantindo que a entrada possua ate 100 argumentos
	printf("Numer: %d\n", argc - 2);//os dois primeiros sao: nome_prog e num_entradas
	printf("Numero de elementos: %d\nElementos:\n", argc -2);
	for(i=2 ; i<argc ; ++i){
		printf("%d: %d\n", i-1, atoi(argv[i]));
	}
}

void create_threads_to_init_w(int n){
	int i, result;
	pid_t pid;
	pthread_t * thread = malloc(sizeof(pthread_t)*n);//alocando n threads

	for(i = 0; i < n; ++i) {
		printf("i = %d\n", i);
       result = pthread_create(&thread[i], NULL, &set_w, (void*) i); 

       if( result != 0) {
           printf("ERRO!!\n");
       }
	}
	for(i=0 ; i < n ; ++i){
		pthread_join(thread[i],NULL);
	}
}

void * set_w(int arg){
	printf("arg = %d\n", arg);
	printf("Thread %d com id %d trabalhando..\n", arg, (int) pthread_self());
	w[arg] = 1;
}