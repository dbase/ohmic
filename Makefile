CC	?= gcc
SRC	= ohmic.c test.c
DEPS	= ohmic.h
CFLAGS	= -Wall -pedantic -std=c99 -g -O0
LFLAGS	=

test: $(SRC) $(DEPS)
	$(CC) $(CFLAGS) $(SRC) $(LFLAGS) -o test
