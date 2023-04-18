#ifndef LIST_H
#define LIST_H
#include "point.h"
typedef struct list{
    Point* ponto;
    struct list* next;
}List;
List* create_list(Point* a);
void insert(List* list,Point* a);
void free_list(List* a);
Point** vetor_de_pontos(List* a);

#endif