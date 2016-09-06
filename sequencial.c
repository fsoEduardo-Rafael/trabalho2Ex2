#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char **argv){
	int max;
	int i, size_array = argc-2;
	int array[size_array];
	clock_t start, end;

	for(i=0 ; i < size_array ; ++i){
		array[i] = atoi(argv[i+2]);
	}

	start = clock();
	max = array[0];
	printf("max = %d\n", max);
	for(i=1 ; i<size_array ; ++i){
		if(array[i] > max)
			max = array[i];
		printf("max = %d\n", max);
	}
	end = clock();
	printf("O maximo e: %d\n", max);
	printf("O tempo foi de: %.2f", (double)end-start/CLOCKS_PER_SEC);
	return 0;
}