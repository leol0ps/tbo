#include <stdio.h>
#include "point.h"
#include "list.h"
#include "file.h"

int main(int argc, char** argv){
    int dimension;
    List* list = read_file(argv[1],&dimension);
    print_list(list,dimension);
    free_list(list);
    return 0;
}