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
  std::array<std::string, 5> MenuOptions{
      "Main Menu", "Create Collection", "Reset Collection", "Remove Collection",
      "Exit Program"};
  std::array<std::string, 6> LoginOptions{"Login Menu",    "Student Login",
                                          "Faculty Login", "Proctor Login",
                                          "Admin Login",   "Exit Menu"};
  switch (MenuHandler<MainMenu, MenuOptions.size()>(MenuOptions, Create)) {
    case Create: {
      MenuHandler<LoginMenu, LoginOptions.size()>(LoginOptions, Student);
      break;
    }
    case Reset: {
      break;
    }
    case Remove: {
      break;
    }
    default:
      break;
  }
  return 0;
}