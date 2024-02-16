#ifndef S21_STRING_H
#define S21_STRING_H

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "s21_errlist.h"

#define S21_NULL (void *)0
#define MAXLENGTH 1024
#define PI 3.14159265358979323846
typedef unsigned long long s21_size_t;

s21_size_t s21_strlen(const char *str);
s21_size_t s21_strcspn(const char *str1, const char *str2);
void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strerror(int errnum);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

int s21_sprintf(char *str, const char *format, ...);
int s21_sscanf(const char *str, const char *format, ...);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

char *s21_int_to_str(char *str, int variable);
char *s21_strcat(char *dest, const char *append);

typedef struct {
  int plus;
  int minus;
  int space;
  int lattice;
  int zero;
  int width;
  int accuracy;
  char length;
  int number_system;
  int spot_for_sign;
  int dot;
  int capital;
  int g;
  int e;
  int p;
} params;

typedef struct {
  long double numb;
  int sign;
  s21_size_t whole;
  s21_size_t fraction;
  int whole_size;
  int fraction_size;
  int exp;
  int exp_sign;
} Realnumber;

// SPRINTF HEADER

char *my_strcpy(char *dst, const char *src);
int add_symbol(char *str, int *i, char symbol);
char *append_to_str(int width, int i, const char *buffer, char *str);

const char *def_param(params *param, const char *format, va_list *arguments);
const char *def_flags(const char *format, params *param);
const char *def_capacity(const char *format, int *width, va_list *arguments);
params def_number_system(params param, char ch_format);
char *process_specificator(char *str, char *source, const char *format,
                           params param, va_list *arguments);
char *print_c(char *str, params param, int symbol);
char *print_s(char *str, params param, char *string);
char *print_d(char *str, params param, va_list *arguments);
s21_size_t get_size_d(params *param, long int num);
int int_to_buffer(params param, long int num, char *buffer, s21_size_t size_d);
char *print_upositive(char *str, params param, unsigned long int num);
char *print_unull(char *str, params param);
int ui_to_buffer(char *buffer, params param, unsigned long int num,
                 s21_size_t size_u);

void print_exp(s21_size_t *size_f, char *str__f, params param, int *i,
               Realnumber real);
char *print_f(char *str, params param, char format, va_list *arguments);
char *print_e_(char *str, params param, char format, va_list *arguments);
params def_param_eg(params param, char format);
int f_e_to_buffer(char *str_f, params param, s21_size_t size_f,
                  Realnumber real);
char *print_inf_nan(char *str, params param, long double num);
int find_e(Realnumber *real);
params def_param_g(params param, Realnumber real);
int s21_sprintf(char *str, const char *format, ...);

s21_size_t get_size_u(params param, unsigned long int num);
s21_size_t get_size_f_e(params *param, Realnumber *real);
int is_inf_nan(long double num);
s21_size_t double_to_str(char *str_f, params param, s21_size_t size_f,
                         int *i_ptr, Realnumber real);
s21_size_t int_pow(int base, int degree);
char *print_g(char *str, params param, char format, va_list *arguments);
void get_realnumber(Realnumber *real, char format, va_list *arguments);
char *print_as_f(char *str, params *param, Realnumber *real, int e);
char *print_as_e(char *str, params *param, Realnumber *real);

#endif