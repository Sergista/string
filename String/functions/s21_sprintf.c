#include "../s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  char symbols_of_specificators[] = "cdifFsugGeExXop%";
  char *source = str;

  va_list arguments;
  va_start(arguments, format);

  while (*format) {
    if (*format == '%') {
      format++;
      params param = {0};
      param.number_system = 10;
      format = def_param(&param, format, &arguments);
      while (!s21_strchr(symbols_of_specificators, *format)) format++;
      str = process_specificator(str, source, format, param, &arguments);
    } else {
      *str = *format;
      str++;
    }
    format++;
  }
  *str = '\0';
  va_end(arguments);
  return (str - source);
}

const char *def_param(params *param, const char *format, va_list *arguments) {
  format = def_flags(format, param);
  format = def_capacity(format, &param->width, arguments);
  if (*format == '.') {
    param->dot = 1;
    format++;
    format = def_capacity(format, &param->accuracy, arguments);
  }
  if (*format == 'L')
    param->length = 'L';
  else if (*format == 'l')
    param->length = 'l';
  else if (*format == 'h')
    param->length = 'h';
  if (param->length != 0) format++;

  return format;
}

const char *def_flags(const char *format, params *param) {
  while (format) {
    if (*format == '+')
      param->plus = 1;
    else if (*format == '-')
      param->minus = 1;
    else if (*format == '#')
      param->lattice = 1;
    else if (*format == ' ')
      param->space = 1;
    else if (*format == '0')
      param->zero = 1;
    else
      break;
    format++;
  }
  param->space = (param->space && !param->plus);
  param->zero = (param->zero && !param->minus);
  return format;
}

const char *def_capacity(const char *format, int *capacity,
                         va_list *arguments) {
  *capacity = 0;
  if (*format == '*') {
    *capacity = va_arg(*arguments, int);
    format++;
  }
  while (format) {
    if ('0' <= *format && *format <= '9') {
      *capacity *= 10;
      *capacity += *format - '0';
    } else
      break;
    format++;
  }
  return format;
}

params def_number_system(params param, char ch_format) {
  if (ch_format == 'x' || ch_format == 'X')
    param.number_system = 16;
  else if (ch_format == 'o')
    param.number_system = 8;
  if (ch_format == 'X') param.capital = 1;
  return param;
}

char *process_specificator(char *str, char *source, const char *format,
                           params param, va_list *arguments) {
  switch (*format) {
    case 'c': {
      str = print_c(str, param, va_arg(*arguments, int));
      break;
    }
    case '%': {
      str = print_c(str, param, '%');
      break;
    }
    case 's': {
      char *string = va_arg(*arguments, char *);
      if (string == NULL)
        str = print_s(str, param, "(null)");
      else
        str = print_s(str, param, string);
      break;
    }
    case 'd':
    case 'i': {
      if (param.dot) param.zero = 0;
      str = print_d(str, param, arguments);
      break;
    }
    case 'u':
    case 'o':
    case 'x':
    case 'X': {
      if (param.dot) param.zero = 0;
      param = def_number_system(param, *format);
      unsigned long int num = 0;
      if (*(format - 1) == 'l')
        num = (unsigned long int)va_arg(*arguments, unsigned long int);
      else if (*(format - 1) == 'h')
        num = (unsigned short)va_arg(*arguments, unsigned int);
      else
        num = va_arg(*arguments, unsigned int);
      if (num)
        str = print_upositive(str, param, num);
      else
        str = print_unull(str, param);
      break;
    }
    case 'p': {
      unsigned long int ulint_ptr = va_arg(*arguments, unsigned long int);
      param.p = 1;
      param.number_system = 16;
      param.lattice = 1;
      param.capital = 0;

      if (ulint_ptr) {
        param.length = 'l';
        str = print_upositive(str, param, ulint_ptr);
      } else {
        str = print_unull(str, param);
      }
      break;
    }
    case 'F':
    case 'f': {
      if (*format == 'F') {
        param.capital = 1;
      }
      str = print_f(str, param, *(format - 1), arguments);
      break;
    }
    case 'e':
    case 'E': {
      param = def_param_eg(param, *format);
      str = print_e_(str, param, *(format - 1), arguments);
      break;
    }
    case 'g':
    case 'G': {
      param = def_param_eg(param, *format);
      str = print_g(str, param, *(format - 1), arguments);
      break;
    }
    default: {
      str = S21_NULL;
      break;
    }
  }
  if (!str) *source = '\0';
  return str;
}

