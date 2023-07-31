echo -ne "Enter a number: "
read num

length=${#num}

for((i=length-1; i>=0; i--))
do
rev=$rev${num:i:1}
done

if [ $rev == $num ]
then
echo "$num is a palindrome"
else 
echo "$num is not a palindrome"
fi
