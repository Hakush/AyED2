CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all: clean program.output

%.output: ;
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) -c store.c 
	$(CC) $(CFLAGS) -c array_helpers.c
	$(CC) $(CFLAGS) main.o array_helpers.o store.o -o program.output

clean:
	@rm -f main.o
	@rm -f array_helpers.o
	@rm -f store.o
	@rm -f *.output
	@rm -f *.out
