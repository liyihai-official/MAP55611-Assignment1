

#ifndef function_h
#define function_h
#endif /* structure_h */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


/* Function prototypes */
int return_message(const int err);


int write_vector(void * vec, int N);
int vector_fscanf(char * file_name, int ** vec, int * N);
int decomp1d(int n, int p, int myid, int *s, int *e);
