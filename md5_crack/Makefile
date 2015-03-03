CC=gcc
CFLAGS=-O3 -Wall -march=native

.PHONY: all clean
all: test test2


test2: test2.c
	$(CC) $(CFLAGS) -lssl -lcrypto -o $@ $<

clean:
	rm -f test test2
