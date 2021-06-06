#Makefile criado pelo Dois para compilar programas de SO
CC = gcc 		#C Compiler

LIBS = -pthread -Wall

DEPS = *.h

OBJ = monitor.o programa.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(LIBS)

prog: $(OBJ)
	$(CC) -o prog.out $^ $(LIBS)

.PHONY: run
run:
	./prog.out

.PHONY: clean
clean:
	rm -rf *.out *.o
