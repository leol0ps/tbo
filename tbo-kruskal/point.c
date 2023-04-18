#include "point.h"
#include "math.h"
double distance(Point* a, Point* b, int n ){
    double ret = 0;
    for(int i = 0; i < n;i++){
        ret += (a->dim[i] - b->dim[i])*(a->dim[i] - b->dim[i]);
    }
    return sqrt(ret);
}

Point* create_point(int dimension,char* name,double* vet){
    Point* a = malloc(sizeof(Point));
    int strsize = strlen(name);

    a->name = malloc((strsize+1)*sizeof(char));
    strcpy(a->name,name);
    a->dim = malloc(dimension*sizeof(double)); 
    for(int i = 0; i < dimension; i++){
        a->dim[i] = vet[i];
    }
    return a;
}
void delete_point(Point* a){
    free(a->name);
    free(a->dim);
    free(a);
}
void print_point(Point* a, int n ){
    printf("%s ", a->name);
    for(int i = 0; i < n; i++){
        printf("%lf ", a->dim[i]);
    }
    printf("\n");
}