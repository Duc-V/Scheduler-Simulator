.DEFAULT: all

CC = g++
CFLAGS = -Wall -Werror -std=c++20 -g -O

all: fifo sjf rr

fifo: FF/main.o FF/fifo.o loader.o pcb.o
	$(CC) $(CFLAGS) -O -o $@ $^

sjf: SHJF/main.o SHJF/sjf.o loader.o pcb.o
	$(CC) $(CFLAGS) -O -o $@ $^

rr: ROR/main.o ROR/rr.o loader.o pcb.o
	$(CC) $(CFLAGS) -O -o $@ $^

clean:
	rm -f fifo sjf rr FF/main.o FF/fifo.o SHJF/main.o SHJF/sjf.o loader.o pcb.o ROR/main.o ROR/rr.o loader.o pcb.o