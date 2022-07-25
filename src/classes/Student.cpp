#include "../../include/Student.h"

Student::Student(
    const uint16_t &id, const std::string &password, const uint16_t studentYear,
    const float &GPA, const std::vector<std::string> &classSchedule,
    const std::unordered_map<std::string, char> &grades,
    const AcademicStatus &studentStatus)
    : Person::Person(id, password),
      studentYear_(studentYear),
      GPA_(GPA),
      classSchedule_(classSchedule),
      grades_(grades),
      studentStatus_(studentStatus) {}

Student::Student(
    const uint16_t &id, const std::string &password, const uint16_t studentYear,
    const float &GPA, const std::vector<std::string> &classSchedule)
    : Student(
          id, password, studentYear, GPA, classSchedule,
          std::unordered_map<std::string, char>(), AcademicStatus::Good_Standing) {}

Student::Student(
    const uint16_t &id, const std::string &password, const uint16_t studentYear)
    : Student(
          id, password, studentYear, 0.0f, std::vector<std::string>(),
          std::unordered_map<std::string, char>(), AcademicStatus::Good_Standing) {}