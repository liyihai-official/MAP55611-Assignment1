/**
 * @file assignment1a.c
 * @brief This program is using MPI_Send and MPI_Recv to 
 * do broadcast the message and gather from other processes.
*/
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>


/* file path */
char file_name[] = "datafile/q3file_16.txt";

/* Function prototypes */
int return_message(const int err);
int vector_fscanf(char * file_name, int ** vec, int * N);


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
        }
        printf("\n");
    
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
        }
        /* Send results to Rank 0 */
        MPI_Send(vec, count, MPI_INT, 0, 1, MPI_COMM_WORLD);

    }
    /* MPI close */
    MPI_Finalize();

    return 0;
}




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