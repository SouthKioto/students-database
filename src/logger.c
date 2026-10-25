#include "../include/logger.h"
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#define INIT_BUFFER_SIZE 100

static FILE *log_file = NULL;
void init_logging(const char *filename) {
  if (filename) {
    log_file = fopen(filename, "a");
    if (!log_file) {
      fprintf(stderr, "Failed to open log file: %s\n", filename);
      exit(EXIT_FAILURE);
    }
  } else {
    log_file = stdout;
  }
}

void close_logging() {
  if (log_file && log_file != stdout) {
    fclose(log_file);
    log_file = NULL;
  }
}

void log_message(const char *text) {
  if (!log_file) {
    fprintf(stderr, "Logging not initialized.\n");
    return;
  }
  time_t now = time(NULL);
  struct tm *t = localtime(&now);

  char buffer[INIT_BUFFER_SIZE];

  strftime(buffer, sizeof(buffer), "[%Y-%m-%d %H:%M:%S]", t);

  fprintf(log_file, "%s %s\n", buffer, text);
  fflush(log_file);
}
