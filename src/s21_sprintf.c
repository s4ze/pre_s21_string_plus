#include "s21_string.h"

// char *s21_int_to_exp_str(char *s, long long n);
char *s21_float_to_str(char *s, long double n);

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
      c = format[++format_counter];
      if (s21_strchr("-+ #0", c) != S21_NULL) {  // flags
        // TODO: flags
      }
      if (s21_strchr("*0123456789", c) != S21_NULL) {  // width
        // TODO: width
      }
      if (c == '.' && s21_strchr("", format[++format_counter])) {  // accuracy
        // TODO: .accuracy
      }
      if (s21_strchr("lLh", c)) {  // length
        // TODO: length
      }
      if (s21_strchr("cdieEfgGosuxXpn%", c)) {  // specificator
        if (c == 'c') {
          int val = va_arg(args, int);
          //
          str[str_counter++] = val;
        } else if (c == 'd' || c == 'i') {
          int val = va_arg(args, int);
          //
          s21_int_to_str(str + str_counter, val);
          str_counter++;
        } else if (c == 'e') {
          // int val = va_arg(args, int);
          //
          // s21_long_to_exp_str(str + str_counter, val);
          str_counter++;
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

char *s21_int_to_str(char *s, long long n) {
  s21_size_t counter = s21_int_length(n) - 1;
  while (n > 9) {
    s[counter--] = (n % 10) + 48;
    n /= 10;
  }
  s[counter] = '0' + n % 10;
  return s;
}

char *s21_float_to_str(char *s, long double n) {
  char *result = S21_NULL;
  if (s != S21_NULL) {
    result = s;
    long double integral, fractional = modfl(n, &integral);

    // doesn't work

    /* int negative = 0;
    if (n > 0) negative = 1;
    long long fractional = (long long)n;
    s21_int_to_str(s, fractional);
    s21_size_t fractional_len = s21_int_length(fractional);
    double integral = n - fractional;
    s21_int_to_str(s + fractional_len, integral);
    result += (int)integral - (int)integral; */
  }
  return result;
}

/* char *s21_long_to_exp_str(char *s, long n) {
  s21_size_t counter = s21_int_length(n) - 1;
  while (n > 9) {
    s[counter--] = (n % 10) + 48;
    n /= 10;
  }
  s[counter] = n % 10 + 48;
  return s;
} */

s21_size_t s21_int_length(long long n) {
  s21_size_t size = 0;
  if (n != 0)
    for (; n != 0; n /= 10) size++;
  else
    size = 1;
  return size;
}

s21_size_t s21_float_integral_length(long double n) {
  s21_size_t size = 0;
  if (n != 0.0) {
    if (n < 1 || n > -1) size -= 1;
    for (; n != 0; size++) {
      if (n > 0 && n <= 1 || n < 0 && n >= -1) n = truncl(n);
      n /= 10;
    }
  }
  return size;
}

s21_size_t s21_float_fractional_length(long double n) {
  s21_size_t size = 0;
  if (n != 0.0) {
    if (n >= 1 || n <= -1) {
      long double _;
      n = modfl(n, &_);
    }
    for (; n != 0; size++) {
      n *= 10.0;
      int digit = (int)n;
      n -= digit;
    }
  } else
    size = 0;
  return size;
}