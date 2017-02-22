# Makefile for 01_block

CC = gcc
SRC = src
TEST_SRC = test
OUT = codecool
TEST_OUT = codecool_test
CFLAGS=-I.

# Source headers
DEPS = $(SRC)/selfprot.h
# Test headers
TEST_DEPS = $(TEST_SRC)/test_envdata.h
# Source files
FILES = $(SRC)/calculatesystemstate.o $(SRC)/chartomorse.o $(SRC)/createenvironmentdata.o $(SRC)/morsetobinary.o 
# Test files
TEST_FILES = $(TEST_SRC)/test_envdata.o


%.o: %.c $(TEST_DEPS) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all:
	echo Run

source: $(FILES) $(SRC)/main.o
	$(CC) -o $(OUT) $^ $(CFALGS)

test: $(FILES) $(TEST_FILES) $(TEST_SRC)/testmain.o
	$(CC) -o $(TEST_OUT) $^ $(CFALGS) -lcunit

clean:
	rm -f **/*.o core
	rm -f *.o core
	rm -f codecool
	rm -f codecool_test