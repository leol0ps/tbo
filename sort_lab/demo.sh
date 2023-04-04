#!/bin/bash
IN=in
OUT=out01_c
EXE=./lab02 
for infile in ls $IN/unif_rand/*.txt; do
base=$(basename $infile)
echo $infile
$EXE "1000" < $infile
done

