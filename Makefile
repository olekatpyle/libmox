

CC=gcc
CFLAGS=-g -Wall -Wextra -Werror

USRDIR=/usr/include/libmox
SRC=src
INCL=include
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o,$(SRCS))

# dtst
DTST=$(SRC)/dtst
DTSRC=$(wildcard $(DTST)/*.c)
DTOBJ=$(patsubst $(DTST)/%.c,$(OBJ)/%.o,$(DTSRC))

# search
SEARCH=$(SRC)/search
SRSRC=$(wildcard $(SEARCH)/*.c)
SROBJ=$(patsubst $(SEARCH)/%.c,$(OBJ)/%.o,$(SRSRC))

# sort
SORT=$(SRC)/sort
SOSRC=$(wildcard $(SORT)/*.c)
SOOBJ=$(patsubst $(SORT)/%.c,$(OBJ)/%.o,$(SOSRC))

# math
MATH=$(SRC)/math
MSRC=$(wildcard $(MATH)/*.c)
MOBJ=$(patsubst $(MATH)/%.c,$(OBJ)/%.o,$(MSRC))

# tests
TEST=tests
TESTS=$(wildcard $(TEST)/t_*.c)
TESTBINS=$(patsubst $(TEST)/%.c, $(TEST)/bin/%, $(TESTS))


LIBDIR=lib
LIB=$(LIBDIR)/libmox.so
STATIC_LIB=$(LIBDIR)/libmox.a

all: clean $(LIB) $(STATIC_LIB) test

release: CFLAGS=-Wall -O2 -DNDEBUG
release: clean
release: $(LIB) $(STATIC_LIB)

# libadd.so: add.c add.h
# 	$(CC) $(CFLAGS) -fPIC -shared -o $@ add.c -lc
$(LIB): $(LIBDIR) $(OBJ) $(OBJS) $(SROBJ) $(SOOBJ) $(MOBJ) $(DTOBJ) perftest
	$(RM) $(LIB)
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $(OBJS) $(SROBJ) $(SOOBJ) $(MOBJ) $(DTOBJ) -lc

$(STATIC_LIB): $(LIBDIR) $(OBJ) $(OBJS) $(SROBJ) $(SOOBJ) $(MOBJ) $(DTOBJ)
	ar -cvrs $(STATIC_LIB) $(OBJS)

$(OBJ)/%.o: $(SRC)/%.c $(INCL)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: $(SEARCH)/%.c $(INCL)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: $(DTST)/%.c $(INCL)/%.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OBJ)/%.o: $(SORT)/%.c $(INCL)/sort.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: $(MATH)/%.c $(INCL)/mmath.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.c $(SRC)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST)/bin/%: $(TEST)/%.c
	$(CC) $(CFLAGS) $< $(OBJS) $(SROBJ) $(MOBJ) $(SOOBJ) $(DTOBJ) -o $@ -lcriterion

perftest: $(TEST)/perftest.c $(OBJ)/i_array.o $(SOOBJ)
	$(CC) $(CFLAGS) $< $(OBJ)/i_array.o $(SOOBJ) -o ./$(TEST)/perftest

$(TEST)/bin:
	mkdir $@

$(OBJ):
	mkdir $@

$(LIBDIR):
	mkdir $@

test: $(LIB) $(TEST)/bin $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test --verbose; done


perf:
	rm ./tests/perftest
	make perftest
	./tests/perftest $(LOOPS)

install:
	rm -rf $(USRDIR)
	mkdir $(USRDIR)
	cp -r $(INCL)/* $(USRDIR)
	cp $(LIB) /lib

clean:
	$(RM) -r $(LIBDIR) $(OBJ) $(TEST)/bin $(TEST)/perftest compile_commands.json .cache
