CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all: clean program.output

%.output: ;
	$(CC) $(CFLAGS) -c balanced.c
	$(CC) $(CFLAGS) -c helpers/stack.c 
	$(CC) $(CFLAGS) balanced.o stack.o -o program.output

clean:
	@rm -f balanced.o
	@rm -f stack.o
	@rm -f *.output
	@rm -f *.out
