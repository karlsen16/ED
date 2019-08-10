
APPS 			= ./apps
BIN 			= ./bin
INCLUDE		= ./include
LIB 			= ./lib
OBJ 			= ./obj
SRC 			= ./src
FLAGS 		= -Wall -std=gnu99
LIBS			= -llis2 -lm -L $(LIB)

all: liblis2 app

new: clean all run

liblis2: \
	$(OBJ)/lista2.o
	ar -rcs $(LIB)/liblis2.a $(OBJ)/*.o

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
