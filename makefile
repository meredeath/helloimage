all: picmaker.o
	gcc picmaker.o -o test
picmaker.o: picmaker.c
	gcc -c picmaker.c
run: all
	./test
	display tuhua.ppm
