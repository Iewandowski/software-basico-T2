all: tagcloud.o
	gcc tagcloud.o tagcloud.c -o main

tagcloud.o: tagcloud.h
	gcc -c tagcloud.c

clean:
	rm ./obj/*.o