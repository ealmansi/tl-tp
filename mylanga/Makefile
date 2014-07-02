SRC 	= src
AUTO 	= $(SRC)/auto
OBJ 	= obj
BIN 	= bin
OUTPUT_DIRS 	= $(OBJ) $(AUTO) $(BIN)
CXXFLAGS 	= -std=c++0x -I$(SRC) -I$(AUTO)

all: $(OUTPUT_DIRS) $(BIN)/mylanga_parser

$(OUTPUT_DIRS):
	mkdir -p $(OUTPUT_DIRS)
	
$(AUTO)/parser.hpp $(AUTO)/parser.cpp: $(SRC)/parser.y
	bison -d -o $@ $<
	
$(AUTO)/tokens.cpp: $(SRC)/tokens.l
	lex -o $@ $<

$(OBJ)/parser.o: $(AUTO)/parser.cpp $(SRC)/mylanga_fp_t.h $(SRC)/mylanga_ast.h $(SRC)/mylanga_sem_types.h $(SRC)/mylanga_error.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)/tokens.o: $(AUTO)/tokens.cpp $(SRC)/mylanga_ast.h $(SRC)/mylanga_sem_types.h $(SRC)/mylanga_error.h $(AUTO)/parser.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)/mylanga_fp_t.o: $(SRC)/mylanga_fp_t.cpp $(SRC)/mylanga_fp_t.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ)/mylanga_ast.o: $(SRC)/mylanga_ast.cpp $(SRC)/mylanga_fp_t.h $(SRC)/mylanga_ast.h $(SRC)/mylanga_sem_types.h $(SRC)/mylanga_error.h $(AUTO)/parser.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN)/mylanga_parser: $(SRC)/main.cpp $(OBJ)/parser.o $(OBJ)/tokens.o $(OBJ)/mylanga_fp_t.o $(OBJ)/mylanga_ast.o
	$(CXX) $(CXXFLAGS) $^ -o $@;
	cp $(BIN)/mylanga_parser ..

.PHONY: clean wipe

clean:
	rm -f $(OBJ)/*
	rm -f $(AUTO)/*

wipe:
	rm -rf $(OUTPUT_DIRS)