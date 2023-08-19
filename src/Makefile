NAME := s21_string.a
HEADER := s21_string.h
HEADER_TEST := tests/test_suite.h # переставить
SRC_TEST := main.c \
			s21_to_upper_tests.c \
			s21_to_lower_tests.c \
			s21_insert_tests.c \
			s21_trim_tests.c \
			s21_memchr_tests.c \
			s21_memcmp_tests.c \
			s21_memcpy_tests.c \
			s21_memset_tests.c \
			s21_strncat_tests.c \
			s21_strchr_tests.c \
			s21_strncmp_tests.c \
			s21_strncpy_tests.c \
			s21_strcspn_tests.c \
			s21_strlen_tests.c \
			s21_strpbrk_tests.c \
			s21_strrchr_tests.c \
			s21_strstr_tests.c \
			s21_strtok_tests.c \
			s21_strerror_tests.c \
			s21_sprintf_tests.c
			
SRC_TEST := $(addprefix tests/, $(SRC_TEST))
REPORT := GcovReport

CC := gcc
GCOVFLAGS := -fprofile-arcs -ftest-coverage
CFLAGS := -std=c11 -Wall -Werror -Wextra -g #-fsanitize=leak -fsanitize=address
TEST := test

OS = $(shell uname)
ifeq ($(OS), Linux)
    CHECK_FLAGS := -lcheck -lpthread -lrt -lm -lsubunit
else
    CHECK_FLAGS := -lcheck
endif

ifeq ($(OS), Linux)
    LEAKS := valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./test
endif
ifeq ($(OS), Darwin)
    LEAKS := leaks --atExit -- ./test
endif

SRCS_LIBS :=  \
			s21_string.c \
			s21_sprintf.c

			 
SRCS := $(SRCS_LIBS) # Поправить, где используется
OBJS := $(SRCS:.c=.o)

.PHONY: clean gcov_report test

all: s21_string.a

s21_string.a: $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: clean $(NAME) $(SRC_TEST)
	$(CC) $(CFLAGS) $(SRC_TEST) $(NAME) $(CHECK_FLAGS) -o $(TEST)
	./$(TEST)

lint: $(SRC_TEST) $(SRCS_LIBS) $(HEADER) $(HEADER_TEST) 
	clang-format -i $^

check:
	clang-format -n *.c *.h */*.h */*.c
	cppcheck --enable=all --force --suppress=missingIncludeSystem *.h *.c */*.c */*.h
	$(LEAKS)

gcov_report: $(SRC_TEST) $(SRCS)
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(SRC_TEST) $(SRCS) $(CHECK_FLAGS) -o $(REPORT)
	chmod +x *
	./GcovReport
	lcov -t "$(REPORT)" -o $(REPORT).info -c -d .
	genhtml -o report $(REPORT).info
	rm -rf ./*.gcno ./*.gcda ./$(REPORT).*s
	open report/index.html

rebuild: clean all

clean: 
	rm -rf report GcovReport GcovReport.info *.o *.a *.gcno *.gcda test
