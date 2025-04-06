CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11

SOURCES=s21_string.c

all: clang-format testing  

testing:
	$(CC) $(CFLAGS) $(SOURCES) testing.c -o $@

debug:
	$(CC) $(CFLAGS) -g -O0 $(SOURCES) -o $@

clean:
	@rm testing
	@# rm .clang-format

test:

s21_string.a:

gcov_report:

clang-format:
	@cp ./../materials/linters/.clang-format ./
	@clang-format -n $(SOURCES)

cppcheck:
	@cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCES)