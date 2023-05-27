CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all: clean program.output

%.output: ;
	$(CC) $(CFLAGS) -c clone.c
	$(CC) $(CFLAGS) clone.o -o program.output

clean:
	@rm -f clone.o
	@rm -f *.output
