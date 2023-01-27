#!/bin/bash
input="yes"
while [[ $input = "yes" ]]
do
	read x
	read act
	read y

	case $act in
	"+") echo " $x + $y ="  $(expr $y + $x);;
	"-") echo "$x - $y ="   $(expr $x - $y);;
	"/") if [ $y -eq 0 ]; then
	       echo "error: delimiter by zero";
	     else
  	     echo " $x / $y =" $(expr  $x / $y);
 	    fi;;
	"*") echo " $x * $y =" $(expr  $x \* $y);;
	*) echo "command is unknown!"
	esac
	echo "Do you want to calculate again (yes/no):"
	read input 
done
