#include <array>
#include <string>

#include "../include/Highlights.h"
#include "../include/Menu.h"

void LoginHandler() {
  std::array<std::string, 6> LoginOptions{"Login Menu",    "Student Login",
                                          "Faculty Login", "Proctor Login",
                                          "Admin Login",   "Exit Menu"};
  LoginMenu option = ExitMenu;
  do {
    option = MenuHandler<LoginMenu, LoginOptions.size()>(LoginOptions, Student);
    switch (option) {
      case Student: {
        break;
      }
      case Faculty: {
        break;
      }
      case Proctor: {
        break;
      }
      case Admin: {
        break;
      }
      default:
        break;
    }
  } while (option != ExitMenu);
}