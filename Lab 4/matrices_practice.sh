#!/bin/bash

matrix1=()
matrix2=()

echo "Enter the number of rows and columns"
read rows cols

echo "Enter matrix 1: "
for((i=0; i<rows; i++))
do
for((j=0; j<cols; j++))
do
read element
matrix1+=($element)
done 
done

echo "Enter matrix 2: "
for((i=0; i<rows; i++))
do
for((j=0; j<cols; j++))
do
read element
matrix2+=($element)
done 
done


echo "Matrix 1:"
for((i=0; i<rows; i++))
do
for((j=0; j<cols; j++))
do
index=$((i*cols+j))
echo -ne "${matrix1[index]} "
done 
echo
done


echo "Matrix 2:"
for((i=0; i<rows; i++))
do
for((j=0; j<cols; j++))
do
index=$((i*cols+j))
echo -ne "${matrix2[index]} "
done 
echo
done

echo -e "Addition of 2 matrices: \nMatrix 3: "
matrix3=()
for((i=0; i<rows; i++))
do
for((j=0; j<cols; j++))
do
index=$((i*cols+j))
matrix3+=($((${matrix1[index]} + ${matrix2[index]})))
echo -ne "${matrix3[index]} "
done 
echo
done