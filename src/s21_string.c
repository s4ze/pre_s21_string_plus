#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *str_ptr = (const void *)str;
  s21_size_t done = n;
  for (s21_size_t i = 0; i < n && done == n; i++) {
    if (str_ptr[i] == c) {
      done = i;
    }
  }
  return done != n ? (void *)(str_ptr + done) : S21_NULL;
}

/* void *s21_memchr(const void *str, int c, s21_size_t n) {
  s21_size_t success = n;
  const unsigned char *ptr_str = (const unsigned char *)str;
  if (str != S21_NULL) {
    s21_size_t i = 0;
    while (i < n && success == n) {
      if (ptr_str[i] == (unsigned char)c) {
        success = i;
      }
      i++;
    }
  }
  return success == n ? S21_NULL : (void *)(ptr_str + success);
} */