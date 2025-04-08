#include "s21_string.h"

int main() {
  char *result = (char *)malloc(sizeof(char) * 100);
  int i = 123456;
  char *s = (char *)malloc(sizeof(char) * (int_length(i) + 1));
  int_to_str(s, i);
  printf("%s\n", s);
  printf("%lu %lu", int_length(0), int_length(14039));
  free(result);
  return 0;
}