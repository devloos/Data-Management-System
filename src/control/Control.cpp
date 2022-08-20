#include "Control.h"

namespace Control {
void LoginMenu() {
  std::array<std::string, 6> LoginOptions{"Login Menu",    "Student Login",
                                          "Teacher Login", "Proctor Login",
                                          "Admin Login",   "Exit Menu"};
  MenuOptions::Login option = MenuOptions::Login::Exit;
  do {
    option = Menu::Handle::MenuLogic<MenuOptions::Login, LoginOptions.size()>(
        LoginOptions, MenuOptions::Login::Student);
    switch (option) {
      case MenuOptions::Login::Student: {
        system("clear");
        std::string id;
        std::string password;
        std::cout << "Enter ID: ";
        std::cin >> id;
        std::cout << "Enter Password: ";
        std::cin >> password;
        break;
      }
      case MenuOptions::Login::Teacher: {
        break;
      }
      case MenuOptions::Login::Proctor: {
        break;
      }
      case MenuOptions::Login::Admin: {
        break;
      }
      default:
        break;
    }
  } while (option != MenuOptions::Login::Exit);
}

void MainMenu() {
  std::array<std::string, 5> MainOptions{
      "Main Menu", "Create Collection", "Reset Collection", "Remove Collection",
      "Exit Program"};
  MenuOptions::Main option = MenuOptions::Main::Exit;
  do {
    option = Menu::Handle::MenuLogic<MenuOptions::Main, MainOptions.size()>(
        MainOptions, MenuOptions::Main::Create);
    switch (option) {
      case MenuOptions::Main::Create: {
        // init database();
        LoginMenu();
        break;
      }
      case MenuOptions::Main::Reset: {
        break;
      }
      case MenuOptions::Main::Remove: {
        break;
      }
      default:
        break;
    }
  } while (option != MenuOptions::Main::Exit);

}  // namespace Handler
}  // namespace Control
