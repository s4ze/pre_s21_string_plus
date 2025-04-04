#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  s21_size_t index = n;
  const unsigned char *str_uchar = (const unsigned char *)str;
  if (str != S21_NULL) {
    for (s21_size_t i = 0; i < n && index == n; i++) {
      if (str_uchar[i] == (unsigned char)c) {
        index = i;
      }
    }
  }
  return index != n ? (void *)(str_uchar + index) : S21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int cmp = 0;
  if (str1 != S21_NULL && str2 != S21_NULL) {
    const unsigned char *str1_uchar = (const unsigned char *)str1;
    const unsigned char *str2_uchar = (const unsigned char *)str2;
    for (s21_size_t i = 0; i < n && cmp == 0; i++) {
      if (str1_uchar[i] != str2_uchar[i]) {
        cmp = (int)str1_uchar[i] - (int)str2_uchar[i];
      }
    }
  } else if (str1 != str2) {
    if (str1 == S21_NULL)
      cmp = -1;
    else
      cmp = 1;
  }
  return cmp;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest != S21_NULL && src != S21_NULL) {
    unsigned char *dest_uchar = (unsigned char *)dest;
    const unsigned char *src_uchar = (const unsigned char *)src;
    for (s21_size_t i = 0; i < n; i++) {
      dest_uchar[i] = src_uchar[i];
    }
  }
  return dest;
}