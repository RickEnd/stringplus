#include "test_suite.h"

START_TEST(to_upper_test1) {
  char *str = "abz";
  char *res = "ABZ";

  char *tmp = s21_to_upper(str);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(to_upper_test2) {
  char *str = "Abz";
  char *res = "ABZ";
  char *tmp = s21_to_upper(str);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(to_upper_test3) {
  char *str = "";
  char *res = "";
  char *tmp = s21_to_upper(str);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(to_upper_test4) {
  char *str = "abz1,#";
  char *res = "ABZ1,#";
  char *tmp = s21_to_upper(str);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

// START_TEST(to_upper_test5) {
//   char str[4] = {127, 89, -6, 0};  // warning из за переполнения типов
//   char *res = S21_NULL;
//   char *tmp = s21_to_upper(str);

//   ck_assert_ptr_eq(tmp, res);

//   free(tmp);
// }
// END_TEST

START_TEST(to_upper_test6) {
  char *str = S21_NULL;
  char *res = S21_NULL;
  char *tmp = s21_to_upper(str);

  ck_assert_ptr_eq(tmp, res);

  free(tmp);
}
END_TEST

START_TEST(to_upper_test7) {
  char *str = "ab\0z";
  char *res = "AB";
  char *tmp;

  tmp = s21_to_upper(str);

  ck_assert_str_eq(tmp, res);

  free(tmp);
}
END_TEST

Suite *suite_to_upper(void) {
  Suite *s16;
  TCase *tc16;
  s16 = suite_create("s21_TO_UPPER");
  tc16 = tcase_create("case_to_upper");
  tcase_add_test(tc16, to_upper_test1);
  tcase_add_test(tc16, to_upper_test2);
  tcase_add_test(tc16, to_upper_test3);
  tcase_add_test(tc16, to_upper_test4);
  // tcase_add_test(tc16, to_upper_test5);
  tcase_add_test(tc16, to_upper_test6);
  tcase_add_test(tc16, to_upper_test7);
  suite_add_tcase(s16, tc16);
  return s16;
}