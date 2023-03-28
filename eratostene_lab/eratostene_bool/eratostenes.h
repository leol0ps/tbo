#ifndef ERASTOTENES_H
#define ERASTOTENES_H
#include <stdlib.h>
#include <stdbool.h>

bool* CriaLista(int n); // cria lista n >= 2
void marcar(int a,bool* list, int n);
void checkAll(bool* a, int n);
void freeList(bool* a);
#endif