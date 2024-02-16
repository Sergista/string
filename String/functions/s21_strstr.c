#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = S21_NULL;
  s21_size_t len1 = s21_strlen(haystack);
  s21_size_t len2 = s21_strlen(needle);
  if (len1 >= len2) {
    for (s21_size_t i = 0; i <= len1 - len2; i++) {
      int check = 1;
      for (s21_size_t j = i, k = 0; needle[k]; k++, j++) {
        if (haystack[j] != needle[k]) {
          check = 0;
          break;
        }
      }
      if (check) {
        res = (char *)haystack + i;
        break;
      }
    }
  }
  return res;
}