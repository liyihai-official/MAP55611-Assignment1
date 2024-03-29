/**
 * @file assignment1d.c
 * @brief This program read a vector from given file, distribute the vector among P 
 * processors. Calculate the Euclidean norm of the vector.
 * @version 1.0.0
 * @date 2024.01.09
*/
#include "function.h"
#include <mpi.h>

/* file path */
char file_name[] = "datafile/q3file_97.txt";


int main(int argc, char * argv[]){
    MPI_Init(&argc, &argv);
    
    int np, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    int N = 0; // 总数组大小
    int *vec = NULL;
    int s, e;

    /* MPI main body */
    if (rank == 0){
        vector_fscanf(file_name, &vec, &N);
        for (int id = 0; id < np; id++){
            decomp1d(N, np, id, &s, &e);
            MPI_Send(vec+s, e-s, MPI_INT, id, 0, MPI_COMM_WORLD);
        }
    } 

    /* Broadcast start and end to all process */
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    decomp1d(N, np, rank, &s, &e);

    /* Receive sub-vector and calculate the sum of elementary squares. */
    double sub_norm;
    int * subvec = malloc((e-s)*sizeof(int));
    MPI_Recv(subvec, e-s, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    
    l2_norm2(subvec, e-s, &sub_norm);
    
    MPI_Send(&sub_norm, 1, MPI_DOUBLE, rank, 1, MPI_COMM_WORLD); 


    /* Allocating memory for store cache values */
    double * cache = NULL;
    if (np > 2){
        if (rank == 2){
            cache = malloc(np*sizeof(double));
        }
    } else {
        if (rank == 0){
            cache = malloc(np*sizeof(double));
        }
    }

    /* Gather values to rank 2 (if has) or rank 0 processor */
    if (np > 2){
        MPI_Gather(&sub_norm, 1, MPI_DOUBLE, cache, 1, MPI_DOUBLE, 2, MPI_COMM_WORLD);
    } else {
        MPI_Gather(&sub_norm, 1, MPI_DOUBLE, cache, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    }


    /* Sumption and determine the Norm */
    if (np > 2){
        if (rank == 2) {
            double sum = 0;
            for (int i = 0; i < np; i++){
                sum += cache[i];
            }
            sum = pow(sum, 0.5);
            printf("Load from: \t%s \t l2 norm = %lf\n", file_name, sum);
        }
    } else {
        if (rank == 0){
            double sum = 0;
            for (int i = 0; i < np; i++){
                sum += cache[i];
            }
            sum = pow(sum, 0.5);
            printf("Load from: \t%s \t l2 norm = %lf\n", file_name, sum);
        }
    }

    free(subvec);
    free(cache);
    

    MPI_Finalize();
    return 0;
}
