#ifndef ERASTOTENES_H
#define ERASTOTENES_H
#include <stdlib.h>

int* CriaLista(int n); // cria lista n >= 2
void marcar(int a,int* list, int n);
void checkAll(int* a, int n);
void freeList(int* a);
#endif