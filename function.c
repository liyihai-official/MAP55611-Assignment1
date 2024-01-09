#include "function.h"

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



/**
 * @brief One dimensional decomposition of a list of items of length n over p processors.
 * This is the function for question 2.
 * 
 * @param myid, is the rank of the processor; 
 * @param n, The number of vector
 * @param p, The number of processors
 * @param myid, id of process 
 * @param s, start of chuck vector
 * @param e, end of chuck vector
 * 
 * @return Return 0 for success
*/
int decomp1d(int n, int p, int myid, int *s, int *e){
    int size = n/p;
    int remainder = n % p;

    /* Error checking */
    if (s == NULL || e == NULL){
        return return_message(1);
    }

    /* Dividing */
    *s = 0;
    *e = 0;
    for (int i = 0; i <= myid; i++){
        *e += size + (i < remainder ? 1:0);
        if (i < myid){
            *s += size + (i < remainder ? 1:0);
        }
    }

    return 0;
}