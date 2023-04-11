#ifndef BST_H
#define BST_H
#include <stdlib.h>
#include <stdio.h>
typedef struct bst Bst;

Bst* cria_bst();
void free_bst(Bst* a);
void insert_bst(Bst* a, int element);
int bst_high(Bst* a);
void print_bst(Bst* a);
#endif
