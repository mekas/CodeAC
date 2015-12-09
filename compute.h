//
// Created by eka on 04/12/15.
//

#ifndef CODEAC_COMPUTE_H
#define CODEAC_COMPUTE_H
#include "structure.h"
#include <math.h>
#define round(x) ((x)>=0?(long)((x)+0.5):(long)((x)-0.5)) //taken from https://www.cs.tut.fi/~jkorpela/round.html

int sum(int , int );
int fahrenheitToCelcius(int);
int divide(Vector *);
int suml(Vector *);
Vector *sumVec(Vector2d *);
int minimumOfArray(Vector *);
int maximumOfArray(Vector *);
void maxMinOfArray(Vector *, int **, int **);
Vector *fahrenheitToCelciusVect(Vector *vect);
Vector *minimumOfVec(Vector2d *);
Vector *genericOpVec(int (*func)(Vector *), Vector2d *);
#endif //CODEAC_COMPUTE_H
