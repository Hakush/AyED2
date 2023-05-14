CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all: clean program.output

%.output: ;
	$(CC) $(CFLAGS) -c array_helpers.c
	$(CC) $(CFLAGS) -c list.c   
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) array_helpers.o list.o main.o -o program.output

clean:
	@rm -f array_helpers.o
	@rm -f list.o
	@rm -f main.o
	@rm -f *.output