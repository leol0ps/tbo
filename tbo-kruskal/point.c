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
double** distance_matrix(Point** a,int size,int dimension){
    double** matrix = malloc(size*sizeof(double*));
    for(int i = 0 ; i < size; i++){
        matrix[i] = malloc((i+1)*sizeof(double));
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < i; j++){
            matrix[i][j] = distance(a[i],a[j],dimension);
        }
    }
    return matrix;
}
void free_matrix(double** matrix,int size){
    for(int i = 0; i < size; i++){
        free(matrix[i]);
    }
    free(matrix);
}
void print_matrix(double** matrix,int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < i; j++){
            printf("matrix[%d][%d] = %lf\n", i,j,matrix[i][j]);
        }
        printf("\n");
    }
}