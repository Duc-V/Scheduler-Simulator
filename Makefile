.DEFAULT: all

CC = g++
CFLAGS = -Wall -Werror -std=c++20 -g -O

all: fifo sjf rr

fifo: Fifo/main.o Fifo/fifo.o loader.o pcb.o
	$(CC) $(CFLAGS) -O -o $@ $^

sjf: Sjf/main.o Sjf/sjf.o loader.o pcb.o
	$(CC) $(CFLAGS) -O -o $@ $^

rr: Rr/main.o Rr/rr.o loader.o pcb.o
	$(CC) $(CFLAGS) -O -o $@ $^

clean:
	rm -f fifo sjf rr Fifo/main.o Fifo/fifo.o Sjf/main.o Sjf/sjf.o loader.o pcb.o Rr/main.o Rr/rr.o loader.o pcb.o