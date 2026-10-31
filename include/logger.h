#ifndef LOGGER_H
#define LOGGER_H

#include <stdbool.h>

typedef enum {
  LOG_DEBUG,
  LOG_INFO,
  LOG_WARN,
  LOG_ERROR,
} LogLevel;

bool logger_init(const char *path, LogLevel level);
void logger_log(LogLevel level, const char *fmt, ...);
void logger_close(void);

#endif // !LOGGER_H
