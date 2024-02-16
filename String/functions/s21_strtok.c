#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *ptr = S21_NULL;
  if (str == S21_NULL) str = ptr;
  while (str && *str && s21_strchr(delim, *str)) {
    str++;
  }
  if (str && *str == '\0') {
    str = S21_NULL;
    ptr = S21_NULL;
  }
  if (str && *str != '\0') {
    ptr = str;
    while (*ptr && !(s21_strchr(delim, *ptr))) {
      ptr++;
    }
  }
  if (ptr && *ptr) {
    *ptr = '\0';
    ptr++;
  }
  if (ptr && *ptr == '\0') {
    ptr = S21_NULL;
  }
  return str;
}