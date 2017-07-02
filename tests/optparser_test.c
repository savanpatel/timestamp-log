#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/options.h"
#include "../src/optparser.c"

void test_defaultfiles();
void test_customoutputfiles();
void test_invalidarguments();

int main() {
  test_defaultfiles();
  test_customoutputfiles();
  test_invalidarguments();
}



void test_defaultfiles() {

   printf("Testing default timestamp and output file...\n");
   Options *options = parse(0, NULL);
   assert(0 == strcmp(options->output_file, DEFAULT_OUTPUT_FILE));
   assert(0 == strcmp(options->timestamp_file, DEFAULT_TIMESTAMP_FILE));
   printf("Testing default timestamp and output file.[Success]\n\n");
}

void test_customoutputfiles() {
  printf("Testing custom timestamp and output file input...\n");
  char *argv[] = {"executableName", "-t", "timestamp_file.txt", "-o", "output_file.txt"};
  Options *options = parse(5, argv);
  assert(0 == strcmp(options->output_file, "output_file.txt"));
  assert(0 == strcmp(options->timestamp_file, "timestamp_file.txt"));
  printf("Testing custom timestamp and output file input.[Success]\n\n");
}

void test_invalidarguments() {
  printf("Testing invalid arguments...\n");
  char *argv[] = {"executableName", "-h", "timestamp_file.txt", "-p", "output_file.txt"};
  Options *options = parse(5, argv);
  assert(0 == strcmp(options->output_file, DEFAULT_OUTPUT_FILE));
  assert(0 == strcmp(options->timestamp_file, DEFAULT_TIMESTAMP_FILE));
  printf("Testing invalid arguments[Success]\n\n");
}
