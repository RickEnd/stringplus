#include "s21_string.h"

static void reverse(char *s);
static s21_size_t pos_cut(const char *src, const char *trim_chars);

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *out = S21_NULL;
  char *prog = (char *)str;
  for (s21_size_t i = 0; prog == S21_NULL || i < n; prog++, i++) {
    if (prog[0] == c) {
      out = prog;
      break;
    }
  }
  return out;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int out = 0;
  const char *one = (char *)str1;
  const char *two = (char *)str2;
  for (s21_size_t i = 0; i < n && one != S21_NULL && two != S21_NULL && !out;
       i++, one++, two++) {
    if (*one != *two) {
      out = one[0] - two[0];
    }
  }
  return out;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *res = (char *)dest;
  char *tmp = (char *)src;
  for (s21_size_t i = 0; i < n; i++) *(char *)(res + i) = *(char *)(tmp + i);
  return dest;
}

void *s21_memset(void *str, int c, size_t n) {
  unsigned char *res = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++)
    *(unsigned char *)(res + i) = (unsigned char)c;
  return res;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t num = s21_strlen(dest);
  s21_size_t i = num;

  for (; i < num + n; i++) dest[i] = src[i - num];
  dest[i] = '\0';

  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *newstr = S21_NULL;

  for (int i = 0; str[i] == c || str[i] != '\0'; i++)
    if ((int)str[i] == c) {
      newstr = (char *)(str + i);
      break;
    }

  return newstr;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;

  for (s21_size_t i = 0; i < n; i++)
    if (str1[i] != str2[i]) {
      res = str1[i] - str2[i];
      break;
    }

  return res;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    if (src[i] != '\000')
      dest[i] = src[i];
    else {
      while (i < n) {
        dest[i] = '\0';
        i++;
      }
    }
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len_segment = 0;
  s21_size_t flag = 0;
  for (s21_size_t i = 0; i <= s21_strlen(str1); i++) {
    for (s21_size_t j = 0; j <= s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) flag++;
    }
    if (flag == 0) len_segment++;
  }
  return len_segment;
}

