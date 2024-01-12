/**
 * @file assignment1c.c
 * @brief This is a short MPI program to testify 
 * the function decomp1d 
 * @see decomp1d
 * @date 2024.01.09
 * @version 1.0.0
)*/
#include "function.h"
#include <mpi.h>


int main(int argc, char * argv[]){

    MPI_Init(&argc, &argv);

    int np, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    /* Suppose we have vector with N elements */
    int N = 1000;

    /* Determine the decomposition of vector */
    int s, e;
    decomp1d(N, np, rank, &s, &e);
    printf("Rank %d got %d members with index: [%d, %d]\n", rank, e-s, s, e);


    MPI_Finalize();
    return 0;
}