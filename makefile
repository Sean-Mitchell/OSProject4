# Specify Compiler
CC=gcc

#Specify options for compiler
CFLAGS=-c -Wall

program: MemoryMethods.o
		$(CC) MemoryMethods.c -o program

MemoryMethods: MemoryMethods.c
		$(CC) $(CFLAGS) MemoryMethods.c

clean: 
		rm -rf *o program 