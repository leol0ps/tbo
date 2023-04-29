#ifndef POINT_H
#define POINT_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct point{
    char* name;
    double* dim;
    int group;
}Point;

void write_group(Point** a,int size,int* groups);
Point* create_point(int dimension,char* name,double* vet);
void delete_point(Point* a);
double distance(Point* a, Point* b, int n );
void print_point(Point* a, int n);
double** distance_matrix(Point** a, int size,int dimension);
void free_matrix(double** matrix,int size);
void print_point_name(Point* a);
void sort_point_by_group(Point** a, int size);
#endif