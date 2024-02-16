#include "../s21_string.h"

#include <check.h>
#include <string.h>

#define BUFF_SIZE 2048

/* ------=====           testing s21_insert         =====------ */

/* ------=====                   START                  =====------ */
START_TEST(insert_1) {
  s21_size_t n = 2;
  char src[128] = "Tahow me the code.";
  char str[128] = "lk is cheap. S";
  char *str_exp = "Talk is cheap. Show me the code.";
  char *str_got = (char *)s21_insert(src, str, n);
  ck_assert_pstr_eq(str_got, str_exp);
  if (str_got) free(str_got);
}
END_TEST

START_TEST(insert_2) {
  s21_size_t n = 20;
  char src[128] = "Tahow me the code.";
  char str[128] = "lk is cheap. S";
  char *str_exp = S21_NULL;
  char *str_got = (char *)s21_insert(src, str, n);
  ck_assert_pstr_eq(str_got, str_exp);
  if (str_got) free(str_got);
}
END_TEST

START_TEST(insert_3) {
  s21_size_t n = 8;
  char *src = S21_NULL;
  char str[128] = "AbobaBoy";
  char *str_exp = S21_NULL;
  char *str_got = (char *)s21_insert(src, str, n);
  ck_assert_pstr_eq(str_got, str_exp);
  if (str_got) free(str_got);
}
END_TEST

START_TEST(insert_4) {
  s21_size_t n = 8;
  char *src = S21_NULL;
  char *str = S21_NULL;
  char *str_exp = S21_NULL;
  char *str_got = (char *)s21_insert(src, str, n);
  ck_assert_pstr_eq(str_got, str_exp);
  if (str_got) free(str_got);
}
END_TEST

START_TEST(insert_5) {
  s21_size_t n = 5;
  char *src = "";
  char *str = "";
  char *str_exp = S21_NULL;
  char *str_got = (char *)s21_insert(src, str, n);
  ck_assert_pstr_eq(str_got, str_exp);
  if (str_got) free(str_got);
}
END_TEST

START_TEST(insert_6) {
  s21_size_t n = 3;
  char *src = "";
  char *str = "";
  char *str_exp = S21_NULL;
  char *str_got = (char *)s21_insert(src, str, n);
  ck_assert_pstr_eq(str_got, str_exp);
  if (str_got) free(str_got);
}
END_TEST
/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_memchr         =====------ */

/* ------=====                   START                  =====------ */
START_TEST(memchr_1) {
  s21_size_t num_of_byte = 0;
  char *str_1 = "";
  int search = '\0';
  ck_assert_ptr_eq(s21_memchr(str_1, search, num_of_byte),
                   memchr(str_1, search, num_of_byte));
}
END_TEST

START_TEST(memchr_2) {
  s21_size_t num_of_byte = 10;
  char *str_1 = "Aboba Boy";
  int search = '\0';
  ck_assert_ptr_eq(s21_memchr(str_1, search, num_of_byte),
                   memchr(str_1, search, num_of_byte));
}
END_TEST

START_TEST(memchr_3) {
  s21_size_t num_of_byte = 10;
  char *str_1 = "Aboba Boy";
  int search = '\0';
  ck_assert_ptr_eq(s21_memchr(str_1, search, num_of_byte),
                   memchr(str_1, search, num_of_byte));
}
END_TEST

START_TEST(memchr_4) {
  s21_size_t num_of_byte = 10;
  char *str_1 = "Aboba Boy";
  int search = 'B';
  ck_assert_ptr_eq(s21_memchr(str_1, search, num_of_byte),
                   memchr(str_1, search, num_of_byte));
}
END_TEST

START_TEST(memchr_5) {
  s21_size_t num_of_byte = 10;
  char *str_1 = "Aboba Boy";
  int search = 'o';
  ck_assert_ptr_eq(s21_memchr(str_1, search, num_of_byte),
                   memchr(str_1, search, num_of_byte));
}
END_TEST

START_TEST(memchr_6) {
  s21_size_t num_of_byte = 16;
  char *str_1 = "Aboba B1230456y";
  int search = '0';
  ck_assert_ptr_eq(s21_memchr(str_1, search, num_of_byte),
                   memchr(str_1, search, num_of_byte));
}
END_TEST

START_TEST(memchr_7) {
  float arr[] = {1, 2, 3, 2048, 9, 87, 6};
  s21_size_t num_of_byte = sizeof(float) * 7;
  int search = 2048;
  ck_assert_ptr_eq(s21_memchr(arr, search, num_of_byte),
                   memchr(arr, search, num_of_byte));
}
END_TEST

START_TEST(memchr_8) {
  s21_size_t num_of_byte = 10;
  char *str_1 = "Aboba boy";
  int search = 'V';
  ck_assert_ptr_eq(s21_memchr(str_1, search, num_of_byte),
                   memchr(str_1, search, num_of_byte));
}
END_TEST
/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_memcmp         =====------ */

/* ------=====                   START                  =====------ */
START_TEST(memcmp_1) {
  s21_size_t n = 4;
  char *str_1 = "Magiko mi Dubi";
  char *str_2 = "Magiko mi Dubi";
  int func = s21_memcmp(str_1, str_2, n);
  int orig = memcmp(str_1, str_2, n);
  ck_assert_int_eq(func, orig);
}
END_TEST

START_TEST(memcpy_1) {
  s21_size_t bytes_q = 8;
  char str[128] = "";
  char s21_str[128] = "";
  char *src = "11123332\02345";
  ck_assert_pstr_eq(memcpy(str, src, bytes_q),
                    s21_memcpy(s21_str, src, bytes_q));
}
END_TEST

