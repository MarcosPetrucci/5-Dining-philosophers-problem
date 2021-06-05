#Makefile criado pelo Dois para compilar programas de SO
CC = gcc 		#C Compiler

LIBS = -pthread -Wall

FILES = *.o

#%.o: *.c
#	$(CC) -o $@ $< $(LIBS)

.PHONY: prog1
all: *.c
	$(CC) -o prog.out $^ $(LIBS)

.PHONY: run
run:
	./prog.out

.PHONY: clean
clean:
	rm -rf *.out *.o
