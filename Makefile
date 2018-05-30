CC = gcc

FLAG = -Wall -Werror -std=c99

.PHONY: clean

default: bin/chess

test: bin/chess-test

bin/chess: build/main.o build/board.o build/function.o bin
		$(CC) $(FLAG) build/main.o build/board.o build/function.o -o bin/chess

build/main.o: src/main.c src/board.h src/function.h build
		$(CC) $(FLAG) -c src/main.c -o build/main.o

build/board.o: src/board.c src/function.h src/board.h build -lm
		$(CC) $(FLAG) -c src/board.c -o build/board.o

build/function.o: src/function.c src/function.h src/board.h build
		$(CC) $(FLAG) -c src/function.c -o build/function.o

bin/chess-test: build/main_test.o build/board.o build/function.o src bin
		$(CC) $(FLAG) build/main_test.o build/board.o build/function.o -o bin/chess-test

build/main_test.o: test/main.c thirdparty/ctest.h src/board.h src/function.h build
		$(CC) $(FLAG) -I thirdparty -I src -c test/main.c -o build/main_test.o

build:
		mkdir build

bin:
		mkdir bin

clean:
		rm -rf build bin

open:
		./bin/chess-test
