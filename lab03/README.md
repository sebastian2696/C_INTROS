# Introduction

*Assigned: 2016-01-27*

*Due: 2016-02-05 11:59:59 PM EST*

This is the Lab 3 assignment for ECE 1120 - C Programming for ECE.

The goals of this lab are to introduce you to different C types,
arithmetic, and printing. You may have to read the chapter in the
textbook about program looping in order to do these problems.

You may also have to read in the book about the operators `==`, `!=`,
`<`, `<=`, `>`, `>=`. In particular, note that the operator `==` used
in an `if` statement to test for equality has two equals signs, and is
different from a single equals assignment operator.


**Be sure to put your name in a comment at the top of each program you
write.**

# Steps

## Prelude: Use git to clone the Lab 3 assignment.

***Make sure you are inside your assignments folder.***

From the cloud9 command-line, use the git source code control tool to
make a copy of the starter source code for this assignment.

```
git clone https://github.com/gw-ece1120-s2016/lab03
```

You should see some output similar to this:
```
Cloning into 'lab03'...
remote: Counting objects: 4, done.
remote: Compressing objects: 100% (4/4), done.
remote: Total 4 (delta 0), reused 4 (delta 0), pack-reused 0
Unpacking objects: 100% (4/4), done.
Checking connectivity... done.
```

#### Do some house keeping before proceeding

Remove .git folder from the assignment:

```
$ rm -rf lab03/.git
```

Make sure git tracks your progress on the assignment:

```
$ git add lab03/*
```

These steps are crucial for correct submission. We are not responsible
for wrong submissions, therefore please feel free to ask TA for
clarification or confirmation.

## Part 1

Write a program called `part1.c` to compute the GCD of two
integers. You may copy the code from the book, but you must modify it
to read the two input number in separate `scanf` statements.

When you are done with this part make sure git tracks this file. Run
following command form inside lab03 folder: ``` git add part1.c ```

## Part 2

Write a program called `part2.c` to read in an integer and extract and
display digits in *reverse*, but in *English*.

For example, if the number `55369` is entered, the program should
print `nine six three five five`. 

Be sure your program can handle single digit numbers.

What happens when the user enters a negative number? Be sure you add
some code to detect negative numbers and print the word `negative` at
the end of the line. For example, given the input `-4421` your program
should print `one two four four negative`.

When you are done with this part make sure git tracks this file. Run
following command form inside lab03 folder: ``` git add part2.c ```

# Part 3

Write a program called `part3.c` that will read in an integer `n` and
compute a table of values from `i=0` up to and including `i=n`
printing the values for `i`, `i**2`, `i**3`, and `i!`.

For example, given the input `9`, the program should print:

```
0 0 0 1
1 1 1 1
2 4 8 2
3 9 27 6
4 16 64 24
5 25 125 120
6 36 216 720
7 49 343 5040
8 64 512 40320
9 81 729 362880

```

What happens when the user enters a negative number? Since a factorial
for a negative integer is not defined, be sure you add some code to
detect negative numbers, print an error message, and exit gracefully
if a negative number is entered.

When you are done with this part make sure git tracks this file. Run
following command form inside lab03 folder: ``` git add part3.c ```

# Part 4

Write a program called `part4.c` that will read in an integer `n` and
calculate the sum of its digits. For example, the sum of the digits of
the number `2155` is `2 + 1 + 5 + 5` or `13`. The program should
accept any arbitrary integer typed in by the user (including negative
integers).

When you are done with this part make sure git tracks this file. Run
following command form inside lab03 folder: ``` git add part4.c ```

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
Program compiles                       : 10%
Program compiles with no warnings      : 10%
Some output generated                  : 10%
Correct output in normal cases         : 40%
Correct output in unusual cases        : 30%

Total : 100%
```

You will receive *at most* 10% if your program does not compile. You
will receive *at most* 20%if your program compiles with warnings.

You will lose 20% if you do not put your name in a comment near
the top of the program. 

