# ECE1120 Lab 08 -- Project Part 1

*Assigned: 2016-01-04*

*Due: 2016-04-15 11:59:59 PM EST*

## Introduction

In Linux and other UNIX-like systems, the pipeline mechanism is a
powerful way to connect multiple programs together to accomplish a
task. 

In this lab assignment, you will learn about pipelines, and develop
your own versions of some simple tools to be used in a pipeline. This
lab constitutes the first part of your project.

### Background

Many UNIX commands, when run without arguments, process input from the
user on the terminal, and perform some processing on it, and print it
back to the terminal.

For example, the `cat` is used to concatenate the contents of several
files together, but when executed by itself, just copies its input to
its output.

You should try running the `cat` command and typing a few lines in to
see what happens. When you're done enter `Ctrl+D` to send an
end-of-file (EOF) indicator to the program.

Next try running the `wc` command. After `wc` reaches the end of a
file (either with a specified file or no arguments), it prints a count
of the lines, words, and characters in the input.


### Redirection and Pipeline

The output and input streams for programs can be redirected to and
from files.

Carefully read through this tutorial at DigitalOcean for an overview:
https://www.digitalocean.com/community/tutorials/an-introduction-to-linux-i-o-redirection
and experiment with the examples.

### Prelude: Use git to clone the Lab 6 assignment.

***Make sure you are inside your assignments folder.***

From the cloud9 command-line, use the git source code control tool to
make a copy of the starter source code for this assignment.

```
git clone https://github.com/gw-ece1120-s2016/lab08
```

You should see some output similar to this:
```
Cloning into 'lab08'...
remote: Counting objects: 4, done.
remote: Compressing objects: 100% (4/4), done.
remote: Total 4 (delta 0), reused 4 (delta 0), pack-reused 0
Unpacking objects: 100% (4/4), done.
Checking connectivity... done.
```

#### Do some house keeping before proceeding

Remove .git folder from the assignment:

```
$ rm -rf lab08/.git
```



These steps are crucial for correct submission. We are not responsible
for wrong submissions, therefore please feel free to ask TA for
clarification or confirmation.

### Assignment Part 1: Analyze `getline`

You have been provided an program that simply copies its input to its
output. It uses the relatively recent (standardized in 2008)
`getline` library function to read input lines from a file. Notice
that memory to hold each line is dynamically allocated by the C
library and must be `free`'d after use.

Inside the program, there are 12 questions in the comments. Answer all
questions for this part of the assignment. You may have to search
online, the system man pages, or in your textbook for some of the
answers to these questions.

### Assignment Part 2: Implement `tolower`

In this part, you will implement a program to read from standard input
and turn all of the uppercase letters to lowercase.

This will accomplish roughly what the standard `tr` command does when
invoked like this:

```
tr '[A-Z]' '[a-z]'
```

Example:
```
>echo 'Hello World!' | tr '[A-Z]' '[a-z]'
hello world
```

Your program should do the same when invoked in a pipeline.

Implement your program by copying `getline.c` to a file called
`tolower.c` and modifying it. Be sure to put your name at the top of
the file. Also be sure to strip out the comments containing
questions. You can implement your functionality by modifying the
`process_line` function. You may use the the `tolower()` function  in
the C library to do this. Be sure to add `#include <ctype.h>` include
directive to get the definition of this function.


### Assignment Part 3: Implement `strip_punct`

In this part, you will implement a program to read from standard
input, strip out all of the punctuation, and copy the result to
standard output.

This will accomplish roughly what the standard `tr` command does when
invoked like this:

```
>echo 'Hello! World!!' | tr -d '[:punct:]'
Hello World
```

Your program should do the same when invoked in a pipeline. Implement
your program by copying `tolower.c` to a file called `strip_punct.c`
and modifying it. For this part, you can use the `ispunct()` library
function.


### Assignment Part 4: Implement `print_words`

In this part, you will implement a program to extract every word from
standard input, and print it out, one line at a time to standard
out. For this part, assume that a word is an alphanumeric character
separated by one or more whitespace (spaces, tabs, newlines)
characters. You can use the `isalnum()` and `isspace()` C library
functions to test for these.

This will accomplish roughly what the standard `egrep` command does when
invoked like this:

```
>echo 'Hello World1234    5678' | egrep -o '[[:alnum:]]+'
Hello
World1234
5678
```

Again, implement your code by following the same template as before
and modifying it. Put your code in a file called `print_words.c`.


### Assignment Part 4: Implement `word_count`

In this part, you will implement a program to count the numbers of
words, lines, and characters in a file. You will have to significantly
modify your `process_line` function in order to do this. Specifically,
you will have to maintain state from invocation to invocation. That's
just a fancy way of saying you'll have to keep track of things across
function calls.

We recommend that you use a `struct` containing the count of words,
lines, and characters seen so far, and pass a pointer to the struct to
the `process_line` function, and update it during each invocation.

When your program is done reading the input, it should then print the
totals.

Again, implement your code by following the same template as before
and modifying it. Put your code in a file called `word_count.c`.

Example:
```
>echo 'Hello! World! Hello!' | wc
      1       3      21
```

## Submission Procedure

Make sure git tracks your progress on the assignment:

```
$ git add lab06/*
```

Commit your changes
```
$ git commit -am "Commit message"
```

Push your changes to the remote repo
```
$ git push origin master
```

## Grading Rubric

All parts 1-4 are worth 25 points each.

For parts 2-4, the rubric is:


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

Also be sure to strip out the comments containing the questions in the
example and to update the comments describing the purpose of the
program as needed.
