//
// Created by eka on 04/12/15.
//

#include "main.h"

int main(int argc, char **argv){
    //printf("Hello World\n");
    char *filename="/home/eka/ClionProjects/CodeAC/input.txt";
    Vector2d *vect2d=readInputAsIntVect2d(filename);
    int r = sumVec(vect2d);
    printf("%d\n",r);
    return 0;
}
