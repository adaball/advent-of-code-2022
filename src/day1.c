#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
  char* filename = "input/day1.txt";
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "error opening file %s: %s\n", filename, strerror(errno));
    return 1;
  }

  if (fseek(fp, 0, SEEK_END)) {
    fprintf(stderr, "error seeking to the end of %s: %s\n", filename, strerror(errno));
    return 1;
  }

  long size = ftell(fp);
  if (size == -1L) {
    fprintf(stderr, "error getting size of %s: %s\n", filename, strerror(errno));
    return 1;
  }

  fprintf(stdout, "size of %s is %ld\n", filename, size);

  char* input = malloc(size + 1);
  rewind(fp);

  if (fread(input, size, 1, fp)) {
    fprintf(stderr, "error reading file %s: %s\n", filename, strerror(errno));
    return 1;
  }
}
