CXX=g++
CPPFLAGS=-std=c++11 -Wfatal-errors -Wall
LDFLAGS=-lgtest -lpthread

ODIR=obj
SRC=src/*.h
TEST=test/*.h

.PHONY: dirs clean test

all: dirs ut_all

ut_all: $(SRC) $(TEST)
	$(CXX) $(CPPFLAGS) test/ut_main.cpp -o bin/ut_all $(LDFLAGS)

dirs:
	mkdir -p bin
	mkdir -p obj

test: dirs ut_main
	./bin/ut_main

clean:
	rm -f bin/* obj/*
