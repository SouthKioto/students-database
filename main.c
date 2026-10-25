#include "include/database.h"
#include "include/logger.h"
#include "include/student.h"
#include <stdio.h>

int main() {
  init_logging("log.log");
  initDatabase();

  loadStudents();

  close_logging();
  return 0;
}
