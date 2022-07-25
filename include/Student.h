#ifndef STUDENT_H_
#define STUDENT_H_
#include <unordered_map>
#include <vector>

#include "Person.h"

enum struct AcademicStatus { Probation = 0, Falling_Behind, Good_Standing, Honors };

class Student : public Person {
 public:
  Student(
      const uint16_t &id, const std::string &password, const uint16_t studentYear,
      const float &GPA, const std::vector<std::string> &classSchedule,
      const std::unordered_map<std::string, char> &grades,
      const AcademicStatus &studentStatus);
  Student(
      const uint16_t &id, const std::string &password, const uint16_t studentYear,
      const float &GPA, const std::vector<std::string> &classSchedule);
  Student(const uint16_t &id, const std::string &password, const uint16_t studentYear);

 private:
  uint16_t studentYear_;
  float GPA_;
  std::vector<std::string> classSchedule_;
  std::unordered_map<std::string, char> grades_;
  AcademicStatus studentStatus_;
};

#endif  // STUDENT_H_