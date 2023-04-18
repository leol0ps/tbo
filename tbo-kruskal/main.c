#include <stdio.h>
#include "point.h"


int main(){
    double vet[] = {1.2, 1.3, 1.4};
    Point* a = create_point(3,"abc",vet);
    print_point(a,3);
    delete_point(a);
    return 0;
}