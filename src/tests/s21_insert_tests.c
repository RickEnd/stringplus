#include "test_suite.h"

START_TEST(insert_test1) {
  char src[4] = "abc";
  char str[4] = "def";
  char res[7] = "abcdef";

  char *tmp = s21_insert(src, str, 3);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(insert_test2) {
  char src[4] = "abc";
  char str[4] = "def";
  char res[7] = "adefbc";

  char *tmp = s21_insert(src, str, 1);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(insert_test3) {
  char src[4] = "ab\0c";
  char str[4] = "def";
  char res[7] = "abdef";

  char *tmp = s21_insert(src, str, 2);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(insert_test4) {
  char src[4] = "";
  char str[4] = "def";
  char res[7] = "def";

  char *tmp = s21_insert(src, str, 0);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(insert_test5) {
  char src[4] = "abc";
  char str[4] = "def";
  char *res = NULL;

  char *tmp = s21_insert(src, str, 5);

  ck_assert_pstr_eq(tmp, res);

  // free(tmp);
}
END_TEST

START_TEST(insert_test6) {
  char src[4] = "abc";
  char *str = S21_NULL;  // s21_NULL или NULL
  char *res = NULL;

  char *tmp = s21_insert(src, str, 3);

  ck_assert_pstr_eq(tmp, res);

  // free(tmp); не нужен в данном случае
}
END_TEST

START_TEST(insert_test7) {
  char *src = NULL;
  char str[4] = "def";
  char *res = S21_NULL;

  char *tmp = s21_insert(src, str, 3);

  ck_assert_ptr_eq(tmp, res);

  // free(tmp);
}
END_TEST

Suite *suite_insert(void) {
  Suite *s18;
  TCase *tc18;                         // собранные тесты все
  s18 = suite_create("s21_INSERT");    // создаем ядро
  tc18 = tcase_create("case_insert");  //
  tcase_add_test(tc18, insert_test1);
  tcase_add_test(tc18, insert_test2);
  tcase_add_test(tc18, insert_test3);
  tcase_add_test(tc18, insert_test4);
  tcase_add_test(tc18, insert_test5);
  tcase_add_test(tc18, insert_test6);
  tcase_add_test(tc18, insert_test7);

  suite_add_tcase(s18, tc18);
  return s18;
}