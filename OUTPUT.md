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
[liy35@chuck MAP55611-Assignment1]$ mpiexec -np 10 assi
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
</ul>