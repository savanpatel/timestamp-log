#include "options.h"
#include <string.h>
#include <stdlib.h>

void print_error_and_exit(char *error) {
  if(NULL != error) {
    printf("Error %s\n", error );
  }

  exit(-1);
}

/**
 * Parse options and retrun options struct.
 * Fill with defaults for missing options.
 * @param argc : total arguments
 * @param argv : arguments
 * @return : {@Options} struct containing option values.
 */
Options * parse(int argc, char **argv) {
  Options *opt = (Options *) malloc(sizeof(Options));

  if (NULL == opt) {
      print_error_and_exit("Failed to allocate memory");
  }

  for (int i = 1; i < argc; i++) {

    if (strcmp(argv[i], TIMESTAMP_OPT_SHORT) == 0) {
        if (i++ < argc) {
          opt->timestamp_file = argv[i];
        } else {
          print_error_and_exit("Missing timestamp file name.");
        }
    } else if (strcmp(argv[i], OUTPUT_OPT_SHORT) == 0) {
      if (i++ < argc) {
        opt->output_file = argv[i];
      } else {
        print_error_and_exit("Missing output file name.");
      }
    }
  }

  if (NULL == opt->timestamp_file) {
    opt->timestamp_file =
      (char *) malloc( sizeof(DEFAULT_TIMESTAMP_FILE) * sizeof(char));

    opt->output_file =
      (char *) malloc( sizeof(DEFAULT_OUTPUT_FILE) * sizeof(char));

    if(NULL == opt->timestamp_file || NULL == opt->output_file) {
      print_error_and_exit("Optionparser Error: Can not allocate memory for options");
    }

  }

  printf("Options : timestamp file : %s, output file : %s \n", opt->timestamp_file, opt->output_file);
  return opt;
}