char *s21_strerror(int errnum) {
  char *err_msg = S21_NULL;
#ifdef __APPLE__
  s21_size_t num_of_msgs = 106;
  static char *arr_msgs[] = {"Undefined error: 0",
                             "Operation not permitted",
                             "No such file or directory",
                             "No such process",
                             "Interrupted system call",
                             "Input/output error",
                             "Device not configured",
                             "Argument list too long",
                             "Exec format error",
                             "Bad file descriptor",
                             "No child processes",
                             "Resource deadlock avoided",
                             "Cannot allocate memory",
                             "Permission denied",
                             "Bad address",
                             "Block device required",
                             "Resource busy",
                             "File exists",
                             "Cross-device link",
                             "Operation not supported by device",
                             "Not a directory",
                             "Is a directory",
                             "Invalid argument",
                             "Too many open files in system",
                             "Too many open files",
                             "Inappropriate ioctl for device",
                             "Text file busy",
                             "File too large",
                             "No space left on device",
                             "Illegal seek",
                             "Read-only file system",
                             "Too many links",
                             "Broken pipe",
                             "Numerical argument out of domain",
                             "Result too large",
                             "Resource temporarily unavailable",
                             "Operation now in progress",
                             "Operation already in progress",
                             "Socket operation on non-socket",
                             "Destination address required",
                             "Message too long",
                             "Protocol wrong type for socket",
                             "Protocol not available",
                             "Protocol not supported",
                             "Socket type not supported",
                             "Operation not supported",
                             "Protocol family not supported",
                             "Address family not supported by protocol family",
                             "Address already in use",
                             "Can't assign requested address",
                             "Network is down",
                             "Network is unreachable",
                             "Network dropped connection on reset",
                             "Software caused connection abort",
                             "Connection reset by peer",
                             "No buffer space available",
                             "Socket is already connected",
                             "Socket is not connected",
                             "Can't send after socket shutdown",
                             "Too many references: can't splice",
                             "Operation timed out",
                             "Connection refused",
                             "Too many levels of symbolic links",
                             "File name too long",
                             "Host is down",
                             "No route to host",
                             "Directory not empty",
                             "Too many processes",
                             "Too many users",
                             "Disc quota exceeded",
                             "Stale NFS file handle",
                             "Too many levels of remote in path",
                             "RPC struct is bad",
                             "RPC version wrong",
                             "RPC prog. not avail",
                             "Program version wrong",
                             "Bad procedure for program",
                             "No locks available",
                             "Function not implemented",
                             "Inappropriate file type or format",
                             "Authentication error",
                             "Need authenticator",
                             "Device power is off",
                             "Device error",
                             "Value too large to be stored in data type",
                             "Bad executable (or shared library)",
                             "Bad CPU type in executable",
                             "Shared library version mismatch",
                             "Malformed Mach-o file",
                             "Operation canceled",
                             "Identifier removed",
                             "No message of desired type",
                             "Illegal byte sequence",
                             "Attribute not found",
                             "Bad message",
                             "EMULTIHOP (Reserved)",
                             "No message available on STREAM",
                             "ENOLINK (Reserved)",
                             "No STREAM resources",
                             "Not a STREAM",
                             "Protocol error",
                             "STREAM ioctl timeout",
                             "Operation not supported on socket",
                             "Policy not found",
                             "State not recoverable",
                             "Previous owner died",
                             "Interface output queue is full",
                             "Unknown error: "};
#elif __linux__ || __unix__
  s21_size_t num_of_msgs = 133;
  static char *arr_msgs[] = {
      "Success",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted system call",
      "Input/output error",
      "No such device or address",
      "Argument list too long",
      "Exec format error",
      "Bad file descriptor",
      "No child processes",
      "Resource temporarily unavailable",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Block device required",
      "Device or resource busy",
      "File exists",
      "Invalid cross-device link",
      "No such device",
      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "No space left on device",
      "Illegal seek",
      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Numerical result out of range",
      "Resource deadlock avoided",
      "File name too long",
      "No locks available",
      "Function not implemented",
      "Directory not empty",
      "Too many levels of symbolic links",
      "Unknown error 41",
      "No message of desired type",
      "Identifier removed",
      "Channel number out of range",
      "Level 2 not synchronized",
      "Level 3 halted",
      "Level 3 reset",
      "Link number out of range",
      "Protocol driver not attached",
      "No CSI structure available",
      "Level 2 halted",
      "Invalid exchange",
      "Invalid request descriptor",
      "Exchange full",
      "No anode",
      "Invalid request code",
      "Invalid slot",
      "Unknown error 58",
      "Bad font file format",
      "Device not a stream",
      "No data available",
      "Timer expired",
      "Out of streams resources",
      "Machine is not on the network",
      "Package not installed",
      "Object is remote",
      "Link has been severed",
      "Advertise error",
      "Srmount error",
      "Communication error on send",
      "Protocol error",
      "Multihop attempted",
      "RFS specific error",
      "Bad message",
      "Value too large for defined data type",
      "Name not unique on network",
      "File descriptor in bad state",
      "Remote address changed",
      "Can not access a needed shared library",
      "Accessing a corrupted shared library",
      ".lib section in a.out corrupted",
      "Attempting to link in too many shared libraries",
      "Cannot exec a shared library directly",
      "Invalid or incomplete multibyte or wide character",
      "Interrupted system call should be restarted",
      "Streams pipe error",
      "Too many users",
      "Socket operation on non-socket",
      "Destination address required",
      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Operation not supported",
      "Protocol family not supported",
      "Address family not supported by protocol",
      "Address already in use",
      "Cannot assign requested address",
      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Transport endpoint is already connected",
      "Transport endpoint is not connected",
      "Cannot send after transport endpoint shutdown",
      "Too many references: cannot splice",
      "Connection timed out",
      "Connection refused",
      "Host is down",
      "No route to host",
      "Operation already in progress",
      "Operation now in progress",
      "Stale file handle",
      "Structure needs cleaning",
      "Not a XENIX named type file",
      "No XENIX semaphores available",
      "Is a named type file",
      "Remote I/O error",
      "Disk quota exceeded",
      "No medium found",
      "Wrong medium type",
      "Operation canceled",
      "Required key not available",
      "Key has expired",
      "Key has been revoked",
      "Key was rejected by service",
      "Owner died",
      "State not recoverable",
      "Operation not possible due to RF-kill",
      "Memory page has hardware error",
      "Unknown error "};
#else
#error "Unknown compiler"
#endif

  if (errnum >= 0 && errnum <= (int)num_of_msgs)
    err_msg = arr_msgs[errnum];
  else {
    static char part1[256] = "";
    part1[0] = '\0';
    s21_strcat(part1, arr_msgs[num_of_msgs + 1]);
    char part2[32] = "";
    part2[0] = '\0';
    if (errnum == -2147483648)
      s21_strcat(part1, "-2147483648");
    else {
      s21_itoa(errnum, 10, part2);
      s21_strcat(part1, part2);
    }
    err_msg = part1;
  }

  return err_msg;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t count_str = 0;
  while (*str++) count_str++;
  return count_str;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *new = S21_NULL;
  s21_size_t num = s21_strlen(str1);

  for (s21_size_t i = 0; i < s21_strlen(str2); i++)
    for (s21_size_t j = 0; j < s21_strlen(str1); j++)
      if (num > j && str2[i] == str1[j]) {
        new = (char *)(str1 + j);
        num = j;
      }

  return new;
}

char *s21_strrchr(const char *str, int c) {
  char *newstr = S21_NULL;

  for (int i = s21_strlen(str); i >= 0; i--)
    if ((int)str[i] == c) {
      newstr = (char *)(str + i);
      break;
    }

  return newstr;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *newstr = S21_NULL;

  for (s21_size_t i = 0; i <= s21_strlen(haystack); i++)
    if (!s21_strncmp(haystack + i, needle, s21_strlen(needle))) {
      newstr = (char *)(haystack + i);
      break;
    }

  return newstr;
}

