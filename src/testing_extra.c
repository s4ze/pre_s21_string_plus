#include "s21_string.h"

int main() {
  printf("TESTING:\n");
  char *result = (char *)malloc(sizeof(char) * 100);
  s21_strcpy(result, "0123456789");
  printf("%s\n", result);
  char *result2 = (char *)malloc(sizeof(char) * 100);
  result = s21_insert(result, ", himynameis ", 2);
  printf("%s\n", result);

  free(result);
  free(result2);
  return 0;
}