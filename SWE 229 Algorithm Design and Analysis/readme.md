# ALgorithm Design and Analysis

## Resources

1. <a href = "https://codeforces.com/blog/entry/54090"> Sieve </a> or <a href = "https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html"> click here </a>
	- Topics you will find in this link:
		- Sieve of Eratosthenes
		- Linear Sieve
		- Multiplicative Function (Totient Function)
		- Extension on the Linear Sieve
		- Example Problems

2. <a href = "http://www.shafaetsplanet.com/?p=855"> Bitwise Sieve </a>

#### Code of bitwise sieve

```C++
#include <bits/stdc++.h>
using namespace std;

#define ALHAMDULILLAH return 0
#define ll long long
#define debug 01

int N = 10000;
int prime[10000]; 
int status[10000/32 + 1];  // 0: prime, 1: not-prime or composite

bool Check(int index,int bitNumber){
	int x = status[index] & (1<<bitNumber);
	if( x == 0 ) {
		return false; // prime
	}
	else {
		return true; // composite
	}
}

void Set(int index,int bitNumber){	
	status[index] = status[index] | (1 << bitNumber);
}

void sieve()
{
     int i, j, sqrtN; 
     sqrtN = int( sqrt( N ) );
     for( i = 3; i <= sqrtN; i += 2 ) 
     {
		 if( Check(i/32, i%32) == false )
		 {
	 		 for( j = i*i; j <= N; j += 2*i )
			 {
				Set(j/32, j%32);
	 		 }
		 }
	 }	 	
}

bool isPrime( int num ) {
	if( num == 2 ) return true;
	else if( num % 2 == 0 ) return false;
	else {
		return !Check(num/32, num%32);
	}
}

int main()
{
	sieve();

	for( int i = 2; i < 100; i++ ) {
		if( isPrime(i) ) {
			cout << i << " ";
		}
	}

	ALHAMDULILLAH;
}
```

3. <a href = "https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#segmented-sieve"> Segmented Sieve </a>


4. <a href = "https://cp-algorithms.com/algebra/phi-function.html"> Euler's Totient Function </a>

#### Code of Phi Function

An implementation using factorization:

```C++
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {	// This "i" is always a prime here.
            while (n % i == 0)
                n /= i;
            result -= result / i;	// This line implies that result *= (1-1/i); where "i" is a prime.
        }
    }
    if (n > 1)		// If n is greater than 1 then n is always a prime.
        result -= result / n;
    return result;
}
```

**Complexity:** _O(sqrt(n))_

Computing totient of all numbers from **1** to **n** (using the idea of **sieve**):

```C++
void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
```

**Complexity:** _O(n log log n)_

Computing totient of all numbers from **1** to **n** (using the property of **Divisor Sum**):

```C++
void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
}
```

**Application of Totient Function**
* <a href = "https://cp-algorithms.com/algebra/phi-function.html#divsum"> Divisor Sum Property </a>
* <a href = "https://cp-algorithms.com/algebra/phi-function.html#application"> Euler's Theorem </a>


5. <a href = "https://cp-algorithms.com/algebra/divisors.html"> Number or Sum Of Divisors </a>

#### Code of Number of Divisors:

(...HW...) Using the method of phi function

**Complexity:** _O(sqrt(n))_

<a href = "https://codeforces.com/blog/entry/22317"> Counting Numbe of Divisors in _O(n^(1/3))_ Complexity </a>

Faster algorithm to check if a number is a prime : **Miller Rabin Algorithm**

#### Code of Sum of Divisors:

(...HW...) Using the method of phi function

**Complexity:** _O(sqrt(n))_


#### Extended Euclidean Algorithm

<a href = "https://cp-algorithms.com/algebra/extended-euclid-algorithm.html"> Link </a>

#### Big Mod

#### Modular multiplicative inverse

<a href = "https://cp-algorithms.com/algebra/module-inverse.html"> Link </a>

#### Chinese Remainder Theorem

<a href = "https://cp-algorithms.com/algebra/chinese-remainder-theorem.html"> Link </a>

<a href = "https://codeforces.com/blog/entry/61290"> Link-02 </a>

#### Shortest Path: 
<a href = "https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html"> Floyd Warshall </a>









