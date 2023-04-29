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
    printf("name:%s, group:%d ", a->name,a->group);
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
void write_group(Point** a,int size,int* groups){
    for(int i = 0; i < size; i++){
        a[i]->group = groups[i];
    }
}
void print_point_name(Point* a){
    printf("%s",a->name);
}
int compare_str(const void * a, const void * b) {
    Point* x = *(Point**)a;
    Point* y = *(Point**)b;
   return strcmp(x->name,y->name);
}
void sort_point_by_name(Point** a, int size){
    qsort(a,size,sizeof(Point*),compare_str);
}
int compare_group(const void* a, const void * b){
    Point* x = *(Point**)a;
    Point* y = *(Point**)b;
    return x->group-y->group;
}
void sort_point_by_group(Point** a, int size){
    qsort(a,size,sizeof(Point*),compare_group);
}
typedef struct group{
    int begin;
    int end;
    int name;
    char** first;
}Group;
Group* create_group(int start,int end,int name,char** first){
    Group* new_group = malloc(sizeof(Group));
    new_group->begin = start;
    new_group->end = end;
    new_group->name = name;
    new_group->first = first;
    return new_group;
}
void free_group(Group* a){
    free(a);
}
int order_groups(const void* a, const void * b){
    Group* x = *(Group**)a;
    Group* y = *(Group**)b;
    //return x->name-y->name;
    return strcmp(*(x->first),(*y->first));
}
void print_group_points(Group* a, Point** vetor){
    for(int i = a->begin; i < a->end;i++){
        print_point_name(vetor[i]);
        printf(",");
    }
    print_point_name(vetor[a->end]);
    printf("\n");
}
void print_to_file(Point** vetor,int size,int k){
    Group** grupos = malloc(k*sizeof(Group*));
    sort_point_by_group(vetor,size);
    int i = 0;
    int last = 0;
    Point** ponteiro;
    int aux = vetor[0]->group;
    for(int j = 0; j < size;j++){
        if(vetor[j]->group!=aux){
            ponteiro = &vetor[last];
            sort_point_by_name(ponteiro,(j-last));
            grupos[i++] = create_group(last,(j-1),aux,&vetor[last]->name);
            aux = vetor[j]->group;
            last = j;
        }
    }
    ponteiro = &vetor[last]; 
    sort_point_by_name(ponteiro,size-last-1);
    //qsort(grupos,sizeof(Group*),k,order_groups);
    grupos[i]= create_group(last,(size-1),vetor[last]->group,&vetor[last]->name);
        for(int j = 0; j < k; j++){
        print_group_points(grupos[j],vetor);
    }
    for(int j = 0; j < k ; j++){
        free_group(grupos[j]);
    }
    free(grupos);
}