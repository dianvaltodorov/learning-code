Tiered vector
===
* bucketing - group elements in order to cope with them.
* example for bucketing - nearest neighbour.
* we divide everything into buckets, small squares.
* if we have too many buckets imperfection of the buckets- often the nearst
  neighbour won't be inside the current bucket
* manhanhan distance - sum of the difference on xs and on ys
* we divide out points into spaces
* we make the assumption that tha points are equally distributed.

Tree
====
* balanced tree
* binary search tree
* binary ordered tree


Finding the k-th number:
====
* binary search tree, insertion
  - insert O(logN)
  - delete O(logN)
  - search O(logN)
* array
  - search O(1)
  - insert O(N)
  - delete O(N)
* tiered vector
  - insert o(sqrt(N))
  - delete o(sqrt(N))
  - retrieve o(1)
  - http://judge.openfmi.net:9080/mediawiki/index.php/Tiered_Vector

Tiered Vector
===
  - we divide into groups of B elements(B - bucket size). We search for the k-th
    element
  - bucket = k / B
  - index = k % B
  - like an array but in a cycle.
  - 5, 7, 11, 13, 19, 23, 2 ,3
  - we store the beginning of the array. Just an array with an extra index.
  - we end up with an array of array which are sorted.
  - Example:
      |13, 15, 17| , |19, 20, 22|,  |42, 111, 666|, |1001, 1337|
      |15, 17, 13| , |19, 20, 22|,  |111, 42, 666|, |1001, 1337|
                x      x                   x                  x
  - count buckets N/B - size of the bucket
  - binary tree with a hack by the biggest and the lowest.
  - all the buckets must be with same size.
  - let's insert 101
  - we insert the biggest item in every consequent bucket
  - optimal is O(sqrt(N))
  - sqrt(N) - queue, sqrt(N) buckets
  - Let B = sqrt(N)
  - let's remove 20
  - every buckets holds B elements, except the last one.
  - if we add and add and add and goes up a lot and the initial bucket size is way
    smaller thant sqrt(N). We need to make strategy when to resize. If B - current
    size of buckets but sqrt(N) != B && sqrt(N) > 2B we resize. Resizing in heavy
    operation. It is o(N). It happens rarely enough so that we don't care. The same
    goes for deleting. Inside stl vector it is used. Amortized complexity. Adding it
    is comlex. TODO: amortized complexity.
  - TODO: informatike tiered paper.

Example Problem:
---
Segment with length L. A long pot. N drops fall. We have the order of falling.
Which is the last drop 50, 3, 57, 1, 30, 61, 23, 40, 13, 55. Let k be 25. We
have L, k, drops which is the last interval we don't have an interval below k.
The answer is 23. K <= L <= 10^9, N <= 100,000. If a drop falls on k and on 0
then k is empty.

For every bucket we need to store the smallest and the biggest.

if k*N < L => there is a interval

Solutions:
  - buckets of k.Linear complexity.
  - binary search tree
  - sort every time.
  - binary search we divide into two buckets and sort them.


resources: informatika.bg/misc

Trie
=====
cat
cow
cave
hat
have
hate
car

bigger alphabet
<char, Node>
hashtable[letters]Node
compressed version
patricia tree
radix tree.

Teachers:
avulev@gmail.com
istranjev@gmail.com
