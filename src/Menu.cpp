#include "../include/menu.h"

// Initializing window
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
// Clear window content
// Required for spill of content when resizing
void Menu::clear() { wclear(m_Win); }
// Gets current size of window and compares it to "passed" y max and x max
// if change then resize window
void Menu::CheckWindowSize() {
  getmaxyx(stdscr, m_Height, m_Width);
  // if either or
  if (m_yMax != m_Height || m_xMax != m_Width) {
    m_yMax = m_Height;
    m_xMax = m_Width;
    // Based on ncurses documentation https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/
    wborder(m_Win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(m_Win);
    endwin();
    // new window created
    m_Win = newwin(m_yMax / 2, m_xMax / 2, m_yMax / 4, m_xMax / 4);
  }
  // This method boxes window regardless since we call wclear every cycle
  box(m_Win, 0, 0);
}

void Menu::PrintTitle(const std::string &Title) const {
  mvwprintw(
      m_Win, 1, (m_xMax / 4) - (Title.size() / 2),
      Title.c_str());  // Always 1 for y
}