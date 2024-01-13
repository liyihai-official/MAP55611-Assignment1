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

## Compile

### Manually
Compile files manually, should use compilers <code>GCC</code> and <code>MPICC</code> and link to library
<code>math.h</code>.
The debug flags are <code>-Wall -Wextra</code>.
<pre>
gcc -Wall -Wextra -c function.c -o function.o
mpicc -Wall -Wextra assignment1a.c function.o -o assignment1a -lm
mpicc -Wall -Wextra assignment1b.c function.o -o assignment1b -lm
mpicc -Wall -Wextra assignment1c.c function.o -o assignment1c -lm
mpicc -Wall -Wextra assignment1d.c function.o -o assignment1d -lm
</pre>

### Makefile 
Type <code>make</code> should compile all files, and <code>make clean</code> deletes the executables.

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