char *print_c(char *str, params param, int symbol) {
  int w = param.width;
  while (w > 1 && !param.minus) {
    *str = ' ';
    str++;
    w--;
  }
  *str = symbol;
  str++;
  while (w > 1 && param.minus) {
    *str = ' ';
    str++;
    w--;
  }
  return str;
}

char *print_s(char *str, params param, char *string) {
  int wid = param.width;
  int pp = param.accuracy;
  int len = s21_strlen(string);
  int spaces;
  if (param.dot && pp < len) len = pp;
  if (wid < len) wid = len;
  spaces = wid - len;
  while (spaces && !param.minus) {
    *str = ' ';
    str++;
    spaces--;
  }
  while (*string != '\0' && len) {
    *str = *string;
    str++;
    string++;
    len--;
  }
  while (spaces && param.minus) {
    *str = ' ';
    str++;
    spaces--;
  }
  return str;
}
char *print_d(char *str, params param, va_list *arguments) {
  long int num = 0;
  if (param.length == 'l') {
    num = (long int)va_arg(*arguments, long int);
  } else if (param.length == 'h') {
    num = (short)va_arg(*arguments, int);
  } else {
    num = (int)va_arg(*arguments, int);
  }
  s21_size_t size_d = get_size_d(&param, num);
  char *buffer = malloc(sizeof(char) * size_d);
  if (buffer) {
    int len = int_to_buffer(param, num, buffer, size_d);
    str = append_to_str(param.width, len, buffer, str);
  }
  if (buffer) free(buffer);
  return str;
}

s21_size_t get_size_d(params *param, long int num) {
  s21_size_t result = 0;
  if (param->space || param->plus || num < 0) {
    param->spot_for_sign = 1;
  }
  if (num == 0 && (param->accuracy)) {
    result++;
  }
  while (num != 0) {
    num /= 10;
    result++;
  }
  if ((s21_size_t)param->width > result) result = param->width;
  if ((s21_size_t)param->accuracy > result) result = param->accuracy;
  if (param->spot_for_sign == 1 && !param->zero) result++;
  if (result == 0 && num == 0 && !param->accuracy && !param->width &&
      !param->space && !param->dot)
    result++;
  return result;
}

int int_to_buffer(params param, long int num, char *buffer, s21_size_t size_d) {
  int len = 0;
  long int num_ = num;

  int empty = 0;
  if (num == 0 && param.dot && param.accuracy == 0) empty = 1;
  if (num == 0 && !empty &&
      (param.accuracy || param.width || param.space || !param.dot)) {
    buffer[len] = '0';
    len++;
    size_d--;
  }

  while (num_ && buffer && size_d) {
    buffer[len] = abs((int)(num_ % 10)) + '0';
    len++;
    size_d--;
    num_ /= 10;
  }

  int flag_prec = 0;
  if (param.accuracy > len) {
    param.accuracy -= len;
    param.zero = 1;
  } else
    flag_prec = 1;

  if (size_d <= 2 && param.zero == 1 && param.spot_for_sign == 1)
    param.zero = 0;

  while (param.zero && buffer && (size_d - param.spot_for_sign > 0) &&
         (param.accuracy || flag_prec)) {
    if (size_d == 1 && param.spot_for_sign == 1) break;
    buffer[len] = '0';
    len++;
    size_d--;
    param.accuracy--;
  }

  if (param.space && num >= 0 && size_d) {
    buffer[len] = ' ';
    len++;
    size_d--;
  }
  if (num < 0 && size_d) {
    buffer[len] = '-';
    len++;
    size_d--;
  }
  if (num >= 0 && param.plus && size_d) {
    buffer[len] = '+';
    len++;
    size_d--;
  }

  if (size_d && !param.minus) {
    while ((size_d - param.spot_for_sign > 0) && buffer) {
      buffer[len] = ' ';
      len++;
      size_d--;
    }
  }
  return len;
}

