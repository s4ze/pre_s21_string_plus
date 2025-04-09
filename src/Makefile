CC=gcc
CFLAGS=-Werror -Wextra -std=c11 # -Wall

SOURCES=s21_string.c s21_string_extra.c s21_sprintf.c

.PHONY=clang-format testing

all: clang-format testing

testing:
	@$(CC) $(CFLAGS) $(SOURCES) testing_sprintf.c -o $@

debug:
	@$(CC) $(CFLAGS) -g -O0 $(SOURCES) testing_sprintf.c -o $@

clean:
	@rm testing debug
	@# rm .clang-format

test:

s21_string.a:

gcov_report:

clang-format:
	@cp ./../materials/linters/.clang-format ./
	@clang-format -n $(SOURCES)

cppcheck:
	@cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCES)