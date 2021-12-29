.PHONY: directories clean stat

all: directories ut

CFLAGS = -std=c++11 -Wfatal-errors
HEADERS = test/ut_term.h
TESTS = src/term.h

ut: test/ut_main.cpp $(HEADERS) $(TESTS)
	g++ $(CFLAGS) test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean: directories
	rm -rf bin

stat:
	wc src/* test/*
