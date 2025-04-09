#include "s21_string.h"

int main() {
  printf("TESTING:\n");
  char *result = (char *)malloc(sizeof(char) * 100);
  s21_strcpy(result, "0123456789");
  printf("%s\n", result);
  char *result2 = (char *)malloc(sizeof(char) * 100);
  result = (char *)s21_insert(result, ", himynameis ", 2);
  printf("%s\n", result);

  s21_strcpy(result, "      ");
  s21_strcpy(result2, s21_trim(result, " "));
  printf("%s%s\n", result2, "end");  // should be "end"

  s21_strcpy(result, "a      b");
  s21_strcpy(result2, s21_trim(result, " "));
  printf("%s%s\n", result2, "end");  // should be "a      bend"

  s21_strcpy(result, "a      ");
  s21_strcpy(result2, s21_trim(result, " "));
  printf("%s%s\n", result2, "end");  // should be "aend"

  s21_strcpy(result, "      b");
  s21_strcpy(result2, s21_trim(result, " "));
  printf("%s%s\n", result2, "end");  // should be "bend"

  s21_strcpy(result, " ");
  s21_strcpy(result2, s21_trim(result, " "));
  printf("%s%s\n", result2, "end");  // should be "end"

  s21_strcpy(result, "a");
  s21_strcpy(result2, s21_trim(result, " "));
  printf("%s%s\n", result2, "end");  // should be "aend"

  s21_strcpy(result, " b");
  s21_strcpy(result2, s21_trim(result, " "));
  printf("%s%s\n", result2, "end");  // should be "bend"

  s21_strcpy(result, "a ");
  s21_strcpy(result2, s21_trim(result, " "));
  printf("%s%s\n", result2, "end");  // should be "aend"

  free(result);
  free(result2);
  return 0;
}