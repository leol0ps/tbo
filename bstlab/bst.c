#include "bst.h"

typedef struct no{
	int key;
	struct no* l;
	struct no* r;

}No;
typedef struct bst{
	No* prim;
}Bst;

Bst* cria_bst(){
	Bst* a = malloc(sizeof(Bst));
	a->prim = NULL;
	return a;
}
No* criaNo(int n){
	No* novoNo = malloc(sizeof(No));
	novoNo->key = n;
	novoNo->l = NULL;
	novoNo->r = NULL;
	return novoNo;
	
}
void free_no(No* a){
	if(a ==NULL)
		return;
	free_no(a->l);
	free_no(a->r);
	free(a);
}
void free_bst(Bst* a){
	free_no(a->prim);
	free(a);
}
void insert_no(No* a, int element){
	if(a->key == element){
		return;
	}
	else if(a->key > element){
		if(a->l != NULL){
			insert_no(a->l,element);
		}
		else{
			a->l = criaNo(element);
		}
		
	}
	else{
		if(a->r != NULL){
			insert_no(a->r,element);
		}
		else{
			a->r = criaNo(element);
		}
		
	}
	
}
void insert_bst(Bst* a, int element){
	Bst* aux = a;
	if(a->prim == NULL){
		a->prim = criaNo(element);
	}
	else{
		insert_no(a->prim,element);
	}
}

int no_count(No* a){
	if(a == NULL)
		return 0;
	int max;
	int l = no_count(a->l);
	int r = no_count(a->r);
	if(l>r)
		max = l;
	else
		max = r;	
	
	return 1 + max;
}

int bst_high(Bst* a){
	if(a->prim ==NULL)
		return -1;
	return no_count(a->prim) -1;
}

void print_no(No* a){
	if( a == NULL)
		return;
	print_no(a->l);
	printf("%d\n",a->key);
	print_no(a->r);
}
void print_bst(Bst* a){
	print_no(a->prim);
}


