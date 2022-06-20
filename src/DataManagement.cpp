#include <cstdlib>
#include <iostream>
#include <string>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/options/client.hpp>
#include <ncurses.h>

#include "../include/Menu.h"
  // mongocxx::instance inst{};
  // const auto uri = mongocxx::uri{"mongodb+srv://averageJoe:hxYWatUPGcblcWU5@sandboxdatabase.ok6hp.mongodb.net/?retryWrites=true&w=majority"};
  // mongocxx::client conn{uri};
  // mongocxx::database db = conn["SandBox"];
  // if (db.has_collection(bsoncxx::v_noabi::string::view_or_value("Connor Goated at Unit Circle")))
  //   std::cout << "This works my guy\n";

int main() {
  Menu main(20, 20, (LINES - 20)/2, (COLS - 20)/2, LINES, COLS);
  main.init();
  while(1) {
    if (LINES < 25)
      LINES = 25;
    if (COLS < 25)
      COLS = 25;

    if (LINES != main.m_lines || COLS != main.m_cols) {
      main.resize();
    }
  }
  getch();
	endwin();			
	return 0;
}