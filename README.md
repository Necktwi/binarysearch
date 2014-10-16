binarysearch
============

Assignment 1 Write your own implementation of linked lists and one of binary search trees that contain integers. For the purpose of this assignment, you only need to implement "insert" and "find" as follows:
If you are writing your code in Java: 
 list.insert(x)
 list.find(x)


tree.insert(x) 
tree.find(y)
 where "x" and "y" are two integers, and "list"/"tree" is an instance of a linked list/binary search tree. Insert does not return any value, and find returns true or false depending on whether y is in the tree.

If x is already in the data structure, insert(x) does nothing.

Insert n random integers between 0 and 100,000,000, for n = 50, n = 10,000 and n = 10,000,000. For each n, calculate the total time required to insert all elements. Then, calculate how long it takes to find 10,000 random elements for each n.


You can use any random number generator of your choice. 
Do not use a stopwatch to calculate the time. Rather, use time functions integrated in the runtime.
Run each experiments 100 times and report the average.


The expected output of your program is:


Binary search tree:
n=50 insert: xxx.xxx ms; find: xxx.xxx ms
n=10000 insert: xxx.xxx ms; find: xxx.xxx ms
n=10000000 insert: xxx.xxx ms; find: xxx.xxx ms


List:
n=50 insert: xxx.xxx ms; find: xxx.xxx ms
n=10000 insert: xxx.xxx ms; find: xxx.xxx ms
n=10000000 insert: xxx.xxx ms; find: xxx.xxx ms
