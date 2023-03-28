#include "eratostenes.h"


bool* CriaLista(int n){
    if(n < 2)
        return NULL;
    bool* list = malloc(n*sizeof(bool));
        for(int i = 0; i < n ; i++){
            list[i] = false;
        }
    return list;
}

void marcar(int a,bool* list, int n){ 
    for(int i = a+1; i < n; i++){
        if(i%a == 0)
            list[i] = true;
    }
}
void checkAll(bool* a, int n){
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
void freeList(bool* a){
    free(a);
}
