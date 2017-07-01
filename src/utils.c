#ifndef TIMESTAMP_UTILS_C
#define TIMESTAMP_UTILS_C
/**
 * Print error message and exit.
 */
void print_error_and_exit(char *error) {
  if(NULL != error) {
    printf("Error %s\n", error );
  }

  exit(-1);
}

#endif
