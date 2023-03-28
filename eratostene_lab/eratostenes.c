#include "eratostenes.h"


int* CriaLista(int n){
    if(n < 2)
        return NULL;
    int* list = malloc(n*sizeof(int));
        for(int i = 0; i < n ; i++){
            list[i] = 0;
        }
    return list;
}

void marcar(int a,int* list, int n){ 
    for(int i = a+1; i < n; i++){
        if(i%a == 0)
            list[i] = 1;
    }
}
void checkAll(int* a, int n){
    int i = 0;
    int old = -1;
    while(i < n){
        if(!a[i] && i > old){ //se não está marcado e maior que anterior
            marcar(i+2,a,n); // consideramos que o index 0 representa o numero 2
            old = i;
        }
        i++;
    }
}
void freeList(int* a){
    free(a);
}
