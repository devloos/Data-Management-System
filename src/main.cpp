#include <cstdlib>
#include <iostream>
#include <string>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/options/client.hpp>

int main() {
  mongocxx::instance inst{};
  const auto uri = mongocxx::uri{"mongodb+srv://averageJoe:hxYWatUPGcblcWU5@sandboxdatabase.ok6hp.mongodb.net/?retryWrites=true&w=majority"};
  mongocxx::client conn{uri};
  mongocxx::database db = conn["SandBox"];
}
