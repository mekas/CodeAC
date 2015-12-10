//
// Created by eka on 09/12/15.
//

#ifndef CODEAC_LIBSTRING_H
#define CODEAC_LIBSTRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STRING_INITIAL_CAPACITY 100

typedef struct{
    int size;
    int capacity;
    char *string;
} String;

typedef struct{
    int size;
    int capacity;
    char **string;
} StringBuffer;


/* StringBuffer API*/
void stringbuffer_init(StringBuffer *);
void stringbuffer_double_capacity_if_full(StringBuffer *);
void stringbuffer_free(StringBuffer *);
char *string_get(StringBuffer *, int index);
void stringbuffer_append(StringBuffer *, char *);
void stringbuffer_set(StringBuffer *, int index, char *value);
void stringbuffer_print(StringBuffer *);

/* String API*/
void string_init(String *string);
void string_double_capacity_if_full(String *string);
void string_free(String *string);
char string_getchar(String *string, int index);
void string_append(String *string, char c);

#endif //CODEAC_LIBSTRING_H
