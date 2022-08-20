#ifndef M_LOGIC_H_
#define M_LOGIC_H_

#include <cstdint>

#include "../Menu.h"

namespace Menu {
namespace Logic {
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
template <typename T, std::size_t SIZE>
T Input(std::array<std::string, SIZE> MenuOptions, T option) {
  Menu menu;
  const int8_t ENTER_KEY = 10, UP_ARROW = 'A', DOWN_ARROW = 'B';
  char ch;
  // ^ Removes access to win_ which is what I want
  while ((ch = menu.input())) {
    menu.clear();
    menu.CheckWindowSize();
    menu.PrintTitle(MenuOptions[0]);
    switch (ch) {
      case UP_ARROW: {
        DecreaseHighlighted<T>(option);
        break;
      }
      case DOWN_ARROW: {
        IncreaseHighlighted<T>(option, MenuOptions.size() - 1);
        break;
      }
      case ENTER_KEY: {
        return option;
        break;
      }
      default: {
        break;
      }
    }
    // Calling print and passing size of array for template @param SIZE
    menu.print<T, MenuOptions.size()>(option, MenuOptions);
  }
  return option;
}
}  // namespace Logic

}  // namespace Menu

#endif  // M_LOGIC_H_