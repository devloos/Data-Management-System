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

int main() {
  initscr();
  noecho();
  curs_set(0);

  int yMax, xMax, height, width;
  getmaxyx(stdscr, yMax, xMax);

  WINDOW* win = newwin(yMax / 2, xMax / 2, yMax / 4, xMax / 4);
  nodelay(win, true);
  box(win, 0, 0);

  char ch;
  while (ch = wgetch(win)) {
    CheckWindowSize(win, yMax, xMax, height, width);
    switch (ch) {
      case KEY_DOWN: {
        break;
      }
      case KEY_UP: {
        break;
      }
      default: {
        mvwprintw(win, 1, xMax / 4.5, "Main Menu"); // Always 1 for y
        break;
      }
    }
  }

  endwin();
	return 0;
}