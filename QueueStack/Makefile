
APPS 		= ./apps
BIN 		= ./bin
INCLUDE 	= ./include
LIB 		= ./lib
OBJ 		= ./obj
SRC 		= ./src
FLAGS 		= -Wall -std=gnu99
LIBS		= -lqs -L $(LIB)

all: libqs app

libqs: \
	$(OBJ)/queue.o \
	$(OBJ)/stack.o
	ar -rcs $(LIB)/libqs.a $(OBJ)/*.o

app: 	$(BIN)/test_stack  \
	$(BIN)/test_queue

$(BIN)/%: $(APPS)/%.c
	gcc $(FLAGS) $< -I $(INCLUDE) $(LIBS) -o $@

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

stack:
	$(BIN)/test_stack
	
queue:
	$(BIN)/test_queue	

clean:
	rm $(OBJ)/*
	rm $(BIN)/*
	rm $(LIB)/*
