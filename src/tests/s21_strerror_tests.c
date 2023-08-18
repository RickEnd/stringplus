#include "test_suite.h"

START_TEST(strerror_test1) {  // Ifdef если на маке и на линуксе
  for (int i = -1; i <= 134; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

Suite *suite_strerror(void) {
  Suite *s10;
  TCase *tc10;
  s10 = suite_create("s21_STRERROR");
  tc10 = tcase_create("case_strerror");
  tcase_add_test(tc10, strerror_test1);
  suite_add_tcase(s10, tc10);
  return s10;
}