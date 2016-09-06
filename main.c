#include "util.h"
	
int main (int argc, char **argv){
	int i;

	//w = malloc(sizeof(atoi(argv - 2*(char))));//alocando o vetor w

	print_elements(argc, argv); // Imprimindo informações iniciais

	//Criando n threads e setando 1 no vetor W:
	create_threads_to_init_w(argc-2);

	for(i=2 ; i<argc ; ++i){
		printf("W[%d] = %d\n", i-2, w[i-2]);
	}
	return 0;
}