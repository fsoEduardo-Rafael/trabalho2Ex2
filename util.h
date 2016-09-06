#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <pthread.h>

int w[100];
typedef struct numeros Numeros;
struct numeros {
	int num1;
	int num2;
};
Numeros numeros;


void *set_w();
void *compare_numbers();

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

void * create_threads_to_compare(int argc, char **argv){
	int i, j, result;
	int size_array = argc-2;
	int array[size_array];
	int old_cancel_state;

	for(i=0 ; i < size_array ; ++i){
		array[i] = atoi(argv[i+2]);
		printf("Array[%d] = %d\n",i, array[i]);
	}
	pthread_t * thread = malloc(sizeof(pthread_t)*(argc-2/2));//alocando n/2 threads

	for(i = 0; i < size_array; ++i) {
		for(j = 0; j < size_array; ++j) {
			printf("i = %d e j = %d\n", i, j);
			pthread_setcancelstate (PTHREAD_CANCEL_DISABLE, &old_cancel_state);
			numeros.num1 = array[i];
			numeros.num2 = array[j];
			pthread_setcancelstate (old_cancel_state, NULL);
	        result = pthread_create(&thread[i], NULL, &compare_numbers, (void*) i); 
	        if( result != 0) {
	            printf("ERRO!!\n");
	        }
	   }
	}
	for(i=0 ; i < size_array ; ++i){
		pthread_join(thread[i],NULL);
	}
}

void * set_w(int arg){
	printf("arg = %d\n", arg);
	printf("Thread %d trabalhando..\n", arg);
	w[arg] = 1;
}

void * compare_numbers(int i){
	int old_cancel_state;
	printf("Entrou aqui\n");
	printf("Base da comparacao = %d\n", i);
	printf("Comparando %d x %d\n", numeros.num1, numeros.num2);
	if(numeros.num1 < numeros.num2){
		w[i] = 0; 
	}
}