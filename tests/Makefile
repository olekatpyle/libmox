# Makefile tests

OBJ=../obj
OBJS=$(wildcard ../obj/*.o)
BIN=bin
TESTS=$(wildcard t_*.c)
TESTBINS=$(TESTS:%.c=$(BIN)/%)

test: $(BIN) $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test --verbose; done

perf:
	make perftest
	bin/perftest $(LOOPS)

# Used by target perf
perftest: perftest.c
	$(CC) $(CFLAGS) $< $(OBJ)/i_array.o  $(OBJ)/bubblesort.o $(OBJ)/insertsort.o \
	$(OBJ)/mergesort.o $(OBJ)/quicksort.o $(OBJ)/selectsort.o -o $(BIN)/perftest

$(BIN):
	mkdir $@

$(BIN)/%: %.c
	$(CC) $(CFLAGS) $< $(OBJS) -o $@ -lcriterion
