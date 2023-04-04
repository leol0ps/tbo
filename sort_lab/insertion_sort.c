#include "item.h"
void sort(Item *a, int lo, int hi){
	for(int i = lo; i < hi+1; i++){
		for(int j = lo; j < i; j++){
			compexch(a[j], a[i]);
		}
	}
}
