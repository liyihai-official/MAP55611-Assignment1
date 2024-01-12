# MAP55611-Assignment1
MAP55611 HPC Software Computing Assignment1

## Installation
The Open-MPI module and GCC is required.
In order to install this, you can execute the command lines 
### On MacOS
<pre>
brew install open-mpi
</pre>
### On chuck
<pre>
module load openmpi
module load cports
</pre>

### On Seagull
<pre>
module load openmpi-3.1.6-gcc-9.3.0 
module load gcc-9.3.0-gcc-4.8.5-wkarmeh
</pre>

<!-- ## Problem 1
Read vector from file. Write code to:
<ul>
    <li>read a vector from file on rank 0. The file format should be:</li>
    <ul>
        <li>length of the vector on the first line</li>
        <li>entries of the vector, separated by spaces or carriage returns, on the remaining line or lines</li>
    </ul>
    <li>Evenly divide the vector among the processes (you can assume that the number of processors divides the length of the vector). On each processor, you should only allocate enough memory for the local subset of the vector assigned to that processor</li>
    <li>Add 1.0 to each element of the local vector on each processor</li>
    <li>gather the local vectors back into a vector on rank 0 and write this vector to a file of the same format as the input file</li>
    <li>Run this code on 4 processors and for a vector of length $n=16$. Run the code on at least 10 processors for a vector length at $n = 10000$</li>
    <li>Provide two implementations of this code: one which uses <code>MPI_Send / MPI_Recv</code> and a second which uses <code>MPI</code> collective calls</li>
</ul> -->

## Details
<ol>
 <li>Files</li>
 Assignment1a.c is the <code>MPI_Send / MPI_Recv</code> version of question 1, and the assignment1b.c is the one uses other MPI collective 
 calls. The file assignment1c.c is the program of question 2, and the last one 
 assignment1d.c is for question 3.

 <li>Compile</li>
 Load modules first, then compile using gcc for library function file and mpicc for 
 executable files.<pre>
gcc -Wall -Wextra -c function.c -o function.o
mpicc -Wall -Wextra assignment1a.c function.o -o assignment1a -lm
mpicc -Wall -Wextra assignment1b.c function.o -o assignment1b -lm
mpicc -Wall -Wextra assignment1c.c function.o -o assignment1c -lm
mpicc -Wall -Wextra assignment1d.c function.o -o assignment1d -lm
</pre>

<li>Running</li>
Suppose the number of processors is $N$ and the executable file names are 
<code>file_name</code>. Below is the command line to run the program.
<pre>
mpiexec -np N ./"file_name"
</pre>
For question 1, the command lines would be 
<pre>
mpiexec -np 4 ./assignment1a
mpiexec -np 10 ./assignment1a
mpiexec -np 4 ./assignment1b
mpiexec -np 10 ./assignment1b
</pre>

In order to load and store the results with various files, 
the user could 
modify the global variables 
<pre>
char file_name[] = "datafile/q3file_10000.txt";
char _file_name[] = "resultfile/q3file_10000.txt";
</pre> 
in each assignment <code>.c</code> files.
</ol>


<!-- ## Problem 2 -->