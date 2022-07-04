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
  void PrintTitle() const;
  void print(const Highlights& highlighted) const;
  std::array<std::string, 5> MainSelection{
      "Main Menu", "Create Collection", "Reset Collection", "Remove Collection",
      "Exit Program"};
  uint8_t m_Width;
  uint8_t m_Height;
  uint8_t m_xMax;
  uint8_t m_yMax;
  WINDOW* m_Win;
};

#endif  // MENU_H_