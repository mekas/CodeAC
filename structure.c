//
// Created by eka on 04/12/15.
//

#include "structure.h"

void vector_init(Vector *vector) {
    // initialize size and capacity
    vector->size = 0;
    vector->capacity = VECTOR_INITIAL_CAPACITY;

    // allocate memory for vector->data
    vector->data = malloc(sizeof(int) * vector->capacity);
}

void vector2d_init(Vector2d *vector2d){
    vector2d->size=0;
    vector2d->capacity=VECTOR_INITIAL_CAPACITY;
    vector2d->vector=malloc(sizeof(Vector) * vector2d->capacity);
}

void vector_append(Vector *vector, int value) {
    // make sure there's room to expand into
    vector_double_capacity_if_full(vector);

    // append the value and increment vector->size
    vector->data[vector->size++] = value;
}

void vector2d_append(Vector2d *vector2d, Vector *vector) {
    // make sure there's room to expand into
    vector2d_double_capacity_if_full(vector2d);

    //(*vector2d)->vector[(*vector2d)->size++];

    // append the value and increment vector->size
    vector2d->vector[vector2d->size++]=*vector;
}

int vector_get(Vector *vector, int index) {
    if (index >= vector->size || index < 0) {
        printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
        exit(1);
    }
    return vector->data[index];
}

Vector *vector2d_get(Vector2d *vector2d, int index) {
    if (index >= vector2d->size || index < 0) {
        printf("Index %d out of bounds for vector2d of size %d\n", index, vector2d->size);
        exit(1);
    }
    return &vector2d->vector[index];
}

void vector_set(Vector *vector, int index, int value) {
    // zero fill the vector up to the desired index
    while (index >= vector->size) {
        vector_append(vector, 0);
    }

    // set the value at the desired index
    vector->data[index] = value;
}

void vector2d_set(Vector2d *vector2d, int index, Vector *vector) {
    // zero fill the vector up to the desired index
    Vector *vect;
    while (index >= vector2d->size) {
        vect=malloc(sizeof(Vector));
        vector_init(vect);
        vector2d_append(vector2d, vect);
    }

    // set the value at the desired index
    vector2d->vector[index] = *vector;
}

void vector_double_capacity_if_full(Vector *vector) {
    if (vector->size >= vector->capacity) {
        // double vector->capacity and resize the allocated memory accordingly
        vector->capacity *= 2;
        vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
    }
}

void vector2d_double_capacity_if_full(Vector2d *vector2d) {
    if (vector2d->size >= vector2d->capacity) {
        // double vector->capacity and resize the allocated memory accordingly
        vector2d->capacity *= 2;
        vector2d->vector = realloc(vector2d->vector, sizeof(Vector) * vector2d->capacity);
    }
}

void vector_free(Vector *vector) {
    free(vector->data);
}

void vector2d_free(Vector2d *vector2d){
    int caps=vector2d->capacity;
    int i;
    for(i=0;i<caps;i++){
        free(&vector2d->vector[i]);
    }
    free(vector2d->vector);
}

void vector_print(Vector *vector){
    int caps = vector->size;
    int i,x;
    for(i=0;i<caps;i++){
        x=vector_get(vector, i);
        printf("%d ",x);
    }
    printf("\n");
}

/**
 * Return subvectir in range [start,end)
 * Start starting index from 0
 */
Vector *vector_subvector(Vector *vector, int start, int end){
    Vector *subvect = malloc(sizeof(Vector));
    vector_init(subvect);
    int i;
    int caps=vector->size;
    subvect->size == end - start;
    vector_double_capacity_if_full(subvect);
    for(i=start;i<end;i++){
        vector_append(subvect,vector_get(vector,i));
    }
    return subvect;
}