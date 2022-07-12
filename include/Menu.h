#ifndef MENU_H_
#define MENU_H_
#include <ncurses.h>
#undef timeout

#include <array>
#include <cstdint>
#include <string>

#include "../include/Highlights.h"

class Menu {
 public:
  // TODO: Implementing the rule of 5
  Menu();
  // Refer to documentation in Menu.cpp
  void clear();
  void CheckWindowSize();
  void PrintTitle(const std::string &Title) const;
  char input() const;

  // This is the bread and butter of printing the menu to the window
  // a template it used to pass an array of any size (could have used vector didnt think
  // the extra overhead was worth it)
  // using window attribute on and off to highlight the currently selected menu option
  template <std::size_t SIZE>
  void print(
      const Highlights &highlighted,
      const std::array<std::string, SIZE> &MenuSelection) const {
    // Placement of text with respect of the y axis
    int8_t yPlacement = MenuSelection.size() / 2;
    // loop starting at index 1 to avoid collisions with title
    for (int i = 1; i < MenuSelection.size(); ++i) {
      // this is tenary since I might use a map later but checks if current index should
      // be the one highlighted
      if (highlighted == Highlights(i)) wattron(m_Win, A_STANDOUT);
      mvwprintw(
          m_Win, (m_yMax / 4) - yPlacement, (m_xMax / 4) - (MenuSelection[i].size() / 2),
          MenuSelection[i].c_str());
      if (highlighted == Highlights(i)) wattroff(m_Win, A_STANDOUT);
      --yPlacement;
    }
  }

 private:
  uint8_t m_Width;
  uint8_t m_Height;
  uint8_t m_xMax;
  uint8_t m_yMax;
  WINDOW* m_Win;
};

#endif  // MENU_H_