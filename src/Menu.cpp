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

void Menu::PrintTitle() const {
  mvwprintw(
      m_Win, 1, (m_xMax / 4) - (MainSelection[0].size() / 2),
      MainSelection[0].c_str());  // Always 1 for y
}
void Menu::print(const Highlights &highlighted) const {
  for (int i = 1; i < MainSelection.size(); ++i) {
    if (highlighted == Highlights(i)) wattron(m_Win, A_STANDOUT);
    mvwprintw(
        m_Win, (m_yMax / 4) + i, (m_xMax / 4) - (MainSelection[i].size() / 2),
        MainSelection[i].c_str());  // Always 1 for y
    if (highlighted == Highlights(i)) wattroff(m_Win, A_STANDOUT);
  }
}