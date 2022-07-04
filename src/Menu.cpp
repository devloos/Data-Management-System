#include "../include/menu.h"

Menu::Menu() {
  initscr();
  noecho();
  curs_set(0);

  getmaxyx(stdscr, m_yMax, m_xMax);
  m_Height = m_yMax;
  m_Width = m_xMax;

  m_Win = newwin(m_yMax / 2, m_xMax / 2, m_yMax / 4, m_xMax / 4);
  nodelay(m_Win, true);
}
void Menu::clear() { wclear(m_Win); }
void Menu::CheckWindowSize() {
  getmaxyx(stdscr, m_Height, m_Width);
  if (m_yMax != m_Height || m_xMax != m_Width) {
    m_yMax = m_Height;
    m_xMax = m_Width;
    wborder(m_Win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(m_Win);
    endwin();
    m_Win = newwin(m_yMax / 2, m_xMax / 2, m_yMax / 4, m_xMax / 4);
  }
  box(m_Win, 0, 0);
}