#ifndef MENU_H_
#define MENU_H_
#include <ncurses.h>

#include <cstdint>

class Menu {
 public:
  Menu();
  void clear();
  void CheckWindowSize();
  uint8_t m_Width;
  uint8_t m_Height;
  uint8_t m_xMax;
  uint8_t m_yMax;
  WINDOW* m_Win;
};

#endif  // MENU_H_