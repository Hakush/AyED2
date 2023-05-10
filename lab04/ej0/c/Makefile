CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all: clean program.output

%.output: ;
	$(CC) $(CFLAGS) -c sizes.c
	$(CC) $(CFLAGS) sizes.o -o program.output

clean:
	@rm -f sizes.o
	@rm -f *.output