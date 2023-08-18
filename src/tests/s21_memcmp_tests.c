#include "test_suite.h"

START_TEST(memcmp_tests1) {
  char *str = "Hello World";
  char *str1 = "Hello World";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(str, str1, n), 0);
}
END_TEST
START_TEST(memcmp_tests2) {
  char *str = "Hello";
  char *str1 = "notequal";
  int n = 5;
  ck_assert_int_lt(s21_memcmp(str, str1, n), 0);
}
END_TEST
START_TEST(memcmp_tests3) {
  char *str = "Hello World";
  char *str1 = "";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
}
END_TEST
START_TEST(memcmp_tests4) {
  char *str = " \n\0\0";
  char *str1 = " a\n\0";
  ck_assert_int_lt(s21_memcmp(str, str1, 3), 0);
}
END_TEST
START_TEST(memcmp_tests5) {
  char *str = "abc";
  char *str1 = "bca";
  ck_assert_int_lt(s21_memcmp(str, str1, 2), 0);
}
END_TEST
START_TEST(memcmp_tests6) {
  char *str = "Hello";
  char *str1 = "HeLlo";
  ck_assert_int_eq(memcmp(str, str1, 3), s21_memcmp(str, str1, 3));
}
END_TEST

Suite *suite_memcmp(void) {
  Suite *s2;
  TCase *tc2;
  s2 = suite_create("s21_MEMCMP");
  tc2 = tcase_create("case_memcmp");
  tcase_add_test(tc2, memcmp_tests1);
  tcase_add_test(tc2, memcmp_tests2);
  tcase_add_test(tc2, memcmp_tests3);
  tcase_add_test(tc2, memcmp_tests4);
  tcase_add_test(tc2, memcmp_tests5);
  tcase_add_test(tc2, memcmp_tests6);
  suite_add_tcase(s2, tc2);
  return s2;
}