#include "kruskal.h"
#include <stdlib.h>
#include <stdio.h>






int UF_find(int i, int* id) {
    while (i != id[i]) {
        id[i] = id[id[i]]; // Uma unica linha de codigo adicional.
        i = id[i]; // Cada passo agora requer 5 acessos.
    }
    return i;
}
void UF_union(int p, int q, int* id, int* sz) {
    int i = UF_find(p,id); // Pendure a arvore menor sob a maior.
    int j = UF_find(q, id); // Profundidade de ? acessos.
    if (i == j) return;
    if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
    else { id[j] = i; sz[i] += sz[j]; }
}
Edge* cria_aresta(int i, int j,double a){
    Edge* new_edge = malloc(sizeof(Edge));
    new_edge->edge_lenght=a;
    new_edge->i=i;
    new_edge->j=j;
    return new_edge;
}
Edge** cria_vetor_arestas(double** matrix, int dimension, int* edge_array_size){
    int size = dimension*(dimension-1)/2;
    *edge_array_size = size;
    Edge** vetor = malloc(size*sizeof(Edge*));
    int count = 0;
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < i ; j++){
            vetor[count] = cria_aresta(i,j,matrix[i][j]);
            count++;
        }
    }
    printf("count %d\n",count);
    return vetor;
}

void print_arestas(Edge** vetor,int size){
    for(int i = 0; i < size; i++){
        printf("%d %d aresta %lf\n", vetor[i]->i,vetor[i]->j,vetor[i]->edge_lenght);
    }
}
void free_vetor_arestas(Edge** a, int size){
    for(int i = 0; i < size; i++){
        free(a[i]);
    }
    free(a);
}
int cmpfunc (const void * a, const void * b) {
    Edge* x = (Edge*)a;
    Edge* y = (Edge*)b;
   return  y->edge_lenght < x->edge_lenght;
}
int* kruskal(Edge** arestas, int size){
    int * nsei;
    qsort(arestas,size,sizeof(Edge*),cmpfunc);
    print_arestas(arestas,size);
    //Edge** vetor_de_arestas = cria_arestas(matrix);
    return nsei;
}