# ALgorithm Design and Analysis

## Resources

1. <a href = "https://codeforces.com/blog/entry/54090"> Sieve </a> or <a href = "https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html"> click here </a>
	- Topics list:
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
