CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all: clean program.output

%.output: ;
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) -c helpers.c 
	$(CC) $(CFLAGS) -c sort.c
	$(CC) $(CFLAGS) main.o helpers.o sort.o -o program.output

clean:
	@rm -f main.o
	@rm -f helpers.o
	@rm -f sort.o
	@rm -f *.output
	@rm -f *.out
