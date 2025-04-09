#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  s21_size_t index = n;
  const unsigned char *str_uchar = (const unsigned char *)str;
  unsigned char c_uchar = (unsigned char)c;
  if (str != S21_NULL)
    for (s21_size_t i = 0; i < n && index == n; i++)
      if (str_uchar[i] == c_uchar) index = i;

  return index != n ? (void *)(str_uchar + index) : S21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int cmp = 0;
  if (str1 != S21_NULL && str2 != S21_NULL) {
    const unsigned char *str1_uchar = (const unsigned char *)str1;
    const unsigned char *str2_uchar = (const unsigned char *)str2;
    for (s21_size_t i = 0; i < n && cmp == 0; i++)
      if (str1_uchar[i] != str2_uchar[i])
        cmp = (int)str1_uchar[i] - (int)str2_uchar[i];
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
    for (s21_size_t i = 0; i < n; i++) dest_uchar[i] = src_uchar[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  if (str != S21_NULL) {
    unsigned char *str_uchar = (unsigned char *)str;
    unsigned char c_uchar = (unsigned char)c;
    for (s21_size_t i = 0; i < n; i++) str_uchar[i] = c_uchar;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (dest != S21_NULL && src != S21_NULL) {
    s21_size_t dest_size = s21_strlen(dest);
    char *ptr = dest + dest_size;
    for (s21_size_t i = 0; i < n; i++) *ptr++ = src[i];
    *ptr = '\0';
  }
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *c_ptr = S21_NULL;
  if (str != S21_NULL) {
    char c_uchar = (char)c;
    for (s21_size_t i = 0; c_ptr == S21_NULL && (i == 0 || str[i - 1] != '\0');
         i++)
      if (str[i] == c_uchar) c_ptr = (char *)str + i;
  }
  return c_ptr;
}

/* char *s21_strchr(const char *str, int c) {
  return (char *)s21_memchr((const void *)str, c, s21_strlen(str) + 1);
}  // functional implementation */

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t size = s21_strlen(str1) + 1;
  size = size > s21_strlen(str2) + 1 ? s21_strlen(str2) + 1 : size;
  size = size > n ? n : size;
  return s21_memcmp((const void *)str1, (const void *)str2, size);
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (dest != S21_NULL && src != S21_NULL) {
    /* s21_size_t i = 0;
    for (; src[i] != '\0' && i < n; i++) dest[i] = src[i];
    // or next block */

    // to remove if previous block used
    dest = (char *)s21_memcpy(dest, src, n);
    s21_size_t i = s21_strlen(dest);
    //

    for (; i < n + 1; i++) dest[i] = '\0';
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const s21_size_t str1_len = s21_strlen(str1);
  s21_size_t index = str1_len;
  if (str1 != S21_NULL && str2 != S21_NULL) {
    const s21_size_t str2_len = s21_strlen(str2);
    for (s21_size_t i = 0; i < str1_len && index == str1_len; i++)
      for (s21_size_t j = 0; j < str2_len && index == str1_len; j++)
        if (str1[i] == str2[j]) index = i;
  }
  return index;
}

char *s21_strerror(int errnum) {
  char *errnum_description;
  static char *errlist[] = ERRLIST;
  if (errnum >= 0 && errnum < ERRLIST_LEN)
    errnum_description = (char *)errlist[errnum];
  else {
    errnum_description = errlist[ERRLIST_LEN - 1];
    // TODO: add errnum after "Unkown error " with sprintf
  }
  return errnum_description;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t size = 0;
  if (str != S21_NULL)
    for (; str[size] != '\0'; size++);
  return size;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *index = S21_NULL;
  if (str1 != S21_NULL && str2 != S21_NULL) {
    const s21_size_t str1_len = s21_strlen(str1);
    const s21_size_t str2_len = s21_strlen(str2);
    for (s21_size_t i = 0; i < str1_len && index == 0; i++) {
      for (s21_size_t j = 0; j < str2_len && index == 0; j++)
        if (str1[i] == str2[j]) index = (char *)str1 + i;
    }
  }
  return index;
}

char *s21_strrchr(const char *str, int c) {
  char *c_ptr = S21_NULL;
  if (str != S21_NULL) {
    char c_uchar = (char)c;
    for (s21_size_t i = 0; i == 0 || str[i - 1] != '\0'; i++)
      if (str[i] == c_uchar) c_ptr = (char *)str + i;
  }
  return c_ptr;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *result_ptr = S21_NULL;
  const s21_size_t haystack_len = s21_strlen(haystack);
  const s21_size_t needle_len = s21_strlen(needle);
  if (haystack != S21_NULL && needle != S21_NULL &&
      s21_strncmp(needle, "", 1) > 0) {
    for (s21_size_t i = 0;
         i <= haystack_len - needle_len && result_ptr == S21_NULL; i++)
      for (s21_size_t j = 0; j < needle_len && haystack[i + j] == needle[j];
           j++)
        if (j + 1 == needle_len) result_ptr = (char *)haystack + i;
  } else if (haystack != S21_NULL &&
             (needle == S21_NULL || s21_strncmp(needle, "", 1) == 0)) {
    result_ptr = (char *)haystack;
  }
  return result_ptr;
}

char *s21_strtok(char *str, const char *delim) {
  static char *save_ptr = S21_NULL;
  if (str != S21_NULL) save_ptr = str;
  for (; *save_ptr != '\0' && s21_is_char_in_str(save_ptr, delim) == 1;
       save_ptr++);
  char *token_start = S21_NULL;
  if (*save_ptr != '\0') {
    token_start = save_ptr;
    for (; *save_ptr != '\0' && s21_is_char_in_str(save_ptr, delim) == 0;
         save_ptr++);
    if (*save_ptr != '\0') *save_ptr++ = '\0';
  }
  return token_start;
}

char s21_is_char_in_str(const char *c, const char *s) {
  const s21_size_t s_len = s21_strlen(s);
  char is_in = 0;
  for (s21_size_t i = 0; i < s_len && is_in == 0; i++)
    if (*c == s[i]) is_in = 1;
  return is_in;
}
