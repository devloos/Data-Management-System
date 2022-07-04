#include <cstdlib>
#include <iostream>
// #include <mongocxx/client.hpp>
// #include <mongocxx/instance.hpp>
// #include <mongocxx/options/client.hpp>
// #include <mongocxx/uri.hpp>
#include <string>
#undef timeout
#include <array>

#include "../include/Highlights.h"
#include "../include/Menu.h"

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
  std::array<std::string, 6> LoginSelection{"Login Menu",    "Student Login",
                                            "Faculty Login", "Proctor Login",
                                            "Admin Login",   "Exit Menu"};
  std::array<std::string, 5> MainSelection{
      "Main Menu", "Create Collection", "Reset Collection", "Remove Collection",
      "Exit Program"};
  Highlights highlighted = CreateCollection;
  char ch;

  while ((ch = wgetch(menu.m_Win))) {
    menu.clear();
    menu.CheckWindowSize();
    menu.PrintTitle(MainSelection[0]);
    switch (ch) {
      case 'B': {
        operator++(highlighted, MainSelection.size());
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
    menu.print<MainSelection.size()>(highlighted, MainSelection);
  }
  return 0;
}