#include "../s21_string.h"
#include "test_suite.h"

#define BUFF_SIZE 512

START_TEST(sprintf_test1) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%5d|", 888);
  int b = s21_sprintf(array2, "|%5d|", 888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test2) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%5d|", -888);
  int b = s21_sprintf(array2, "|%5d|", -888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test3) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%-5d|", 888);
  int b = s21_sprintf(array2, "|%-5d|", 888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test4) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%-5d|", -888);
  int b = s21_sprintf(array2, "|%-5d|", -888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test5) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%+5d|", -888);
  int b = s21_sprintf(array2, "|%+5d|", -888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test6) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%+5d|", +888);
  int b = s21_sprintf(array2, "|%+5d|", +888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test7) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%*d|", 4, -888);
  int b = s21_sprintf(array2, "|%*d|", 4, -888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test8) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%+5d|", -888);
  int b = s21_sprintf(array2, "|%+5d|", -888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test9) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|% d|", 888);
  int b = s21_sprintf(array2, "|% d|", 888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test10) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|% d|", -888);
  int b = s21_sprintf(array2, "|% d|", -888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test11) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|% -d|", 888);
  int b = s21_sprintf(array2, "|% -d|", 888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test12) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|% -d|", -888);
  int b = s21_sprintf(array2, "|% -d|", -888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test13) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%04d|", 88);
  int b = s21_sprintf(array2, "|%04d|", 88);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test14) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%05d|", -88);
  int b = s21_sprintf(array2, "|%05d|", -88);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test15) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%05d|", -88);
  int b = s21_sprintf(array2, "|%05d|", -88);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test16) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%+05d|", -88);
  int b = s21_sprintf(array2, "|%+05d|", -88);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test17) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%.3d|", 88);
  int b = s21_sprintf(array2, "|%.3d|", 88);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test18) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%.03d|", 88);
  int b = s21_sprintf(array2, "|%.03d|", 88);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

// Спецификатор %i
START_TEST(sprintf_test20) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%-5i|", 12345);
  int b = s21_sprintf(array2, "|%-5d|", 12345);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test21) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%-5i|", -12345);
  int b = s21_sprintf(array2, "|%-5i|", -12345);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test22) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%+5i|", -12345);
  int b = s21_sprintf(array2, "|%+5i|", -12345);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test23) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%+5i|", +12345);
  int b = s21_sprintf(array2, "|%+5i|", +12345);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

// Cпецификатор %с

START_TEST(sprintf_test24) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%c|", 'a');
  int b = sprintf(data1, "|%c|", 'a');
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test25) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%5c|", 'R');
  int b = sprintf(data1, "|%5c|", 'R');
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test26) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%-5c|", 'R');
  int b = sprintf(data1, "|%-5c|", 'R');
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test27) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%c|", '\0');
  int b = sprintf(data1, "|%c|", '\0');
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

// Спецификатор %e

START_TEST(sprintf_test28) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%e|", 3.141592);
  int b = sprintf(data1, "|%e|", 3.141592);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test29) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%e|", 314.1592);
  int b = sprintf(data1, "|%e|", 314.1592);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test30) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%E|", 314.1592);
  int b = sprintf(data1, "|%E|", 314.1592);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

// Спецификатор %f

START_TEST(sprintf_test31) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%.3f|", 8.8888);
  int b = s21_sprintf(array2, "|%.3f|", 8.8888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test32) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%.03f|", 8.88);
  int b = s21_sprintf(array2, "|%.03f|", 8.88);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test33) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%0.3f|", 8.88);
  int b = s21_sprintf(array2, "|%0.3f|", 8.88);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test34) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%*.*f|", 8, 3, 8.8888);
  int b = s21_sprintf(array2, "|%*.*f|", 8, 3, 8.8888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test35) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%-*.*f|", 8, 3, 8.8888);
  int b = s21_sprintf(array2, "|%-*.*f|", 8, 3, 8.8888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test36) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%0*.*f|", 8, 3, 8.8888);
  int b = s21_sprintf(array2, "|%0*.*f|", 8, 3, 8.8888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

// Спецификатор %g и G

START_TEST(sprintf_test37) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%g|", 8.88000);
  int b = s21_sprintf(array2, "|%g|", 8.88000);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test38) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%.0g|", 8.88000);
  int b = s21_sprintf(array2, "|%.0g|", 8.88000);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test39) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%.1g|", 8.88000);
  int b = s21_sprintf(array2, "|%.1g|", 8.88000);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test40) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%.2g|", 8.88000);
  int b = s21_sprintf(array2, "|%.2g|", 8.88000);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test41) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%.2G|", 8.88000);
  int b = s21_sprintf(array2, "|%.2G|", 8.88000);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

