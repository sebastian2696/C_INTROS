#!/bin/bash

file=$1

if [ -z $file ]
then
	echo -e "Error, add filename\n"
	exit 1
fi

cat $file | ./tolower | ./strip_punt | ./wordsout | sed '/^s*$/d' | ./sort | sed '/^s*$/d' | ./unique | ./sort | sed '/^s*$/d'  | ./word_count
