//
// Created by eka on 04/12/15.
//

#include "main.h"

int main(int argc, char **argv){
    //printf("Hello World\n");
    char *filename="/home/eka/ClionProjects/CodeAC/input.txt";

    //Vector2d *vect2d=readInputAsIntVect2d(filename);
    //Vector *vect = genericOpVec(&maximum_of_array,vect2d);
    //vector_print(vect);
    Vector *vector = readInputAsIntVect(filename);
    int *max;
    int *min;
    //max=malloc(sizeof(int));
    //min=malloc(sizeof(int));
    maxMinOfArray(vector,&max,&min);
    printf("%d %d\n",*max,*min);
    return 0;
}
