#include "test_suite.h"

START_TEST(memcpy_1) {
  char str_5[3] = "a\n\0";
  char str_6[3] = "\0";
  ck_assert_str_eq(memcpy(str_5, str_6, 2), s21_memcpy(str_5, str_6, 2));
}
END_TEST

START_TEST(memcpy_2) {
  char str_1[] = "\0";
  char str_2[] = " ";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 1));
}
END_TEST

START_TEST(memcpy_3) {
  char str_1[] = "copy_! ";
  char str_2[] = "n66";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
}
END_TEST

START_TEST(memcpy_4) {
  char str_1[] = "\n/n";
  char str_2[] = "-55";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
}
END_TEST

START_TEST(memcpy_5) {
  char str_1[] = "5656";
  char str_2[] = "\0\f";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
}
END_TEST

START_TEST(memcpy_6) {
  char str_1[] = "%hf*-5";
  char str_2[] = "\0\f";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
}
END_TEST

START_TEST(memcpy_7) {
  char s1[255] = "QWERTY";
  char s2[255] = "E";
  ck_assert_pstr_eq(memcpy(s1, s2, 6), s21_memcpy(s1, s2, 6));
}
END_TEST

Suite *suite_memcpy(void) {
  Suite *s3;
  TCase *tc3;
  s3 = suite_create("s21_MEMCPY");
  tc3 = tcase_create("case_memcpy");
  tcase_add_test(tc3, memcpy_1);
  tcase_add_test(tc3, memcpy_2);
  tcase_add_test(tc3, memcpy_3);
  tcase_add_test(tc3, memcpy_4);
  tcase_add_test(tc3, memcpy_5);
  tcase_add_test(tc3, memcpy_6);
  tcase_add_test(tc3, memcpy_7);
  suite_add_tcase(s3, tc3);
  return s3;
}