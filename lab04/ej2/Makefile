CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all: clean program.output

%.output: ;
	$(CC) $(CFLAGS) -c counter.c 
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) counter.o main.o -o program.output

clean:
	@rm -f counter.o
	@rm -f main.o
	@rm -f *.output