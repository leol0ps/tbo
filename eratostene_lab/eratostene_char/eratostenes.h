#ifndef ERASTOTENES_H
#define ERASTOTENES_H
#include <stdlib.h>

char* CriaLista(int n); // cria lista n >= 2
void marcar(int a,char* list, int n);
void checkAll(char* a, int n);
void freeList(char* a);
#endif