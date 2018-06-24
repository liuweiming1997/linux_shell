main:function/mytool1.o function/mytool2.o main.o
	gcc function/mytool1.o function/mytool2.o main.o -o main

main.o:main.c
	gcc -c main.c -o main.o -Ifunction

mytool1.o:function/mytool1.c
	gcc -c function/mytool1.c -o function/mytool1.o

mytool2.o:function/mytool2.c 
	gcc -c function/mytool2.c -o function/mytool2.o
