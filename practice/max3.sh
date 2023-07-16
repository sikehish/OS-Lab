echo "Enter the three numbers: "
read num1 num2 num3

largest=$num1

if [[ $num1 -lt $num2 ]]
then
    largest=$num2
fi

if [[ $largest -lt $num3 ]]
then
    largest=$num3
fi

echo "The number $largest is the greatest of the given three numbers"