START_TEST(memcpy_2) {
  s21_size_t bytes_q = 8;
  char str[128] = "Chipi chipi";
  char s21_str[128] = "Chipi chipi";
  char *src = "reneesaa";
  ck_assert_pstr_eq(memcpy(str, src, bytes_q),
                    s21_memcpy(s21_str, src, bytes_q));
}
END_TEST

START_TEST(memcpy_3) {
  s21_size_t bytes_q = 7;
  char str[128] = "Magiko mi Dubi";
  char s21_str[128] = "Magiko mi Dubi";
  ck_assert_pstr_eq(memcpy(str, str + 7, bytes_q),
                    s21_memcpy(s21_str, s21_str + 7, bytes_q));
}
END_TEST
/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_memset         =====------ */

/* ------=====                   START                  =====------ */
START_TEST(memset_1) {
  s21_size_t n = 6;
  int c = '7';
  char str[128] = "Banana No Peels ";
  char s21_str[128] = "Banana No Peels ";
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(s21_str, c, n));
}
END_TEST

START_TEST(memset_2) {
  s21_size_t n = 4;
  int c = '4';
  char str[128] = "T-Choppa";
  char s21_str[128] = "T-Choppa";
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(s21_str, c, n));
}
END_TEST

START_TEST(memset_3) {
  s21_size_t n = 0;
  int c = '4';
  char str[128] = "Suburban$";
  char s21_str[128] = "Suburban$";
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(s21_str, c, n));
}
END_TEST

START_TEST(memset_4) {
  s21_size_t n = 3;
  int c = '\0';
  char str[128] = "T-Choppa";
  char s21_str[128] = "T-Choppa";
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(s21_str, c, n));
}
END_TEST

START_TEST(memset_5) {
  s21_size_t n = 3;
  int c = '4';
  char str[128] = "";
  char s21_str[128] = "";
  ck_assert_pstr_eq(memset(str, c, n), s21_memset(s21_str, c, n));
}
END_TEST
/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_strchr         =====------ */

