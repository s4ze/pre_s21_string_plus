#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  s21_size_t done = n;
  const unsigned char *str_ptr = (const unsigned char *)str;
  if (str != S21_NULL) {
    for (s21_size_t i = 0; i < n && done == n; i++) {
      if (str_ptr[i] == c) {
        done = i;
      }
    }
  }
  return done != n ? (void *)(str_ptr + done) : S21_NULL;
}
