#include "test_suite.h"

START_TEST(memset_tests1) {
  char str[10] = "123456789";
  ck_assert_str_eq(memset(str, 'k', 3), s21_memset(str, 'k', 3));
}
END_TEST

START_TEST(memset_tests2) {
  char str1[11] = "1234567890";
  char str2[11] = "5432167890";
  int c = 'q';
  int n = 10;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(memset_tests3) {
  char str1[13] = "qweqweqweqwe";
  char str2[13] = "qweqweqweqwe";
  int c = '\0';
  int n = 5;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(memset_tests4) {
  char str1[13] = "qweqweqweqwe";
  char str2[13] = "qweqweqweqwe";
  int c = '\n';
  int n = 5;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(memset_tests5) {
  char s1[255] = "QWERTY";
  ck_assert_pstr_eq(memset(s1, 2, 6), s21_memset(s1, 2, 6));
}
END_TEST

Suite *suite_memset(void) {
  Suite *s4;
  TCase *tc4;
  s4 = suite_create("s21_MEMSET");
  tc4 = tcase_create("case_memset");
  tcase_add_test(tc4, memset_tests1);
  tcase_add_test(tc4, memset_tests2);
  tcase_add_test(tc4, memset_tests3);
  tcase_add_test(tc4, memset_tests4);
  tcase_add_test(tc4, memset_tests5);
  suite_add_tcase(s4, tc4);
  return s4;
}