char get_num_char(int num, int capital) {
  char flag = '0';
  switch (num) {
    case 10:
      flag = (char)('a' - capital * 32);
      break;
    case 11:
      flag = (char)('b' - capital * 32);
      break;
    case 12:
      flag = (char)('c' - capital * 32);
      break;
    case 13:
      flag = (char)('d' - capital * 32);
      break;
    case 14:
      flag = (char)('e' - capital * 32);
      break;
    case 15:
      flag = (char)('f' - capital * 32);
      break;
  }
  if (0 <= num && num <= 9) flag = (char)(num + 48);
  return flag;
}

char *print_upositive(char *str, params param, unsigned long int num) {
  s21_size_t size_u = get_size_u(param, num);
  char *buffer = malloc(sizeof(char) * size_u);
  if (buffer) {
    int len = ui_to_buffer(buffer, param, num, size_u);
    str = append_to_str(param.width, len, buffer, str);
  }
  if (buffer) free(buffer);
  return str;
}

char *print_unull(char *str, params param) {
  s21_size_t size_u = 0;
  if (param.p) {
    size_u += 2;
    if (param.width == 0) param.width++;
  }
  if (param.number_system == 8 && !param.lattice && !param.accuracy &&
      !param.width && !param.dot) {
    *str = '0';
    str++;
  } else {
    if (param.accuracy || param.width) size_u++;
    if ((s21_size_t)param.width > size_u) size_u = param.width;
    if ((s21_size_t)param.accuracy > size_u) size_u = param.accuracy;
    if (size_u == 0 && !param.space && !param.dot) size_u++;

    char *buffer = malloc(sizeof(char) * size_u);
    if (buffer) {
      int len = ui_to_buffer(buffer, param, 0, size_u);
      str = append_to_str(param.width, len, buffer, str);
    }
    if (buffer) free(buffer);
  }
  return str;
}

int ui_to_buffer(char *buffer, params param, unsigned long int num,
                 s21_size_t size_u) {
  int len = 0;
  int flag = 0;
  int accuracy = param.accuracy;
  unsigned long int num_ = num;
  if ((param.lattice && param.number_system == 8))
    param.spot_for_sign = 1;
  else if (param.lattice && param.number_system == 16) {
    param.spot_for_sign = 2;
  }

  int empty = (num == 0) &&
              ((param.dot && param.accuracy == 0) || param.number_system == 8);
  if (num == 0 && size_u && !empty) {
    buffer[len++] = '0';
    size_u--;
  }

  while (num_ && buffer && size_u) {
    char sym = '^';
    if (param.number_system)
      sym = get_num_char(num_ % param.number_system, param.capital);
    buffer[len++] = sym;
    size_u--;
    if (param.number_system) num_ /= param.number_system;
  }

  if (accuracy - len > 0) {
    accuracy -= len;
    param.zero = 1;
  } else
    flag = 1;

  while (param.zero && buffer && (size_u - param.spot_for_sign > 0) &&
         (accuracy || flag)) {
    if (size_u == 1 && param.spot_for_sign == 1) break;
    buffer[len++] = '0';
    size_u--;
    accuracy--;
  }

  if (param.lattice && param.number_system == 8 &&
      (accuracy || !param.accuracy)) {
    buffer[len++] = '0';
    size_u--;
  } else if (param.lattice && param.number_system == 16 && param.capital &&
             num != 0) {
    buffer[len++] = 'X';
    size_u--;
    buffer[len++] = '0';
    size_u--;
  } else if (param.lattice && param.number_system == 16 && !param.capital &&
             (num != 0 || param.p)) {
    buffer[len++] = 'x';
    size_u--;
    buffer[len++] = '0';
    size_u--;
  }

  if (size_u > 0 && !param.minus) {
    while ((size_u > 0) && buffer) {
      buffer[len++] = ' ';
      size_u--;
    }
  }
  return len;
}

s21_size_t get_size_u(params param, unsigned long int num) {
  s21_size_t size = 0;
  unsigned long int num_ = num;
  while (num_ > 0) {
    if (param.number_system) num_ /= param.number_system;
    size++;
  }
  if ((s21_size_t)param.accuracy > size) size = param.accuracy;

  if (param.number_system == 8 && param.lattice)
    size++;
  else if (param.number_system == 16 && param.lattice)
    size += 2;

  if ((s21_size_t)param.width > size) size = param.width;

  return size;
}

