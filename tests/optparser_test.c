#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/options.h"
#include "../src/optparser.c"

void test_defaultfiles();
int main() {
  test_defaultfiles();
}



void test_defaultfiles() {

   printf("Testing default timestamp and output file...\n");
   Options *options = parse(0, NULL);
   assert(0 == strcmp(options->output_file, DEFAULT_OUTPUT_FILE));
   assert(0 == strcmp(options->timestamp_file, DEFAULT_TIMESTAMP_FILE));

   printf("Testing default timestamp and output file.[Success]\n");
}
