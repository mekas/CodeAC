//
// Created by eka on 09/12/15.
//

#include "libstring.h"

void string_init(String *string){
    string->size=0;
    string->capacity=STRING_INITIAL_CAPACITY;

    //initialize the pointer
    string->string = malloc(sizeof(char)*STRING_INITIAL_CAPACITY);
    //preinitialize the string with empty string: first character is 0
    string->string[0]='\0';
}

void stringbuffer_init(StringBuffer *sb){
    sb->size=0;
    sb->capacity=STRING_INITIAL_CAPACITY;
    //initialize the pointer
    sb->string = malloc(sizeof(String)*STRING_INITIAL_CAPACITY);
}

void string_double_capacity_if_full(String *string){
    if(string->size>=string->capacity){
        string->capacity*=2;
        string->string=realloc(string, sizeof(char)*string->capacity);
    }
}

void stringbuffer_double_capacity_if_full(StringBuffer *sb){
    if(sb->size >= sb->capacity){
        sb->capacity*=2;
        sb->string=realloc(sb, sizeof(String) * sb->capacity);
    }
}

char string_getchar(String *string, int index) {
    if (index >= string->size || index < 0) {
        printf("Index %d out of bounds for vector of size %d\n", index, string->size);
        exit(1);
    }
    return string->string[index];
}

char *stringbuffer_get(StringBuffer *sb, int index){
    if (index >= sb->size || index < 0) {
        printf("Index %d out of bounds for vector of size %d\n", index, sb->size);
        exit(1);
    }
    return sb->string[index];
}

void string_append(String *string, char value) {
    // make sure there's room to expand into
    string_double_capacity_if_full(string);

    // append the value and increment vector->size
    string->string[string->size++] = value;
}

void stringbuffer_append(StringBuffer *sb, char *value){
    stringbuffer_double_capacity_if_full(sb);
    sb->string[sb->size++]=value;
}

void string_free(String *string) {
    free(string->string);
}

void stringbuffer_free(StringBuffer *sb){
    int i;
    for(i=0;i<sb->capacity;i++){
        free(&sb->string[i]);
    }
    free(sb);
}

void stringbuffer_set(StringBuffer *sb, int index, char *value){
    char *string;
    while (index >= sb->size) {
        string =malloc(sizeof(String)*100);
        stringbuffer_append(sb, string);
    }

    // set the value at the desired index
    sb->string[index] = value;
}

void stringbuffer_print(StringBuffer *sb){
    int j;
    for (j = 0; j < sb->size; ++j) {
        printf("%s\n",sb->string[j]);
    }
}