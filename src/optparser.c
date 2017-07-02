#include "options.h"
#include "utils.c"
#include <string.h>
#include <stdlib.h>

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

  for (int i = 1; NULL != argv && i < argc; i++) {

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
    opt->timestamp_file = (char *) malloc( sizeof(DEFAULT_TIMESTAMP_FILE) * sizeof(char));
    (NULL == opt->timestamp_file) ? print_error_and_exit("Optionparser Error: Can not allocate memory for options"):0;
    strcpy(opt->timestamp_file, DEFAULT_TIMESTAMP_FILE);
  }

  if(NULL == opt->output_file) {
    opt->output_file = (char *) malloc( sizeof(DEFAULT_OUTPUT_FILE) * sizeof(char));
    (NULL == opt->output_file) ? print_error_and_exit("Optionparser Error: Can not allocate memory for options"):0;
    strcpy(opt->output_file, DEFAULT_OUTPUT_FILE);
  }
  return opt;
}