// Спецификатор %o

START_TEST(sprintf_test42) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%o|", 888);
  int b = s21_sprintf(array2, "|%o|", 888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test43) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%#o|", 888);
  int b = s21_sprintf(array2, "|%#o|", 888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

// Спецификатор %x и X

START_TEST(sprintf_test44) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%x|", 888);
  int b = s21_sprintf(array2, "|%x|", 888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test45) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%#x|", 888);
  int b = s21_sprintf(array2, "|%#x|", 888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test46) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%X|", 888);
  int b = s21_sprintf(array2, "|%X|", 888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test47) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%#X|", 888);
  int b = s21_sprintf(array2, "|%#X|", 888);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

// Спецификатор %s

START_TEST(sprintf_test48) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%.3s| love |%20s|", "IIII", "you");
  int b = sprintf(data1, "|%.3s| love |%20s|", "IIII", "you");
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test96) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|test %-12i et %24s !|", 0, "zero");
  int b = sprintf(data1, "|test %-12i et %24s !|", 0, "zero");
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test49) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%.15s|", "21school");
  int b = sprintf(data1, "|%.15s|", "21school");
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test50) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%.0s|", "21school");
  int b = sprintf(data1, "|%.0s|", "21school");
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test51) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%s|", "\0ab");
  int b = sprintf(data1, "|%s|", "\0ab");
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test52) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%s|", "");
  int b = sprintf(data1, "|%s|", "");
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test53) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%10.8s|", "yandex");
  int b = sprintf(data1, "|%10.8s|", "yandex");
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test54) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%-10.2s|", "21school21");
  int b = sprintf(data1, "|%-10.2s|", "21school21");
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test99) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%25s|", "1fg*#&h");
  int b = sprintf(data1, "|%25s|", "1fg*#&h");
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

// Спецификатор %u

START_TEST(sprintf_test55) {
  char data[100];
  char data1[100];
  int c = s21_sprintf(data, "|%-2.8u|", (unsigned)-345);
  int d = sprintf(data1, "|%-2.8u|", (unsigned)-345);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(c, d);
}
END_TEST

START_TEST(sprintf_test56) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%u|", (unsigned)34);
  int b = sprintf(data1, "|%u|", (unsigned)34);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test57) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%-u|", (unsigned)50);
  int b = sprintf(data1, "|%-u|", (unsigned)50);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test58) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%15.20u|", (unsigned)-100000);
  int b = sprintf(data1, "|%15.20u|", (unsigned)-100000);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

// Спецификтор %p

START_TEST(sprintf_test59) {
  char data[100];
  char data1[100];
  int c = 3;
  int a = s21_sprintf(data, "|%p|", &c);
  int b = sprintf(data1, "|%p|", &c);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test60) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%p|", (void *)0x2123);
  int b = sprintf(data1, "|%p|", (void *)0x2123);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test95) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%p|", (void *)0x2123);
  int b = sprintf(data1, "|%p|", (void *)0x2123);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test61) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%12p|", (void *)12345678);
  int b = sprintf(data1, "|%12p|", (void *)12345678);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test62) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%p|", (void *)0xaB123);
  int b = sprintf(data1, "|%p|", (void *)0xaB123);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

// Спецификатор %n

START_TEST(sprintf_test64) {  // Вот тут правильно или нет, 3 сравнения
  char data[100];
  char data1[100];
  int num = 0;
  int s21_num = 0;
  int a = s21_sprintf(data, "|%d%n|", 6525365, &s21_num);
  int b = sprintf(data1, "|%d%n|", 6525365, &num);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(s21_num, num);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test65) {
  char data[100];
  char data1[100];
  int num = 0;
  int s21_num = 0;
  int a = s21_sprintf(data, "|%d%s%n|", 6525365, "fight", &s21_num);
  int b = sprintf(data1, "|%d%s%n|", 6525365, "fight", &num);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(s21_num, num);
  ck_assert_int_eq(a, b);
}
END_TEST

