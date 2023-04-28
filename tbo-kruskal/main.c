#include <stdio.h>
#include "point.h"
#include "list.h"
#include "file.h"
#include "kruskal.h"

int main(int argc, char** argv){
    int dimension;
    int lines = 0;
    List* list = read_file(argv[1],&dimension,&lines);
    Point** vetor = vetor_de_pontos(list,lines);
    double** matriz = distance_matrix(vetor,lines,dimension);
    int size_arestas;
    Edge** arestas = cria_vetor_arestas(matriz,lines,&size_arestas);
    int* idontk = kruskal(arestas,size_arestas);
    //printf("%d\n", size_arestas);
    free_vetor_arestas(arestas, size_arestas);

    //print_matrix(matriz,lines);
    free_matrix(matriz,lines);
    //print_list(list,dimension);
    free_list(list);
    free_vetor_de_pontos(vetor);
    printf("numero de linhas %d",lines);
    return 0;
}