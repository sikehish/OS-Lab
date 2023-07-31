#!/bin/bash

echo "Enter the number of elements in the array: "
read n
echo "Enter the elements of the array: "
for((i=0;i<n;i++))
do
    read element
    array+=($element)
done

largest=${array[0]}

for((i=1;i<n;i++))
do
if [[ $largest<${array[i]} ]]
then
largest=${array[i]}
fi
done

echo "The largest element is $largest"