#include <cstdlib>
#include <iostream>
// #include <mongocxx/client.hpp>
// #include <mongocxx/instance.hpp>
// #include <mongocxx/options/client.hpp>
// #include <mongocxx/uri.hpp>
#include <array>
#include <string>

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
  std::array<std::string, 6> LoginOptions{"Login Menu",    "Student Login",
                                          "Faculty Login", "Proctor Login",
                                          "Admin Login",   "Exit Menu"};
  std::array<std::string, 5> MainOptions{
      "Main Menu", "Create Collection", "Reset Collection", "Remove Collection",
      "Exit Program"};
  MainMenu options = Create;
  char ch;

  // ^ Removes access to m_Win which is what I want
  while ((ch = menu.input())) {
    menu.clear();
    menu.CheckWindowSize();
    menu.PrintTitle(MainOptions[0]);
    switch (ch) {
      case 'B': {
        IncreaseHighlighted<MainMenu>(options, MainOptions.size() - 1);
        break;
      }
      case 'A': {
        DecreaseHighlighted<MainMenu>(options);
        break;
      }
      default: {
        break;
      }
    }
    // Calling print and passing size of array for template @param SIZE
    menu.print<MainMenu, MainOptions.size()>(options, MainOptions);
  }
  return 0;
}