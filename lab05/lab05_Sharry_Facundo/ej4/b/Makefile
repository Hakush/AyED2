CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all: clean program.output

%.output: ;
	$(CC) $(CFLAGS) -c readstr.c
	$(CC) $(CFLAGS) readstr.o -o program.output

clean:
	@rm -f readstr.o
	@rm -f *.output
