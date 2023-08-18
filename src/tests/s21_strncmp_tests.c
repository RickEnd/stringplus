#include "test_suite.h"

START_TEST(strncmp_test1) {
  char str_1[10] = "\0";
  char str_2[50] = "Per aspera ad astra";
  ck_assert_int_eq(strncmp(str_1, str_2, 0), s21_strncmp(str_1, str_2, 0));
}
END_TEST

START_TEST(strncmp_test2) {
  char str_1[12] = "i am\nproger";
  char str_2[50] = " \n\0\0";
  ck_assert_int_eq(strncmp(str_1, str_2, 5), s21_strncmp(str_1, str_2, 5));
}
END_TEST

START_TEST(strncmp_test3) {
  char str_1[10] = " a\n\0";
  char str_2[15] = "1234567890";
  ck_assert_int_eq(strncmp(str_1, str_2, 3), s21_strncmp(str_1, str_2, 3));
}
END_TEST

START_TEST(strncmp_test4) {
  char str_1[15] = "1234975654";
  char str_2[15] = "1234567890";
  ck_assert_int_eq(strncmp(str_1, str_2, 1), s21_strncmp(str_1, str_2, 1));
}
END_TEST

START_TEST(strncmp_test5) {
  char str_1[15] = "1234567890";
  char str_2[10] = "qwerty";
  ck_assert_int_eq(strncmp(str_1, str_2, 5), s21_strncmp(str_1, str_2, 5));
}
END_TEST

START_TEST(strncmp_test6) {
  char s1[255] = "QWERTY";
  char s2[255] = "E";
  ck_assert_int_eq(strncmp(s1, s2, 6), s21_strncmp(s1, s2, 6));
}
END_TEST

Suite *suite_strncmp(void) {
  Suite *s7;
  TCase *tc7;
  s7 = suite_create("s21_STRNCMP");
  tc7 = tcase_create("case_strncmp");
  tcase_add_test(tc7, strncmp_test1);
  tcase_add_test(tc7, strncmp_test2);
  tcase_add_test(tc7, strncmp_test3);
  tcase_add_test(tc7, strncmp_test4);
  tcase_add_test(tc7, strncmp_test5);
  tcase_add_test(tc7, strncmp_test6);
  suite_add_tcase(s7, tc7);
  return s7;
}