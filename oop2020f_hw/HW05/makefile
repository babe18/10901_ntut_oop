.PHONY: dirs clean run
CC = g++
SRC = ./src
BIN = ./bin
TEST = ./test
CFLAG = -std=c++11 -Wfatal-errors
LIB = -lgtest -lpthread

all: dirs $(BIN)/ut_all

$(BIN)/ut_all: $(TEST)/ut_main.cpp $(TEST)/*.h $(SRC)/*.h
	$(CC) $(CFLAG) -o $@ $< $(LIB)

dirs:
	mkdir -p $(BIN)

.PHONY: clean
clean:
	rm -f bin/*
	rm -f obj/*
