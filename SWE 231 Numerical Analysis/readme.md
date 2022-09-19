# Numerical Analysis - Dr. Ahsan Habib

### Lecture-01:    29th August, 2022

sometimes exact solutions can be extracted but sometimes not.
so we need to be as precise as we can.

Hard time solution, real time solution.
how much error (threshold value) we will accept.

**Why use Numerical Methods?**
- To solve problems that cannot be solved exactly
- To solve problems that are intractable

**How do we solve an engineering problem?** <br>
Problem Description -> Mathematical Model -> Solution of Mathematical Model -> Using the Solution

**Mathematical Model:** Converting the problem into mathematics.otherwise computer cannot help to solve this problem.

**Using the Solution:** Compare with existing solutions.

<br>
<br>


### Lecture-02:    31st August, 2022

#### Nonlinear Equations
How much of the floating ball is under water?

<br>
<br>

### Lecture-03:    5th September, 2022

#### Root Finding Methods

f(x) = x^3 - 6x^2 + 11x - 6 = 0
f(1) = 0, f(2) = 0, f(3) = 0

We do not need numerical analysis here because we have found the exact solutions.

Some root finding methods are:
* Bisection Method
* Method of False Position
* Newton Raphson's Method
* Fixed Point Iteration Method

#### Bisection Method
If a function ***f(x)*** is continuous between *a* and *b* and ***f(a).f(b) < 0*** ( or ***f(a)*** and ***f(b)*** are of opposite sign), then there exists ***at least one root*** between _a_ and _b_.

We can find only one root of ***f(x)*** within the interval ***[a, b]***.

<a href = "https://atozmath.com/CONM/Bisection.aspx"> ***Bisection Method Root Finding Calculator*** </a>

Find the root of the following functions using bisection method:
1. ***f(x) = x^3 - 2x^2 - 4 = 0; a = 2, b = 3***
2. ***f(x) = x^3 + x^2 - 1= 0; a = 0, b = 1***
3. ***f(x) = x^2 + sin(x) - 1= 0; a = null, b = null***

<br>
<br>

### Lecture-04:    14th September, 2022

#### False Position Method

<a href = "https://byjus.com/maths/false-position-method/#:~:text=The%20false%20position%20method%20is,the%20roots%20of%20the%20equation."> Theory Link </a>

<a href = "https://atozmath.com/CONM/Bisection.aspx?q=fp"> False Position Method Calculator </a>

#### Newton Raphson Method

<a href = "https://byjus.com/maths/newton-raphson-method/"> Theory Link </a>

<a href = "https://atozmath.com/CONM/Bisection.aspx?q=nr"> Newton Raphson Method Calculator </a>


<br>
<br>

### Lecture-05:    19th September, 2022

#### Interpolation

1. Newton's Formula
    * Forward Formula
    * Backward Formula

[Interpolation.pdf](https://github.com/shanto-swe029/2nd-Year-2nd-Semester/files/9597735/Interpolation.pdf)

##### Newton's Forward Interpolation Formula

##### Newton's Backward Interpolation Formula













