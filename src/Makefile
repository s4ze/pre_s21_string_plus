CC=gcc
CFLAGS=-Werror -Wextra -std=c11 # -Wall

SOURCES=s21_string.c s21_string_extra.c s21_sprintf.c
SOURCE_TESTS_FUNC = $(wildcard ./tests/*.c)

.PHONY=clang-format testing

ifeq ($(OS), Darwin)
	det_OS = -lcheck
	GCOV_FLAGS = -fprofile-arcs -ftest-coverage
else
	det_OS = -lcheck -lm -lpthread -lsubunit
endif

all: clang-format testing

testing:
	@$(CC) $(CFLAGS) $(SOURCES) testing_sprintf.c -o $@ -lm

debug:
	@$(CC) $(CFLAGS) -g -O0 $(SOURCES) testing_sprintf.c -o $@ -lm

clean:
	@rm -f testing debug
	@# rm -f .clang-format

clean_tests:
	rm -rf test *.gcda *.gcno *.o *.info *.a *.h.gch tests/*.gcno report 
	rm -rf s21_test_string.dSYM s21_test_string
	rm -rf tests/*.h.gch 

test: s21_string.a 
	@$(CC) $(CFLAGS) --coverage $(SOURCE_TESTS_FUNC) s21_string.a -o s21_test_string $(det_OS)

s21_string.a:
	@$(CC) $(CFLAGS) $(SOURCES) $(GCOV_FLAGS) -c
	@ar rc s21_string.a *.o
	@ranlib s21_string.a
	@rm -rf *.o

gcov_report:

clang-format:
	@cp ./../materials/linters/.clang-format ./
	@clang-format -n $(SOURCES)

cppcheck:
	@cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCES)