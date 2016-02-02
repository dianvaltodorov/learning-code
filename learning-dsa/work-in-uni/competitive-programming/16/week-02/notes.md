Dynamic Programing
====
TODO: read informatika.bg on topic dynamic programming
thrinkcreative@outlook.com


Dynamic Programing bit masks
===

How to train - make a contest and retry the task.

bit operations:
===
* AND
* OR
* XOR
* >>, <<
* !
* ~, inverse 101010 -> becomes 010101

JAVA  >>> and <<<
---
* 42 << 2 -> as if we multiply by 2^2
* 42 >> 3 -> as if we divide 2^3 (42 / 8 = 5)

Different from 0
----
if (x==0) return 0
if (x!=0) return 1
return !!x -> return if a number is not null


The thief problem.
----
bool used[20] -> takes 20*8 bits
int usedMask = 0 -> substitues the

A single int is 4 bytes which is 32 bits.

usedMask  |= 1 << 17 -> mark the seventieth bit as used(mark the store as robed)
usedMask  ^= 1 << 17 -> mark the seventieth bit as not used (mark the store as not robed)
usedMask  &= ~(1 << 17) -> mark the(mark the 17th bit as 0 no matter what it is)
(usedMask  >> 17) & 1


PROBLEM:
======
We have 20 dots and we want to connect the dots so that the sum of all the
connections is maximum. The greedy strategy -> connect two farthest points. But
this would not work. The dynamic programming would work. We will use bit mask
and remember which dots are connected.

```
int 8;
recurse - returns the maximum available dots.

double dyn[1 << n];
bool vis[1<<n] -

x = 101101
vis[x] ->  which states we have checked and which not
dyn[x] ->  the answer for the current

double recurse(int mask)
{  
  if (mask == (1 << n) - 1) // check if all dots are connected.
    return 0;

  if (visited[mask]) // memoization, this configuration is already calculated.
    return dyn[mask];

  double best = 0;
  for(i = 0; i < n; i++)
  {
    if(!(masked & (1 << i))) // find one position with one
    {
      for(c = i + 1; c < n; c++)
      {
        if(!(mask&(1<<c)){  // find another position with one
            double cur = dist(i, c) + recurse(maks | (1 << i) | (1 << c))
            best = max(best, cur)
        }
      }
    }
  }
  vis[mask] = true;
  return dyn[mask] = best;
}
```

We don't need dyn[1 << n] because we don't need all the memory. Half of the
memory is not used.

How to spot 2 ^ 15 - 20 -> This is how we spot such tasks.

Problem
----
We have N cities. Between the cities there are roads. The distance can be
different. Graph of cities. Eli starts from a city and steals something.
Afterwards she goes to another city. She travels all of the cities and cannot
return to the same city. Travelling salesman. Can't go to the same city, has to
go all the cities but cannot. Hamilton path. NP tasks - no polinominial time for
this problem.

Most simple solution O(N!)
N! works til N = 12


Solution:
----
What we care about?:

Which vertex are visited.
What is the current distance.

dyn[20][2 ^ 20] means  dyn[currentNode][mask]

O(2^N * N^2)

xkcd.com/399


Magic
====
const int MASK = 2 << 20;
bool vis[MASK]
double dyn[MASK]
int dun[MASK]

memset(dyn , -1, sizeof(dyn)) -> all become to -1

What happens in double array which we set with -1. Becomes Nan

if(dun[mask] == dyn[mask])
  return dyn[mask];

Problem
======

Overview:
---
dynamic on template(динамично по шаблон)
* dyn[6][6][6][6][6] - dynamic with template, winamp bars

We have a matrix 5x5. We put letters so that in every line and every column the
letters are in increasing order.

two five

The xs are the only valid positions. We can put letters only in the small xs. We
don't care what is the next letters we only care which is free.

|A|D|F|G|x|
|B|E|x| | |
|C|I| | | |
|H|x| | | |
|x| | | | |

 the current state above is [4][3][1][1][0]

We can compress state and use dyn[6^5] - every letter in this is some letter.
