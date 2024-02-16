#include "../s21_string.h"

int countSpecificatorForFormat(const char *format);
void *specificationFormat(char *specification, const char *format);

struct my_sscanf {
  int star;
  int width;
  char modif;
  char type;
};

int s21_sscanf(const char *str, const char *format, ...) {
  char *CH;
  char *S;
  int *I;
  int outCount = 0;

  int x = 0;
  const char *point = str;
  char specification[50] = {0};
  int spec = 0;
  int n = countSpecificatorForFormat(format);
  specificationFormat(specification, format);
  va_list factor;
  va_start(factor, format);
  for (int i = 0; i < n; i++) {
    switch (specification[spec]) {
      case 'c':
        CH = va_arg(factor, char *);
        while (point[x] == ' ' || point[x] == '\t') {
          x++;
        }
        *CH = point[x];
        x++;
        if (CH) outCount++;
        break;

      case 'd':
        I = va_arg(factor, int *);
        int start_d = 0;
        int len_d = 0;
        int d_minus = 1;
        while (point[x] == ' ' || point[x] == '\t') {
          x++;
        }
        if ((point[x] >= '0' && point[x] <= '9') ||
            (point[x] == '-' && point[x + 1] >= '0' && point[x + 1] <= '9')) {
          int y = x;
          if (point[x] == '-') {
            len_d--;
            d_minus = -1;
            y = x + 1;
          }
          while ((point[x + 1] >= '0' && point[x + 1] <= '9')) {
            len_d++;
            x++;
          }
          while (len_d > -1) {
            start_d += (int)(point[y] - 48) * pow(10, len_d);
            len_d--;
            y++;
          }
          *I = start_d * d_minus;
          x++;
          if (I) outCount++;
        }
        break;

      case 's':
        S = va_arg(factor, char *);

        int y = 0;
        while (point[x] == ' ' || point[x] == '\t') {
          x++;
        }
        while (point[x] != ' ' && point[x] != '\0' && point[x] != '\t') {
          S[y] = point[x];
          y++;
          S[y] = '\0';
          x++;
        }
        if (S) outCount++;
        break;
    }
    spec++;
  }
  va_end(factor);

  return outCount;
}

int countSpecificatorForFormat(const char *format) {
  int i = 0, count = 0;
  while (format[i] != '\0') {
    if (format[i] == '%') count++;
    i++;
  }
  return count;
}

void *specificationFormat(char *specification, const char *format) {
  int i = 0;
  int j = 0;
  while (format[i] != '\0') {
    if (format[i] == 'c' || format[i] == 'd' || format[i] == 's') {
      specification[j] = format[i];
      j++;
    }
    i++;
  }
  return specification;
}