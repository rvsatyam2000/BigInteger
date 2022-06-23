# bigint
## Big Integer Library for C++
## 1 Million digits? 1 Billion? 1 Trillion? No Worries. This Library can handle any Integer of any Length.

### bigint is a C++ library which can handle Very very __Big Integers__. It can calculate *factorial* of __1000000...__ it can go any big. It may be useful in *Competitive Coding* and *Scientific Calculations* which deals with very very large Integers.

---

# How to use it?

Download [bigint] header file bigint.h and include in your C++ program.

```c++
#include "bigint.h"     // with proper file path 
```
---

# Declaring and Intializing Variables.

Declartion is done like making object of bigint class.
Intialization can be done by passing *String* or *Integer* or *Long* type at Object creation.

```c++
BigInt a("56654250564056135415631554531554513813");     // big integer initialization with String
BigInt d(956486133);                                    // big integer intialization with Integer
BigInt c(a);                                            // big integer intialization with another big integer 

```
---
# Addition

Addition can be done as it is done with general integer types of variables.
- (*Note : variable's value and declaration will be followed as it goes.*)
Here, number could be positive or negative.
```c++
BigInt c = a + b;                         // Addition, with both operand as bigint
cout << c << std::endl;     // Output : 56715071128747796771095069997119178381

c = a + 56242;                            // Addition, with one operand as bigint and other as integer
cout << c << std::endl;     // Output : 56654250564056135415631554531554570055

c = 52 + 98;                              // Addition, with both operand as integers.
cout << c << std::endl;     // Ouput : 150

```
---
# Subtraction 

Subtraction can be done as it is done with general integer types variables.
It handles negative numbers also.

```c++
c = a - b;                                 // Subtraction, with both operand as bigint
cout << c << std::endl;     // Ouput : 56593429999364474060168039065989849245

c = a - 56242;                            // Subtraction, with one operand as bigint and other as integer
cout << c << std::endl;     // Output : 56654250564056135415631554531554457571

c = 52 - 98;                              // Subtraction, with both operand as integers.
cout << c << std::endl;     // Output : -46
```

---

# Multiplication

Multiplication can be done as it is done with general integer types variables.
It handles negative numbers also.

```c++
c = a * b;                                 // Multiplication, with both operand as bigint
cout << c << std::endl;     // Output : 3445743511488768021543787806860750328299778111849236444610289955667677784

c = a * 56242;                            // Multiplication, with one operand as bigint and other as integer
cout << c << std::endl;     // Output : 3186348360223645168045949889963688965870746

c = 52 * 98;                              // Multiplication, with both operand as integers.
cout << c << std::endl;     // Output : 5096

```
---

# Division

Division can be done as it is done with general integer types variables.
It handles negative numbers also.
```c++
c = a / b;                                 // Divison, with both operand as bigint
cout << c << std::endl;     // Output : 931

c = a / 56242;                            // Divison, with one operand as bigint and other as integer
cout << c << std::endl;     // Output : 1007329941397107773827949833426167

c = 98 / 56;                              // Divison, with both operand as integers.
cout << c << std::endl;     // Output : 1

```

---

# Mod

Mod can be done as it is done with general integer types variables.

```c++
c = a % b;                                 // mod, with both operand as bigint
cout << c << std::endl;     // Output : 56654250564056135415631554531554513813

c = a % 56242;                            // mod, with one operand as bigint and other as integer
cout << c << std::endl;     // Output : 29399

c = 98 % 56;                              // mod, with both operand as integers.
cout << c << std::endl;        // output : 42

```
---

# Conditional Statements

Conditionals can be used as it is done with general integer types variables.
Supports :  *>* , *<* ,  *>=* , *<=* , *==* , *!=*
It handles negative numbers also.

```

---


## abs(bigint)  -   absolute function

It takes BigInt as argument and return type is also *BigInt*.

```c++
BigInt b = -60820564691661355463515465564664568
cout << abs(b) << std::endl;    // Output : 60820564691661355463515465564664568

```

---

## operator ^ (bigint, bigint)  -   power function using operator overloading

It takes two bigint as arguments and return type is also *bigint*, returns the *first* bigint argument to the power *second* bigint argument.

---
## sqrt(bigint)     -   square root function

It takes one bigint as arguments and return type is also *bigint*(floor value), returns the square root of the bigint.

```c++
cout << sqrt(a) << std::endl;               // returns sqrt of bigint
```
---
---
# Increment and Decrement

Increment and Decrement can be done as it is done with general integer types of variables.

```c++
cout << a << "\t" << ++a << std::endl;              // Output : 654456  654457
cout << a << "\t" << --a << std::endl;              // Output : 654457  654456
```
