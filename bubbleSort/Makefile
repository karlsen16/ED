
CC				= gcc
BIN 			= ./bin
INC				= ./include
OBJ 			= ./obj
SRC 			= ./src
CFLAGS 		= -c -Wall
LFLAGS 		= -Wall
MAIN			= Main
DEFN			= stdafx BubbleSort
MODS			= $(MAIN) $(DEFN)
EXEC			= $(BIN)/$(MAIN)
SRCS			= $(addsuffix .c, $(addprefix $(SRC)/,$(MODS)))
OBJS			= $(addsuffix .o, $(addprefix $(OBJ)/,$(MODS)))
HEAD			= $(addsuffix .h, $(addprefix $(INC)/,$(DEFN)))

all: $(OBJS) $(EXEC)

new: clean all run

neu: all run

$(OBJ)/%.o:	$(SRC)/%.c $(HEAD)
	$(CC) $(CFLAGS) $< -I$(INC) -o $@

$(EXEC): $(OBJS)
	$(CC) $(LFLAGS) $^ -o $@

run:
	$(EXEC)

clean:
	rm $(OBJ)/*
	rm $(EXEC)
