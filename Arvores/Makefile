
APPS 		= ./apps
BIN 		= ./bin
INCLUDE 	= ./include
LIB 		= ./lib
OBJ 		= ./obj
SRC 		= ./src
FLAGS 		= -Wall -std=gnu99
LIBS		= -larv -L $(LIB)

all: libarv app

libarv: \
	$(OBJ)/arvore.o \
	$(OBJ)/exercicios.o  
	ar -rcs $(LIB)/libarv.a $(OBJ)/*.o

app: 	$(BIN)/test_arvore

$(BIN)/%: $(APPS)/%.c
	gcc $(FLAGS) $< -I $(INCLUDE) $(LIBS) -o $@

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

run:
	$(BIN)/test_arvore

clean:
	rm $(OBJ)/*
	rm $(BIN)/*
	rm $(LIB)/*
