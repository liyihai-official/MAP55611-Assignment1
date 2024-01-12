/**
 * @file assignment1b.c
 * @brief This is the program doing same by various functions 
 * @date 2024-01-09
 * @author LIYIHAI
 * @version 1.0.0
*/
#include "function.h"
#include <mpi.h>


/* file path */
char file_name[] = "datafile/q3file_10000.txt";
char _file_name[] = "resultfile/q3file_10000.txt";

int main(int argc, char * argv[]){

    /* MPI initialization */
    MPI_Init(&argc, &argv);
    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int N; // 总数组大小
    int *vec = NULL;
    int chunkSize;

    /* Loading vector from file */
    if (rank == 0) {
        vector_fscanf(file_name, &vec, &N);
        chunkSize = N / size;
    }

    /* Broadcast size N to all process */
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank != 0) {
        chunkSize = N / size;
    }


    /* Allocated memories for all processes */
    int *subArray = (int *)malloc(chunkSize * sizeof(int));

    /* Scatter vector to processes */
    MPI_Scatter(vec, chunkSize, MPI_INT, subArray, chunkSize, MPI_INT, 0, MPI_COMM_WORLD);

    /* Do operations on all processes */
    for (int i=0; i<chunkSize; i++){
        subArray[i]++;
    }

    /* Gather vector to rank 0 */
    MPI_Gather(subArray, chunkSize, MPI_INT, vec, chunkSize, MPI_INT, 0, MPI_COMM_WORLD);

    /* Print vector on rank 0*/
    if (rank == 0){
        /* Store the vector in result folder */
        write_vector(_file_name, vec, N, TYPE_INT); 
    }

    MPI_Finalize();
    free(subArray);
    free(vec);
    
    return 0;
}