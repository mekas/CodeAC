//
// Created by eka on 04/12/15.
//

#ifndef CODEAC_COMPUTE_H
#define CODEAC_COMPUTE_H
#include "structure.h"

int sum(int , int );
int suml(Vector *);
Vector *sumVec(Vector2d *);
int minimumOfArray(Vector *vector);
int maximumOfArray(Vector *vector);
void maxMinOfArray(Vector *vector, int **, int **);
Vector *minimumOfVec(Vector2d *vector2d);
Vector *genericOpVec(int (*func)(Vector *), Vector2d *vector2d);
#endif //CODEAC_COMPUTE_H
