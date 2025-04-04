#include <stdio.h>
#include <string.h>

#include "s21_string.h"

int main() {
  printf("memchr:\n");
  char str1[] = "Hello, World!";
  printf("%c\n", *(char *)s21_memchr(str1, 'o', 7));
  printf("%c\n\n", *(char *)memchr(str1, 'o', 7));

  printf("memcmp:\n");
  char str2[] = "Hello!";
  printf("%d\n", s21_memcmp(str1, str2, 7));
  printf("%d\n\n", memcmp(str1, str2, 7));

  printf("memcpy:\n");
  char str1_copy1[] = "Bruhi!!";
  char str1_copy2[] = "Bruhi!!";
  s21_memcpy(str1_copy1, str1, 5);
  printf("%s\n", str1_copy1);
  memcpy(str1_copy2, str1, 5);
  printf("%s\n\n", str1_copy2);

  printf("memset:\n");
  s21_memset(str1_copy1, 'B', 6);
  printf("%s\n", str1_copy1);
  memset(str1_copy2, 'B', 6);
  printf("%s\n\n", str1_copy2);

  return 0;
}