/* ------=====                   START                  =====------ */
START_TEST(strchr_1) {
  char *str = "This work created by Ded inside";
  char c = 'D';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_2) {
  char *str = "This work created by Ded inside";
  char c = 'Z';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_3) {
  char *str = "This work created by \0Ded inside";
  char c = 'D';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST
/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_strcspn        =====------ */

/* ------=====                   START                  =====------ */
START_TEST(strcspn_1) {
  char *str = "This work created by Ded inside";
  char *src = "by";
  ck_assert_int_eq(strcspn(str, src), s21_strcspn(str, src));
}
END_TEST

START_TEST(strcspn_2) {
  char *str = "This work created by Ded inside";
  char *src = "QAZ";
  ck_assert_int_eq(strcspn(str, src), s21_strcspn(str, src));
}
END_TEST

START_TEST(strcspn_3) {
  char *str = "This work created \0by Ded inside";
  char *src = "by";
  ck_assert_int_eq(strcspn(str, src), s21_strcspn(str, src));
}
END_TEST

START_TEST(strcspn_4) {
  char *str = "This work created by Ded inside";
  char *src = "by\0cnsdi";
  ck_assert_int_eq(strcspn(str, src), s21_strcspn(str, src));
}
END_TEST

START_TEST(strcspn_5) {
  char *str = "+7 800 555 35 35";
  char *src = "58463";
  ck_assert_int_eq(strcspn(str, src), s21_strcspn(str, src));
}
END_TEST
/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_strerror       =====------ */

/* ------=====                   START                  =====------ */
START_TEST(strerror_1) {
  int err_num = -7;
  ck_assert_str_eq(strerror(err_num), s21_strerror(err_num));
}
END_TEST

START_TEST(strerror_2) {
  for (int i = 0; i < 134; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}

START_TEST(strerror_3) {
  int err_num = 160;
  ck_assert_str_eq(strerror(err_num), s21_strerror(err_num));
}
END_TEST
/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_strlen         =====------ */

/* ------=====                   START                  =====------ */
START_TEST(strlen_1) {
  char *str_1 = "Derangt0n\0";
  ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
}
END_TEST

START_TEST(strlen_2) {
  char *str_1 = "This work created \0 by Ded inside";
  ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
}
END_TEST

START_TEST(strlen_3) {
  char *str_1 = "\0";
  ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
}
END_TEST

START_TEST(strlen_4) {
  char *str_1 =
      "WWEGETF #$ @ @:::: ;;; !! ||| "
      " 123552345\0 ' ' ";
  ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
}
END_TEST
/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_strncat        =====------ */

/* ------=====                   START                  =====------ */
START_TEST(strncat_1) {
  s21_size_t n = 6;
  char str[128] = "";
  char s21_str[128] = "";
  char *src = "";
  ck_assert_pstr_eq(strncat(str, src, n), s21_strncat(s21_str, src, n));
}
END_TEST

START_TEST(strncat_2) {
  s21_size_t n = 2;
  char str[128] = "123456";
  char s21_str[128] = "123456";
  char *src = "Evolution";
  ck_assert_pstr_eq(strncat(str, src, n), s21_strncat(s21_str, src, n));
}
END_TEST

START_TEST(strncat_3) {
  s21_size_t n = 8;
  char str[128] = "This work created by ";
  char s21_str[128] = "This work created by ";
  char *src = "Ded inside";
  ck_assert_pstr_eq(strncat(str, src, n), s21_strncat(s21_str, src, n));
}
END_TEST

START_TEST(strncat_4) {
  s21_size_t n = 0;
  char str[128] = "";
  char s21_str[128] = "";
  char *src = "Abobus";
  ck_assert_pstr_eq(strncat(str, src, n), s21_strncat(s21_str, src, n));
}
END_TEST

START_TEST(strncat_5) {
  s21_size_t n = 9;
  char str[128] = "";
  char s21_str[128] = "";
  char *src = "Abobus";
  ck_assert_pstr_eq(strncat(str, src, n), s21_strncat(s21_str, src, n));
}
END_TEST

START_TEST(strncat_6) {
  s21_size_t n = 5;
  char str[128] = "Gailfeda";
  char s21_str[128] = "Gailfeda";
  char *src = "";
  ck_assert_pstr_eq(strncat(str, src, n), s21_strncat(s21_str, src, n));
}
END_TEST

START_TEST(strncat_7) {
  s21_size_t n = 5;
  char str[128] = "Const\0anc";
  char s21_str[128] = "Const\0anc";
  char *src = "end";
  ck_assert_pstr_eq(strncat(str, src, n), s21_strncat(s21_str, src, n));
}
END_TEST

START_TEST(strncat_8) {
  s21_size_t n = 1;
  char str[128] = "Persiana";
  char s21_str[128] = "Persiana";
  char *src = "\0";
  ck_assert_pstr_eq(strncat(str, src, n), s21_strncat(s21_str, src, n));
}
END_TEST
/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_strncmp        =====------ */

/* ------=====                   START                  =====------ */
START_TEST(strncmp_1) {
  s21_size_t n = 5;
  char *str_1 = "Chipi of chapa";
  char *str_2 = "Chipi of chapa";
  int system = strncmp(str_1, str_2, n);
  int s21 = s21_strncmp(str_1, str_2, n);
  system > 1 ? system = 1 : system < -1 ? system = -1 : system;
  s21 > 1 ? s21 = 1 : s21 < -1 ? s21 = -1 : s21;
  ck_assert_int_eq(system, s21);
}
END_TEST

START_TEST(strncmp_2) {
  s21_size_t n = 3;
  char *str_1 = "";
  char *str_2 = "Chipi of chapa";
  int system = strncmp(str_1, str_2, n);
  int s21 = s21_strncmp(str_1, str_2, n);
  system > 1 ? system = 1 : system < -1 ? system = -1 : system;
  s21 > 1 ? s21 = 1 : s21 < -1 ? s21 = -1 : s21;
  ck_assert_int_eq(system, s21);
}
END_TEST

START_TEST(strncmp_3) {
  s21_size_t n = 14;
  char *str_1 = "Chipi of chapa chapa";
  char *str_2 = "Chipi of chapa chapa";
  int system = strncmp(str_1, str_2, n);
  int s21 = s21_strncmp(str_1, str_2, n);
  system > 1 ? system = 1 : system < -1 ? system = -1 : system;
  s21 > 1 ? s21 = 1 : s21 < -1 ? s21 = -1 : s21;
  ck_assert_int_eq(system, s21);
}
END_TEST

START_TEST(strncmp_4) {
  s21_size_t n = 4;
  char *str_1 = "Chipi of chapa";
  char *str_2 = "Chipi of ";
  int system = strncmp(str_1, str_2, n);
  int s21 = s21_strncmp(str_1, str_2, n);
  system > 1 ? system = 1 : system < -1 ? system = -1 : system;
  s21 > 1 ? s21 = 1 : s21 < -1 ? s21 = -1 : s21;
  ck_assert_int_eq(system, s21);
}
END_TEST
/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_memcmp         =====------ */

/* ------=====                   START                  =====------ */
START_TEST(strncpy_1) {
  s21_size_t n = 4;
  char str[128] = "OakTrees";
  char s21_str[128] = "OakTrees";
  char *src = "Best!";
  ck_assert_pstr_eq(strncpy(str, src, n), s21_strncpy(s21_str, src, n));
}
END_TEST

START_TEST(strncpy_2) {
  s21_size_t n = 4;
  char str[128] = "OakTrees";
  char s21_str[128] = "OakTrees";
  char *src = "Be\0st!";
  ck_assert_pstr_eq(strncpy(str, src, n), s21_strncpy(s21_str, src, n));
}
END_TEST

START_TEST(strncpy_3) {
  s21_size_t n = 7;
  char str[128] = "+7 800 555 35 35";
  char s21_str[128] = "+7 800 555 35 35";
  char *src = "21564\0vfs003543";
  ck_assert_pstr_eq(strncpy(str, src, n), s21_strncpy(s21_str, src, n));
}
END_TEST

START_TEST(strncpy_4) {
  s21_size_t n = 0;
  char str[128] = "";
  char s21_str[128] = "";
  char *src = "";
  ck_assert_pstr_eq(strncpy(str, src, n), s21_strncpy(s21_str, src, n));
}
END_TEST

START_TEST(strncpy_5) {
  s21_size_t n = 0;
  char str[128] = "OakTrees";
  char s21_str[128] = "OakTrees";
  char *src = "Best!";
  ck_assert_pstr_eq(strncpy(str, src, n), s21_strncpy(s21_str, src, n));
}
END_TEST

START_TEST(strncpy_6) {
  s21_size_t n = 5;
  char str[128] = "OakTrees";
  char s21_str[128] = "OakTrees";
  char *src = "";
  ck_assert_pstr_eq(strncpy(str, src, n), s21_strncpy(s21_str, src, n));
}
END_TEST
/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_strpbrk        =====------ */

/* ------=====                   START                  =====------ */
START_TEST(strpbrk_1) {
  char *str = "You can modify your code";
  char *src = "cde";
  ck_assert_pstr_eq(strpbrk(str, src), s21_strpbrk(str, src));
}
END_TEST

START_TEST(strpbrk_2) {
  char *str = "You can modify your code";
  char *src = "";
  ck_assert_pstr_eq(strpbrk(str, src), s21_strpbrk(str, src));
}
END_TEST

START_TEST(strpbrk_3) {
  char *str = "";
  char *src = "dev";
  ck_assert_pstr_eq(strpbrk(str, src), s21_strpbrk(str, src));
}
END_TEST

START_TEST(strpbrk_4) {
  char *str = "Raise of sunrise";
  char *src = "465";
  ck_assert_pstr_eq(strpbrk(str, src), s21_strpbrk(str, src));
}
END_TEST

START_TEST(strpbrk_5) {
  char *str = "Raise of sunrise";
  char *src = "/0";
  ck_assert_pstr_eq(strpbrk(str, src), s21_strpbrk(str, src));
}
END_TEST

START_TEST(strpbrk_6) {
  char *str = "Raise of sunrise";
  char *src = "rAISeESI";
  ck_assert_pstr_eq(strpbrk(str, src), s21_strpbrk(str, src));
}
END_TEST
/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_strrchr        =====------ */

/* ------=====                   START                  =====------ */
START_TEST(strrchr_1) {
  char *str = "Raise of sunrise";
  char c = 'o';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_2) {
  char *str = "Raise \0of sunrise";
  char c = 'o';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_3) {
  char *str = "Raise of \0sunrise";
  char c = 'o';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_4) {
  char *str = "Raise of sunrise";
  char c = '\0';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_5) {
  char *str = "Raise of sunrise";
  char c = 'Z';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_6) {
  char *str = "Raise of sunrise";
  char c = 'Z';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_7) {
  char *str = "";
  char c = 'D';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_8) {
  char *str = "+7 800 555 35 35";
  char c = '3';
  ck_assert_pstr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST
/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_strstr         =====------ */

/* ------=====                   START                  =====------ */
START_TEST(strstr_1) {
  char *str = "This work created by Ded inside";
  char *needle = "ed in";
  ck_assert_pstr_eq(strstr(str, needle), s21_strstr(str, needle));
}
END_TEST

START_TEST(strstr_2) {
  char *str = "This work created by Ded inside";
  char *needle = " by \0Ded";
  ck_assert_pstr_eq(strstr(str, needle), s21_strstr(str, needle));
}
END_TEST

START_TEST(strstr_3) {
  char *str = "";
  char *needle = "ed in";
  ck_assert_pstr_eq(strstr(str, needle), s21_strstr(str, needle));
}
END_TEST

START_TEST(strstr_4) {
  char *str = "This work created \0by Ded inside";
  char *needle = "by";
  ck_assert_pstr_eq(strstr(str, needle), s21_strstr(str, needle));
}
END_TEST

START_TEST(strstr_5) {
  char *str = "This work created by Ded inside";
  char *needle = "";
  ck_assert_pstr_eq(strstr(str, needle), s21_strstr(str, needle));
}
END_TEST

START_TEST(strstr_6) {
  char *str = "";
  char *needle = "";
  ck_assert_pstr_eq(strstr(str, needle), s21_strstr(str, needle));
}
END_TEST
/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_strlen         =====------ */
/* ------=====                   START                  =====------ */
START_TEST(strtok_1) {
  char str[] = "This,work/created/by Ded,inside";
  char s21_str[] = "This,work/created/by Ded,inside";
  const char delim[] = ", /";
  char *system = strtok(str, delim);
  char *s21 = s21_strtok(s21_str, delim);
  ck_assert_uint_eq(s21_strlen(system), s21_strlen(s21));
  ck_assert_str_eq(system, s21);
  while (system && s21) {
    system = strtok(S21_NULL, delim);
    s21 = s21_strtok(S21_NULL, delim);
    if (system || s21) {
      ck_assert_str_eq(system, s21);
    } else {
      ck_assert_ptr_null(system);
      ck_assert_ptr_null(s21);
    }
  }
}
END_TEST

START_TEST(strtok_2) {
  char str[] = "This+++,work/cre==ated/by -=+?---Ded??,inside";
  char s21_str[] = "This+++,work/cre==ated/by -=+?---Ded??,inside";
  const char delim[] = ", /+=-?";
  char *system = strtok(str, delim);
  char *s21 = s21_strtok(s21_str, delim);
  ck_assert_uint_eq(s21_strlen(system), s21_strlen(s21));
  ck_assert_str_eq(system, s21);
  while (system && s21) {
    system = strtok(S21_NULL, delim);
    s21 = s21_strtok(S21_NULL, delim);
    if (system || s21) {
      ck_assert_str_eq(system, s21);
    } else {
      ck_assert_ptr_null(system);
      ck_assert_ptr_null(s21);
    }
  }
}
END_TEST

START_TEST(strtok_3) {
  char str[] = "ThisworkcreatedbyDedinside";
  char s21_str[] = "ThisworkcreatedbyDedinside";
  const char delim[] = ", /";
  char *system = strtok(str, delim);
  char *s21 = s21_strtok(s21_str, delim);
  ck_assert_uint_eq(s21_strlen(system), s21_strlen(s21));
  ck_assert_str_eq(system, s21);
  while (system && s21) {
    system = strtok(S21_NULL, delim);
    s21 = s21_strtok(S21_NULL, delim);
    ck_assert_ptr_null(system);
    ck_assert_ptr_null(s21);
  }
}
END_TEST

START_TEST(strtok_4) {
  char str[] = "++++++constanc+++++";
  char s21_str[] = "++++++constanc+++++";
  const char delim[] = ", /+=-?";
  char *system = strtok(str, delim);
  char *s21 = s21_strtok(s21_str, delim);
  ck_assert_uint_eq(s21_strlen(system), s21_strlen(s21));
  ck_assert_str_eq(system, s21);
  while (system && s21) {
    system = strtok(S21_NULL, delim);
    s21 = s21_strtok(S21_NULL, delim);
    ck_assert_ptr_null(system);
    ck_assert_ptr_null(s21);
  }
}
END_TEST

START_TEST(strtok_5) {
  char str[] = "+A+a+B+b++G+     +D";
  char s21_str[] = "+A+a+B+b++G+     +D";
  const char delim[] = ", /+=-?";
  char *system = strtok(str, delim);
  char *s21 = s21_strtok(s21_str, delim);
  ck_assert_uint_eq(s21_strlen(system), s21_strlen(s21));
  ck_assert_str_eq(system, s21);
  while (system && s21) {
    system = strtok(S21_NULL, delim);
    s21 = s21_strtok(S21_NULL, delim);
    if (system || s21) {
      ck_assert_str_eq(system, s21);
    } else {
      ck_assert_ptr_null(system);
      ck_assert_ptr_null(s21);
    }
  }
}
END_TEST
/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_to_lower       =====------ */

/* ------=====                   START                  =====------ */
START_TEST(to_lower_1) {
  char str_1[] = "MONEY IS MY HONEY!";
  char *str_s21 = (char *)s21_to_lower(str_1);
  char *exp = "money is my honey!";
  ck_assert_str_eq(str_s21, exp);
  if (str_s21) free(str_s21);
}
END_TEST

START_TEST(to_lower_2) {
  char str_1[] = "MoNeY is MY hONeY! 88005553535";
  char *str_s21 = (char *)s21_to_lower(str_1);
  char *exp = "money is my honey! 88005553535";
  ck_assert_str_eq(str_s21, exp);
  if (str_s21) free(str_s21);
}
END_TEST

START_TEST(to_lower_3) {
  char str_1[] = ",.?!-_789123";
  char *str_s21 = (char *)s21_to_lower(str_1);
  char *exp = ",.?!-_789123";
  ck_assert_str_eq(str_s21, exp);
  if (str_s21) free(str_s21);
}
END_TEST

START_TEST(to_lower_4) {
  char str_1[] = "";
  char *str_s21 = (char *)s21_to_lower(str_1);
  char *exp = "";
  ck_assert_str_eq(str_s21, exp);
  if (str_s21) free(str_s21);
}
END_TEST
/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_to_upper       =====------ */
/* ------=====                   START                  =====------ */
START_TEST(to_upper_1) {
  char str_1[] = "best team!";
  char *str_s21 = (char *)s21_to_upper(str_1);
  char *exp = "BEST TEAM!";
  ck_assert_str_eq(str_s21, exp);
  if (str_s21) free(str_s21);
}
END_TEST

START_TEST(to_upper_2) {
  char str_1[] = "bEsT tEAm!9821";
  char *str_s21 = (char *)s21_to_upper(str_1);
  char *exp = "BEST TEAM!9821";
  ck_assert_str_eq(str_s21, exp);
  if (str_s21) free(str_s21);
}
END_TEST

START_TEST(to_upper_3) {
  char str_1[] = "";
  char *str_s21 = (char *)s21_to_upper(str_1);
  char *exp = "";
  ck_assert_str_eq(str_s21, exp);
  if (str_s21) free(str_s21);
}
END_TEST

START_TEST(to_upper_4) {
  char str_1[] = ",.?!-_789123";
  char *str_s21 = (char *)s21_to_upper(str_1);
  char *exp = ",.?!-_789123";
  ck_assert_str_eq(str_s21, exp);
  if (str_s21) free(str_s21);
}
END_TEST
/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_trim           =====------ */

/* ------=====                   START                  =====------ */
START_TEST(trim_1) {
  char str[] = "<,HONEY_";
  char str_trim[] = "_<,";
  char *exp = "HONEY";
  char *s21_str = (char *)s21_trim(str, str_trim);
  ck_assert_str_eq(s21_str, exp);
  if (s21_str) free(s21_str);
}
END_TEST

START_TEST(trim_2) {
  char str[] = "MoneyIsHoney";
  char str_trim[] = "IsH";
  char *exp = "MoneyIsHoney";
  char *s21_str = (char *)s21_trim(str, str_trim);
  ck_assert_str_eq(s21_str, exp);
  if (s21_str) free(s21_str);
}
END_TEST

START_TEST(trim_3) {
  char str[] = "    Money     ";
  char str_trim[] = " ";
  char *exp = "Money";
  char *s21_str = (char *)s21_trim(str, str_trim);
  ck_assert_str_eq(s21_str, exp);
  if (s21_str) free(s21_str);
}
END_TEST

START_TEST(trim_4) {
  char str[] = "      Money      ";
  char str_trim[] = "";
  char *exp = "Money";
  char *s21_str = (char *)s21_trim(str, str_trim);
  ck_assert_str_eq(s21_str, exp);
  if (s21_str) free(s21_str);
}
END_TEST

START_TEST(trim_5) {
  char str[] = "& -- ?Honey&&&---  ?";
  char str_trim[] = "&- ?";
  char *exp = "Honey";
  char *s21_str = (char *)s21_trim(str, str_trim);
  ck_assert_str_eq(s21_str, exp);
  if (s21_str) free(s21_str);
}
END_TEST

START_TEST(trim_6) {
  char str[] = "";
  char str_trim[] = ",*&";
  char *exp = "";
  char *s21_str = (char *)s21_trim(str, str_trim);
  ck_assert_str_eq(s21_str, exp);
  if (s21_str) free(s21_str);
}
END_TEST

/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_sprintf          =====------ */

/* ------=====                   START                  =====------ */

START_TEST(s21_sprintf_test_1) {
  // flag % c % d % s
  char std_1[80];
  char s21_1[80];
  char *s_null = S21_NULL;
  ck_assert_int_eq(sprintf(std_1, "%6s %d %-3c %hd %3s %-10s", "one", 2, '3',
                           34, s_null, "hello"),
                   s21_sprintf(s21_1, "%6s %d %-3c %hd %3s %-10s", "one", 2,
                               '3', 34, s_null, "hello"));
  ck_assert_str_eq(std_1, s21_1);

  char std_2[80];
  char s21_2[80];
  ck_assert_int_eq(sprintf(std_2, "%+d %-d % d", 123, 456, 789),
                   s21_sprintf(s21_2, "%+d %-d % d", 123, 456, 789));
  ck_assert_str_eq(std_2, s21_2);

  char std_3[80];
  char s21_3[80];
  ck_assert_int_eq(sprintf(std_3, "%ld", 123000000000),
                   s21_sprintf(s21_3, "%ld", 123000000000));
  ck_assert_str_eq(std_3, s21_3);
}
END_TEST

START_TEST(s21_sprintf_test_2) {
  // flag %i %u %x %X %o
  char std_1[80];
  char s21_1[80];
  ck_assert_int_eq(
      sprintf(std_1, "%i %*u %x %X %o %% %#x %#X", -123, 5, 456, 0xabc123,
              0xabc123, 01234567, 123456, 7890),
      s21_sprintf(s21_1, "%i %*u %x %X %o %% %#x %#X", -123, 5, 456, 0xabc123,
                  0xabc123, 01234567, 123456, 7890));
  ck_assert_str_eq(std_1, s21_1);

  // flag %f
  char std_2[80];
  char s21_2[80];
  long double long_double = 123456789.123456789;
  ck_assert_int_eq(sprintf(std_2, "%f %3.f %+f %03f %#5f %3.5f %.*Lf", -PI, PI,
                           PI, PI, -PI, PI, 5, long_double),
                   s21_sprintf(s21_2, "%f %3.f %+f %03f %#5f %3.5f %.*Lf", -PI,
                               PI, PI, PI, -PI, PI, 5, long_double));
  ck_assert_str_eq(std_2, s21_2);

  char std_3[80];
  char s21_3[80];
  ck_assert_int_eq(
      sprintf(std_3, "%lu %hu %hu", 123456789123456789, 123, 0),
      s21_sprintf(s21_3, "%lu %hu %hu", 123456789123456789, 123, 0));
  ck_assert_str_eq(std_3, s21_3);

  char std_4[80];
  char s21_4[80];
  ck_assert_int_eq(sprintf(std_4, "%f %f %f %F %F %F", NAN, INFINITY, -INFINITY,
                           NAN, INFINITY, -INFINITY),
                   s21_sprintf(s21_4, "%f %f %f %F %F %F", NAN, INFINITY,
                               -INFINITY, NAN, INFINITY, -INFINITY));
  ck_assert_str_eq(std_4, s21_4);
}
END_TEST

START_TEST(s21_sprintf_test_3) {
  // flag %p
  char std_1[80];
  char s21_1[80];
  ck_assert_int_eq(sprintf(std_1, "%p %5p %p", std_1, std_1, s21_1),
                   s21_sprintf(s21_1, "%p %5p %p", std_1, std_1, s21_1));
  ck_assert_str_eq(std_1, s21_1);

  // flag %e
  char std_2[100];
  char s21_2[100];
  ck_assert_int_eq(sprintf(std_2, "% 15.4e %-10e %.8E %#+E %#6e %-10.4g", PI,
                           -PI, PI, PI, 0.0, 0.0),
                   s21_sprintf(s21_2, "% 15.4e %-10e %.8E %#+E %#6e %-10.4g",
                               PI, -PI, PI, PI, 0.0, 0.0));
  ck_assert_str_eq(std_2, s21_2);
}
END_TEST

START_TEST(s21_sprintf_test_4) {
  char std_1[180];
  char s21_1[180];
  ck_assert_int_eq(
      sprintf(std_1, "%F % F %+F %f % f %+f %E", INFINITY, INFINITY, INFINITY,
              INFINITY, INFINITY, INFINITY, NAN),
      s21_sprintf(s21_1, "%F % F %+F %f % f %+f %E", INFINITY, INFINITY,
                  INFINITY, INFINITY, INFINITY, INFINITY, NAN));
  ck_assert_str_eq(std_1, s21_1);

  char std_2[180];
  char s21_2[180];
  ck_assert_int_eq(
      sprintf(std_2, "%.e %.3e %e %E %e", -9999.999999, 99.99999, 12.99999,
              -123456789012345.6, 0.999999999999999),
      s21_sprintf(s21_2, "%.e %.3e %e %E %e", -9999.999999, 99.99999, 12.99999,
                  -123456789012345.6, 0.999999999999999));
  ck_assert_str_eq(std_2, s21_2);

  char std_3[180];
  char s21_3[180];
  long double ldbl = 12320232023.2;
  ck_assert_int_eq(
      sprintf(std_3, "%e %E %9e %#e %LE %e %e", -23.456789, 0.000777,
              -0.000000004545, 31415926.0, ldbl, 0.0, 1.0),
      s21_sprintf(s21_3, "%e %E %9e %#e %LE %e %e", -23.456789, 0.000777,
                  -0.000000004545, 31415926.0, ldbl, 0.0, 1.0));
  ck_assert_str_eq(std_3, s21_3);
}
END_TEST

START_TEST(s21_sprintf_test_5) {
  char std_empty[80];
  char s21_empty[80];
  ck_assert_int_eq(sprintf(std_empty, "%.0i", 0),
                   s21_sprintf(s21_empty, "%.0i", 0));
  ck_assert_str_eq(std_empty, s21_empty);

  char std_1[80];
  char s21_1[80];
  ck_assert_int_eq(
      sprintf(std_1, "%8d %12c %d %.5i % 02d %p", 234, 'm', 0, 0, 1, std_1),
      s21_sprintf(s21_1, "%8d %12c %d %.5i % 02d %p", 234, 'm', 0, 0, 1,
                  std_1));
  ck_assert_str_eq(std_1, s21_1);

  char std_2[80];
  char s21_2[80];
  ck_assert_int_eq(sprintf(std_2, "%o %#o %.11u %02u %.8u %-12hu", 0, 345,
                           31415, 7, 123, 271),
                   s21_sprintf(s21_2, "%o %#o %.11u %02u %.8u %-12hu", 0, 345,
                               31415, 7, 123, 271));
  ck_assert_str_eq(std_2, s21_2);

  char std_3[180];
  char s21_3[180];
  ck_assert_int_eq(
      sprintf(std_3, "%# 0f %015f %f %.5f %#.f %f %.2f %f", 0.0, 123.45,
              23.9999999, 12.6656789, 25.0, 0.25, 4.999999, 90.999999),
      s21_sprintf(s21_3, "%# 0f %015f %f %.5f %#.f %f %.2f %f", 0.0, 123.45,
                  23.9999999, 12.6656789, 25.0, 0.25, 4.999999, 90.999999));
  ck_assert_str_eq(std_3, s21_3);
}
END_TEST

START_TEST(s21_sprintf_test_6) {  // flag %g
  char std_1[180];
  char s21_1[180];
  long double ldbl = -12345678.234499777777777777777777;
  char format1[100] = "%# -14.12Lg %08G % G %+.1G %0g %-05g %#.3g %-9g";

  ck_assert_int_eq(sprintf(std_1, format1, ldbl, INFINITY, -INFINITY, 2.0,
                           22.33, 0.0, 0.0, 1.0),
                   s21_sprintf(s21_1, format1, ldbl, INFINITY, -INFINITY, 2.0,
                               22.33, 0.0, 0.0, 1.0));
  ck_assert_str_eq(std_1, s21_1);

  char std_2[180];
  char s21_2[180];
  long double infi = -INFINITY;
  char format2[100] = "%+g %-6LG %0.10g %-0.8g %.8G";
  ck_assert_int_eq(sprintf(std_2, format2, 2.2, infi, 0.00555, -0.000000123456,
                           -0.00004565768776599),
                   s21_sprintf(s21_2, format2, 2.2, infi, 0.00555,
                               -0.000000123456, -0.00004565768776599));

  char std_3[180];
  char s21_3[180];
  char format3[100] = "%.8g %-12g %g %.3g %g";
  ck_assert_int_eq(sprintf(std_3, format3, 123.4, 12345.67, 1234567.8901,
                           0.00234, 0.00000123456),
                   s21_sprintf(s21_3, format3, 123.4, 12345.67, 1234567.8901,
                               0.00234, 0.00000123456));
  ck_assert_str_eq(std_3, s21_3);

  char std_4[180];
  char s21_4[180];
  char format4[100] =
      "%# -14.12Lg % .12g||text% .6g||% 12.2G||%011.8g % .4g....% G__%#0.10g";
  long double ldouble = -1234567823449977777.7777777777777;
  double dbl = -0.00000000999999;
  double d1 = -4567.67999999999;
  double d2 = -1234567890.02334;
  ck_assert_int_eq(sprintf(std_4, format4, ldouble, d1, dbl, -INFINITY, dbl,
                           dbl, d2, 0.000555),
                   s21_sprintf(s21_4, format4, ldouble, d1, dbl, -INFINITY, dbl,
                               dbl, d2, 0.000555));
  ck_assert_str_eq(std_4, s21_4);
}
END_TEST

/* ------=====                  FINISH                  =====------ */

/* ------=====           testing s21_sprintf          =====------ */

/* ------=====                   START                  =====------ */

START_TEST(s21_sscanf_test_1) {
  // %c
  const char *str_1 = "q werty";
  char x, y, z;
  char a, b, c;
  ck_assert_int_eq(s21_sscanf(str_1, "%c %c %c", &a, &b, &c),
                   sscanf(str_1, "%c %c %c", &x, &y, &z));
  ck_assert_int_eq(a, x);
  ck_assert_int_eq(b, y);
  ck_assert_int_eq(c, z);
}
END_TEST

START_TEST(s21_sscanf_test_2) {
  // %d
  const char *str_1 = "123 -456 789";
  int x, y, z;
  int a, b, c;
  ck_assert_int_eq(s21_sscanf(str_1, "%d %d %d", &a, &b, &c),
                   sscanf(str_1, "%d %d %d", &x, &y, &z));
  ck_assert_int_eq(a, x);
  ck_assert_int_eq(b, y);
  ck_assert_int_eq(c, z);
}
END_TEST

START_TEST(s21_sscanf_test_3) {
  // %s
  const char *str_1 = "hello world";
  char s21_1[20] = {0};
  char s21_2[20] = {0};
  char std_1[20] = {0};
  char std_2[20] = {0};
  ck_assert_int_eq(s21_sscanf(str_1, "%s %s", s21_1, s21_2),
                   sscanf(str_1, "%s %s", std_1, std_2));
  ck_assert_str_eq(s21_1, std_1);
  ck_assert_str_eq(s21_2, std_2);
}
END_TEST

START_TEST(s21_sscanf_test_all) {
  // %c %d %s
  const char *str_1 = "7b hello";
  int a, x;
  char b, y;
  char c[20], z[20];
  ck_assert_int_eq(s21_sscanf(str_1, "%d %c %s", &a, &b, c),
                   sscanf(str_1, "%d %c %s", &x, &y, z));
  ck_assert_int_eq(a, x);
  ck_assert_int_eq(b, y);
  ck_assert_str_eq(c, z);
}
END_TEST

/* ------=====                  FINISH                  =====------ */

Suite *

s21_stringh_suite(void) {
  Suite *suite = suite_create("s21_stringh");
  TCase *tcase_core = tcase_create("core");
  tcase_add_test(tcase_core, insert_1);
  tcase_add_test(tcase_core, insert_2);
  tcase_add_test(tcase_core, insert_3);
  tcase_add_test(tcase_core, insert_4);
  tcase_add_test(tcase_core, insert_5);
  tcase_add_test(tcase_core, insert_6);

  tcase_add_test(tcase_core, memchr_1);
  tcase_add_test(tcase_core, memchr_2);
  tcase_add_test(tcase_core, memchr_3);
  tcase_add_test(tcase_core, memchr_4);
  tcase_add_test(tcase_core, memchr_5);
  tcase_add_test(tcase_core, memchr_6);
  tcase_add_test(tcase_core, memchr_7);
  tcase_add_test(tcase_core, memchr_8);

  tcase_add_test(tcase_core, memcmp_1);

  tcase_add_test(tcase_core, memcpy_1);
  tcase_add_test(tcase_core, memcpy_2);
  tcase_add_test(tcase_core, memcpy_3);

  tcase_add_test(tcase_core, memset_1);
  tcase_add_test(tcase_core, memset_2);
  tcase_add_test(tcase_core, memset_3);
  tcase_add_test(tcase_core, memset_4);
  tcase_add_test(tcase_core, memset_5);

  tcase_add_test(tcase_core, strchr_1);
  tcase_add_test(tcase_core, strchr_2);
  tcase_add_test(tcase_core, strchr_3);

  tcase_add_test(tcase_core, strerror_1);
  tcase_add_test(tcase_core, strerror_2);
  tcase_add_test(tcase_core, strerror_3);

  tcase_add_test(tcase_core, strlen_1);
  tcase_add_test(tcase_core, strlen_2);
  tcase_add_test(tcase_core, strlen_3);
  tcase_add_test(tcase_core, strlen_4);

  tcase_add_test(tcase_core, strcspn_1);
  tcase_add_test(tcase_core, strcspn_2);
  tcase_add_test(tcase_core, strcspn_3);
  tcase_add_test(tcase_core, strcspn_4);
  tcase_add_test(tcase_core, strcspn_5);

  tcase_add_test(tcase_core, strncat_1);
  tcase_add_test(tcase_core, strncat_2);
  tcase_add_test(tcase_core, strncat_3);
  tcase_add_test(tcase_core, strncat_4);
  tcase_add_test(tcase_core, strncat_5);
  tcase_add_test(tcase_core, strncat_6);
  tcase_add_test(tcase_core, strncat_7);
  tcase_add_test(tcase_core, strncat_8);

  tcase_add_test(tcase_core, strncmp_1);
  tcase_add_test(tcase_core, strncmp_2);
  tcase_add_test(tcase_core, strncmp_3);
  tcase_add_test(tcase_core, strncmp_4);

  tcase_add_test(tcase_core, strncpy_1);
  tcase_add_test(tcase_core, strncpy_2);
  tcase_add_test(tcase_core, strncpy_3);
  tcase_add_test(tcase_core, strncpy_4);
  tcase_add_test(tcase_core, strncpy_5);
  tcase_add_test(tcase_core, strncpy_6);

  tcase_add_test(tcase_core, strpbrk_1);
  tcase_add_test(tcase_core, strpbrk_2);
  tcase_add_test(tcase_core, strpbrk_3);
  tcase_add_test(tcase_core, strpbrk_4);
  tcase_add_test(tcase_core, strpbrk_5);
  tcase_add_test(tcase_core, strpbrk_6);

  tcase_add_test(tcase_core, strrchr_1);
  tcase_add_test(tcase_core, strrchr_2);
  tcase_add_test(tcase_core, strrchr_3);
  tcase_add_test(tcase_core, strrchr_4);
  tcase_add_test(tcase_core, strrchr_5);
  tcase_add_test(tcase_core, strrchr_6);
  tcase_add_test(tcase_core, strrchr_7);
  tcase_add_test(tcase_core, strrchr_8);

  tcase_add_test(tcase_core, strstr_1);
  tcase_add_test(tcase_core, strstr_2);
  tcase_add_test(tcase_core, strstr_3);
  tcase_add_test(tcase_core, strstr_4);
  tcase_add_test(tcase_core, strstr_5);
  tcase_add_test(tcase_core, strstr_6);

  tcase_add_test(tcase_core, strtok_1);
  tcase_add_test(tcase_core, strtok_2);
  tcase_add_test(tcase_core, strtok_3);
  tcase_add_test(tcase_core, strtok_4);
  tcase_add_test(tcase_core, strtok_5);

  tcase_add_test(tcase_core, to_lower_1);
  tcase_add_test(tcase_core, to_lower_2);
  tcase_add_test(tcase_core, to_lower_3);
  tcase_add_test(tcase_core, to_lower_4);

  tcase_add_test(tcase_core, to_upper_1);
  tcase_add_test(tcase_core, to_upper_2);
  tcase_add_test(tcase_core, to_upper_3);
  tcase_add_test(tcase_core, to_upper_4);

  tcase_add_test(tcase_core, trim_1);
  tcase_add_test(tcase_core, trim_2);
  tcase_add_test(tcase_core, trim_3);
  tcase_add_test(tcase_core, trim_4);
  tcase_add_test(tcase_core, trim_5);
  tcase_add_test(tcase_core, trim_6);

  tcase_add_test(tcase_core, s21_sprintf_test_1);
  tcase_add_test(tcase_core, s21_sprintf_test_2);
  tcase_add_test(tcase_core, s21_sprintf_test_3);
  tcase_add_test(tcase_core, s21_sprintf_test_4);
  tcase_add_test(tcase_core, s21_sprintf_test_5);
  tcase_add_test(tcase_core, s21_sprintf_test_6);

  tcase_add_test(tcase_core, s21_sscanf_test_1);
  tcase_add_test(tcase_core, s21_sscanf_test_2);
  tcase_add_test(tcase_core, s21_sscanf_test_3);
  tcase_add_test(tcase_core, s21_sscanf_test_all);

  suite_add_tcase(suite, tcase_core);
  return suite;
}

int main(void) {
  Suite *suite = s21_stringh_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  srunner_free(suite_runner);
  return 0;
}