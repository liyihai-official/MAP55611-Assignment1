/**
 * @file function.h
 * @brief This is the header file of function.c 
 * @author LI Yihai
 * @date 2024-01-06
*/

#ifndef function_h
#define function_h
#endif /* structure_h */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Structure for datatype identification */
typedef enum {
    TYPE_INT,
    TYPE_DOUBLE,
    TYPE_FLOAT
} DataType;

/* Function prototypes */
int return_message(const int err);

int write_vector(char * file_name, void * vec, int N, DataType type);
int vector_fscanf(char * file_name, int ** vec, int * N);

int decomp1d(int n, int p, int myid, int *s, int *e);
int l2_norm2(const int * in, const int N, double * norm);

