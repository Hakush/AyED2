CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all: clean program.output

%.output: ;
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) -c array_helpers.c 
	$(CC) $(CFLAGS) -c bakery_product.c
	$(CC) $(CFLAGS) main.o array_helpers.o bakery_product.o -o program.output

clean:
	@rm -f main.o
	@rm -f array_helpers.o
	@rm -f bakery_product.o
	@rm -f *.output
	@rm -f *.out
