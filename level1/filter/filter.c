#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

void ft_filter(char *line, char *s) {
  int len = strlen(s);
  int i = 0;
  int j;

  while (line[i]) {
    j = 0;
    while (s[j] && line[i + j] == s[j])
      j++;
    if (j == len) {
      while (j--)
        write(1, "*", 1);
      i += len;
    } else
      write(1, &line[i++], 1);
  }
}

int main(int argc, char **argv) {
  char line[999999];
  int total = 0;
  int ret;

  if (argc != 2 || !argv[1][0])
    return (1);
  while ((ret = read(0, &line[total], BUFFER_SIZE)) > 0)
    total += ret;
  if (ret < 0) {
    perror("Error");
    return (1);
  }
  line[total] = '\0';
  ft_filter(line, argv[1]);
  return (0);
}