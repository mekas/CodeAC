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

Vector *sumVec(Vector2d *vector2d){
    int caps=vector2d->size;
    int i;
    int sumv;
    Vector *vector, *result;
    result=malloc(sizeof(Vector));
    vector_init(result);
    for(i=0;i<caps;i++){
        vector=vector2d_get(vector2d,i);
        sumv=suml(vector);
        vector_append(result,sumv);
    }
    return result;
}

int maximumOfArray(Vector *vector){
    int caps=vector->size;
    int i,x;
    //set initial max to most minimum integer
    int max=(1<<31);
    for(i=0;i<caps;i++){
        x=vector_get(vector,i);
        if(x<max)
            max=x;
    }
    return max;
}

int minimumOfArray(Vector *vector){
    int caps=vector->size;
    int i,x;
    //set initial minimum to maximum integer
    int min=((unsigned)1<<31)-1;
    for(i=0;i<caps;i++){
        x=vector_get(vector,i);
        if(x<min)
            min=x;
    }
    return min;
}

//since this function need to return max and min, we return the computation via function argument
void maxMinOfArray(Vector *vector, int **max, int **min){
    int caps=vector->size;
    int i,x;
    *max=malloc(sizeof(int));
    **max=1<<31; //set initial max to most minimum integer
    //printf("%d\n",*max);
    *min=malloc(sizeof(int));
    **min= ((unsigned)1<<31)-1; //set initial minimum to maximum integer
    //printf("%d\n",*min);

    for(i=0;i<caps;i++){
        x=vector_get(vector,i);
        if(x>(**max))
            **max=x;
        if(x<(**min))
            **min=x;
    }
    //printf("%d %d\n",*max,*min);
}

Vector *minimumOfVec(Vector2d *vector2d){
    int caps=vector2d->size;
    Vector *vector, *result;
    int i,y;
    result=malloc(sizeof(Vector));
    vector_init(result);
    for(i=0;i<caps;i++){
        vector=vector2d_get(vector2d,i);
        y=minimumOfArray(vector);
        vector_append(result,y);
    }
    return result;
}

//try implementing function pointer
Vector *genericOpVec(int (*func)(Vector *), Vector2d *vector2d){
    int caps=vector2d->size;
    Vector *vector, *result;
    int i,y;
    result=malloc(sizeof(Vector));
    vector_init(result);
    for(i=0;i<caps;i++){
        vector=vector2d_get(vector2d,i);
        y=(*func)(vector);
        vector_append(result,y);
    }
    return result;
}