# Introduction

*Assigned: 2016-02-29*

*Due: 2016-03-07 11:59:59 PM EST*

This is the Lab 6 assignment for ECE 1120 - C Programming for ECE.

The goals of this lab are to extend your experience with loops,
functions and arrays.  You may have to read the chapter in the
textbook about loops, arrays, functions, and character arrays in order
to do these problems.


**Be sure to put your name in a comment at the top of each program you
write.**

# Steps

## Prelude: Use git to clone the Lab 6 assignment.

***Make sure you are inside your assignments folder.***

From the cloud9 command-line, use the git source code control tool to
make a copy of the starter source code for this assignment.

```
git clone https://github.com/gw-ece1120-s2016/lab06
```

You should see some output similar to this:
```
Cloning into 'lab06'...
remote: Counting objects: 4, done.
remote: Compressing objects: 100% (4/4), done.
remote: Total 4 (delta 0), reused 4 (delta 0), pack-reused 0
Unpacking objects: 100% (4/4), done.
Checking connectivity... done.
```

#### Do some house keeping before proceeding

Remove .git folder from the assignment:

```
$ rm -rf lab06/.git
```

Make sure git tracks your progress on the assignment:

```
$ git add lab06/*
```

These steps are crucial for correct submission. We are not responsible
for wrong submissions, therefore please feel free to ask TA for
clarification or confirmation.

# Part 1
Write a program called `part1.c` to find the identity and location of
the largest and smallest elements in an array. You may base your code
on code from the slides (which may also be in the book), but you must
write **two** function with the prototypes:

```
void find_maximum(int A[], int n, int *idx_max, int *max_val)
```

and

````
void find_minimum(int A[], int n, int *idx_min, int *min_val)
```

Note the special pointer notation such as `int *idx_max` and `int
*max_val`. For now, you can just think of this as a way for a function
to modify input arguments. The `find_minimum` and `find_maximum`
functions should only find items, not print anything.

Your program should generate `10000` random integers using the standard
library function called `long int random(void)`, print the input
array, and then the call the functions, and then print the location
and value of the minimum and maximum elements.

When you are done with this part make sure git tracks this file. Run
following command form inside lab06 folder: ``` git add part1.c ```

# Part 2

Write a function that raises an integer to a an integer power, without
using any of the math library functions. Use the prototype:
```int x_to_the_n(int x, int n);```

Your program should prompt the user for integer `x`, read it in,
prompt the user for an integer `n`, read it in, call `x_to_the_n`, and
print the result. Be sure your program works for negative values of
`x` and validates the range of `n`. What happens when `n` is too big?
Your function should return an error, and your main program should
display an error message and exit gracefully.

When you are done with this part make sure git tracks this file. Run
following command form inside lab06 folder: ``` git add part2.c ```

# Part 3

Given the following definition of `struct time`:

```
struct time {
       int hour;     /* 0 to 23 */
       int minutes;  /* 0 to 59 */
       int seconds;  /* 0 to 60 */
};
```

Write a function `elapsed_time` that takes as its arguments two time
structures and returns a time structure that represents the elapsed
time (in hours, minutes, and seconds) between the two times. So the
call `elapsed_time (time1, time2)` where time1 represents 3:45:15 and
time2 represents 9:44:03, should return a time structure that
represents 5 hours, 58 minutes, and 48 seconds. Be careful with times
that cross midnight. Assume that caller of the function passes arguments
such that time1 is always earlier than time 2. So, if time2 looks like
a lower numerical value, it is a signal for midnight-crossing subtraction.

Your main function should prompt for and read two times in `hh:mm:ss`
format and print the difference between them.

Example:
```
Enter time1: 3:45:15
Enter time2: 9:44:03
time2 - time1 is 05:58:48
```

When you are done with this part make sure git tracks this file. Run
following command form inside lab06 folder: ``` git add part3.c ```

# Part 4

Write a program called `part4.c` with a function called:

```int find_string(char *haystack, char *needle);```

to determine if one character string exists inside another string. The
first argument to the function should be the character string that is
to be searched and the second argument is the string you are
interested in finding.

Here we are using fancy pointer notation for the character
arrays. Explain in a comment why we do not need to pass in the size
of each string.

If the function finds the specified string, have it return the
location in the source string where the string was found. If the
function does not find the string, have it return `–1`.

So, for example, the call `index = findString ("a chatterbox",
"hat");` searches the string `"a chatterbox"` for the string
`"hat"`. Because `"hat"` does exist inside the source string, the
function returns 3 to indicate the starting position inside the source
string where "hat" was found. 

Your main function should prompt for, and read in two strings, the first
the string to be searched (i.e. haystack), and the second the substring
to be searched for (i.e. needle).
format and print the difference between them.

When you are done with this part make sure git tracks this file. Run
following command form inside lab06 folder: ``` git add part4.c ```

# Part 5

Write a program called `part5.c` to compute a solution to the problem
presented at https://www.expii.com/solve/1/5# 

The problem reads:
```
Oh no! You’re above a pit of fire and the only way out is a 1000-rung
escape ladder. You’re on the first rung.

Every second, a standard (6 sided) die rolls. If it’s a 1 or 2, you
move down one rung. Anything 3 or greater, you move up one rung. If
you move down from the first rung, you fall into the fire! If you move
up from the 1000th rung, you escape.

What is the probability that you escape?

```

You should simulate a dice roll using the the standard library
function called `long int random(void)`. You should write clean code
with a function to simulate a single experimental run and return
whether or not you escaped. Your main program should repeatedly call
this function to estimate an overall escape probability.

Explain in comments exactly how your program works.

Your program should simulate this problem N=10000 times and print the
number of successes, the number of failures, and the fraction of
successes. 

When you are done with this part make sure git tracks this file. Run
following command form inside lab06 folder: ``` git add part5.c ```

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

