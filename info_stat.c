#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

char * get_binary(int n) {
  int ret = 0;
  int i = 8;
  char s[9];
  while (n) {
    //printf("while\n");
    if (n & 1) {
      if ((i % 3) == 0) {
	s[i] = 'r';
	//printf("%c\n", s[i]);
      }
      if ((i % 3) == 1) {
	s[i] = 'w';
	//printf("w: %c\n", s[i]);
      }
      if ((i % 3) == 2) {
	s[i] = 'x';
	//printf("xx");
      }
    }
    else {
      //printf("else\n");
      s[i] = '-';
      //printf("%c\n", s[i]);
    }
    i -= 1;
    n >>= 1;
  }
  //printf("%s\n", s);
  return s;
}

void print_b(int n) {
  while(n) {
    if (n & 1)
      printf("1");
    else
      printf("0");
    n >>= 1;
  }
}

int main() {
  struct stat stats;
  stat("info_stat.c", &stats);
  printf("File size: %dB\n", stats.st_size);
  printf("File size: %fkB\n", (float)stats.st_size / 1000);
  printf("File size: %fMB\n", (float)stats.st_size / 10000);
  printf("File size: %fGB\n", (float)stats.st_size / 100000);
  printf("Mode: %o\n", stats.st_mode);
  int a = 0;
  a = stats.st_mode % 512;
  printf("a: %o\n", 4);
  char * perm;
  //print_b(4);
  perm = get_binary(a);
  printf("%s\n", perm);
  printf("Access time: %s\n", ctime(&stats.st_atime));
 
  return 0;
}
