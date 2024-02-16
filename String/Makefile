OS=$(shell uname -s)
CC = gcc -Wall -Wextra -Werror -std=c11
ifeq ($(OS), Linux)
 CC += -D OS_LINUX
endif
ifeq ($(OS), Darwin)
 CC += -D OS_MAC
endif

GCOVFLAGS = -fprofile-arcs -ftest-coverage
HEADER = s21_string.h s21_errlist.h
LINUX=-lcheck -lm -lpthread -lrt -lsubunit
MACOS= -lcheck
OS_GCOVR = lcov --directory . --capture --output s21_string.info
GCOVR_DOP = genhtml s21_string.info --output ./report
SOURCES = $(wildcard functions/*.c)

OBJ_LIBRARY := $(patsubst %.c, %.o, $(SOURCES))


# ---------------------

%.o: %.c $(HEADER)
	$(CC) -c $< -o $@

# ---------------------

all: clean s21_string.a test gcov_report

s21_string.a: $(OBJ_LIBRARY) $(HEADERS)
	ar rcs s21_string.a $(OBJ_LIBRARY)
	ranlib s21_string.a
	rm -rf ./*/*.o

gcov_report: s21_string.a ./tests/s21_string_test.c
ifeq ($(OS), Darwin)
	gcc $(GCOVFLAGS) ./tests/s21_string_test.c $(SOURCES) -o report.out $(MACOS)
else
	gcc $(GCOVFLAGS) ./tests/s21_string_test.c $(SOURCES) -o report.out $(LINUX)
endif

	./report.out
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o report/ Coverage_Report.info
	rm -f *.gcno *.gcda *.info report.out *.gcov
	open ./report/index-sort-f.html


clean:
	rm -rf functions/*.o *.a *.gc* *.info ./report *.out

test: s21_string.a tests/s21_string_test.c
ifeq ($(OS), Darwin)
	$(CC) tests/s21_string_test.c s21_string.a -o test.out $(MACOS)
else
	$(CC) tests/s21_string_test.c s21_string.a -o test.out $(LINUX)
endif

	./test.out

style:
	clang-format --style=Google -i functions/*.c tests/*.c *.h

check_style:
	clang-format --style=Google -n functions/*.c tests/*.c *.h

cpp:
	cppcheck --enable=all --inconclusive --force --language=c --std=c11 --suppress=missingIncludeSystem functions/*.c *.h tests/*.c *.c

rebuild: clean all