#include <stdio.h>
#include <stdlib.h>

char expected[] = "i.4cdn.org/\1\2\3\0";

int main(void) {
  char c;
  char url[512];
  int r = 0, ei = 0, i;
  while ((c = getchar()) != EOF) {
    char e = expected[ei++];
    if (e == 0) {
      url[r - 1] = 0;
      printf("%s\n", url);
      for (i = 0; i < r; i++)
        url[i] = 0;
      r = 0;
      ei = 0;
    } else if (e == 1) {
      if (c != '/')
        ei--;
      url[r++] = c;
    } else if (e == 2) {
      if (c >= '0' && c <= '9')
        ei--;
      else if (c != '.')
        goto restart;
      url[r++] = c;
    } else if (e == 3) {
      char check = c;
      if ('Z' >= check)
        check ^= ' ';
      if (check >= 'a' && check <= 'z')
        ei--;
      url[r++] = c;
    } else if (e == c) {
      url[r++] = c;
    } else {
restart:
      for (i = 0; i < r; i++)
        url[i] = 0;
      r = 0;
      ei = 0;
    }
  }
  return 0;
}

