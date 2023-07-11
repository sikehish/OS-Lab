#!/bin/bash
# Program to demonstrate the arithmetic operations using case
until [[ $choice == 6 ]] 
do 
    echo "Enter the two numbers on which the arithmetic operations are to be done: "
    read num1 num2
    echo "Enter the operation to be performed: "
    echo "1) Addition"
    echo "2) Subtraction"
    echo "3) Multiplication"
    echo "4) Division"
    echo "5) Modulo (Remainder)"
    echo "6) Exit"
    read choice 
    case "${choice}" in

        1)res=$((num1+num2))
           echo "The result is $res";;

        2)res=$((num1-num2))
            echo "The result is $res";;

        3)res=$((num1*num2))
            echo "The result is $res";;

        4)if [[ $num2 == 0 ]]
            then
                echo "Cannot divide by 0"
                flag=1
            else 
                res=$((num1/num2))
                echo "The result is $res"
            fi;;

        5) res=$((num1%num2))
            echo "The result is $res";;
            
        6)echo "Thank you"
            #  break;;
            ;;

        *)echo "Wrong Operation chosen, enter again";;
    esac

    echo "  "
done 