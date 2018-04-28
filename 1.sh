#!/bin/bash

# how to translate character from uppercase to lowercase
function PWD() {
        pwd
}

function getFileName() {
        echo $(basename $0)
      #  echo $(dirname $0)
}

function getDate() {
        date "+%Y_%m_%d %H:%M:%S"    
}

function getLS() {
        ls
}

function getConn() {
        who
}

while true
do
        echo "Enter your option and hit:"
        read cmd
        val=$(echo "$cmd" | awk '{print tolower($cmd)}')     
        echo $val       
		case "${val}" in
				p)
                PWD
                ;;

                s)
                getFileName
                ;;

                d)
                getDate
                ;;

                l)
                getLS
                ;;

                w)
                getConn
                ;;

                q)
                exit 1
        esac
done