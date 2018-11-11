main:function/mytool1.o function/mytool2.o main.o
	g++ function/mytool1.o function/mytool2.o main.o -o main

main.o:main.cpp
	g++ -c main.cpp -o main.o -Ifunction

mytool1.o:function/mytool1.pp
	g++ -c function/mytool1.cpp -o function/mytool1.o

mytool2.o:function/mytool2.pp 
	g++ -c function/mytool2.cpp -o function/mytool2.o

clean:
	rm -rf function/mytool1.o
	rm -rf function/mytool2.o
	rm -rf main.o
	rm -rf main