//
// Created by eka on 04/12/15.
//

#include "main.h"

int main(int argc, char **argv){
    //printf("Hello World\n");
    char *filename="/home/eka/ClionProjects/CodeAC/input.txt";

    /* First mode, read input as vector2d*/
    //Vector2d *vect2d=readInputAsIntVect2d(filename);
    //Vector *vect = genericOpVec(&divide,vect2d);
    //vector_print(vect);

    /* second mode, read input as vector*/
    //Vector *vector = readInputAsIntVect(filename);
    //int *max;
    //int *min;
    //max=malloc(sizeof(int));
    //min=malloc(sizeof(int));
    //maxMinOfArray(vector,&max,&min);
    //printf("%d %d\n",*max,*min);

    /* third mode, read input as vector but skip first element*/
    //Vector *vector = readInputAsIntVectSkipFirstValue(filename);
    //Vector *result = fahrenheitToCelciusVect(vector);
    //vector_print(result);

    /* forth mode, read input as stringbuffer*/
    StringBuffer *sb=readInputAsStringBuffer(filename);
    Vector *countV = countAllVowels(sb);
    vector_print(countV);
    //stringbuffer_print(sb);
    return 0;
}
