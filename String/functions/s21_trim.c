#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  void *result = S21_NULL;
  char *tchars = calloc(1024, 1);

  if (trim_chars == S21_NULL || s21_strlen(trim_chars) == 0)
    s21_strncpy(tchars, " \n\t", 3);
  else
    s21_strncpy(tchars, trim_chars, s21_strlen(trim_chars));

  if (src != S21_NULL) {
    s21_size_t start = 0;
    s21_size_t end = s21_strlen(src) - 1;

    while (start <= end && s21_strchr(tchars, src[start])) {
      start++;
    }

    while (end >= start && s21_strchr(tchars, src[end])) {
      end--;
    }

    s21_size_t len = end - start + 1;

    result = (void *)malloc(len + 1);
    if (result != S21_NULL) {
      s21_memcpy((char *)result, src + start, len);
      ((char *)result)[len] = '\0';
    }

    if (src[0] == '\0') {
      result = (void *)malloc(1);
      if (result != S21_NULL) {
        ((char *)result)[0] = '\0';
      }
    }
  }

  free(tchars);
  return result;
}