#include "../include/database.h"
#include "../include/logger.h"
#include "../include/student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_DATABASE_PATH "database.txt"
#define START_BUFFER_SIZE 50

static FILE *file;
void initDatabase() {
  file = fopen(DEFAULT_DATABASE_PATH, "w");
  char init_data[50] = "Jan;Kowalski\nJanina;Kowaska";

  if (file == NULL) {
    log_message("File not opened");
    return;
  }

  if (fputs(init_data, file) == 1) {
    log_message("Database are created");
  }

  fclose(file);
}

Student *loadStudents() {

  Student *loadedStudents = NULL;
  size_t count = 0;
  size_t capacity = 0;

  char buffer[256];

  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    if (count == capacity) {
      size_t new_capacity = capacity == 0 ? 4 : capacity * 2;

      Student *tmp =
          realloc(loadedStudents, new_capacity * sizeof *loadedStudents);

      if (tmp == NULL) {
        log_message("Nie zaalokowano");
        free(tmp);
        return NULL;
      }
      loadedStudents = tmp;
      capacity = new_capacity;
    }

    loadedStudents[count].name = strchr(buffer, ';');
    loadedStudents[count].surname = strchr(buffer, '\n');

    ++count;
  }

  return loadedStudents;
}
