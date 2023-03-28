#include <stdio.h>
#include "eratostenes.h"

int main (int argc,char* argv[]){
    int n = atoi(argv[1]);
    char* a = CriaLista(n);
    
    checkAll(a,n);
    for(int i = 0; i < n ; i++){
        if(a[i] == ' '){
            printf("%d\n", i);
        }
    }
    freeList(a);
    return 0;
}