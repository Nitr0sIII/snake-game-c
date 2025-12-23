all: snake.o keyManagement.o gridManagement.o movementManagement.o
	
	gcc -o snake snake.o keyManagement.o gridManagement.o movementManagement.o

snake.o : ./src/snake.c 
	gcc -c ./src/snake.c

keyManagement.o : ./src/keyManagement.c
	gcc -c ./src/keyManagement.c

gridManagement.o : ./src/gridManagement.c
	gcc -c ./src/gridManagement.c

movementManagement.o:
	gcc -c ./src/movementManagement.c
clean:
	rm -f *.o snake

#make clean & make & ./snake