# Makefile src/search

VPATH=../../include
SRC=$(wildcard *.c)
OBJ=../../obj
OBJS=$(SRC:%.c=$(OBJ)/%.o)

all: $(OBJS)

$(OBJ)/%.o: %.c search.h
	$(CC) $(CFLAGS) -c $< -o $@
