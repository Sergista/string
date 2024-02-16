#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *ptr1 = (char *)dest;
  char *ptr2 = (char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    ptr1[i] = ptr2[i];
  }
  return dest;
}