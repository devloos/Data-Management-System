#include "../../include/Person.h"

Person::Person(
    const uint16_t &id, const std::string &password, const std::string &name,
    const uint8_t &age, const std::string &birthday)
    : id_(id), password_(password), name_(name), age_(age), birthday_(birthday) {}

Person::Person(const uint16_t &id, const std::string &password)
    : Person(id, password, "", -1, "") {}

uint8_t Person::getAge() const { return age_; }
std::string Person::getName() const { return name_; }
std::string Person::getBirthday() const { return birthday_; }