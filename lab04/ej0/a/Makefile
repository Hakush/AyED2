CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all: clean program.output

%.output: ;
	$(CC) $(CFLAGS) -c array.c
	$(CC) $(CFLAGS) array.o -o program.output

clean:
	@rm -f array.o
	@rm -f *.output