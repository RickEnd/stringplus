#include "test_suite.h"

START_TEST(strlen_test1) {
  char str1[] = "\0";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_test2) {
  char str1[] = "Hello World\0";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_test3) {
  char str1[] = "Hello World\0\n";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_test4) {
  char str1[] = "";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_test5) {
  char str1[] = "a\n\0";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_test6) {
  char str1[] = " \n\0";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_test7) {
  char str1[] = " \0";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_test8) {
  char str1[] = "\n\0";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_test9) {
  char str1[] = "\n\n\f\r\t";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_test10) {
  char *str1 = "QWERTY";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_test11) {
  char *str2 = "Q";
  ck_assert_int_eq(strlen(str2), s21_strlen(str2));
}
END_TEST

START_TEST(strlen_test12) {
  char *str3 = "";
  ck_assert_int_eq(strlen(str3), s21_strlen(str3));
}
END_TEST

START_TEST(strlen_test13) {
  char *str3 = " ";
  ck_assert_int_eq(strlen(str3), s21_strlen(str3));
}
END_TEST

START_TEST(strlen_test14) {
  char str1[] = "7623455234523618";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_test15) {
  char str1[] =
      "ncngejngnwoifnqjewnqw;oeitnoij2o8j29083u4235h05j1091345jrtjijlijwq43234";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_test16) {
  char str1[] = "ncngejngnwoifnqjewnqw\0tjoievgowemowi3045045245";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

Suite *suite_strlen(void) {
  Suite *s11;
  TCase *tc11;
  s11 = suite_create("s21_STRLEN");
  tc11 = tcase_create("case_s21_strlen");
  tcase_add_test(tc11, strlen_test1);
  tcase_add_test(tc11, strlen_test2);
  tcase_add_test(tc11, strlen_test3);
  tcase_add_test(tc11, strlen_test4);
  tcase_add_test(tc11, strlen_test5);
  tcase_add_test(tc11, strlen_test6);
  tcase_add_test(tc11, strlen_test7);
  tcase_add_test(tc11, strlen_test8);
  tcase_add_test(tc11, strlen_test9);
  tcase_add_test(tc11, strlen_test10);
  tcase_add_test(tc11, strlen_test11);
  tcase_add_test(tc11, strlen_test12);
  tcase_add_test(tc11, strlen_test13);
  tcase_add_test(tc11, strlen_test14);
  tcase_add_test(tc11, strlen_test15);
  tcase_add_test(tc11, strlen_test16);
  suite_add_tcase(s11, tc11);
  return s11;
}