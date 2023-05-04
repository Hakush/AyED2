CC=gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -g

all: clean any.output

%.output: ;
	$(CC) $(CFLAGS) -c main.c array_helpers.c weather.c weather_utils.c
	$(CC) $(CFLAGS) main.o array_helpers.o weather.o weather_utils.o -o weather.output

clean:
	@rm -f *.o
	@rm -f *.output
