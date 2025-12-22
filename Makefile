all: snake.o keyManagement.o
	gcc -o snake snake.o keyManagement.o

snake.o : ./src/snake.c 
	gcc -c ./src/snake.c

keyManagement.o : ./src/keyManagement.c
	gcc -c ./src/keyManagement.c

clean:
	rm -f *.o snake