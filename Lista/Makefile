
APPS 			= ./apps
BIN 			= ./bin
INCLUDE			= ./include
LIB 			= ./lib
OBJ 			= ./obj
SRC 			= ./src
FLAGS 			= -Wall -std=gnu99
LIBS			= -llis -lm -L $(LIB)

all: liblis app

new: clean all run

liblis: \
	$(OBJ)/lista.o
	ar -rcs $(LIB)/liblis.a $(OBJ)/*.o

app: $(BIN)/main

$(BIN)/%: $(APPS)/%.c
	gcc $(FLAGS) $< -I $(INCLUDE) $(LIBS) -o $@

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

run:
	$(BIN)/main

clean:
	rm $(OBJ)/*
	rm $(BIN)/*
	rm $(LIB)/*
