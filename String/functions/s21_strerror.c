#include "../s21_string.h"

void s21_reverse_str(char *res, char *str) {
  s21_size_t len = s21_strlen(str);
  s21_size_t i = 0;
  for (s21_size_t j = len - 1; i < len; i++, j--) {
    res[i] = str[j];
  }
  res[i] = '\0';
}

char *s21_convert_int(int num) {
  char tmp[20];
  static char res[20];
  int i = 0;
  int n = num;
  while (n != 0) {
    if (n < 0) {
      tmp[i] = (n * (-1) % 10) + '0';
    } else {
      tmp[i] = (n % 10) + '0';
    }
    n /= 10;
    i++;
  }
  if (num < 0) {
    tmp[i++] = '-';
  }
  tmp[i] = '\0';
  s21_reverse_str(res, tmp);
  return res;
}

char *s21_strerror(int errnum) {
  char *res = NULL;
  static char unknown[50] = {'\0'};
  s21_strncpy(unknown, ERROR, 50);
  if (errnum < 0 || errnum >= MAX_ERRLIST) {
    char *errnum_str = s21_convert_int(errnum);
    s21_strncat(unknown, errnum_str, 50);
    res = unknown;
  } else {
    res = (char *)errList[errnum];
  }

  return res;
}