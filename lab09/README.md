# ECE1120 Lab 09 -- Project Part 2

*Assigned: 2016-04-14*

*Due: 2016-05-03 11:59:59 PM EST*

## Introduction

In this lab assignment, you will extend the pipeline you wrote for the
first project to include sorting and counting unique words. This
assignment is split into 3 parts, 2.1, 2.2, and 2.3.

### Assignment Part 2.1 (worth 15%):
### Implement `uniq_words`

In this part, you will implement a program to print runs of uniq
lines. (If supplied sorted lines containing one word each, it will
print a count for each unique word.)

It does this by comparing its current input line with the previous
input line. If they match, it will increment a counter. If they do not
match, the program will print the word and the current value of the
counter and reset the counter to zero.

This will accomplish roughly what the standard `uniq -c` command does.
Example:
```
>cat runs_of_words.txt 
hello
world
hello
hello
hello
world
world
>cat runs_of_words.txt | uniq -c
      1 hello
      1 world
      3 hello
      2 world
```

You should use the getline.c template from the previous Project Part 1
as a starting point.

Note that the output will be messy if you have a wide range of word
counts. Because by default, everything you print is aligned to left.
This will also cause problems when you read this output and try to
sort the numbers lexicographically. An example of such messy output
as a result of `printf("%d\t%s\n", ...)` is below:

```
2     rare
1514325234  often
2345  a_little
```

To avoid such cases you have to *pad* your integers from left. The
way to do that is to use format string in your printf. For instance
`printf("%12d\t%s\n", ...)` would use *at least* 12 characters on
console to print integer. If an integer is small, it will be padded
from the left automatically:

```
           2      rare
  1514325234      often
        2345      a_little
```


### Assignment Part 2.2 (worth 70%):
### Implement `mysort`

In this part, you will implement a program to read from standard input
and sort all of the input lines of text using an efficient mergesort
algorithm. 

This will accomplish what the standard `sort` command does when
invoked from the command line in a pipeline. For example, the file
words-10.txt contains 10 random words. When cat'd and piped to sort,
sort will sort all of the input lines. (Notice how all uppercase
letters are considered to be smaller than lowercase letters.)

```
>cat words-10.txt
tiburon
Socratic
murmurer
dyschronous
anisomelia
rulership
nephewship
consumption
perturbingly
epiplasmic
>cat words-10.txt | sort
Socratic
anisomelia
consumption
dyschronous
epiplasmic
murmurer
nephewship
perturbingly
rulership
tiburon
```

To help you, you have been given a simple program called mergesort_int
that will sort integers from a file:

```
>cat ints-10.txt 
7
28
68
96
17
60
34
78
77
99
>./mergesort_int ints-10.txt 
7
17
28
34
60
68
77
78
96
99
```

Note that this example program does *NOT* read from standard input
when invoked without an argument. Instead, it sorts an array that is
stored inside the program.

You SHOULD NOT modify mergesort_int.c to do this part. You should take
the `merge()` and `mergesort()` functions and use those in a fresh
program that you have copied from getline.c from Project Part 1. You
will have to modify the merge and mergesort functions to operate on
strings, i.e. character pointer arrays, instead of integer arrays. One
major challenge will be figuring out how to compare strings without
the less-than or greater-than operators.

### Assignment Part 2.3 (worth 15%):
### Show the operation of a full pipeline

In this part, you are required to demonstrate that all of the
components in Project Part 1 and Project Part 2 can work together.

Consider the pipeline:
```
cat pandp12.txt | tr '[A-Z]' '[a-z]' | tr -d '[:punct:]' | egrep -o '[[:alnum:]]+' | sort | uniq -c | sort
```

This produces sorted output showing the word count for each unique
word in the input text. In the Project Part 1, you implemented
programs that went right up to the sort command.

YOU MUST TEST THE OPERATION OF YOUR PIPELINE.

If any program in your pipeline is not work, you may substitute the
standard Linux command, so we can grade this Part 2.3. But you MUST
let us know which part is not working properly.

This part of the assignment is easy, you are basically required to
test your code.

## Submission Procedure
Be sure to put your name at the top of each file.

Make sure git tracks your progress on the assignment:

```
$ git add lab09/*
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

Part 1 is worth 15 points, part 2 is worth 70 points, and part is
worth 15 points.

The grading rubric is:


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

Also be sure to update the comments describing the purpose of the
program as needed.
