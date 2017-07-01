#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "optparser.c"

size_t LINE_MAX = 1024;

#define TIME_FILE "/tmp/time.out"
#define OUTPUT_FILE "/tmp/output.out"
int main(int argc, char **argv) {

  Options *opt = parse(argc, argv);
  char *line = (char *) malloc(LINE_MAX * sizeof(char));

  FILE *timeFile = fopen(TIME_FILE, "w+");
  FILE *outFile = fopen(OUTPUT_FILE, "w+");

  if (NULL == line) {
    printf("Error: Failed to allocate buffer. \n");
    exit(-1);
  }

  int bytes_read = 0;
  for(;;) {
    if (getline(&line, &LINE_MAX, stdin) == -1) {
      exit(0);
    }
    fprintf(outFile, "%s",line);
    fprintf(timeFile, "%lu\n", (unsigned long)time(NULL));
    memset(line, '\0', LINE_MAX);
  }
  free(line);
  return 0;
}
