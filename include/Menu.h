#ifndef MENU_H_
#define MENU_H_
#include <cstdint>
#include <ncurses.h>

class Menu {
 public:
  Menu(uint8_t height, uint8_t width, uint8_t y, uint8_t x);
  bool init();
  uint8_t m_width;
  uint8_t m_height;
  uint8_t m_x;
  uint8_t m_y;
  WINDOW* m_win;
};

#endif // MENU_H_