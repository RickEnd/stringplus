#include "test_suite.h"

START_TEST(strncpy_test1) {
  char str_1[50] = "qwerty";
  char str_2[50] = "12345";
  ck_assert_str_eq(strncpy(str_1, str_2, 2 * 2),
                   s21_strncpy(str_1, str_2, 2 * 2));
}
END_TEST

START_TEST(strncpy_test2) {
  char str_1[60] = "50 pdfh";
  char str_2[50] = "HELLO!\n5";
  ck_assert_str_eq(strncpy(str_1, str_2, 5 - 1),
                   s21_strncpy(str_1, str_2, 5 - 1));
}
END_TEST

START_TEST(strncpy_test4) {
  char str_1[20] = "abracadabra ";
  char str_2[] = " 123";
  ck_assert_str_eq(strncpy(str_1, str_2, 10), s21_strncpy(str_1, str_2, 10));
}
END_TEST

START_TEST(strncpy_test5) {
  char str_1[50] = "s_=+*&/te   ";
  char str_2[50] = "vosem'";
  ck_assert_str_eq(strncpy(str_1, str_2, 6), s21_strncpy(str_1, str_2, 6));
}
END_TEST

START_TEST(strncpy_test6) {
  char str_1[50] = "8h2f7y10/n5 6";
  char str_2[] = "'40' -l";
  ck_assert_str_eq(strncpy(str_1, str_2, 10 / 5),
                   s21_strncpy(str_1, str_2, 10 / 5));
}
END_TEST

START_TEST(strncpy_test7) {
  char s1[255] = "QWERTY";
  char s2[255] = "Eeee";
  ck_assert_pstr_eq(strncpy(s1, s2, 2), s21_strncpy(s1, s2, 2));
}
END_TEST

Suite *suite_strncpy(void) {
  Suite *s8;
  TCase *tc8;
  s8 = suite_create("s21_STRNCPY");
  tc8 = tcase_create("case_strncpy");
  tcase_add_test(tc8, strncpy_test1);
  tcase_add_test(tc8, strncpy_test2);
  tcase_add_test(tc8, strncpy_test4);
  tcase_add_test(tc8, strncpy_test5);
  tcase_add_test(tc8, strncpy_test6);
  tcase_add_test(tc8, strncpy_test7);
  suite_add_tcase(s8, tc8);
  return s8;
}