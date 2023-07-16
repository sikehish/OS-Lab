#!/bin/bash

echo "Enter the low bound"
read a
echo "Enter the upper bound"
read b

echo "The prime numbers are: "
for (( i=a; i<=b; i++ ))
do
flag=0
for(( j=2; j<=$i/2; j++ ))
do
if [ $((i%j)) == 0 ] 
then 
flag=1
fi
done
if [ $flag == 0 ] 
then
echo -ne "$i "
fi
done