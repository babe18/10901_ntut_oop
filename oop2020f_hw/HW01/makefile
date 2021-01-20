# This is the default target, which will be built when
# you invoke make
.PHONY: all
all: bin/ut_all

bin/ut_all: test/ut_main.cpp src/ConvString.cpp directories
	@echo ut_all
	g++ test/ut_main.cpp src/ConvString.cpp -o bin/ut_all -lgtest -lpthread

# This rule create the bin and obj directory if they do not exist
directories:
	mkdir -p bin obj

# This rule tells make to delete hello and hello.o
.PHONY: clean
clean:
	rm -f bin/*
	rm -f obj/*
