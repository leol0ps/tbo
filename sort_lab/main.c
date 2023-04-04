#include "item.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern void sort(Item *a, int lo, int hi);
int main(int arc, char* argv[]){
	int n = atoi(argv[1]);
	Item* array = malloc(n*sizeof(Item)); 
	for( int i = 0 ; i < n ; i++){
		scanf("%d",&array[i]);
	}
	sort(array,0,n);
	for(int i = 0; i < n ;  i++){
		printf("%d\n", array[i]);
	}
	free(array);
	return 0;
}
