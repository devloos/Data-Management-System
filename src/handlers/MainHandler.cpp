#include "../../include/Menu.h"

void LoginHandler();

void MainHandler() {
  std::array<std::string, 5> MainOptions{
      "Main Menu", "Create Collection", "Reset Collection", "Remove Collection",
      "Exit Program"};
  MainMenu option = MainMenu::Exit;
  do {
    option = MenuHandler<MainMenu, MainOptions.size()>(MainOptions, MainMenu::Create);
    switch (option) {
      case MainMenu::Create: {
        LoginHandler();
        break;
      }
      case MainMenu::Reset: {
        break;
      }
      case MainMenu::Remove: {
        break;
      }
      default:
        break;
    }
  } while (option != MainMenu::Exit);
}