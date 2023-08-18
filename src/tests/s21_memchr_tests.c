#include "test_suite.h"

START_TEST(memchr_test1) {
  const char src1_s21[15] = "Good job";
  ck_assert_ptr_eq(memchr(src1_s21, 'd', 10), s21_memchr(src1_s21, 'd', 10));
}
END_TEST

START_TEST(memchr_test2) {
  const char str1[10] = "Hello";
  ck_assert_ptr_eq(s21_memchr(str1, 'H', 5), memchr(str1, 'H', 5));
}
END_TEST

START_TEST(memchr_test3) {
  const char str2[10] = "Hellosdsfq";
  ck_assert_ptr_eq(
      s21_memchr(str2, 'l', 0),
      memchr(str2, 'l', 0));  // используем ptr потому что не сравниваем строки,
                              // а указатели ( потому что возвращает NULL)
}
END_TEST

Suite *suite_memchr(void) {
  Suite *s1;
  TCase *tc1;                         // собранные тесты все
  s1 = suite_create("s21_MEMCHR");    // создаем ядро
  tc1 = tcase_create("case_memchr");  //
  tcase_add_test(tc1, memchr_test1);
  tcase_add_test(tc1, memchr_test2);
  tcase_add_test(tc1, memchr_test3);

  suite_add_tcase(s1, tc1);
  return s1;
}
