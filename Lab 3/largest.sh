#!/bin/bash

# Program to find the largest of the given array of numbers
# echo "Enter the size of the array: "
# read n
# declare -A arr
# echo "Enter the elements of the array: " 
# for ((i=0; i<n; i++))
# do
#     read arr["$i"]
# done

# max=${arr[$i]}
# for ((i=1; i<n; i++))
# do
#     if [[ $max < ${arr[$i]} ]]
#     then 
#         max=${arr[$i]}
#     fi
# done

# echo "The largest of the given numbers is $max"

# Alternative approach
echo "Enter the number of elements in the array: "
read n
echo "Enter the elemnts of the array: "
for((i=0;i<n;i++))
do
    read element
    array+=($element)
done
largest=${array[0]}
for((i=1;i<n;i++))
do
    if [[ ${array[i]} > $largest ]] #you can use -gt instead of >
    then
        largest=${array[i]}
    fi
done
echo "The largest element in the array is: $largest" 