#include "util.h"
	
int main (int argc, char **argv){
	int i;

	//w = malloc(sizeof(atoi(argv - 2*(char))));//alocando o vetor w

	print_elements(argc, argv); // Imprimindo informações iniciais

	//Criando n threads e setando 1 no vetor W:
	create_threads_to_init_w(argc-2);

	printf("Vetor W setado em 1:\n");
	for(i=2 ; i<argc ; ++i){
		printf("W[%d] = %d\n", i-2, w[i-2]);
	}
	printf("---------------------------------------\n\n");

	
	create_threads_to_compare(argc, argv);//Criando threads para comparação

	printf("Apos comparacao:\n");
	for(i=2 ; i<argc ; ++i){ //Imprimindo W apos comparação
		printf("W[%d] = %d\n", i-2, w[i-2]);
	}

	for(i=0 ; i < argc-2 ; i++){
		if(w[i] == 1)//Se for 1, é o maior valor do vetor
			printf("E o valor maximo e: %d\nSua posicao e:%d\n", atoi(argv[i+2]), i);
	}
	
	return 0;
}