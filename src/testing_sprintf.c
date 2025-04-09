#include "s21_string.h"

int main() {
  char *result = (char *)malloc(sizeof(char) * 100);
  int i = 123456;
  char *s = (char *)malloc(sizeof(char) * (s21_int_length(i) + 1));
  s21_sprintf(s, "%d", 9432);
  printf("%s\n", s);
  printf("%10.7d\n", 1235);
  printf("%+.20e\n", 1324.343298423);
  printf("%0d\n", 0);
  printf("%f\n", (12.343 / 10));
  printf("%lu %lu", s21_int_length(0), s21_int_length(14039));
  free(result);
  return 0;
}