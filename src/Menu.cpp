#include "../include/Menu.h"

// Initializing window
Menu::Menu() {
  initscr();
  noecho();
  curs_set(0);

  getmaxyx(stdscr, yMax_, xMax_);
  height_ = yMax_;
  width_ = xMax_;

  win_ = newwin(yMax_ / 2, xMax_ / 2, yMax_ / 4, xMax_ / 4);
  nodelay(win_, true);
}

Menu::~Menu() { delwin(win_); }

// Clear window content
// Required for spill of content when resizing
void Menu::clear() { wclear(win_); }
// Gets current size of window and compares it to "passed" y max and x max
// if change then resize window
void Menu::CheckWindowSize() {
  getmaxyx(stdscr, height_, width_);
  // if either or
  if (yMax_ != height_ || xMax_ != width_) {
    yMax_ = height_;
    xMax_ = width_;
    // Based on ncurses documentation https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/
    wborder(win_, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(win_);
    endwin();
    // new window created
    win_ = newwin(yMax_ / 2, xMax_ / 2, yMax_ / 4, xMax_ / 4);
  }
  // This method boxes window regardless since we call wclear every cycle
  box(win_, 0, 0);
}

void Menu::PrintTitle(const std::string &Title) const {
  mvwprintw(win_, 1, (xMax_ / 4) - (Title.size() / 2),
            Title.c_str());  // Always 1 for y
}
char Menu::input() const { return wgetch(win_); }