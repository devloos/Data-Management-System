#include <array>
#include <cstdlib>
#include <iostream>
#include <string>

#include "../include/Highlights.h"
#include "../include/Menu.h"

MainMenu MainHandler() {
  Menu menu;
  std::array<std::string, 5> MainOptions{
      "Main Menu", "Create Collection", "Reset Collection", "Remove Collection",
      "Exit Program"};
  MainMenu option = Create;
  char ch;

  // ^ Removes access to m_Win which is what I want
  while ((ch = menu.input())) {
    menu.clear();
    menu.CheckWindowSize();
    menu.PrintTitle(MainOptions[0]);
    switch (ch) {
      case 'B': {
        IncreaseHighlighted<MainMenu>(option, MainOptions.size() - 1);
        break;
      }
      case 'A': {
        DecreaseHighlighted<MainMenu>(option);
        break;
      }
      case 'D': {
        return option;
        break;
      }
      default: {
        break;
      }
    }
    // Calling print and passing size of array for template @param SIZE
    menu.print<MainMenu, MainOptions.size()>(option, MainOptions);
  }
  return Exit;
}