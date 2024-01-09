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

    int N = 100;
    int s, e;


    decomp1d(N, np, rank, &s, &e);
    printf("Rank %d: [%d, %d]\n", rank, s, e);


    MPI_Finalize();
    return 0;
}