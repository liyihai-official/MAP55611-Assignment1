/**
 * @file function.c
 * @brief This is the function library of assignment1 a, b, c, d
 * @date 2024-01-09
 * @version 1.2.1
 * @author LI Yihai
*/

#include "function.h"

/**
 * @brief Error message for debug
 * @param[int] Integer, Error tags
 * 
 * @return Return 0 for successful, and 1 for NULL pointer error.
 * 2 for Unknown Datatype.
*/
int return_message(const int err){
    if (err == 1){
        printf("NULL pointer\n");
        return 1;
    } else if (err == 2){
        printf("Unknown Datatype\n");
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
 * @brief Store the members and the length of vector to a given file.
 *  The data type could be double and int
 * 
 * @param file_name The name of file.
 * @param vec The void pointer of vector
 * @param N Length of vector
 * @param type The type of members of elements
 * 
 * @return return 0 for success and 1 or NULL pointer error
 * @see return_message()
*/
int write_vector(char * file_name, void * vec, int N, DataType type){
    
    FILE * fp = fopen(file_name, "w");
    if (fp == NULL) {
        return return_message(1);
    }
    fprintf(fp, "%d\n", N);
    switch (type){
        case TYPE_INT:
            for (int i = 0; i < N; i++){
                fprintf(fp, "%d\n", ((int *)vec)[i]);
            }
            break;

        case TYPE_DOUBLE:
            for (int i = 0; i < N; i++){
                fprintf(fp, "%lf\n", ((double *)vec)[i]);
            }
            break;

        default:
            return return_message(2);
    }

    return 0;

}


/**
 * @brief Determine the quadratic elementary sum of input vector
 * 
 * @param in The pointer of vector
 * @param N The length of vector
 * @param norm The pointer pointed to the result
 * 
 * @return Return 0 for successfully operated, return 1 for NULL pointer 
 * error.
 * 
 * @see return_message()
*/
int l2_norm2(const int * in, const int N, double * norm){
    if (norm == NULL){
        return return_message(1);
    }

    *norm = 0;
    for (int i = 0; i < N; i++){
        *norm += in[i]*in[i];
    }
    return 0;
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
 * @return Return 0 for success, return for NULL pointer error
 * 
 * @see return_message()
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