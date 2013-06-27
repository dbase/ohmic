CC	?= gcc

SRC_DIR	= src
SRC	= $(SRC_DIR)/ohmic.c
DEPS	= $(SRC_DIR)/ohmic.h

TEST_DIR= test
TEST	= $(TEST_DIR)/test.c

ERRORS	= -Wall -Wextra -Werror -pedantic -std=c99
CFLAGS	= $(ERRORS) -g -O0 -I$(SRC_DIR)/
LFLAGS	=

test: $(SRC) $(DEPS) $(TEST)
	$(CC) $(CFLAGS) $(SRC) $(TEST) $(LFLAGS) -o ohm-test
