#!/bin/bash

echo "Enter a number:"
read num
length=${#num}

for((i=$length-1; i>=0; i--))
do
reverse=$reverse${num:$i:1}
done

if [ $reverse == $num ]
then
echo "$num is a palindrome"
else 
echo "$num is not a palindrome"
fi