#include <cstdlib>
#include <iostream>
// #include <mongocxx/client.hpp>
// #include <mongocxx/instance.hpp>
// #include <mongocxx/options/client.hpp>
// #include <mongocxx/uri.hpp>
#include <string>
#undef timeout
#include <array>

#include "../include/Menu.h"

enum Highlights { CreateCollection = 1, ResetCollection, RemoveCollection, Exit };

Highlights &operator++(Highlights &highlighted, int) {
  const int i = int(highlighted) + 1;
  if (i >= 3) return highlighted;
  highlighted = Highlights(i);
  return highlighted;
}

Highlights &operator--(Highlights &highlighted, int) {
  const int i = int(highlighted) - 1;
  if (i < 0) return highlighted;
  highlighted = Highlights(i);
  return highlighted;
}

int main() {
  // mongocxx::instance inst{};
  // const auto uri = mongocxx::uri{
  //     "mongodb+srv://averageJoe:hxYWatUPGcblcWU5@sandboxdatabase.ok6hp.mongodb.net/"
  //     "?retryWrites=true&w=majority"};
  // mongocxx::client conn{uri};
  // mongocxx::database db = conn["SandBox"];
  // if (db.has_collection(
  //         bsoncxx::v_noabi::string::view_or_value("Connor Goated at Unit Circle")))
  //   ;
  // std::cout << "This works my guy\n";
  Menu menu;
  std::array<std::string, 5> MainSelection{
      "Main Menu", "Create Collection", "Reset Collection", "Remove Collection",
      "Exit Program"};
  std::array<std::string, 6> LoginSelection{"Login Menu",    "Student Login",
                                            "Faculty Login", "Proctor Login",
                                            "Admin Login",   "Exit Menu"};
  Highlights highlighted = CreateCollection;
  char ch;

  while ((ch = wgetch(menu.m_Win))) {
    menu.clear();
    menu.CheckWindowSize();
    mvwprintw(
        menu.m_Win, 1, (menu.m_xMax / 4) - (MainSelection[0].size() / 2),
        MainSelection[0].c_str());  // Always 1 for y
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
    for (int i = 1; i < 5; ++i) {
      if (highlighted == Highlights(i)) wattron(menu.m_Win, A_STANDOUT);
      mvwprintw(
          menu.m_Win, (menu.m_yMax / 4) + i,
          (menu.m_xMax / 4) - (MainSelection[i].size() / 2),
          MainSelection[i].c_str());  // Always 1 for y
      if (highlighted == Highlights(i)) wattroff(menu.m_Win, A_STANDOUT);
    }
  }
  return 0;
}