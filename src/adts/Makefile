VPATH=../../include
SRC=$(wildcard *.c)
OBJ=../../obj
OBJS=$(SRC:%.c=$(OBJ)/%.o)

all: $(OBJS)

$(OBJ)/%.o: %.c i_array.h
	$(CC) $(CFLAGS) -c $< -o $@