char *append_to_str(int width, int len, const char *buffer, char *str) {
  for (int j = len - 1; j >= 0; j--) {
    *str = buffer[j];
    str++;
  }
  while (len < width) {
    *str = ' ';
    str++;
    width--;
  }
  return str;
}

void get_realnumber(Realnumber *real, char format, va_list *arguments) {
  if (format == 'L') {
    real->numb = va_arg(*arguments, long double);
  } else {
    real->numb = va_arg(*arguments, double);
  }
  if (real->numb < 0)
    real->sign = -1;
  else
    real->sign = 1;
}

char *print_f(char *str, params param, char format, va_list *arguments) {
  Realnumber real = {0};
  get_realnumber(&real, format, arguments);

  if (!is_inf_nan(real.numb)) {
    s21_size_t size_f = get_size_f_e(&param, &real);
    char *buffer = malloc(sizeof(char) * size_f);
    if (buffer) {
      int len = f_e_to_buffer(buffer, param, size_f, real);
      str = append_to_str(param.width, len, buffer, str);
    }
    if (buffer) free(buffer);
  } else {  // nan or +-inf
    str = print_inf_nan(str, param, real.numb);
  }
  return str;
}
int f_e_to_buffer(char *buffer, params param, s21_size_t size_f,
                  Realnumber real) {
  int i = 0;
  if (param.e) print_exp(&size_f, buffer, param, &i, real);

  size_f = double_to_str(buffer, param, size_f, &i, real);

  if ((real.fraction == 0) && param.g) param.accuracy = 0;

  if (size_f == 1 && param.zero == 1 && param.spot_for_sign == 1)
    param.zero = 0;

  while (param.zero && buffer && (size_f - param.spot_for_sign > 0)) {
    buffer[i] = '0';
    i++;
    size_f--;
    param.width--;
  }

  if (param.space && real.sign == 1 && size_f) {
    buffer[i] = ' ';
    param.spot_for_sign = 0;
    i++;
    size_f--;
  }
  if (real.sign == -1 && size_f) {
    param.spot_for_sign = 0;
    buffer[i] = '-';
    i++;
    size_f--;
  }
  if (real.sign == 1 && param.plus && size_f) {
    buffer[i] = '+';
    i++;
    size_f--;
    param.spot_for_sign = 0;
  }

  if (size_f > 0 && param.minus == 0) {
    if (param.e) param.spot_for_sign = 0;

    while (size_f - param.spot_for_sign > 0 && buffer) {
      buffer[i] = ' ';
      i++;
      size_f--;
    }
  }
  return i;
}

s21_size_t get_size_f_e(params *param, Realnumber *real) {
  s21_size_t size = 0;
  long double integer = 0;
  long double frac = modfl(fabsl(real->numb), &integer);
  long double copy_frac = frac;
  int rounded = 0;

  if (copy_frac >= 0.999999999999999 || (long long int)copy_frac == 1) {
    copy_frac = 0.0;
    integer += 1.0;
    rounded = 1;
  }
  real->whole = (s21_size_t)fabsl(integer);

  int count = 0;
  while (integer >= 0.99999999999999999) {
    integer /= 10;
    count++;
  }
  if (!param->g && !param->accuracy && !param->dot &&
      !((long int)(copy_frac * 1000000000000000000) == 0 && param->dot)) {
    param->accuracy = 6;
  }
  real->whole_size = count;

  count = 0;
  if (param->e) {
    for (int j = 0; j < param->accuracy; j++) {
      copy_frac *= 10;
      count++;
    }
  } else {
    for (int j = 0; j < 17 && j < param->accuracy; j++) {
      copy_frac *= 10;
      count++;
    }
  }
  int flagdot = 0;
  real->fraction_size = count;
  real->fraction = (s21_size_t)copy_frac;

  if (!param->accuracy && (frac * 10) >= 4.999999999999999 && !rounded)
    (real->whole)++;
  if (param->e && real->whole == int_pow(10, real->whole_size)) {
    real->numb = 1.0 * real->sign;
    real->whole = 1;
    real->fraction = 0;
    real->exp += real->exp_sign;
  }

  if (param->accuracy && ((s21_size_t)(copy_frac * 10)) % 10 > 4) {
    (real->fraction)++;
    if (param->e && real->fraction == int_pow(10, real->fraction_size)) {
      real->whole++;
      real->fraction = 0;
      if (real->whole == 10) {
        real->numb = 1.0 * real->sign;
        real->whole = 1;
        real->fraction = 0;
        real->exp += real->exp_sign;
      }
    }
  }
  size = real->whole_size + real->fraction_size;
  if (param->accuracy) size++;
  if ((s21_size_t)param->width <= size && !param->e) {
    flagdot = 1;
  }

  if (real->fraction == 0 && param->dot && flagdot && real->whole != 0) size++;

  if ((s21_size_t)param->accuracy > size) size = param->accuracy;

  if (param->space || param->plus || real->sign == -1) {
    param->spot_for_sign = 1;
    size++;
  }
  if (real->whole == 0) {
    size++;
    real->whole_size++;
  }
  if ((s21_size_t)param->width > size && !param->e) {
    size = param->width;
  }

  return size;
}

