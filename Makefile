CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/Client.cpp $(SRC)/Media.cpp $(SRC)/DVDCategory.cpp $(SRC)/DVD.cpp $(SRC)/VideoTape.cpp $(SRC)/Extinguisher.cpp $(SRC)/Rent.cpp $(SRC)/Store.cpp $(SRC)/IoOperations.cpp $(SRC)/main.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
