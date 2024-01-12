/**
 * @file assignment1a.c
 * @brief This program is using MPI_Send and MPI_Recv to 
 * do broadcast the message and gather from other processes.
 * @date 2024-01-09
 * @author LIYIHAI
 * @version 1.0.0
*/
#include "function.h"
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

/* file path */
char file_name[] = "datafile/q3file_10000.txt";

int main(int argc, char * argv[]){

    /* MPI initialization */
    int np, rk;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &rk);

    /* MPI main body */
    if (rk == 0){        
        /* Local operations on Rank 0 process */
        int * vec; 
        int N;
        vector_fscanf(file_name, &vec, &N); /* Loading vector from file */
        int count = N / np;

        /* Send the evenly divided vec to other processes */
        for (int p_id = 1; p_id < np; p_id++){
            MPI_Send(&count, 1, MPI_INT, p_id, 0, MPI_COMM_WORLD);
            MPI_Send(vec+count*p_id, count, MPI_INT, p_id, 0, MPI_COMM_WORLD);
        }

        /* Gather vectors from other processes */
        for (int p_id=1; p_id<np; p_id++){
            MPI_Recv(vec+count*p_id, count, MPI_INT, p_id, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        /* Do local operation and print vector */
        for (int i=0; i<N; i++){
            if (i < count){
                vec[i]++;
            }
            printf("%d ", vec[i]);
            if (i>=20 && i%20 == 0){
                printf("\n");
            }
        }
        printf("\n");

        free(vec);
    
    } else {
        /* Local operations in other process */
        int count;
        MPI_Recv(&count, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        /* Receive the divided vector from Rank 0. */
        int * vec = malloc(count * sizeof(int));
        MPI_Recv(vec, count, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        
        /* Do some operations */
        for (int i =0; i<count; i++){
            vec[i]++;
            // printf("%d ", vec[i]);
        }

        /* Send results to Rank 0 */
        MPI_Send(vec, count, MPI_INT, 0, 1, MPI_COMM_WORLD);

        free(vec);

    }
    /* MPI close */
    MPI_Finalize();

    return 0;
}
