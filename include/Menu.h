#ifndef MENU_H_
#define MENU_H_
#include <cstdint>
#include <ncurses.h>

class Menu {
 protected:
  uint8_t m_width;
  uint8_t m_height;
  uint8_t m_x;
  uint8_t m_y;
  WINDOW* m_win;
 public:
  uint8_t m_lines;
  uint8_t m_cols;
  Menu(uint8_t height, uint8_t width, uint8_t y, uint8_t x, uint8_t lines,
       uint8_t cols);
  bool init();
//   void print() const;
  void resize();
//   virtual void render();
};

#endif // MENU_H_