#ifndef OPTIONS_H
#define OPTIONS_H

/**
 * Stores the option values.
 */
typedef struct options_t {
  char *timestamp_file;
  char *output_file;
}Options;

#define DEFAULT_TIMESTAMP_FILE "timestamp.out"
#define DEFAULT_OUTPUT_FILE "output.out"

#define TIMESTAMP_OPT_SHORT "-t"
#define OUTPUT_OPT_SHORT "-o"
#endif
