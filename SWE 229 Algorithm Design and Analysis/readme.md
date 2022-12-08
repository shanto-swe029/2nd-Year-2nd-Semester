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



<a href = "https://cp-algorithms.com/algebra/chinese-remainder-theorem.html"> Link-01 : ***CP Algorithms'*** Blog of Chinese Remainder Theorem </a>

<a href = "https://codeforces.com/blog/entry/61290"> Link-02 : ***Codeforces'*** Blog of Chinese Remainder Theorem of Coprime & Non Coprime Moduli </a>

<a href = "https://forthright48.com/chinese-remainder-theorem-part-1-coprime-moduli/"> Link-03 : ***forthright48's*** Blog of Chinese Remainder Theorem Part 1 – Coprime Moduli </a>

<a href = "https://forthright48.com/chinese-remainder-theorem-part-2-non-coprime-moduli/"> Link-04: ***forthright48's*** Blog of Chinese Remainder Theorem Part 2 – Non Coprime Moduli </a>

<a href = "https://www.cut-the-knot.org/blue/chinese.shtml"> Link-05: ***Cut The Knot's*** Blog of Chinese Remainder Theorem </a>



##### An Implementation Based on Link-02

We would like to solve the following system of equations

**_x ≅ a₁ ( mod n₁ )_** ......(1)

**_x ≅ a₂ ( mod n₂ )_** ......(2)

where **_a₁, a₂, n₁, n₂ ≤ 10⁹_**.

Besides it is **not necessary** that **_n₁_** & **_n₂_** are coprime.

The following implementation handles overflow when calculating the value of **_x_**!!!

<br>

```C++
#define ll long long

ll Egcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = Egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll CRT_2( ll a1, ll n1, ll a2, ll n2 ) // CRT for 2 equations
{
	ll d = __gcd(n1, n2);
	a1 = a1 % n1;
	a2 = a2 % n2;
	if( ( ((a1-a2) % d) + d ) % d != 0 ) return -1; // no solution : empty vector

	ll x, x1, y1;
	ll lcm = n1 * n2 / d;
	if( n1 > n2 ) {
		ll tmp1 = n1; n1 = n2, n2 = tmp1;
		ll tmp2 = a1; a1 = a2, a2 = tmp2;
	}
	Egcd(n1, n2, x1, y1);

	ll a = x1 * (a2 - a1) / d;
	ll b = n2 / d;
	ll c = n1;

	return x = (((a1 + (a%b) * c) % lcm) + lcm) % lcm; // this is the lowest solution; 
}
```

**_Time Complexity:_** _O( log(lcm(n₁, n₂)) )_

<br>

Now we would like to solve the following system of equations

**_x ≅ a₁ ( mod n₁ )_** ......(1)

**_x ≅ a₂ ( mod n₂ )_** ......(2)

...

...

**_x ≅ aₜ ( mod nₜ )_** ......(t)

The simultaneous congruences are solvable when **_aᵢ = aⱼ ( mod GCD(nᵢ, nⱼ))__** for all **_i_** & **_j_** ; **_i≠j_**. The solution is unique modulo **_lcm(n₁, n₂, ..., nₜ)_**.

The following code will work only if **_lcm(n₁, n₂, ..., nₜ)_ ≤ 10¹⁸**.


```C++
#define ll long long

ll CRT_2( ll a1, ll n1, ll a2, ll n2 ); // must be implemented before the following function "CRT_t(vector<ll>, vector<ll>)"

ll CRT_t( std::vector<ll> a, std::vector<ll> n ) // CRT for t equations
{
	ll a1 = CRT_2(a[0], n[0], a[1], n[1]);
	if( a1 == -1 ) return -1; // no solution

	ll n1 = n[0] * n[1] / __gcd(n[0], n[1]);
	ll a2, n2, sz = a.size();

	for( int i = 2; i < sz; i++ ) {
		a2 = a[i], n2 = n[i];
		a1 = CRT_2(a1, n1, a2, n2);
		if( a1 == -1 ) return -1;
		ll d = __gcd(n1, n2);
		n1 = n1 * n2 / d;
	}
	return a1;
}
```

**_Time Complexity:_** _O( t.log(lcm(n₁, n₂, ..., nₜ)) )_

#### Shortest Path: 

##### Floyd Warshall Algorithm - Finding All Pair Shortest Path

<a href = "https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html"> CP Algorithm's Blog of Floyd Warshall Algorithm </a>

<a href = "https://youtu.be/oNI0rf2P9gE"> Video Tutorial of Abdul Bari </a>

##### Bellman Ford Algorithm - Single Source Shortest Path With Negative Edges

<a href = "https://cp-algorithms.com/graph/bellman_ford.html"> CP Algorithm's Blog of Bellman Ford Algorithm </a>

<a href = "https://youtu.be/FtN3BYH2Zes"> Video Tutorial of Abdul Bari </a>



### DP

#### Longest Common Subsequence

```cpp
#include <bits/stdc++.h>
using namespace std;
const int m_ = 101;
const int n_ = 101;
int dp[m_][n_];


int lcs( string x, string y, int m, int n ) {
    if( m * n == 0 ) return 0;

    if( dp[m][n] != -1 ) return dp[m][n];

    if( x[m-1] != y[n-1] ) {
        if( m > 0 && n > 0){
            dp[m-1][n] = lcs(x, y, m-1, n);
            dp[m][n-1] = lcs(x, y, m, n-1);
            return dp[m][n] = max( dp[m-1][n], dp[m][n-1] );
        }
        return 0;
    }

    if( m > 0 && n > 0 ) {
        dp[m-1][n-1] = lcs(x, y, m-1, n-1);
        return dp[m][n] = 1 + dp[m-1][n-1];
    }
    return 1;
}

int lcs_easy( string A, string B, int m, int n ) {
	int LCS[m+1][n+1];
	
	for(int i = 0; i <= m; i++ ) {
	    for( int j = 0; j <= m; j++ ) {
	        LCS[i][j] = 0;
	    }
	}
	
	for( int i = 1; i <= m; i++ ) {
		for( int j = 1; j <= n; j++ ) {
			if( A[i-1] == B[j-1] ) LCS[i][j] = 1 + LCS[i-1][j-1];
			else LCS[i][j] = max( LCS[i-1][j], LCS[i][j-1] );
		}
	}
	return LCS[m][n];
}

int main()
{
    string s1 = "axyt";
    string s2 = "ayxb";

    std::cin >> s1 >> s2;

    for( int i = 0; i < m_; i++ ) {
        for( int j = 0; j < n_; j++ ) {
            dp[i][j] = -1;
        }
    }

    cout << lcs( s1, s2, s1.size(), s2.size() ) << endl;
    cout << lcs_easy( s1, s2, s1.size(), s2.size() ) << endl;
}

```







