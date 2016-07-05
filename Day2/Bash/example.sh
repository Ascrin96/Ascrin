#!/bin/bash 

echo Enter number\n

n=0
i=0
read a
n=a
echo You entered $(a)
mas[]

while[ n!=1 ] do 
	mas[i]=n%2
	n=n/2
	i=i++
done

echo Enter:\"left\" or \"right\"

read position

echo Enter value

read value

if [[ position == "letf" ]]
then 
	for[[ i=0; i<value; i++ ]] do
			
	done

fi
