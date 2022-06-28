#include <cstdlib>
#include <iostream>
#include <string>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/options/client.hpp>
#include <ncurses.h>

#include "../include/Menu.h"

void CheckWindowSize(WINDOW* &win, int &yMax, int &xMax, int &height, int &width);
  // mongocxx::instance inst{};
  // const auto uri = mongocxx::uri{"mongodb+srv://averageJoe:hxYWatUPGcblcWU5@sandboxdatabase.ok6hp.mongodb.net/?retryWrites=true&w=majority"};
  // mongocxx::client conn{uri};
  // mongocxx::database db = conn["SandBox"];
  // if (db.has_collection(bsoncxx::v_noabi::string::view_or_value("Connor Goated at Unit Circle")))
  //   std::cout << "This works my guy\n";
enum Highlights {
  RunDatabase = 0,
  ResetDatabase,
  Exit
};

Highlights& operator++(Highlights& highlighted, int) {
  const int i = int(highlighted)+1;
  if (i >= 3)
    return highlighted;
  highlighted = Highlights(i);
  return highlighted;
}

Highlights& operator--(Highlights& highlighted, int) {
  const int i = int(highlighted)-1;
  if (i < 0)
    return highlighted;
  highlighted = Highlights(i);
  return highlighted;
}

int main() {
  initscr();
  noecho();
  curs_set(0);

  int yMax, xMax, height, width;
  getmaxyx(stdscr, yMax, xMax);

  WINDOW* win = newwin(yMax / 2, xMax / 2, yMax / 4, xMax / 4);
  nodelay(win, true);
  box(win, 0, 0);

  Highlights highlighted = RunDatabase;
  char ch;

  while (ch = wgetch(win)) {
    CheckWindowSize(win, yMax, xMax, height, width);
    mvwprintw(win, 1, (xMax / 4)-4, "Main Menu"); // Always 1 for y
    switch (ch) {
      case 'B': {
        highlighted++;
        break;
      }
      case 'A': {
        highlighted--;
        break;
      }
      default: {
        break;
      }
    }
    switch (highlighted) {
      case RunDatabase: {
        wattron(win, A_STANDOUT);
        mvwprintw(win, (yMax / 4)-2, (xMax / 4)-5, "Run Database");
        wattroff(win, A_STANDOUT);
        mvwprintw(win, (yMax / 4)-1, (xMax / 4)-6, "Reset Database");
        mvwprintw(win, (yMax / 4), (xMax / 4)-1, "Exit");
        break;
      }
      case ResetDatabase: {
        mvwprintw(win, (yMax / 4)-2, (xMax / 4)-5, "Run Database");
        wattron(win, A_STANDOUT);
        mvwprintw(win, (yMax / 4)-1, (xMax / 4)-6, "Reset Database");
        wattroff(win, A_STANDOUT);
        mvwprintw(win, (yMax / 4), (xMax / 4)-1, "Exit");
        break;
      }
      case Exit: {
        mvwprintw(win, (yMax / 4)-2, (xMax / 4)-5, "Run Database");
        mvwprintw(win, (yMax / 4)-1, (xMax / 4)-6, "Reset Database");
        wattron(win, A_STANDOUT);
        mvwprintw(win, (yMax / 4), (xMax / 4)-1, "Exit");
        wattroff(win, A_STANDOUT);
        break;
      }
      default: {
        break;
      }
    }
  }

  endwin();
	return 0;
}