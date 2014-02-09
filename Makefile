all: main.o clist.o
	gcc main.o clist.o -o clist

main: main.c
	gcc -c main.c -o main.o
clist: clist.c
	gcc -c clist.c -o clist.o

clean:
	rm main.o clist.o clist