s21_size_t double_to_str(char *str_f, params param,

                         s21_size_t size_f, int *i_ptr, Realnumber real) {
  int i = *i_ptr;
  int printdot = param.accuracy || (real.fraction == 0 && param.lattice);
  if (param.g && real.fraction == 0 && !param.lattice) {
    printdot = 0;
    size_f--;
  }

  while (str_f && real.fraction_size) {
    str_f[i] = real.fraction % 10 + '0';
    i++;
    size_f--;
    real.fraction /= 10;
    real.fraction_size--;
  }

  real.whole += real.fraction;
  if (printdot && size_f) {
    str_f[i] = '.';
    i++;
    size_f--;
  }

  while (str_f && real.whole_size) {
    str_f[i] = real.whole % 10 + '0';
    i++;
    size_f--;
    real.whole_size--;
    real.whole /= 10;
  }
  *i_ptr = i;
  return size_f;
}

int is_inf_nan(long double num) {
  int is = 0;
  if (num != num)
    is = 1;
  else if (num + 111 == num)
    is = 1;
  return is;
}

char *print_inf_nan(char *str, params param, long double num) {
  char *string = calloc(5, 1);
  if (string) {
    if (num != num) {
      if (param.capital)
        my_strcpy(string, "NAN");
      else
        my_strcpy(string, "nan");
    } else if (num + 21 == num && num > 0) {
      if (param.capital)
        if (param.plus)
          my_strcpy(string, "+INF");
        else if (param.space)
          my_strcpy(string, " INF");
        else
          my_strcpy(string, "INF");
      else if (param.plus)
        my_strcpy(string, "+inf");
      else if (param.space)
        my_strcpy(string, " inf");
      else
        my_strcpy(string, "inf");
    } else if (num + 21 == num && num < 0) {
      if (param.capital)
        my_strcpy(string, "-INF");
      else
        my_strcpy(string, "-inf");
    }
    param.accuracy = s21_strlen(string);
    str = print_s(str, param, string);
    free(string);
  }
  return str;
}

params def_param_eg(params param, char format) {
  if (format == 'g' || format == 'G')
    param.g = 1;
  else if (format == 'e' || format == 'E')
    param.e = 1;
  if (format == 'G' || format == 'E') param.capital = 1;
  return param;
}

int find_e(Realnumber *real) {
  int e = 0;
  long double num = fabsl(real->numb);
  if (num > 0.9999999999) {
    real->exp_sign = 1;
    while (num > 10) {
      num /= 10;
      e++;
    }
  } else if (num == 0.0) {
    real->exp_sign = 1;
  } else {
    real->exp_sign = -1;
    while (num < 0.9999999999) {
      num *= 10;
      e++;
    }
  }
  real->numb = num * real->sign;
  return e;
}

char *print_e_(char *str, params param, char format, va_list *arguments) {
  Realnumber real = {0};
  get_realnumber(&real, format, arguments);

  if (!is_inf_nan(real.numb)) {
    s21_size_t size = 0;

    real.exp = find_e(&real);
    if (param.accuracy == 0 && !param.dot) param.accuracy = 6;

    size += get_size_f_e(&param, &real);

    size += 4;  //"e+99"

    if ((int)size < param.accuracy) size = param.accuracy;
    if ((int)size < param.width) size = param.width;

    char *buffer = malloc(sizeof(char) * size);

    if (buffer) {
      int len = f_e_to_buffer(buffer, param, size, real);
      str = append_to_str(param.width, len, buffer, str);
    }
    if (buffer) free(buffer);
  } else {
    str = print_inf_nan(str, param, real.numb);
  }
  return str;
}

