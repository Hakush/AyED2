CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all: clean program.output

%.output: ;
	$(CC) $(CFLAGS) -c string.c   
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) string.o main.o -o program.output

clean:
	@rm -f string.o
	@rm -f main.o
	@rm -f *.output