#include <stdio.h>
#include "point.h"
#include "list.h"
#include "file.h"

int main(int argc, char** argv){
    int dimension;
    int lines = 0;
    List* list = read_file(argv[1],&dimension,&lines);
    Point** vetor = vetor_de_pontos(list,lines);
    double** matriz = distance_matrix(vetor,lines,dimension);
    //print_matrix(matriz,lines);
    free_matrix(matriz,lines);
    print_list(list,dimension);
    free_list(list);
    free_vetor_de_pontos(vetor);
    printf("numero de linhas %d",lines);
    return 0;
}