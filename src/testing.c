#include <stdio.h>
#include <string.h>

#include "s21_string.h"

int main() {
  char *str1 = "Hello, World!";

  printf("memchr:\n");
  printf("%c\n", *(char *)s21_memchr(str1, 'o', 7));
  printf("%c\n\n", *(char *)memchr(str1, 'o', 7));

  char *str2 = "Hello!";

  printf("memcmp:\n");
  printf("%d\n", s21_memcmp(str1, str2, 7));
  printf("%d\n\n", memcmp(str1, str2, 7));

  char *str1_copy1 = malloc(sizeof(char) * 15);
  strcpy(str1_copy1, "Bruhi!!");
  char *str1_copy2 = malloc(sizeof(char) * 15);
  strcpy(str1_copy2, "Bruhi!!");

  printf("memcpy:\n");
  s21_memcpy(str1_copy1, str1, 5);
  printf("%s\n", str1_copy1);
  memcpy(str1_copy2, str1, 5);
  printf("%s\n\n", str1_copy2);

  printf("memset:\n");
  s21_memset(str1_copy1, 'B', 6);
  printf("%s\n", str1_copy1);
  memset(str1_copy2, 'B', 6);
  printf("%s\n\n", str1_copy2);

  printf("strncat:\n");
  s21_strncat(str1_copy1, "browhatthehell", 7);
  printf("%s\n", str1_copy1);
  strncat(str1_copy2, "browhatthehell", 7);
  printf("%s\n\n", str1_copy2);

  printf("strchr:\n");
  printf("%s %p %c\n", str1_copy1, s21_strchr(str1_copy1, 't'),
         *s21_strchr(str1_copy1, 'B'));
  printf("%s %p %c\n\n", str1_copy1, strchr(str1_copy1, 't'),
         *strchr(str1_copy1, 'B'));

  printf("strncmp:\n");
  printf("%d\n", s21_strncmp(str1, str1_copy1, 7));
  printf("%d\n\n", strncmp(str1, str1_copy1, 7));

  char *str1_copy3 = (char *)malloc(sizeof(char) * 21);
  char *str1_copy4 = (char *)malloc(sizeof(char) * 21);

  printf("strncpy:\n");
  printf("%s\n", s21_strncpy(str1_copy3, str1_copy1, 20));
  printf("%s\n\n", strncpy(str1_copy4, str1_copy1, 20));

  printf("strcspn:\n");
  printf("%ld\n", s21_strcspn(str1_copy3, "N"));
  printf("%ld\n", s21_strcspn(str1_copy3, "t"));
  printf("%ld\n\n", s21_strcspn(str1_copy3, "B"));
  printf("%ld\n", strcspn(str1_copy3, "N"));
  printf("%ld\n", strcspn(str1_copy3, "t"));
  printf("%ld\n\n", strcspn(str1_copy3, "B"));

  printf("strerror:\n");
  for (int i = 0; i < 161; i += 20) {
    printf("%s\t%s\n", strerror(i), s21_strerror(i));
  }

  printf("strpbrk:\n");
  printf("%p %c\n", s21_strpbrk(str1_copy3, "othaw"),
         *s21_strpbrk(str1_copy3, "othaw"));
  printf("%p %c\n\n", strpbrk(str1_copy3, "othaw"),
         *s21_strpbrk(str1_copy3, "othaw"));

  printf("strrchr:\n");
  printf("%s %p %c\n", str1_copy1, s21_strrchr(str1_copy1, 't'),
         *s21_strchr(str1_copy1, 'B'));
  printf("%s %p %c\n\n", str1_copy1, strrchr(str1_copy1, 't'),
         *strchr(str1_copy1, 'B'));

  return 0;
}