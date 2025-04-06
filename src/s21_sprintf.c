#include <stdio.h>

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  // specificator: %[флаги][ширина][.точность][длина]
  while (1) {  // TODO: conditional reading args, following format string
    int val = va_arg(args, int);  // getting args values
  }
  va_end(args);
}