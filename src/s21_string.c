#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  s21_size_t index = n;
  const unsigned int *str_uint = (const unsigned int *)str;
  if (str != S21_NULL) {
    for (s21_size_t i = 0; i < n && index == n; i++) {
      if (str_uint[i] == (unsigned int)c) {
        index = i;
      }
    }
  }
  return index != n ? (void *)(str_uint + index) : S21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned int *str1_uint = (const unsigned int *)str1;
  const unsigned int *str2_uint = (const unsigned int *)str2;
  int cmp = 0;
  if (str1 != S21_NULL && str2 != S21_NULL) {
    for (s21_size_t i = 0; i < n && cmp == 0; i++) {
      if (str1_uint[i] < str2_uint[i]) {
        cmp = -1;
      } else if (str1_uint[i] > str2_uint[i]) {
        cmp = 1;
      }
    }
  }  // проверить поведение оригинальной функции
  return cmp;
}