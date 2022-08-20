#ifndef PERSON_H_
#define PERSON_H_
#include <cstdint>
#include <string>

namespace Model {
class Person {
 public:
  Person(
      const uint16_t &id, const std::string &password, const std::string &name,
      const uint8_t &age, const std::string &birthday);
  Person(const uint16_t &id, const std::string &password);
  std::string getName() const;
  uint8_t getAge() const;
  std::string getBirthday() const;

 protected:
  uint16_t id_;
  std::string password_;
  std::string name_;
  uint8_t age_;
  std::string birthday_;
};
}  // namespace Model

#endif  // PERSON_H_