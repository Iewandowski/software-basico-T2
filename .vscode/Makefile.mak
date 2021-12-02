all: tagcloud.o
	gcc tagcloud.o main.c -o main

tagtree.o: tagtree.c
	gcc -c tagtree.c

run:
	./main
clean:
	rm ./obj/*.o