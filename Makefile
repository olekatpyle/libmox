

CC=gcc
CFLAGS=-g -Wall -Wextra -Werror -O0 -lc

INCDIR=/usr/include/libmox
LIBDIR=/lib
LIB=lib
SRC=src
OBJ=obj

# match source files in /src
SRCS=$(wildcard $(SRC)/*.c)

# match all object files build on all source files at top level /src.
# currently this only builds util.o.
OBJS=$(SRCS:$(SRC)/%.c=$(OBJ)/%.o)

# match all object files in obj/
OF=$(wildcard $(OBJ)/*.o)

all: clean
all: $(OBJ) $(LIB) $(OBJS) sub $(LIB)/libmox.so $(LIB)/libmox.a

# targets for directories
$(OBJ):
	mkdir $@

$(LIB):
	mkdir $@

# target to build utils
$(OBJ)/%.o: $(SRC)/%.c $(SRC)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

# recurse build step into src subdirectories where the corresponding makefile
# is being called
sub:
	$(MAKE) -C src/adts
	$(MAKE) -C src/math
	$(MAKE) -C src/search
	$(MAKE) -C src/sort

# build shared object libmox.so
$(LIB)/libmox.so: $(OF)
	$(RM) $(LIB)/libmox.so
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $(OF)

# build static archive libmox.a
$(LIB)/libmox.a: $(OF)
	ar -cvrs $@ $(OF)


#-----------------------------------------------------#
# 				  Targets for tests   				  #
#-----------------------------------------------------#
test:
	$(MAKE) test -C tests

perf:
	$(MAKE) perf


# Installation targets
install:
	rm -rf $(INCDIR)
	mkdir $(INCDIR)
	cp include/* $(INCDIR)
	cp $(LIB)/libmox.so $(LIBDIR)

uninstall:
	rm -rf $(INCDIR)
	rm $(LIBDIR)/libmox.so

# delete build artifacts
clean:
	$(RM) -rf $(LIB) $(OBJ) tests/bin
