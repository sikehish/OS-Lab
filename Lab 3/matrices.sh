#!/bin/bash 
# Program to read two matrices and compute their sums

echo "Enter the order of the first matrix: "
read row1 col1
echo "Enter the ordder of the second matrix: "
read row2 col2
declare -A mat1
declare -A mat2
declare -A mat3

if [[ $col1 == "$col2" && $row1 == "$row2" ]]
then
    echo "Enter the first matrix: "
    for ((i=0; i<row1; i++))
    do
        for ((j=0; j<col1; j++))
        do
            read mat1[$((i*col1+j))]
            mat3[$((i*col1+j))]=${mat1[$((i*col1+j))]}
        done
    done

    echo "Enter the second matrix: "
    for ((i=0; i<row1; i++))
    do
        for ((j=0; j<col1; j++))
        do
            read mat2[$((i*col1+j))]
            mat3[$((i*col1+j))]=$((${mat3[$((i*col1+j))]}+${mat2[$((i*col1+j))]}))
        done
    done

    echo "The resultant matrix is: "
    for ((i=0; i<row1; i++))
    do
        for ((j=0; j<col1; j++))
        do
            echo -ne "${mat3[$((i*col1+j))]} "
        done
        echo
    done
fi

# //Alternative approach:
# #!/bin/bash

# # https://drive.google.com/drive/u/0/folders/1vfQtxgCqEvwC1PHi4s1QVQKnYhI44xwO
# # https://drive.google.com/file/d/1kksqpGT_YBQsFwsyVyftikPRP-sZZF-e/view

# matrix1=()
# matrix2=()

# read -p "Enter the number of rows: " rows
# read -p "Enter the number of cols: " cols

# echo "Enter the first matrix"
# for((i=0; i<rows; i++))
# do
#   for((j=0; j<cols; j++))
#   do
#    read ele
#     matrix1+=($ele)
#   done
# done

# echo

# echo "Enter the second matrix"
# for((i=0; i<rows; i++))
# do
#   for((j=0; j<cols; j++))
#   do
#     read ele
#     matrix2+=($ele)
#   done
# done

# echo

# echo "First matrix"
# for((i=0; i<rows; i++))
# do
#   for((j=0; j<cols; j++))
#   do
#     index=$((i*cols+j))
#     echo -n "${matrix1[index]} "
#   done
#   echo
# done

# echo "Second matrix"
# for((i=0; i<rows; i++))
# do
#   for((j=0; j<cols; j++))
#   do
#     index=$((i*cols+j))
#     echo -n "${matrix2[index]} "
#   done
#   echo
# done

# k=0
# matrix3=()
# for((i=0; i<rows; i++))
# do
#   for((j=0; j<cols; j++))
#   do
#     index=$((i*cols+j))
#     matrix3[k]=$((${matrix1[index]} + ${matrix2[index]}))
#     k=$((k+1))
#   done
# done

# echo "Addition of two matrix"
# for((i=0; i<rows; i++))
# do
#   for((j=0; j<cols; j++))
#   do
#     index=$((i*cols+j))
#     echo -n "${matrix3[index]} "
#   done
#   echo
# done