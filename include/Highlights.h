#ifndef HIGHLIGHTS_H_
#define HIGHLIGHTS_H_

#include <cstdint>

namespace {
enum MainMenu { Create = 1, Reset, Remove, Exit };
enum LoginMenu { Student = 1, Faculty, Proctor, Admin, ExitMenu };

template <typename T>
void IncreaseHighlighted(T &highlighted, const int8_t &max) {
  const int i = int(highlighted) + 1;
  if (i >= max) {
    highlighted = T(max);
    return;
  }
  highlighted = T(i);
  return;
}

template <typename T>
void DecreaseHighlighted(T &highlighted) {
  const int8_t min = 1;
  const int i = int(highlighted) - 1;
  if (i <= min) {
    highlighted = T(min);
    return;
  }
  highlighted = T(i);
  return;
}
};  // namespace

#endif  // HIGHLIGHTS_H_