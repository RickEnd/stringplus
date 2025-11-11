#include "test_suite.h"

START_TEST(strchr_test1) {
  char str[] = "Hello world";
  int c = 3;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_test2) {
  char str[] = "Hello world\0";
  int c = 5;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_test3) {
  char str[] = "Hello world";
  int c = 12;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_test4) {
  char str[] = "Hello world";
  int c = '\0';
  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_test5) {
  char str[] = "";
  int c = 0;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_test6) {
  char str[] = "a\n\0";
  int c = 'a';
  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_test7) {
  char str[] = "aaaaaaaaaaaaaaaaaaa";
  int c = 'b';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_test8) {
  char *s1 = "QWERTY";
  char s2 = 'E';
  ck_assert_pstr_eq(strchr(s1, s2), s21_strchr(s1, s2));
}
END_TEST

Suite *suite_strchr(void) {
  Suite *s6;
  TCase *tc6;
  s6 = suite_create("s21_STRCHR");
  tc6 = tcase_create("case_strchr");
  tcase_add_test(tc6, strchr_test1);
  tcase_add_test(tc6, strchr_test2);
  tcase_add_test(tc6, strchr_test3);
  tcase_add_test(tc6, strchr_test4);
  tcase_add_test(tc6, strchr_test5);
  tcase_add_test(tc6, strchr_test6);
  tcase_add_test(tc6, strchr_test7);
  tcase_add_test(tc6, strchr_test8);
  suite_add_tcase(s6, tc6);
  return s6;
}