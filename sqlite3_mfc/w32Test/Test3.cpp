#include <iostream>

#include "SQLiteWrapper.h"

int main() {
  SQLiteWrapper sqlite;
  if (sqlite.Open("SQLiteWrapper.db")) {
    std::cout << "SQLiteWrapper.db created or opened" << std::endl;
  }
  else {
    std::cout << "couldn't open SQLiteWrapper.db"     << std::endl;
  }

  SQLiteStatement* stmt = sqlite.Statement("insert into foo values (?, ?)");

  if (stmt->Bind(0, 3)) {
    std::cout << "value 3 successfully bound at pos 0" << std::endl;
  }
  else {
    std::cout << "value 3 NOT successfully bound at pos 0: " << sqlite.LastError() << std::endl;
  }
  if (stmt->Bind(1, 4)) {
    std::cout << "value 4 successfully bound at pos 1" << std::endl;
  }
  else {
    std::cout << "value 4 NOT successfully bound at pos 1:" << sqlite.LastError() << std::endl;
  }

  // ******************************** Executing 1st time
  if (stmt->Execute()) {
    std::cout << "statement executed" << std::endl;
  }
  else {
    std::cout << "error executing statement: " << sqlite.LastError() << std::endl;
  }

  if (stmt->Bind(0, 5)) {
    std::cout << "value 5 successfully bound at pos 0" << std::endl;
  }
  else {
    std::cout << "value 5 NOT successfully bound at pos 0" << std::endl;
  }

  if (stmt->Bind(1, 6)) {
    std::cout << "value 6 successfully bound at pos 1" << std::endl;
  }
  else {
    std::cout << "value 6 NOT successfully bound at pos 1" << std::endl;
  }

  // ******************************** Executing 2nd time
  if (stmt->Execute()) {
    std::cout << "statement executed" << std::endl;
  }
  else {
    std::cout << "error executing statement: " << sqlite.LastError() << std::endl;
  }

  return 0;
}
