#ifndef MENU_H_
#define MENU_H_
#include <ncurses.h>

#include <array>
#include <cstdint>
#include <string>

#include "../include/Highlights.h"

class Menu {
 public:
  Menu();
  void clear();
  void CheckWindowSize();
  void PrintTitle(const std::string &Title) const;

  template <std::size_t SIZE>
  void print(
      const Highlights &highlighted,
      const std::array<std::string, SIZE> &MenuSelection) const {
    int8_t yPlacement = MenuSelection.size() / 2;
    for (int i = 1; i < MenuSelection.size(); ++i) {
      if (highlighted == Highlights(i)) wattron(m_Win, A_STANDOUT);
      mvwprintw(
          m_Win, (m_yMax / 4) - yPlacement, (m_xMax / 4) - (MenuSelection[i].size() / 2),
          MenuSelection[i].c_str());  // Always 1 for y
      if (highlighted == Highlights(i)) wattroff(m_Win, A_STANDOUT);
      --yPlacement;
    }
  }

  WINDOW *m_Win;

 private:
  uint8_t m_Width;
  uint8_t m_Height;
  uint8_t m_xMax;
  uint8_t m_yMax;
};

#endif  // MENU_H_