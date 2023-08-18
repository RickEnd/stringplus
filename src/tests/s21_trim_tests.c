#include "test_suite.h"

START_TEST(trim_test1) {
  char src[4] = "abc";
  char trim_chars[2] = "a";
  char res[3] = "bc";

  char *tmp = s21_trim(src, trim_chars);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(trim_test2) {
  char *src = "abcd";
  char *trim_chars = "ac";
  char *res = "bcd";

  char *tmp = s21_trim(
      src, trim_chars);  // Почему здесь приведение к char исправило ситуацию

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(trim_test3) {
  char *src = "abcd";
  char *trim_chars = "dc";
  char *res = "ab";

  char *tmp = s21_trim(src, trim_chars);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(trim_test4) {
  char *src = "Hello World";
  char *trim_chars = "Hedl";
  char *res = "o Wor";

  char *tmp = s21_trim(src, trim_chars);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(trim_test5) {
  char *src = "";
  char *trim_chars = "dc";
  char *res = "";

  char *tmp = s21_trim(src, trim_chars);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(trim_test6) {
  char *src = S21_NULL;
  char *trim_chars = "dc";
  char *res = S21_NULL;

  char *tmp = s21_trim(
      src, trim_chars);  // Почему здесь приведение к char исправило ситуацию

  ck_assert_ptr_eq(tmp, res);

  // free(tmp); не пишем потому что память по итогу не выделена!
}
END_TEST

START_TEST(trim_test7) {
  char *src = "abc";
  char *trim_chars = S21_NULL;
  char *res = "abc";

  char *tmp = s21_trim(
      src, trim_chars);  // Почему здесь приведение к char исправило ситуацию

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(trim_test8) {
  char *src = "abcde";
  char *trim_chars = "";
  char *res = "abcde";

  char *tmp = s21_trim(src, trim_chars);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(trim_test9) {
  char *src = "abcde";
  char *trim_chars = "fgh";
  char *res = "abcde";

  char *tmp = s21_trim(src, trim_chars);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(trim_test10) {
  char *src = "aabbcde";
  char *trim_chars = "aea";
  char *res = "bbcd";

  char *tmp = s21_trim(src, trim_chars);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(trim_test11) {
  char *src = "abcde";
  char *trim_chars = "abcde";
  char *res = "";

  char *tmp = s21_trim(src, trim_chars);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

Suite *suite_trim(void) {
  Suite *s19;
  TCase *tc19;
  s19 = suite_create("s21_TRIM");
  tc19 = tcase_create("case_trim");
  tcase_add_test(tc19, trim_test1);
  tcase_add_test(tc19, trim_test2);
  tcase_add_test(tc19, trim_test3);
  tcase_add_test(tc19, trim_test4);
  tcase_add_test(tc19, trim_test5);
  tcase_add_test(tc19, trim_test6);
  tcase_add_test(tc19, trim_test7);
  tcase_add_test(tc19, trim_test8);
  tcase_add_test(tc19, trim_test9);
  tcase_add_test(tc19, trim_test10);
  tcase_add_test(tc19, trim_test11);

  suite_add_tcase(s19, tc19);
  return s19;
}