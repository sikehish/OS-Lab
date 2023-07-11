#!/bin/bash
echo "Enter the two strings to be concatenated: "
read str1
read str2
res="$str1 $str2"  #Spaces are not considered, therefore use underscore to denote space
echo "The resultant string is: "
echo $res