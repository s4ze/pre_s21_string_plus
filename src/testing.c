#include <stdio.h>
#include <string.h>

#include "s21_string.h"

int main() {
  char str[] = "Hello, World!";
  printf("%c\n", *(char *)s21_memchr(str, 'o', 7));
  printf("%c", *(char *)memchr(str, 'o', 7));

  return 0;
}