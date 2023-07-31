#!/bin/bash

echo "Enter the lower bound: "
read n1 
echo "Enter the upper bound: "
read n2 

echo -n "The range of prime numbers are: "

for((i=n1; i<=n2; i++))
do
    flag=0
    for((j=2; j<=i/2; j++))
    do
        if [[ $((i%j)) == 0 ]]
        then 
        flag=1
        break;
        fi
    done
if [[ $flag == 0 ]]
then
echo -ne "$i "
fi
done
echo