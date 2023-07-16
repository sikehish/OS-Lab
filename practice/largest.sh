#!/bin/bash

echo "Enter the length of the array"
read n

echo "Enter the elements of the array"
for (( i=0; i<n; i++))
do
read ele;
array+=($ele)
done

largest=${array[0]}
for (( i=1; i<n; i++ ))
do
if [ ${array[i]} -gt $largest ]
then 
largest=${array[i]}
fi
done

echo "The largest element is $largest"
