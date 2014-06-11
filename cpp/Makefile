SRC 	= src
AUTO 	= $(SRC)/auto
BIN 	= bin
DIRS 	= $(SRC) $(AUTO) $(BIN)

all: $(DIRS) $(BIN)/mylanga_parser

$(DIRS):
	mkdir -p $(DIRS)
	
$(AUTO)/parser.hpp $(AUTO)/parser.cpp: $(SRC)/parser.y $(SRC)/mylanga_ast.h $(SRC)/mylanga_sem_types.h
	bison -d -o $@ $<
	
$(AUTO)/tokens.cpp: $(SRC)/tokens.l $(AUTO)/parser.hpp $(SRC)/mylanga_ast.h $(SRC)/mylanga_sem_types.h
	lex -o $@ $<

$(BIN)/mylanga_parser: $(AUTO)/parser.cpp $(AUTO)/tokens.cpp $(SRC)/mylanga_ast.cpp $(SRC)/main.cpp
	g++ -std=c++11 -I$(SRC) -I$(AUTO) -o $@ $^

.PHONY: clean wipe

clean:
	rm -f $(AUTO)/*

wipe:
	rm -rf $(AUTO)
	rm -rf $(BIN)