CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11

SOURCES=s21_string.c

all: clang-format testing  

testing:
	$(CC) $(CFLAGS) $(SOURCES) testing.c -o $@

debug:
	gcc -Wall -Werror -Wextra -g -O0 s21_string.c testing.c -o s21_string

clean:
	rm testing
	rm .clang-format

test:

s21_string.a:

gcov_report:

clang-format:
	cp ./../materials/linters/.clang-format ./
	clang-format -i $(ALL_SRC)

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(ALL_SRC)