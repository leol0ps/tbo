#include "file.h"


List* read_file(char* path, int* dimension){
    List* a = NULL;
    FILE * fp;
    char * line = NULL;
    int len = 0;
    int read;
    char* aux;
    int number_of_arguments = 0;
    char* name;
    fp = fopen(path, "r");
    if (fp == NULL){
        printf("sem arquivo\n");
        return NULL;
    }
    read = (getline(&line, &len, fp) != -1);
    for(int i = 0; i < len; i++){
            if(line[i]==',')
                number_of_arguments++;
    }
    int i = 0;
    double* posit = malloc(number_of_arguments*sizeof(double));
    name = strtok(line,",");
    aux = name;
    while (aux != NULL && i < number_of_arguments){
        printf ("%s\n",aux);
        aux = strtok (NULL, ",");
        posit[i] = atof(aux);
        i++;
    }
    free(line); // getline aloca memoria 

    Point* ponto = create_point(number_of_arguments,name,posit);
    a = create_list(ponto);
    while ((read = getline(&line, &len, fp)) != -1) {
        i = 0;
        name = strtok(line,",");
        aux = name;
        while (aux != NULL && i < number_of_arguments){
            aux = strtok (NULL, ",");
            posit[i] = atof(aux);
            i++;
        }
        Point* ponto = create_point(number_of_arguments,name,posit);
        insert(a,ponto);
        free(line); 
        
    }
    *dimension = number_of_arguments;
    free(posit);
    fclose(fp);
    return a;
}