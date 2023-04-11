#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"


int main(int argc,char** argv){
	int n = atoi(argv[1]);
	int aux;
	srand(time(NULL)); // should only be called once
	Bst* tree = cria_bst();
	for(int i = 0; i < n ; i++){
		aux = rand();
		insert_bst(tree,aux);
	}
	int altura = bst_high(tree);
	//print_bst(tree);
	printf("%d\n", altura);
	free_bst(tree);
	return 0;
}
