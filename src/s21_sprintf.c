#include "s21_string.h"

char *specificator_flags = "-= #0";
// width: digit or * (asterix)
char accuracy = '.';  // and *
char *length = "hlL";
char *specificators = "cdieEfgGosuxXpn%";

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  // specificator: %[флаги][ширина][.точность][длина]тип
  int val = 0;
  int format_counter = 0, str_counter = 0;
  char c;
  for (; format[format_counter] != '\0';
       format_counter++) {  // TODO: conditional reading
                            // args, following format string
    c = format[format_counter];
    // val = va_arg(args, int);       // getting args values
    if (c == '%') {  // potentionally separate in func
      // format_reader specificator type
      // TODO: flags
      // TODO: width
      // TODO: .accuracy
      // TODO: length
      c = format[++format_counter];
      if (c == 'c') {
        int val = va_arg(args, int);
        //
        str[str_counter++] = val;
      } else if (c == 'd') {
        int val = va_arg(args, int);
        //
        s21_int_to_str(str + str_counter, val);
        str_counter++;  // fix
      } else if (c == 'i') {
      } else if (c == 'e') {
      } else if (c == 'E') {
      } else if (c == 'f') {
      } else if (c == 'g') {
      } else if (c == 'G') {
      } else if (c == 'o') {
      } else if (c == 's') {
      } else if (c == 'u') {
      } else if (c == 'x') {
      } else if (c == 'X') {
      } else if (c == 'p') {
      } else if (c == 'n') {
      } else if (c == '%') {
      }
      //
    }
  }
  va_end(args);
  return val + format_counter;
}

/* int format_reader(const char *format, int *counter) {
  int code = 0;
  for (; format[*counter] != '\0'; *counter++) {
    // if *
  }
  return counter;  // 1-15 type, +20 is * width, +40 is * accuracy, +60 is *
                   // width and accuracy
} */

char *s21_int_to_str(char *s, int n) {
  s21_size_t counter = s21_int_length(n) - 1;
  while (n > 9) {
    s[counter--] = (n % 10) + 48;
    n /= 10;
  }
  s[counter] = n % 10 + 48;
  return s;
}

s21_size_t s21_int_length(int n) {
  s21_size_t size = 0;
  if (n != 0)
    for (; n != 0; n /= 10) size++;
  else
    size = 1;
  return size;
}