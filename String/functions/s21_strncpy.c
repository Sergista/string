#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t size = s21_strlen(src);
  s21_size_t new_n = 0;

  if (size < n)
    new_n = size + 1;
  else
    new_n = n;

  for (s21_size_t i = 0; i < new_n && *src != '\0'; i++) {
    dest[i] = src[i];
  }

  if (*src == '\0') *dest = '\0';

  return dest;
}