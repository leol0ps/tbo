#ifndef KRUSKAL_H
#define KRUSKAL_H
#include "point.h"

typedef struct edge{
    int i;
    int j;
    double edge_lenght;
}Edge;
void free_vetor_arestas(Edge** a, int size);
Edge** cria_vetor_arestas(double** matrix, int dimension, int* edge_array_size);
int* kruskal(Edge** arestas, int size); //retorna a mst

#endif