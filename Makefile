CC	?= gcc
SRC	= ohmic.c test.c
DEPS	= ohmic.h
CLFAGS	= -Wall -pedantic -ansi -g -O0
LFLAGS	=

test: $(SRC) $(DEPS)
	$(CC) $(CFLAGS) $(SRC) $(LFLAGS) -o test
