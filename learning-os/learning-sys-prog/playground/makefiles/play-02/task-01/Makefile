ifndef CC
	CC=gcc
endif
CFLAGS=-std=c99 -Werror -Wall -Wpedantic -Wextra
SRCS=main.c
OBJS=$(subst .c,.o,$(SRCS))
RM=rm -f

all: main

main: main.o

main.o: main.c

clean:
    rm -f main main.o
		
run: main
    ./main