char *s21_strtok(char *str, const char *delim) {
  static char *result = S21_NULL;
  if (str) {
    result = str;
    while (*result && s21_strchr(delim, *result)) *result++ = '\0';
  }
  if (result != NULL) {
    if (*result != '\0') {
      str = result;
      while (*result && !s21_strchr(delim, *result)) ++result;
      while (*result && s21_strchr(delim, *result)) *result++ = '\0';
    } else {
      str = S21_NULL;
    }
  } else {
    str = S21_NULL;
  }
  return str;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = S21_NULL;

  if (src && str) {
    s21_size_t len_str = s21_strlen(str);
    s21_size_t len_src = s21_strlen(src);
    if (start_index <= len_src) {
      res = calloc((len_src + len_str) + 1, sizeof(char));
      for (s21_size_t i = 0; i < start_index; i++) res[i] = src[i];
      for (s21_size_t i = 0; i < len_str; i++) res[start_index + i] = str[i];
      for (s21_size_t i = start_index; i < len_src; i++)
        res[len_str + i] = src[i];
      res[len_src + len_str] = '\0';
    }
  }
  return res;
}

void *s21_to_upper(const char *str) {
  char *res = S21_NULL;
  if (str) {
    res = (char *)calloc((s21_strlen(str) + 1), sizeof(char));
    if (res) {
      s21_strncpy(res, str, s21_strlen(str) + 1);
      for (char *tmp = res; *tmp; tmp++)
        if (*tmp >= 'a' && *tmp <= 'z') *tmp -= 32;
    }
  }
  return res;
}

void *s21_to_lower(const char *str) {
  char *res = S21_NULL;
  if (str) {
    res = (char *)calloc((s21_strlen(str) + 1), sizeof(char));
    if (res) {
      s21_strncpy(res, str, s21_strlen(str) + 1);
      for (char *tmp = res; *tmp; tmp++)
        if (*tmp >= 'A' && *tmp <= 'Z') *tmp += 32;
    }
  }
  return res;
}

static void reverse(char *s) {
  for (int i = 0, j = s21_strlen(s) - 1; i < j; i++, j--) {
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = S21_NULL;
  char *tmp_chars = S21_NULL;

  if (src) {
    if (trim_chars) {
      tmp_chars = (char *)calloc((s21_strlen(trim_chars) + 2), sizeof(char));
      if (s21_strlen(trim_chars) == 0)
        s21_strcpy(tmp_chars, " ");
      else
        s21_strcpy(tmp_chars, trim_chars);
    } else {
      tmp_chars = (char *)calloc(2, sizeof(char));
      s21_strcpy(tmp_chars, " ");
    }
    res = (char *)calloc((s21_strlen(src) + 1), sizeof(char));
    if (res) {
      s21_size_t len_res = s21_strlen(src);
      s21_size_t last_pos = pos_cut(src, tmp_chars);
      if (len_res == last_pos) {
        s21_strcpy(res, "");
      } else {
        s21_strncpy(res, src, s21_strlen(src) - last_pos);
        reverse(res);
        s21_size_t first_pos = pos_cut(res, tmp_chars);
        len_res = s21_strlen(res);
        if (len_res == first_pos) {
          s21_strcpy(res, "");
        } else {
          res[len_res - first_pos] = '\0';
          reverse(res);
        }
      }
    }
    free(tmp_chars);
  }
  return res;
}

static s21_size_t pos_cut(const char *src, const char *trim_chars) {
  s21_size_t res = 0;
  s21_size_t len_src = s21_strlen(src) - 1;

  for (int i = (int)len_src; i >= 0 && i == (int)(len_src - res); i--) {
    for (int j = (int)s21_strlen(trim_chars) - 1; j >= 0; j--) {
      if (src[i] == trim_chars[j]) {
        res++;
        break;
      }
    }
  }
  return res;
}

char *s21_strcpy(char *dest, const char *src) {
  s21_size_t i = 0;
  do dest[i] = src[i];
  while (src[i++] != '\0');
  return dest;
}

char *s21_strcat(char *dest, const char *src) {
  s21_size_t len_dest = s21_strlen(dest);
  s21_size_t i = len_dest;
  s21_size_t len_src = s21_strlen(src);

  for (; i < len_dest + len_src; i++) dest[i] = src[i - len_dest];
  dest[i] = '\0';

  return dest;
}

int s21_strcmp(const char *str1, const char *str2) {
  int res = 0;
  s21_size_t i = 0;
  s21_size_t len_str1 = s21_strlen(str1);
  s21_size_t len_str2 = s21_strlen(str2);

  for (; i < len_str1 && i < len_str2; i++)
    if (str1[i] != str2[i]) {
      res = str1[i] - str2[i];
      break;
    }
  return res;
}