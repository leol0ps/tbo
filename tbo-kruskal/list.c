#include "list.h"

List* create_list(Point* a){
    List* b = malloc(sizeof(List));
    b->ponto  = a;
    b->next = NULL;
    return b;
}


void insert(List* list,Point* a){
    if(list->next != NULL){
        insert(list->next,a);
    }
    else{
        list->next = malloc(sizeof(List));
        list->next->ponto = a;
        list->next->next = NULL;
    }
}
void free_list(List* a){
    if(a == NULL)
        return;
    free_list(a->next);
    delete_point(a->ponto);
    free(a);
}
Point** vetor_de_pontos(List* a);