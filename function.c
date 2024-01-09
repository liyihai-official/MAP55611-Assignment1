#include "function.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * @brief Error message for debug
 * @param[int] Integer, Error tags
 * 
 * @return Return 0 for successful, and 1 for NULL pointer error.
*/
int return_message(const int err){
    if (err == 1){
        printf("NULL pointer\n");
        return 1;
    }
    return 0;
}

/**
 * @brief Load vector and its length from given path
 * @param[file_name] A pointer of file name
 * @param[vec] A pointer pointed to the vector
 * @param[N] A pointer pointed to the integer for length
 * 
 * @return Return 0 if it's successfully finished.
*/
int vector_fscanf(char * file_name, int ** vec, int * N){
    FILE * fp = fopen(file_name, "r");
    if (fp == NULL){
        return return_message(1);
    }

    int index = 0;
    int i;
    while (fscanf(fp, "%d\n", &i) == 1){
        if (index == 0) {
            *vec = malloc(i*sizeof(int));
        } else {
            (*vec)[index-1] = i;
        }
        index ++;
    };

    fclose(fp);
    * N = index - 1;

    return return_message(0);
}