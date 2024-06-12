#!/bin/bash
CC=gcc -Wall -Werror -Wextra -std=c11 -g
SRC=functions/*.c
OBJ=build/*.o
TSRC=tests/*.c
NAME=s21_matrix
LIB_NAME=$(NAME).a
UNAME=$(shell uname -s)
HEADERS=$(NAME).h tests/$(NAME)_tests.h

ifeq ($(UNAME),Linux)
	LIBS=-lm -lrt -lpthread -lcheck -lsubunit
endif

ifeq ($(UNAME),Darwin)
	LIBS=-lcheck
endif

all: $(LIB_NAME)

clean:
	rm -rf build/* $(LIB_NAME)

rebuild: clean all

cf:
	clang-format --style=Google -i $(SRC) $(TSRC) $(HEADERS)

check:
	clang-format --style=Google -n $(SRC) $(TSRC) $(HEADERS)

cppc:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SRC) $(TSRC) $(HEADERS)

$(LIB_NAME): $(SRC)
	$(CC) -c $(SRC)
	mv *.o build
	ar rcs $(LIB_NAME) $(OBJ)

test: clean $(SRC) $(TSRC)
	$(CC) $(SRC) $(TSRC) -o build/$(NAME) $(LIBS) -lm
	build/$(NAME)

gcov_report: clean $(SRC) $(TSRC)
	$(CC) $(SRC) $(TSRC) --coverage $(LIBS) -o build/$(NAME)_tests -lm
	build/$(NAME)_tests
	lcov --no-external -o build/coverage.info -c -d .
	genhtml -o build/report build/coverage.info
ifeq ($(UNAME),Darwin)
	open build/report/index.html
endif
