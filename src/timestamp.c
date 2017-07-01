#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "optparser.c"
#include "utils.c"


size_t LINE_MAX = 1024;

void read_and_log(FILE *, FILE *);
char* getFormattedTime(void);

int main(int argc, char **argv) {

  Options *opt = parse(argc, argv);

  FILE *time_file = fopen(opt->timestamp_file, "w+");
  FILE *out_file = fopen(opt->output_file, "w+");

  if (NULL == time_file || NULL == out_file) {
    print_error_and_exit("Could not open files for timestamp/output.");
  }
  read_and_log(time_file, out_file);
  return 0;
}


void read_and_log(FILE *time_file, FILE *out_file) {

  char *line = (char *) malloc(LINE_MAX * sizeof(char));
  if (NULL == line) {
    printf("Error: Failed to allocate buffer. \n");
    exit(-1);
  }

  int bytes_read = 0;
  for(;;) {
    if (getline(&line, &LINE_MAX, stdin) == -1) {
      exit(0);
    }
    fprintf(out_file, "%s",line);
    fprintf(time_file, "%s\n", getFormattedTime());
    memset(line, '\0', LINE_MAX);
  }

  free(line);
}


char* getFormattedTime() {

    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    static char _retval[20];
    strftime(_retval, sizeof(_retval), "%Y-%m-%d %H:%M:%S", timeinfo);

    return _retval;
}
