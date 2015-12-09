//
// Created by eka on 04/12/15.
//

#include "io.h"

/*
 * At the moment only capable to read 1 line from file
 * */
Vector *readInputAsIntVect(const char *filepath){
    FILE *fp;
    fp=fopen(filepath,"r");
    Vector *vect;
    //read until not EOF
    //inspiration from http://stackoverflow.com/questions/2372813/reading-one-line-at-a-time-in-c
    if(fp !=NULL){
        char line[1000]; //assuming 1 line not exceeding 1000 characters
        while(fgets(line,sizeof(line),fp)!=NULL){
            //printf("%s\n",line);
            vect = parseStringAsIntArr(line);
            //vector_print(vect);
        }
        fclose(fp);
    } else {
        perror(filepath);
    }
    return vect;
}

Vector2d *readInputAsIntVect2d(const char *filepath){
    FILE *fp;
    fp=fopen(filepath,"r");
    Vector2d *vector2d;
    Vector *vect;
    //read until not EOF
    //inspiration from http://stackoverflow.com/questions/2372813/reading-one-line-at-a-time-in-c
    if(fp !=NULL){
        char line[1000]; //assuming 1 line not exceeding 1000 characters
        vector2d = malloc(sizeof(Vector2d));
        vector2d_init(vector2d);
        //skip read header
        fgets(line,sizeof(line),fp);
        while(fgets(line,sizeof(line),fp)!=NULL){
            //printf("%s\n",line);
            vect = parseStringAsIntArr(line);
            vector2d_append(vector2d,vect);
            //vector_print(vect);
        }
        fclose(fp);
    } else {
        perror(filepath);
    }
    return vector2d;
}

/**
 * Input parameter: a string from read one line per file
 * return vector by splitting per whitespace
 */
Vector *parseStringAsIntArr(char *line){
    //initialize int array of 1000 buffers
    Vector *vect=malloc(sizeof(Vector));
    vector_init(vect);
    char *token; //use to store each splitting word
    const char *delimit=" ";
    token = strtok(line, delimit); //split by whitespace
    int x;
    while (token!=NULL){
        x=atoi(token);
        vector_append(vect,x);
        token = strtok(NULL,delimit);
    }
    return vect;
}