#!/bin/bash

echo "Enter three numbers: "
read num1 num2 num3

if [[ $num1 > $num2 ]]
then
largest=$num1
else 
largest=$num2
fi

if [[  $num3 > $largest ]]
then
largest=$num3
fi

echo "The largest number is $largest"