void print_exp(s21_size_t *size_f, char *str, params param, int *i,
               Realnumber real) {
  int copy_e = real.exp;
  if (real.exp == 0) *size_f -= add_symbol(str + *i, i, '0');
  while (copy_e) {
    *size_f -= add_symbol(str + *i, i, '0' + copy_e % 10);
    copy_e /= 10;
  }
  if (real.exp < 10) *size_f -= add_symbol(str + *i, i, '0');
  if (real.exp_sign == 1 || real.exp == 0)
    *size_f -= add_symbol(str + *i, i, '+');
  else
    *size_f -= add_symbol(str + *i, i, '-');
  if (param.capital)
    *size_f -= add_symbol(str + *i, i, 'E');
  else
    *size_f -= add_symbol(str + *i, i, 'e');
}

int add_symbol(char *str, int *len, char symbol) {
  int res = 0;
  if (str) {
    *str = symbol;
    (*len)++;
    res = 1;
  }
  return res;
}

s21_size_t int_pow(int base, int degree) {
  s21_size_t power = 1;
  for (int i = 0; i < degree; i++) {
    power *= base;
  }
  return power;
}

char *my_strcpy(char *dst, const char *src) {
  unsigned char *p1 = (unsigned char *)dst;
  const unsigned char *p2 = (const unsigned char *)src;

  while (*p2) {
    *p1 = *p2;
    p2++;
    p1++;
  };
  *p1 = '\0';
  return dst;
}

char *print_g(char *str, params param, char format, va_list *arguments) {
  Realnumber real = {0};
  get_realnumber(&real, format, arguments);

  if (!is_inf_nan(real.numb)) {
    Realnumber real_ = real;
    real_.exp = find_e(&real_);
    int e = real_.exp * real_.exp_sign;
    if (param.accuracy == 0 && !param.dot) param.accuracy = 6;

    if (-4 <= e && e <= 5) {
      str = print_as_f(str, &param, &real, e);
    } else {
      if (e < 0) {
        str = print_as_e(str, &param, &real);
      } else {
        if (param.accuracy < e + 1) {
          str = print_as_e(str, &param, &real);
        } else {
          param.accuracy -= e + 1;
          str = print_as_f(str, &param, &real, e);
        }
      }
    }

  } else {
    str = print_inf_nan(str, param, real.numb);
  }
  return str;
}

char *print_as_f(char *str, params *param, Realnumber *real, int e) {
  s21_size_t size = 0;
  param->e = 0;
  size = get_size_f_e(param, real);
  if (param->accuracy - e - 1 >= 0) param->accuracy -= e + 1;
  size = get_size_f_e(param, real);
  char *buffer = malloc(sizeof(char) * size);
  if (buffer) {
    while (real->fraction_size && real->fraction % 10 == 0 && !param->lattice) {
      size--;
      real->fraction /= 10;
      real->fraction_size--;
      param->accuracy--;
    }
    int len = f_e_to_buffer(buffer, *param, size, *real);
    str = append_to_str(param->width, len, buffer, str);
  }
  if (buffer) free(buffer);
  return str;
}

char *print_as_e(char *str, params *param, Realnumber *real) {
  s21_size_t size = 0;
  param->e = 1;
  if (param->accuracy) param->accuracy--;

  real->exp = find_e(real);
  size = get_size_f_e(param, real) + 4;

  if ((int)size < param->accuracy) size = param->accuracy;
  if ((int)size < param->width) size = param->width;

  char *buffer = malloc(sizeof(char) * size);
  if (buffer) {
    while (real->fraction_size && real->fraction % 10 == 0 && !param->lattice &&
           real->whole != 0) {
      size--;
      real->fraction /= 10;
      real->fraction_size--;
    }
    int len = f_e_to_buffer(buffer, *param, size, *real);
    str = append_to_str(param->width, len, buffer, str);
  }
  if (buffer) free(buffer);
  return str;
}