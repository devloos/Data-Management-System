#include "../../include/Menu.h"

void LoginHandler() {
  std::array<std::string, 6> LoginOptions{"Login Menu",    "Student Login",
                                          "Faculty Login", "Proctor Login",
                                          "Admin Login",   "Exit Menu"};
  LoginMenu option = LoginMenu::Exit;
  do {
    option =
        MenuHandler<LoginMenu, LoginOptions.size()>(LoginOptions, LoginMenu::Student);
    switch (option) {
      case LoginMenu::Student: {
        break;
      }
      case LoginMenu::Faculty: {
        break;
      }
      case LoginMenu::Proctor: {
        break;
      }
      case LoginMenu::Admin: {
        break;
      }
      default:
        break;
    }
  } while (option != LoginMenu::Exit);
}