//
// Created by eka on 04/12/15.
//

#include "compute.h"
#include "structure.h"

int sum(int a, int b){
    return a+b;
}

int suml(Vector *vect){
    int caps=vect->size;
    int i,sum=0;
    for(i=0;i<caps;i++){
        sum+=vector_get(vect,i);
    }
    return sum;
}

int sumVec(Vector2d *vector2d){
    int caps=vector2d->size;
    int i;
    int sumv;
    Vector *vector,*result;
    result=malloc(sizeof(Vector));
    vector_init(result);
    for(i=0;i<caps;i++){
        vector=vector2d_get(vector2d,i);
        sumv=suml(vector);
        vector_append(vector,sumv);
    }
    return sumv;
}