#include "item.h"
void sort(Item *a, int lo, int hi){
	int aux = 1;
	while(aux){
	aux = 0;
	for(int i = lo; i < hi; i++){
		if(less(a[i+1],a[i])){
			exch(a[i+1],a[i]);
			aux =1;
			}
		}
	}

}
