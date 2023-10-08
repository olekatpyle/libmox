# Makefile src/sort

VPATH=../../include
SRC=$(wildcard *.c)
OBJ=../../obj
OBJS=$(SRC:%.c=$(OBJ)/%.o)

all: $(OBJS)

$(OBJ)/%.o: %.c sort.h
	$(CC) $(CFLAGS) -c $< -o $@
