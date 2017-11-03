#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

char * get_binary(int n) {
  int i = 8;
  char * s;
  s = malloc(sizeof(char) * 9);
  while (n) {
    if (n & 1) {
      if ((i % 3) == 0) { * (s + i) = 'r'; }
      if ((i % 3) == 1) { * (s + i) = 'w'; }
      if ((i % 3) == 2) { * (s + i) = 'x'; }
    }
    else { * (s + i) = '-'; }
    i -= 1;
    n >>= 1;
  }
  return s;
}

int main() {
  struct stat stats;
  stat("info_stat.c", &stats);
  printf("File size: %lldB\n", (long long int)stats.st_size);
  printf("File size: %fkB\n", (float)stats.st_size / 1000);
  printf("File size: %fMB\n", (float)stats.st_size / 10000);
  printf("File size: %fGB\n", (float)stats.st_size / 100000);
  printf("Mode: %o\n", stats.st_mode);
  int a = 0;
  a = stats.st_mode % 512;
  char * perm;
  perm = get_binary(a);
  printf("%s\n", perm);
  printf("Access time: %s", ctime(&stats.st_atime));
  return 0;
}
