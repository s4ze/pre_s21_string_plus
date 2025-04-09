#include "s21_string.h"

int main() {
  char *result = (char *)malloc(sizeof(char) * 200);
  int i = 123456;
  char *s = (char *)malloc(sizeof(char) * (s21_int_length(i) + 1));
  s21_sprintf(s, "%d", 9432);
  printf("%s\n", s);
  printf("%10.7d\n", 1235);
  printf("%+.20e\n", 1324.343298423);
  printf("%0.0e\n", 0.0);
  printf(
      "\ndirect printing to sprintf\n%.90lf\n",
      -1111111111111111.132432423942384732498237498273948723894723984732984732);
  sprintf(
      result, "%.90lf",
      -1111111111111111.132432423942384732498237498273948723894723984732984732);
  printf("%s\n", result);

  double num =
      -1111111111111111.132432423942384732498237498273948723894723984732984732;
  sprintf(result, "%.90lf", num);
  printf("\nseparating from variable:\n%.90lf\n%s\n%lld\n%.90lf\n", num, result,
         (long long)num, num - (long long)num);

  long double int_part, frac_part = modfl(num, &int_part);
  printf("\nmodfl func:\n%Lf\n%Lf\n", int_part, frac_part);
  free(result);
  return 0;
}