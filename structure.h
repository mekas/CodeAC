//
// Created by eka on 04/12/15.
// Taken from https://www.happybearsoftware.com/implementing-a-dynamic-array
//

#ifndef CODEAC_STRUCTURE_H
#define CODEAC_STRUCTURE_H

#include <stdlib.h>
#include <stdio.h>

#define VECTOR_INITIAL_CAPACITY 100

// Define a vector type
typedef struct {
    int size;      // slots used so far
    int capacity;  // total available slots
    int *data;     // array of integers we're storing
} Vector;

typedef  struct {
    int size; //slots used so far
    int capacity; //total available slots
    Vector *vector; //
} Vector2d;

void vector_init(Vector *vector);
void vector2d_init(Vector2d *vector2d);
void vector_append(Vector *vector, int value);
void vector2d_append(Vector2d *vector2d, Vector *vect);
int vector_get(Vector *vector, int index);
Vector *vector2d_get(Vector2d *vector2d, int index);
void vector_set(Vector *vector, int index, int value);
void vector2d_set(Vector2d *vector2d, int index, Vector *vector);
void vector_double_capacity_if_full(Vector *vector);
void vector2d_double_capacity_if_full(Vector2d *vector2d);
void vector_free(Vector *vector);
void vector2d_free(Vector2d *vector2d);
void vector_print(Vector *vector);

#endif //CODEAC_STRUCTURE_H
