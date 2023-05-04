CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all: clean reader.output

%.output: ;
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) main.o -o main.output

clean:
	@rm -f *.o
	@rm -f *.output
