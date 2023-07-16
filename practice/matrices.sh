#!/bin/bash

matrix1=()
matrix2=()

read -p "Enter the number of rows: " rows
read -p "Enter the number of cols: " cols

echo "Enter the first matrix"
for((i=0; i<rows; i++))
do
  for((j=0; j<cols; j++))
  do
   read ele
    matrix1+=($ele)
  done
done

echo

echo "Enter the second matrix"
for((i=0; i<rows; i++))
do
  for((j=0; j<cols; j++))
  do
    read ele
    matrix2+=($ele)
  done
done

echo "First matrix is"
for((i=0; i<rows; i++))
do
  for((j=0; j<cols; j++))
  do
   index=$((i*cols+j))
   echo -n "${matrix1[index]} "
  done
  echo 
done

echo

echo "Second matrix is"
for((i=0; i<rows; i++))
do
  for((j=0; j<cols; j++))
  do
   index=$((i*cols+j))
   echo -n "${matrix2[index]} "
  done
  echo 
done


matrix3=()
for((i=0; i<rows*cols; i++))
do
    matrix3+=($((${matrix1[i]} + ${matrix2[i]})))
done

echo "Addition of two matrix"
for((i=0; i<rows; i++))
do
  for((j=0; j<cols; j++))
  do
    index=$((i*cols+j))
    echo -n "${matrix3[index]} "
  done
  echo
done