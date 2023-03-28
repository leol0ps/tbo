#include "eratostenes.h"


char* CriaLista(int n){
    if(n < 2)
        return NULL;
    char* list = malloc(n*sizeof(char));
        for(int i = 0; i < n ; i++){
            list[i] = ' ';
        }
    return list;
}

void marcar(int a,char* list, int n){ 
    for(int i = a+1; i < n; i++){
        if(i%a == 0)
            list[i] = 'a';
    }
}
void checkAll(char* a, int n){
    int i = 0;
    int old = -1;
    while(i < n){
        if(a[i] == ' ' && i > old){ //se não está marcado e maior que anterior
            marcar(i+2,a,n); // consideramos que o index 0 representa o numero 2
            old = i;
        }
        i++;
    }
}
void freeList(char* a){
    free(a);
}
