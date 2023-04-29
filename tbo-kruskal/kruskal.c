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
    //printf("count %d\n",count);
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
    Edge* x = *(Edge**)a;
    Edge* y = *(Edge**)b;
    if(y->edge_lenght < x->edge_lenght)
        return 1;
    if(y->edge_lenght > x->edge_lenght)
        return -1;
   return 0;
}
int* kruskal(Edge** arestas, int size_aresta,int size_mst,int k){
    int* mst = malloc(size_mst*sizeof(int));
    int* number_of_elements = malloc(size_mst*sizeof(int));

    for(int i = 0; i < size_mst; i++){
        mst[i]=i;
        number_of_elements[i] = 1;
    }
    int min_of_edges  = size_mst - k;
    int j = 0;
    qsort(arestas,size_aresta,sizeof(Edge*),cmpfunc);
    for(int i = 0; i < size_aresta && j < min_of_edges;i++){
        if(UF_find(arestas[i]->i,mst)!=UF_find(arestas[i]->j,mst)){
            UF_union(arestas[i]->i,arestas[i]->j,mst,number_of_elements);
            j++;
        }
    }
    //print_arestas(arestas,size_aresta);
    free(number_of_elements);
    return mst;
}