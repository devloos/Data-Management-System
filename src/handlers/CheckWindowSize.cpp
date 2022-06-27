#include "ncurses.h"

void CheckWindowSize(WINDOW* &win, int &yMax, int &xMax, int &height, int &width) {
  getmaxyx(stdscr, height, width);
  if (yMax != height || xMax != width) {
    yMax = height;
    xMax = width;
    wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    wrefresh(win);
    endwin();
    win = newwin(yMax / 2, xMax / 2, yMax / 4, xMax / 4);
    box(win, 0, 0);
  }
}