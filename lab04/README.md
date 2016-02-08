# Introduction

*Assigned: 2016-02-03*

*Due: 2016-02-12 11:59:59 PM EST*

This is the Lab 4 assignment for ECE 1120 - C Programming for ECE.

The goals of this lab are to give you more experience with loops, and
introduce you to functions and arrays.  You may have to read the
chapter in the textbook about loops, arrays, and functions in order to
do these problems.


**Be sure to put your name in a comment at the top of each program you
write.**

# Steps

## Prelude: Use git to clone the Lab 4assignment.

***Make sure you are inside your assignments folder.***

From the cloud9 command-line, use the git source code control tool to
make a copy of the starter source code for this assignment.

```
git clone https://github.com/gw-ece1120-s2016/lab04
```

You should see some output similar to this:
```
Cloning into 'lab04'...
remote: Counting objects: 4, done.
remote: Compressing objects: 100% (4/4), done.
remote: Total 4 (delta 0), reused 4 (delta 0), pack-reused 0
Unpacking objects: 100% (4/4), done.
Checking connectivity... done.
```

#### Do some house keeping before proceeding

Remove .git folder from the assignment:

```
$ rm -rf lab04/.git
```

Make sure git tracks your progress on the assignment:

```
$ git add lab04/*
```

These steps are crucial for correct submission. We are not responsible
for wrong submissions, therefore please feel free to ask TA for
clarification or confirmation.

## Part 1

Write a program called `part1.c` to compute and the GCD of two
integers `u` and `v`. You may copy your code from lab03 (that was
based on the book), but you must implement a function to compute the
GCD called `int gcd(int a, int b)`. Make sure the `scanfs` and
`printf` are OUTSIDE of the function.

Now, modify your code to print the values of `u` and `v` at three
places. First, in `main` just *BEFORE* the function call to `gcd`,
inside `gcd` just before the return`, and finally in `main` just *AFTER*
 the call to to `gcd`.

Does the function change the value of the inputs as it runs? Do the
values of `u` and `v` change outside of the function. Explain the
results in a comment. 


When you are done with this part make sure git tracks this file. Run
following command form inside lab04 folder: ``` git add part1.c ```

## Part 2

Write a program called `part2.c` with a function called `void
print_int(int x)` to print the input number in decimal (without the
ending newline). You may only use the C `putchar(int c)` function to
display digits (and an optional leading minus sign). 

Your program should read an integer, call `print_int` to print it, and
then exit. Be sure your program can handle single digit and negative
integers.

It may be easier to extract the base-10 digits from lowest to highest
and then reverse them. In order to do it this way, you may have to
declare an array of characters to store the digits and then go through
this array backwards to print the final output.

When you are done with this part make sure git tracks this file. Run
following command form inside lab04 folder: ``` git add part2.c ```

# Part 3

Write a program called `part3.c` with a function called `long
array_sum(int A[], unsigned int n)` to compute the sum of all of the
elements in an array. In this function, the parameter variable `A` is
an array of integers and the parameter variable `n` is the number of
elements in the array.

In `main`, your program should declare an array of size 1000, then
prompt the user to input the number of integers `n`, and fill in the
array with exactly that many integers. Finally, call `array_sum` and
print the result. 

If the user enters n larger than 1000, you should print an error and quit.

When you are done with this part make sure git tracks this file. Run
following command form inside lab04 folder: ``` git add part3.c ```

# Part 4

Write a program called `part4.c` with a function called `double
mysqrt(double x)` compute the square root of a double. You may not use
any of the C math library functions to compute this. You may use the
Newton-Raphson method (see
https://en.wikipedia.org/wiki/Newton%27s_method) or a modified binary
search to find the square root. The `main` function should read a
`double`, call `mysqrt`, and print the result.

Ideally, your program should compute a square root that is accurate to
the full precision of a `double`.

Explain how your method works in a detailed comment.

If the input is negative you should return a `NaN` (meaning
not-a-number). You can load definition of this symbol by adding
`#include <math.h>` to the top of your program.

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

