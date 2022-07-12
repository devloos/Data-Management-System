#include <array>
#include <cstdlib>
#include <iostream>
#include <string>

#include "../include/Highlights.h"
#include "../include/Menu.h"

LoginMenu LoginHandler() {
  Menu menu;
  std::array<std::string, 6> LoginOptions{"Login Menu",    "Student Login",
                                          "Faculty Login", "Proctor Login",
                                          "Admin Login",   "Exit Menu"};
  LoginMenu option = Student;
  char ch;

  // ^ Removes access to m_Win which is what I want
  while ((ch = menu.input())) {
    menu.clear();
    menu.CheckWindowSize();
    menu.PrintTitle(LoginOptions[0]);
    switch (ch) {
      case 'B': {
        IncreaseHighlighted<LoginMenu>(option, LoginOptions.size() - 1);
        break;
      }
      case 'A': {
        DecreaseHighlighted<LoginMenu>(option);
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
    menu.print<LoginMenu, LoginOptions.size()>(option, LoginOptions);
  }
  return ExitMenu;
}