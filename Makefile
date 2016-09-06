max: main.o
	g++ $(CFLAGS) -o  max main.o -lpthread -pthread
main.o: main.c
	gcc $(CFLAGS) -c main.c
clean: 
	rm -f *.o max