#ifndef LOGGER_H
#define LOGGER_H

void init_logging(const char *filename);
void close_logging();
void log_message(const char *text);

#endif // !LOGGER_H
