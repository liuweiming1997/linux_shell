#!/bin/bash

one=$1
two=$2
three=$3

function vimi() {
	if [ ! -f $one ] 
		then echo "no file ${one}, please restart it"

	elif [ ! -f $two ] 
		then 
		echo "no file ${two}"
		cat ${one}

	elif [ ! -f $three ]
		then
		echo "no file ${three}"
		touch "./mydoc.txt"

		cat $one > "./mydoc.txt"
		cat $two >> "./mydoc.txt"

	else 
		echo "???"
		cat $one > ${three}
		cat $two >> ${three}

	fi	
}

vimi

# vimi $@