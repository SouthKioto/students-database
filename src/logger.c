#include "../include/logger.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INIT_BUFFER_SIZE 20

static char **log_buf;
static size_t log_count;
static size_t log_capacity;
static FILE *log_file;
static LogLevel min_level;

bool logger_init(const char *path, LogLevel level) {
  log_count = 0;
  log_file = fopen(path, "a");
  if (log_file == NULL) {
    return false;
  }

  min_level = level;
  log_buf = malloc(INIT_BUFFER_SIZE * sizeof *log_buf);
  if (!log_buf) {
    fclose(log_file);
    log_file = NULL;
    return false;
  }
  log_capacity = INIT_BUFFER_SIZE;

  return true;
}

void logger_log(LogLevel level, const char *fmt, ...) {
  if (!log_file) {
    return;
  }

  if (level < min_level) {
    return;
  }

  time_t fullTime = time(NULL);
  struct localTime = localtime(&fullTime);

  char buffor[256];
  va_list args;
  va_start(args, fmt);
  vsnprintf(buffor, 256, fmt, args);
  va_end(args);
}

void logger_close(void) {
  if (log_file) {
    fclose(log_file);
  }

  for (size_t i = 0; i < log_count; i++) {
    free(log_buf[i]);
  }

  free(log_buf);
  log_count = 0;
  log_capacity = 0;
  log_buf = NULL;
  log_file = NULL;
}
