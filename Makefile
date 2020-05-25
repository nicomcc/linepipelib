output: main.o linepipelib.o
	gcc main.o linepipelib.o -o output

main.o: main.c
	gcc -c main.c

linepipelib.o: linepipelib.c linepipelib.h
	gcc -c linepipelib.c

clean:
	rm *.o output