#include "../../include/Faculty.h"

Faculty::Faculty(
    const uint16_t &id, const std::string &password, const AccessLevel &accessLevel,
    const uint8_t &yearsWorking)
    : Person::Person(id, password),
      accessLevel_(accessLevel),
      yearsWorking_(yearsWorking) {}
Faculty::Faculty(
    const uint16_t &id, const std::string &password, const AccessLevel &accessLevel)
    : Faculty(id, password, accessLevel, 0) {}