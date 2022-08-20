#include "Control.h"

namespace Control {
void LoginMenu() {
  std::array<std::string, 6> LoginOptions{"Login Menu",    "Student Login",
                                          "Teacher Login", "Proctor Login",
                                          "Admin Login",   "Exit Menu"};
  Menu::Options::Login option = Menu::Options::Login::Exit;
  do {
    option = Menu::Logic::Input<Menu::Options::Login, LoginOptions.size()>(
        LoginOptions, Menu::Options::Login::Student);
    switch (option) {
      case Menu::Options::Login::Student: {
        system("clear");
        std::string id;
        std::string password;
        std::cout << "Enter ID: ";
        std::cin >> id;
        std::cout << "Enter Password: ";
        std::cin >> password;
        break;
      }
      case Menu::Options::Login::Teacher: {
        break;
      }
      case Menu::Options::Login::Proctor: {
        break;
      }
      case Menu::Options::Login::Admin: {
        break;
      }
      default:
        break;
    }
  } while (option != Menu::Options::Login::Exit);
}

void MainMenu() {
  std::array<std::string, 5> MainOptions{
      "Main Menu", "Create Collection", "Reset Collection", "Remove Collection",
      "Exit Program"};
  Menu::Options::Main option = Menu::Options::Main::Exit;
  do {
    option = Menu::Logic::Input<Menu::Options::Main, MainOptions.size()>(
        MainOptions, Menu::Options::Main::Create);
    switch (option) {
      case Menu::Options::Main::Create: {
        // init database();
        LoginMenu();
        break;
      }
      case Menu::Options::Main::Reset: {
        break;
      }
      case Menu::Options::Main::Remove: {
        break;
      }
      default:
        break;
    }
  } while (option != Menu::Options::Main::Exit);

}  // namespace Handler
}  // namespace Control
