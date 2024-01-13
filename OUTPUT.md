# Problem 1
<ul>
    <li><code>assignment1a.c/assignment1b.c -> q3file_16.txt</code></li>
<pre>    
    16
    2
    3
    4
    5
    6
    7
    8
    9
    10
    11
    12
    13
    14
    15
    16
    17
</pre>
    <li><code>assignment1a.c/assignment1b ->  q3file_10000.txt</code></li>
    Too long for view, below is a demo
<pre>
10000
2
3
4
5
6
7
8
...
...
9997
9998
9999
10000
10001
</pre>
    
<li><code>assignment1c.c</code></li>
Do 10 processors for $n = 10000$
<pre>
$ mpiexec -np 10 assi
gnment1c
Rank 0: [0, 1000]
Rank 1: [1000, 2000]
Rank 2: [2000, 3000]
Rank 3: [3000, 4000]
Rank 4: [4000, 5000]
Rank 5: [5000, 6000]
Rank 6: [6000, 7000]
Rank 7: [7000, 8000]
Rank 8: [8000, 9000]
Rank 9: [9000, 10000]
</pre>

Do 9 processors for $n = 25$
<pre>
$ mpiexec -np 9 assignment1c
Rank 6 got 3 members with index: [18, 21]
Rank 8 got 2 members with index: [23, 25]
Rank 0 got 3 members with index: [0, 3]
Rank 1 got 3 members with index: [3, 6]
Rank 4 got 3 members with index: [12, 15]
Rank 5 got 3 members with index: [15, 18]
Rank 3 got 3 members with index: [9, 12]
Rank 2 got 3 members with index: [6, 9]
Rank 7 got 2 members with index: [21, 23]
</pre>

Do 1 processor for $n=25$ and $n=10000$, gives the same result as multi-processors version.

<pre>
$ mpiexec -np 1 assignment1c
Rank 0 got 25 members with index: [0, 25]
</pre>

<pre>
$ mpiexec -np 1 assignment1c
Rank 0 got 10000 members with index: [0, 10000]
</pre>

<li><code>assignment1d.c</code></li>
<ol>
    <li><code>q3file_16.txt</code> for 4 processors</li>
<pre>
$ mpiexec -np 4 assignment1d
Load from:      datafile/q3file_16.txt   l2 norm = 38.678159
</pre>
    <li><code>q3file_16.txt</code> for 9 processors</li>
<pre>
$ mpiexec -np 9 assignment1d
Load from:      datafile/q3file_16.txt   l2 norm = 38.678159
</pre>
    <li><code>q3file_16.txt</code> for 1 processors</li>
<pre>
$ mpiexec -np 1 assignment1d
Load from:      datafile/q3file_16.txt   l2 norm = 38.678159
</pre>
    <li><code>q3file_97.txt</code> for 11 processors</li>
<pre>
$ mpiexec -np 11 assignment1d
Load from:      datafile/q3file_97.txt   l2 norm = 555.828211
</pre>
    <li><code>q3file_97.txt</code> for 6 processors</li>
</ol>
<pre>
$ mpiexec -np 6 assignment1d
Load from:      datafile/q3file_97.txt   l2 norm = 555.828211
</pre>
</ul>