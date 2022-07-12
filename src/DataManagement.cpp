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

MainMenu MainHandler();
LoginMenu LoginHandler();

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
  switch (MainHandler()) {
    case Create: {
      LoginHandler();
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