// Спецификатор %%

START_TEST(sprintf_test66) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%%|");
  int b = s21_sprintf(array2, "|%%|");
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

// сборный

START_TEST(sprintf_test67) {
  char str[100];
  char str1[100];
  int a = sprintf(str,
                  "Chislo:|%-5s|kust and |%9c|. This sum is |%i|. This is "
                  "|%%|. And now unsigned: |%u|",
                  "abra", 'e', 56, (unsigned)-43);
  int b = s21_sprintf(str1,
                      "Chislo:|%-5s|kust and |%9c|. This sum is |%i|. This is "
                      "|%%|. And now unsigned: |%u|",
                      "abra", 'e', 56, (unsigned)-43);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(a, b);
}
END_TEST

// Максимальные и минимальные значения

START_TEST(sprintf_test68) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%d|", INT_MAX);
  int b = s21_sprintf(array2, "|%d|", INT_MAX);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test69) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%u|", UINT_MAX);
  int b = s21_sprintf(array2, "|%u|", UINT_MAX);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test70) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%lu|", ULONG_MAX);
  int b = s21_sprintf(array2, "|%lu|", ULONG_MAX);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test71) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%hi|", SHRT_MAX);
  int b = s21_sprintf(array2, "|%hi|", SHRT_MAX);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

// Длинна l,L,h

START_TEST(sprintf_test72) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%li%i|", LONG_MIN, +32767);
  int b = s21_sprintf(array2, "|%li%i|", LONG_MIN, +32767);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test73) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%li%i|", LONG_MIN, +32767);
  int b = s21_sprintf(array2, "|%li%i|", LONG_MIN, +32767);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test74) {
  char array1[100];
  char array2[100];
  int a = sprintf(array1, "|%3.3Lf|", LDBL_MIN);
  int b = s21_sprintf(array2, "|%3.3Lf|", LDBL_MIN);
  ck_assert_str_eq(array1, array2);
  ck_assert_int_eq(a, b);
}
END_TEST

// inf nan spec e f g

START_TEST(sprintf_test301) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%E|", INFINITY);
  int b = sprintf(data1, "|%E|", INFINITY);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test302) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%e|", -INFINITY);
  int b = sprintf(data1, "|%e|", -INFINITY);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test303) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%E|", NAN);
  int b = sprintf(data1, "|%E|", NAN);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test304) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%g|", INFINITY);
  int b = sprintf(data1, "|%g|", INFINITY);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test305) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%g|", -INFINITY);
  int b = sprintf(data1, "|%g|", -INFINITY);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test306) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%G|", NAN);
  int b = sprintf(data1, "|%G|", NAN);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test307) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%f|", INFINITY);
  int b = sprintf(data1, "|%f|", INFINITY);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test308) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%f|", -INFINITY);
  int b = sprintf(data1, "|%f|", -INFINITY);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_test309) {
  char data[100];
  char data1[100];
  int a = s21_sprintf(data, "|%f|", NAN);
  int b = sprintf(data1, "|%f|", NAN);
  ck_assert_str_eq(data, data1);
  ck_assert_int_eq(a, b);
}
END_TEST

