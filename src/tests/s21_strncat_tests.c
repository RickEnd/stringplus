#include "test_suite.h"

START_TEST(strncat_test1) {
  char str_1[100] = "Hello";
  char str_2[100] = " World";
  ck_assert_str_eq(strncat(str_1, str_2, 3), s21_strncat(str_1, str_2, 3));
}
END_TEST

START_TEST(strncat_test2) {
  char str_1[100] = "\0";
  char str_2[100] = "i am proger";
  ck_assert_str_eq(strncat(str_1, str_2, 13), s21_strncat(str_1, str_2, 13));
}
END_TEST

START_TEST(strncat_test3) {
  char str_1[100] = "\n";
  char str_2[100] = "p-\0-roger";
  ck_assert_str_eq(strncat(str_1, str_2, 9), s21_strncat(str_1, str_2, 9));
}
END_TEST

START_TEST(strncat_test4) {
  char str_1[100] = "-\t-";
  char str_2[100] = "\0";
  ck_assert_str_eq(strncat(str_1, str_2, 2), s21_strncat(str_1, str_2, 2));
}
END_TEST

START_TEST(strncat_test5) {
  char str_1[100] = " \b";
  char str_2[100] = "  1 \n";
  ck_assert_str_eq(strncat(str_1, str_2, 5), s21_strncat(str_1, str_2, 5));
}
END_TEST

START_TEST(strncat_test6) {
  char str_1[100] = " 0 ";
  char str_2[100] = "123";
  ck_assert_str_eq(strncat(str_1, str_2, 0), s21_strncat(str_1, str_2, 0));
}
END_TEST

START_TEST(strncat_test7) {
  char str_1[100] = " 0 ";
  char str_2[100] = "qwer";
  ck_assert_str_eq(strncat(str_1, str_2, 0 + 2),
                   s21_strncat(str_1, str_2, 0 + 2));
}
END_TEST

START_TEST(strncat_test8) {
  char str_1[100] = " 0 ";
  char str_2[100] = "error";
  ck_assert_str_eq(strncat(str_1, str_2, 4 - 1),
                   s21_strncat(str_1, str_2, 4 - 1));
}
END_TEST

START_TEST(strncat_test9) {
  char str_1[100] = "999";
  char str_2[100] = "puckKK";
  ck_assert_str_eq(strncat(str_1, str_2, 2 * 2),
                   s21_strncat(str_1, str_2, 2 * 2));
}
END_TEST

START_TEST(strncat_test10) {
  char s1[255] = "QWERTY";
  char s2[255] = "E";
  ck_assert_pstr_eq(strncat(s1, s2, 6), s21_strncat(s1, s2, 6));
}
END_TEST

Suite *suite_strncat(void) {
  Suite *s5;
  TCase *tc5;
  s5 = suite_create("s21_STRNCAT");
  tc5 = tcase_create("case_strncat");
  tcase_add_test(tc5, strncat_test1);
  tcase_add_test(tc5, strncat_test2);
  tcase_add_test(tc5, strncat_test3);
  tcase_add_test(tc5, strncat_test4);
  tcase_add_test(tc5, strncat_test5);
  tcase_add_test(tc5, strncat_test6);
  tcase_add_test(tc5, strncat_test7);
  tcase_add_test(tc5, strncat_test8);
  tcase_add_test(tc5, strncat_test9);
  tcase_add_test(tc5, strncat_test10);
  suite_add_tcase(s5, tc5);
  return s5;
}