#ifndef POINT_H
#define POINT_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct point{
    char* name;
    double* dim;
}Point;


Point* create_point(int dimension,char* name,double* vet);
void delete_point(Point* a);
double distance(Point* a, Point* b, int n );
void print_point(Point* a, int n);
double** distance_matrix(Point** a, int size,int dimension);
void free_matrix(double** matrix,int size);
#endif