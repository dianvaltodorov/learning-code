Part 1
====
Euclid
---
```
typedef long long ll;
typedef long double ld;


evkl(ll a, ll b){
  if(b > a){
    return evkl(b, a);
  }
  if(b== 0) {
    return a;
  }
  ll r;
  while((r = a % b)!=0){
    a=b;
    b=r;
  }
  return b;
}

```

Besu
---
u * a + v * b = d
```
ll evkl_ex(ll a, ll b, ll& u, ll& v){
  // u * v + v * 0 = a
  if (b == 0) {
    u = 1;
    v = 0;
    return a
  }

  ll x1, y1;
  b * x1 + (a % b) y1 = d;
  ll d = evkl_ex(b, a % b, x1, y1)
  u = y1;
  v = x1 - y1 * (a / b);
  return d;
}
```
Proof:
---

```
u * a + v * b = d
y1 * a + (x1 - y1(a / b))b = d
y1 * a + x1 * b- y1(a/b)b = d
y1 * [ a - (a / b) * b ] + x1 * b = d

a - (a / b) * b = a - k * b = a % b

u0 * a + v0 * b = d
u0 * a1 * d + v0 * b1 * d = d
u0 * a1 + v0 * b1 = 1

u * a1 + v * b1 = 1

(u0 - u) a1 + (v0 - v)b1 = 0
(u0 - u) a1 = (v - v0)b1
u0 - u = k * b1
v0 v0 =  
```

Find al the simple numbers till N
Erathosten V1:
```
int p[N];
for (int i = 2 ; i * i < N; i++)
{
  if (p[i]!=0)
    for(j = i * i; j <= N; j += i) {
      p[j] = 0;
    }
}
```

Erathosten V2, Optimized:
```
p[1] = 0;
p[2] = 0;

for(int i = 0; i <= N; i += 2){
  p[i] = 0;
}

for(int i = 3; i * i <= n; i += 2){
  if[p[i]]{
    continue;
  }
  for( j = i * i; j < = N; j +i) {
    p[j] = 0;
  }
}
```

memset(s, 0, sizeof(a))
memset(s, -1, sizeof(a))

Canonical representation:
---
```
a = p1 ^ alfa1 * p2 ^ alfa2 * pk ^ alfak
1 <= alfai
pi - prime number
```

p[i] - smallest prime delimiter of i
p[1] = 1

```
p[1] = 0;
p[2] = 0;


for(int i = 0; i <= N; i += 2){
  p[i] = 2;
}

for(int i = 3; i * i <= n; i += 2){
  if (p[i] == 0) {
    p[i] = i;
  } else {
    continue;
  }
  for( j = i * i; j < = N; j +i) {
    if (p[j] == 0){
      p[j] = i;
    }
  }
}

while (a!= 1) {
  cout  << p[a] << endl;
  a /= p[a]
}
```
Problem
----
Given the interval 0 <= l, r<= 400,000, l - r <= 1000
number of алл delimiters of a is (alfa1 + 1)(alfa2 + 1)(alfa3 + 1)(alfa4 + 1)
12 = 2 ^ 2 * 3
1, 2, 3, 4, 6, 12

(r - l) * log

Part 2
===
```
stepen(ll a, ll b)
{

}

a * a * a * a * a * a ... a = a ^ 57
```

exponential bisquaring
----
57 = 111001

a, a^2 , a^4, a^8, a^16, a^32
1   0,     0,   1,    1,   1   

a * a^8 * a^16 * a^32

```
ll stepen (ll a, ll x, ll mod){
  ll res = 1;
  while(x) {
    if ( x % 2) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    x / = 2;
  }
  return res;
}
```
log 2 x

63 operations


```
(a / b)  % m

64 / 8 = ? (mod 3)
1 / 2 (mod 3)
1 * 2^(-1) (mod 3)
a * a^(-1) = 1(mod p)
```

Small Ferma theorem
a ^ (p - 1) = 1(mod p)
a * a ^ (p - 2 == 1 (mode p)

Calculating combinations
----
```
p = 10 ^ 9 + 7
rev
ll num  =  1;
for (ll i = n - k + 1; i <= n; i++){
  nim  = (num * i) % p
}

ll denom  =  1;
for (ll i = 1 i <= k; i++){
  denim  = (num * i) % p
}

cout << (num  * rev (denom, p)) % p << endl;
```

Recurring sequences
-----
```
a n + 2 = A an + 1 + B an

```

1. Fibonacci
nth fibonacci number with matrices of
(1 1)
(1 0)
In the above left corner is the nth fibonacci number

2. Random
nth number from the sequence A*a(n+1) + B*a(n)
(A B)
(1 0)

3. For a sequence a(n+3) = A a(n+2) + B a(n+2) + C a(n)
(A B C)
(1 0 0)
(0 1 0)

(a0, a1, a2) M ^ (n -1 )
This is done for the purpose of


Fast upping of matrices
----

How many are the paths connecting vertices a and b with length k.
Powering a matrix.

How many are the paths connecting vertices and b with length below k;

We make a loop inside by modifying.

big thoerem of Ferma
----

function euler
function of euler = number of c <b : (b, c) = 1

Passcal triangle

Problem
---

n, p ,q
color
m < 10^9
logarithmic

c[p] - every cells how many ways to color the first column
Combination with repetition
