#include "test_suite.h"

START_TEST(to_lower_test1) {
  char *str = "ABZ";
  char *res = "abz";
  char *tmp = s21_to_lower(str);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(to_lower_test2) {
  char *str = "Abz";
  char *res = "abz";
  char *tmp = s21_to_lower(str);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(to_lower_test3) {
  char *str = "";
  char *res = "";
  char *tmp = s21_to_lower(str);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(to_lower_test4) {
  char *str = "ABZ1,#";
  char *res = "abz1,#";
  char *tmp = s21_to_lower(str);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(to_lower_test6) {
  char *str = NULL;
  char *res = S21_NULL;
  char *tmp = s21_to_lower(str);

  ck_assert_ptr_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(to_lower_test7) {
  char *str = "AB\0z";
  char *res = "ab";
  char *tmp;

  tmp = s21_to_lower(str);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

Suite *suite_to_lower(void) {
  Suite *s17;
  TCase *tc17;
  s17 = suite_create("s21_TO_LOWER");
  tc17 = tcase_create("case_to_lower");
  tcase_add_test(tc17, to_lower_test1);
  tcase_add_test(tc17, to_lower_test2);
  tcase_add_test(tc17, to_lower_test3);
  tcase_add_test(tc17, to_lower_test4);
  tcase_add_test(tc17, to_lower_test6);
  tcase_add_test(tc17, to_lower_test7);
  suite_add_tcase(s17, tc17);
  return s17;
}