#include "item.h"
void sort(Item *a, int lo, int hi){
	int aux;
	for(int i = lo; i < hi+1; i++){
		aux = i;
		for(int j = aux; j < hi+1; j++){
			
			if(less(a[j],a[aux])){
				aux = j;
			}
		}
		exch(a[aux],a[i]);	
	}
}		

