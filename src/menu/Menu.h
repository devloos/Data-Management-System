#ifndef MENU_H_
#define MENU_H_
#include <ncurses.h>
#undef timeout

#include <array>
#include <cstdint>
#include <string>

namespace Menu {
enum Menus { Main = 0, Login };

class Menu {
 public:
  // TODO: Implementing the rule of 5
  Menu();
  ~Menu();
  // Refer to documentation in Menu.cpp
  void clear();
  void CheckWindowSize();
  void PrintTitle(const std::string &Title) const;
  char input() const;

  // This is the bread and butter of printing the menu to the window
  // a template is used to pass an array of any size (could have used vector didnt think
  // the extra overhead was worth it)
  template <typename T, std::size_t SIZE>
  void print(const T &highlighted, const std::array<std::string, SIZE> &options) const {
    // Placement of text with respect of the y axis
    int8_t yPlacement = options.size() / 2;
    // loop starting at index 1 to avoid collisions with title
    for (int i = 1; i < options.size(); ++i) {
      // TODO: Maybe use map
      // using window attribute on and off to highlight the currently selected menu option
      if (highlighted == T(i)) wattron(win_, A_STANDOUT);
      mvwprintw(
          win_, (yMax_ / 4) - yPlacement, (xMax_ / 4) - (options[i].size() / 2),
          options[i].c_str());
      if (highlighted == T(i)) wattroff(win_, A_STANDOUT);
      --yPlacement;
    }
  }

 private:
  uint16_t xMax_;
  uint16_t yMax_;
  WINDOW* win_;
};
}  // namespace Menu

#endif  // MENU_H_