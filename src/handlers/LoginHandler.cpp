#include <iostream>

#include "../../include/Menu.h"

void LoginHandler() {
  std::array<std::string, 6> LoginOptions{"Login Menu",    "Student Login",
                                          "Teacher Login", "Proctor Login",
                                          "Admin Login",   "Exit Menu"};
  LoginMenu option = LoginMenu::Exit;
  do {
    option =
        MenuHandler<LoginMenu, LoginOptions.size()>(LoginOptions, LoginMenu::Student);
    switch (option) {
      case LoginMenu::Student: {
        system("clear");
        std::string id;
        std::string password;
        std::cout << "Enter ID: ";
        std::cin >> id;
        std::cout << "Enter Password: ";
        std::cin >> password;
        break;
      }
      case LoginMenu::Teacher: {
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