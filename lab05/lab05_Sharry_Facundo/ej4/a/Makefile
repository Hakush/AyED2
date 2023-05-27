CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all: clean program.output

%.output: ;
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) -c strfuncs.c 
	$(CC) $(CFLAGS) main.o strfuncs.o -o program.output

clean:
	@rm -f main.o
	@rm -f strfuncs.o
	@rm -f *.output
