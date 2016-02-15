# Introduction

*Assigned: 2016-02-10*

*Due: 2016-02-19 11:59:59 PM EST*

This is the Lab 5 assignment for ECE 1120 - C Programming for ECE.

The goals of this lab are to extend your experience with loops,
functions and arrays.  You may have to read the chapter in the
textbook about loops, arrays, and functions in order to do these
problems.


**Be sure to put your name in a comment at the top of each program you
write.**

# Steps

## Prelude: Use git to clone the Lab 5 assignment.

***Make sure you are inside your assignments folder.***

From the cloud9 command-line, use the git source code control tool to
make a copy of the starter source code for this assignment.

```
git clone https://github.com/gw-ece1120-s2016/lab05
```

You should see some output similar to this:
```
Cloning into 'lab05'...
remote: Counting objects: 4, done.
remote: Compressing objects: 100% (4/4), done.
remote: Total 4 (delta 0), reused 4 (delta 0), pack-reused 0
Unpacking objects: 100% (4/4), done.
Checking connectivity... done.
```

#### Do some house keeping before proceeding

Remove .git folder from the assignment:

```
$ rm -rf lab05/.git
```

Make sure git tracks your progress on the assignment:

```
$ git add lab05/*
```

These steps are crucial for correct submission. We are not responsible
for wrong submissions, therefore please feel free to ask TA for
clarification or confirmation.

# Part 1
Write a program called `part1.c` to compute Fibonacci numbers. You may
copy your code from the slides (which is also in the book), but you must
implement a function to compute and return the `n`th Fibonacci
number. Write the function with a prototype `int fibonacci(int n)`. 

Your program should prompt the user, read in an integer, and compute
and print all of the Fibonacci numbers indexed from `0` to `n - 1`
(i.e. the first Fibonacci number to the `n`th one.)

Example output:
```
Fibonacci[0] = 1
Fibonacci[1] = 1
Fibonacci[2] = 2
Fibonacci[3] = 3
Fibonacci[4] = 5
```

When you are done with this part make sure git tracks this file. Run
following command form inside lab05 folder: ``` git add part1.c ```

# Part 2

This will be based on your previous code from Lab 03, you can
copy-paste your old code as a starting point.

Write a program called `part2.c` that will read in an integer `n` and
compute a table of values from `i=0` up to and including `i=n`
printing the values for `i`, `i**2`, `i**3`, and `i!`.

But modify your code so that it uses a function called `int
 factorial(int x)`  to compute `i!`. 

Next modify your code so that it uses 4 types of loops:
```
Loop 1 : For-loop
Loop 2 : While-loop
Loop 3 : Do-while-loop
Loop 4 : Badly-structured loop constructed with gotos and no for,
while, or do-while constructs
```

Your final output should show the results from all four loops.
For example, given the input `4`, the program should print:

```
0 0 0 1
1 1 1 1
2 4 8 2
3 9 27 6
4 16 64 24
0 0 0 1
1 1 1 1
2 4 8 2
3 9 27 6
4 16 64 24
0 0 0 1
1 1 1 1
2 4 8 2
3 9 27 6
4 16 64 24
0 0 0 1
1 1 1 1
2 4 8 2
3 9 27 6
4 16 64 24

```

Since a factorial for a negative integer is not defined, be sure you
add some code to detect negative numbers, print an error message, and
exit gracefully if a negative number is entered.

When you are done with this part make sure git tracks this file. Run
following command form inside lab05 folder: ``` git add part2.c ```

# Part 3

Write a program called `part3.c` to perform base conversions. You may
start your code from the example in the book, but you must
implement a function to compute and return the base conversions. Write
the function with a prototype:
```int convert_base(int x, int base, char  printable_digits[64])```

Here, `x` is the number to convert, `base` is the new base, and
`printable_digits[64]` is the character array to store the
results. This function should return a `0` if successful and a `-1` if
an error occurred. Think carefully about what kinds of conditions
should be considered errors: a negative input number? a negative base?
Explain your error-checking in a comment.

When you are done with this part make sure git tracks this file. Run
following command form inside lab05 folder: ``` git add part3.c ```

# Part 4

Write a program called `part4.c` to generate a table of prime
numbers through trial division. You may start your code from the
example in the book. 

Your program should prompt the user, read in an integer, and compute
and print all of the prime numbers from the range of integers `1` to
`n`. Make sure your program has an array for primes large enough to
support finding all of the primes less than `10000`.

When you are done with this part make sure git tracks this file. Run
following command form inside lab05 folder: ``` git add part4.c ```

# Part 5

Write a program called `part5.c` to prompt the user for a number and
then report whether that number is prime or not. You should write a
function `int is_prime(int k)` that does this through trial
division and returns a `1` if the input is prime and `0` if the input
is not prime. You may start off with the code you wrote in part 4. 

Your main program should prompt the user, read in an integer, and call
`is_prime` to test whether it is prime, and print the result.

Make sure your function has an array for primes large enough to
support testing an integer number less than `10000`. What happens when
we keep trying to increase this array size? Try your program with
array sizes for `primes[]` of `10000`, `100000`, `1000000`, and so
 on. What is the largest array size you can use? Write that in a
comment, and be sure to change your size back to a reasonable value.

When you are done with this part make sure git tracks this file. Run
following command form inside lab05 folder: ``` git add part5.c ```

## Submission procedure

You have to "commit" changes you made in the assignment. In order to do that run:

```
$ git commit -am "Write some submission message here"
```

This will only update your local repository, meaning that nothing will be updated on GitHub. You have to "push" your changes in order to do that:

```
$ git push origin master
```

Make sure you didn't receive any errors in the output.

You can check the organization page on GitHub for correct
submission. Go to your own assignments repo, and make sure all the
files are updated with the changes you made.

## Grading Rubric

All parts 1-5 are worth 20 points each.

For each part, the rubric is:


```
Program compiles                                    : 10%
Program compiles with no warnings                   : 10%
Some output generated                               : 10%
Correct output in normal cases
(including comment quality of 10% if applicable)    : 40%
Correct output in unusual cases                     : 30%

Total : 100%
```

You will receive *at most* 10% if your program does not compile. You
will receive *at most* 20%if your program compiles with warnings.

You will lose 20% if you do not put your name in a comment near
the top of the program. 

