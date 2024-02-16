#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *ptr1 = (unsigned char *)str1;
  unsigned char *ptr2 = (unsigned char *)str2;
  int result = 0;
  while (n && !result) {
    result = *ptr1 - *ptr2;
    ptr1++;
    ptr2++;
    n--;
  }
  return result;
}