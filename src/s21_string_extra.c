#include "s21_string.h"

void *s21_shift_symbols(const char *str, const char start, const char end,
                        const int shift);

void *s21_to_upper(const char *str) {
  return s21_shift_symbols(str, 'a', 'z', -32);
}

void *s21_to_lower(const char *str) {
  return s21_shift_symbols(str, 'A', 'Z', 32);
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = S21_NULL;
  s21_size_t src_len = s21_strlen(src);
  if (src != S21_NULL && str != S21_NULL && start_index <= src_len) {
    s21_size_t str_len = s21_strlen(str);
    result = (char *)malloc(sizeof(char) * (src_len + str_len + 1));

    // to remove
    /* s21_size_t i = 0;
    for (; i < start_index; i++) result[i] = src[i];
    s21_size_t end_i = i;

    for (s21_size_t j = 0; j < str_len; j++) result[i + j] = str[j];

    for (i += str_len; end_i < src_len; end_i++) result[i++] = src[end_i];

    result[src_len + str_len] = '\0'; */

    s21_strncpy(result, src, start_index);
    s21_strcpy(result + start_index, str);
    s21_strcpy(result + start_index + str_len, src + start_index);
  }
  return (void *)result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = S21_NULL;
  if (src != S21_NULL) {
    char *start_src_ptr = (char *)src;
    for (; s21_is_char_in_str(start_src_ptr, trim_chars) == 1; start_src_ptr++);
    s21_size_t src_len = s21_strlen(src);
    char *end_src_ptr = (char *)src + src_len - 1;
    for (; s21_is_char_in_str(end_src_ptr, trim_chars); end_src_ptr--);
    s21_size_t result_len =
        end_src_ptr > start_src_ptr ? end_src_ptr - start_src_ptr + 1 : 1;
    result = (char *)malloc(sizeof(char) * (src_len + 1));
    for (s21_size_t i = 0; i < result_len; i++) {
      result[i] = start_src_ptr[i];
    }
    result[result_len] = '\0';
  }
  return (void *)result;
}

void *s21_shift_symbols(const char *str, const char start, const char end,
                        const int shift) {
  char *result = S21_NULL;
  if (str != S21_NULL) {
    const s21_size_t len = s21_strlen(str);
    result = (char *)malloc(sizeof(char) * (len + 1));
    for (s21_size_t i = 0; i < len; i++) {
      if (str[i] >= start && str[i] <= end)
        result[i] = str[i] + shift;
      else
        result[i] = str[i];
    }
    result[len] = '\0';
  }
  return (void *)result;
}

char *s21_strcpy(char *dest, const char *src) {
  char *dest_ptr = S21_NULL;
  if (dest != S21_NULL && src != S21_NULL) {
    dest_ptr = dest;
    char *src_ptr = (char *)src;
    for (; *src_ptr != '\0'; dest_ptr++) {
      *dest_ptr = *(src_ptr++);
    }
    *dest_ptr = '\0';
    dest_ptr = dest;
  }
  return dest_ptr;
}