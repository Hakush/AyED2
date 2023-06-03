CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all: clean program.output

%.output: ;
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) -c truco.c 
	$(CC) $(CFLAGS) main.o truco.o -o program.output

clean:
	@rm -f main.o
	@rm -f truco.o
	@rm -f *.output
	@rm -f *.out
