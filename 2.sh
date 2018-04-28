#!/bin/bash

while [ true ]
do
	echo "please enter your source"
	read a

	if [[ $a -lt 0 ]]
		then break;
	elif [[ $a -lt 60 ]]; then
		echo "Failed!"
	elif [[ $a -lt 70 ]]; then
		echo "Passed!"
	elif [[ $a -lt 80 ]]; then
		echo "Medium!"
	elif [[ $a -lt 90 ]]; then
		echo "Good!"
	elif [[ $a -lt 101 ]]; then
		echo "Excellent!"
	else
		echo "error input"
	fi
done