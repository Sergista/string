
#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *result = S21_NULL;
  unsigned char *ptr = (unsigned char *)str;
  while (n > 0) {
    if (*ptr == (unsigned char)c) {
      result = ptr;
      break;
    }
    n--;
    ptr++;
  }
  return result;
}