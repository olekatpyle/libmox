# Makefile src/math

VPATH=../../include
SRC=$(wildcard *.c)
OBJ=../../obj
OBJS=$(SRC:%.c=$(OBJ)/%.o)

all: $(OBJS)

$(OBJ)/%.o: %.c math.h
	$(CC) $(CFLAGS) -c $< -o $@
