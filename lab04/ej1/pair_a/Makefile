CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all: clean program.output

%.output: ;
	$(CC) $(CFLAGS) -c pair.c main.c
	$(CC) $(CFLAGS) pair.o main.o -o program.output

clean:
	@rm -f pair.o
	@rm -f main.o
	@rm -f *.output