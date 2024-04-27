# CC = g++
CC = g++ -arch x86_64 # for MacBook with M1 processor
CPPFLAGS = -Wall -Werror -Wextra -std=c++17

MATRIX = ./s21_*.cpp
TEST = ./tests/s21_*.cpp
OBJECTS = *.o
TEST_FLAGS = -lgtest -lgmock -pthread

CLANG = clang-format

OS:=$(shell uname -s)
ifeq ($(OS), Linux)
	TEST_FLAGS += -lsubunit -lrt
endif

.PHONY: all s21_matrix_oop.a test gcov_report clean

all: s21_matrix_oop.a

s21_matrix_oop.a:
	$(CC) $(CPPFLAGS) -c $(MATRIX)
	ar rcs s21_matrix_oop.a $(OBJECTS)
	ranlib s21_matrix_oop.a

test: s21_matrix_oop.a
	$(CC) $(CPPFLAGS) $(MATRIX) $(TEST) s21_matrix_oop.a $(TEST_FLAGS) -o s21_matrix_oop_test
	./s21_matrix_oop_test

clean:
	rm -rf *.o *.a *.gcda *.gcno *.gch *.info report s21_matrix_oop_test gcov

gcov_report: s21_matrix_oop.a
	$(CC) $(CPPFLAGS) --coverage $(MATRIX) $(TEST) $(TEST_FLAGS) -lstdc++ -o ./gcov
	./gcov
	lcov -t "./gcov" --ignore-errors inconsistent -o report.info --no-external -c -d .
	genhtml --ignore-errors inconsistent -o report report.info
	open ./report/index.html
	rm -rf *.o *.a *.gch *.gcno *.gcda *.info s21_matrix_oop_test gcov

clang_n:
	$(CLANG) -style=Google -n *.cpp *.h

clang_i:
	$(CLANG) -style=Google -i *.cpp *.h
