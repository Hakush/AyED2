CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all: clean program.output

%.output: ;
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) -c queue.c 
	$(CC) $(CFLAGS) -c queue_helpers.c
	$(CC) $(CFLAGS) main.o queue.o queue_helpers.o -o program.output

clean:
	@rm -f main.o
	@rm -f queue.o
	@rm -f queue_helpers.o
	@rm -f *.output
	@rm -f *.out
