#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;

  if (str != S21_NULL) {
    const char *current_char = str;

    while (*current_char != '\0') {
      if (*current_char == (char)c) {
        result = (char *)current_char;
      }
      current_char++;
    }

    if (result == S21_NULL && c == '\0') {
      result = (char *)current_char;
    }
  }

  return result;
}