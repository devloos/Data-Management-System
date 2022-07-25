#ifndef FACULTY_H_
#define FACULTY_H_
#include "Person.h"

enum struct AccessLevel { Teacher = 0, Proctor, Admin };

class Faculty : public Person {
 public:
  Faculty(
      const uint16_t &id, const std::string &password, const AccessLevel &accessLevel,
      const uint8_t &yearsWorking);
  Faculty(
      const uint16_t &id, const std::string &password, const AccessLevel &accessLevel);

 private:
  AccessLevel accessLevel_;
  uint8_t yearsWorking_;
};

#endif  // FACULTY_H_