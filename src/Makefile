CC=gcc
CFLAGS=-I.

hash_table: hash_table.o main.o
	$(CC) -o hash_table hash_table.o main.o

clean :
	-rm *.o $(objects) hash_table