Suite *suite_sprintf() {
  Suite *s20;
  TCase *tc20;
  s20 = suite_create("s21_SPRINTF");
  tc20 = tcase_create("case_sprintf");
  tcase_add_test(tc20, sprintf_test1);
  tcase_add_test(tc20, sprintf_test2);
  tcase_add_test(tc20, sprintf_test3);
  tcase_add_test(tc20, sprintf_test4);
  tcase_add_test(tc20, sprintf_test5);
  tcase_add_test(tc20, sprintf_test6);
  tcase_add_test(tc20, sprintf_test7);
  tcase_add_test(tc20, sprintf_test1);
  tcase_add_test(tc20, sprintf_test8);
  tcase_add_test(tc20, sprintf_test9);
  tcase_add_test(tc20, sprintf_test10);
  tcase_add_test(tc20, sprintf_test11);
  tcase_add_test(tc20, sprintf_test12);
  tcase_add_test(tc20, sprintf_test13);
  tcase_add_test(tc20, sprintf_test14);
  tcase_add_test(tc20, sprintf_test15);
  tcase_add_test(tc20, sprintf_test16);
  tcase_add_test(tc20, sprintf_test17);
  tcase_add_test(tc20, sprintf_test18);
  tcase_add_test(tc20, sprintf_test20);
  tcase_add_test(tc20, sprintf_test21);
  tcase_add_test(tc20, sprintf_test22);
  tcase_add_test(tc20, sprintf_test23);
  tcase_add_test(tc20, sprintf_test24);
  tcase_add_test(tc20, sprintf_test25);
  tcase_add_test(tc20, sprintf_test26);
  tcase_add_test(tc20, sprintf_test27);
  tcase_add_test(tc20, sprintf_test28);
  tcase_add_test(tc20, sprintf_test29);
  tcase_add_test(tc20, sprintf_test30);
  tcase_add_test(tc20, sprintf_test31);
  tcase_add_test(tc20, sprintf_test32);
  tcase_add_test(tc20, sprintf_test33);
  tcase_add_test(tc20, sprintf_test34);
  tcase_add_test(tc20, sprintf_test35);
  tcase_add_test(tc20, sprintf_test36);
  tcase_add_test(tc20, sprintf_test37);
  tcase_add_test(tc20, sprintf_test38);
  tcase_add_test(tc20, sprintf_test39);
  tcase_add_test(tc20, sprintf_test40);
  tcase_add_test(tc20, sprintf_test41);
  tcase_add_test(tc20, sprintf_test42);
  tcase_add_test(tc20, sprintf_test43);
  tcase_add_test(tc20, sprintf_test44);
  tcase_add_test(tc20, sprintf_test45);
  tcase_add_test(tc20, sprintf_test46);
  tcase_add_test(tc20, sprintf_test47);
  tcase_add_test(tc20, sprintf_test48);
  tcase_add_test(tc20, sprintf_test49);
  tcase_add_test(tc20, sprintf_test50);
  tcase_add_test(tc20, sprintf_test51);
  tcase_add_test(tc20, sprintf_test52);
  tcase_add_test(tc20, sprintf_test53);
  tcase_add_test(tc20, sprintf_test54);
  tcase_add_test(tc20, sprintf_test55);
  tcase_add_test(tc20, sprintf_test56);
  tcase_add_test(tc20, sprintf_test57);
  tcase_add_test(tc20, sprintf_test58);
  tcase_add_test(tc20, sprintf_test59);
  tcase_add_test(tc20, sprintf_test60);
  tcase_add_test(tc20, sprintf_test61);
  tcase_add_test(tc20, sprintf_test62);
  tcase_add_test(tc20, sprintf_test64);
  tcase_add_test(tc20, sprintf_test65);
  tcase_add_test(tc20, sprintf_test66);
  tcase_add_test(tc20, sprintf_test67);
  tcase_add_test(tc20, sprintf_test68);
  tcase_add_test(tc20, sprintf_test69);
  tcase_add_test(tc20, sprintf_test70);
  tcase_add_test(tc20, sprintf_test71);
  tcase_add_test(tc20, sprintf_test72);
  tcase_add_test(tc20, sprintf_test73);
  tcase_add_test(tc20, sprintf_test74);
  tcase_add_test(tc20, sprintf_test95);
  tcase_add_test(tc20, sprintf_test96);
  tcase_add_test(tc20, sprintf_test99);
  tcase_add_test(tc20, sprintf_test301);
  tcase_add_test(tc20, sprintf_test302);
  tcase_add_test(tc20, sprintf_test303);
  tcase_add_test(tc20, sprintf_test304);
  tcase_add_test(tc20, sprintf_test305);
  tcase_add_test(tc20, sprintf_test306);
  tcase_add_test(tc20, sprintf_test307);
  tcase_add_test(tc20, sprintf_test308);
  tcase_add_test(tc20, sprintf_test309);

  suite_add_tcase(s20, tc20);
  return s20;
}
