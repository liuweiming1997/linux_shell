
build:
	gcc main.cpp -o main `pkg-config gtk+-2.0 --cflags --libs`

deploy:
	rsync -avz --delete ../cpp root@95.163.202.160:/root