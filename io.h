//
// Created by eka on 04/12/15.
//

#ifndef CODEAC_IO_H
#define CODEAC_IO_H
#include <stdio.h>
#include <string.h>
#include "structure.h"

Vector *readInputAsIntVect(const char *);
Vector2d *readInputAsIntVect2d(const char *);
Vector *readInputAsIntVectSkipFirstValue(const char *);
Vector *parseStringAsIntArr(char *);
#endif //CODEAC_IO_H
