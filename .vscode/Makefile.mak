all: tagcloud.o
	gcc tagcloud.o tagtree.c -o main

tagtree.o: tagtree.h
	gcc -c tagtree.c

run:
	./main
clean:
	rm ./obj/*.o