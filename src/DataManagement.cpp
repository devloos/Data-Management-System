#include <cstdlib>
#include <iostream>
// #include <mongocxx/client.hpp>
// #include <mongocxx/instance.hpp>
// #include <mongocxx/options/client.hpp>
// #include <mongocxx/uri.hpp>
#include <string>
#undef timeout

#include "../include/Menu.h"

enum Highlights { RunDatabase = 0, ResetDatabase, Exit };

Highlights &operator++(Highlights &highlighted, int) {
  const int i = int(highlighted) + 1;
  if (i >= 3) return highlighted;
  highlighted = Highlights(i);
  return highlighted;
}

Highlights &operator--(Highlights &highlighted, int) {
  const int i = int(highlighted) - 1;
  if (i < 0) return highlighted;
  highlighted = Highlights(i);
  return highlighted;
}

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
  Menu menu;
  Highlights highlighted = RunDatabase;
  char ch;

  while ((ch = wgetch(menu.m_Win))) {
    wclear(menu.m_Win);
    menu.CheckWindowSize();
    mvwprintw(menu.m_Win, 1, (menu.m_xMax / 4) - 4, "Main Menu");  // Always 1 for y
    switch (ch) {
      case 'B': {
        highlighted++;
        break;
      }
      case 'A': {
        highlighted--;
        break;
      }
      case 'c': {
        bool d = false;
        while ((ch = wgetch(menu.m_Win)) && !d) {
          wclear(menu.m_Win);
          box(menu.m_Win, 0, 0);
          menu.CheckWindowSize();
          mvwprintw(menu.m_Win, 1, (menu.m_xMax / 4) - 2, "Login");  // Always 1 for y
          switch (ch) {
            case 'B': {
              highlighted++;
              break;
            }
            case 'A': {
              highlighted--;
              break;
            }
            case 'j': {
              d = true;
              break;
            }
            default: {
              break;
            }
          }
          switch (highlighted) {
            case RunDatabase: {
              wattron(menu.m_Win, A_STANDOUT);
              mvwprintw(
                  menu.m_Win, (menu.m_yMax / 4) - 2, (menu.m_xMax / 4) - 5,
                  "Student Login");
              wattroff(menu.m_Win, A_STANDOUT);
              mvwprintw(
                  menu.m_Win, (menu.m_yMax / 4) - 1, (menu.m_xMax / 4) - 6,
                  "Faculty Login");
              mvwprintw(menu.m_Win, (menu.m_yMax / 4), (menu.m_xMax / 4) - 1, "Exit");
              break;
            }
            case ResetDatabase: {
              mvwprintw(
                  menu.m_Win, (menu.m_yMax / 4) - 2, (menu.m_xMax / 4) - 5,
                  "Student Login");
              wattron(menu.m_Win, A_STANDOUT);
              mvwprintw(
                  menu.m_Win, (menu.m_yMax / 4) - 1, (menu.m_xMax / 4) - 6,
                  "Faculty Login");
              wattroff(menu.m_Win, A_STANDOUT);
              mvwprintw(menu.m_Win, (menu.m_yMax / 4), (menu.m_xMax / 4) - 1, "Exit");
              break;
            }
            case Exit: {
              mvwprintw(
                  menu.m_Win, (menu.m_yMax / 4) - 2, (menu.m_xMax / 4) - 5,
                  "Student Login");
              mvwprintw(
                  menu.m_Win, (menu.m_yMax / 4) - 1, (menu.m_xMax / 4) - 6,
                  "Faculty Login");
              wattron(menu.m_Win, A_STANDOUT);
              mvwprintw(menu.m_Win, (menu.m_yMax / 4), (menu.m_xMax / 4) - 1, "Exit");
              wattroff(menu.m_Win, A_STANDOUT);
              break;
            }
            default: {
              break;
            }
          }
        }
        break;
      }
      default: {
        break;
      }
    }
    switch (highlighted) {
      case RunDatabase: {
        wattron(menu.m_Win, A_STANDOUT);
        mvwprintw(
            menu.m_Win, (menu.m_yMax / 4) - 2, (menu.m_xMax / 4) - 5, "Run Database");
        wattroff(menu.m_Win, A_STANDOUT);
        mvwprintw(
            menu.m_Win, (menu.m_yMax / 4) - 1, (menu.m_xMax / 4) - 6, "Reset Database");
        mvwprintw(menu.m_Win, (menu.m_yMax / 4), (menu.m_xMax / 4) - 1, "Exit");
        break;
      }
      case ResetDatabase: {
        mvwprintw(
            menu.m_Win, (menu.m_yMax / 4) - 2, (menu.m_xMax / 4) - 5, "Run Database");
        wattron(menu.m_Win, A_STANDOUT);
        mvwprintw(
            menu.m_Win, (menu.m_yMax / 4) - 1, (menu.m_xMax / 4) - 6, "Reset Database");
        wattroff(menu.m_Win, A_STANDOUT);
        mvwprintw(menu.m_Win, (menu.m_yMax / 4), (menu.m_xMax / 4) - 1, "Exit");
        break;
      }
      case Exit: {
        mvwprintw(
            menu.m_Win, (menu.m_yMax / 4) - 2, (menu.m_xMax / 4) - 5, "Run Database");
        mvwprintw(
            menu.m_Win, (menu.m_yMax / 4) - 1, (menu.m_xMax / 4) - 6, "Reset Database");
        wattron(menu.m_Win, A_STANDOUT);
        mvwprintw(menu.m_Win, (menu.m_yMax / 4), (menu.m_xMax / 4) - 1, "Exit");
        wattroff(menu.m_Win, A_STANDOUT);
        break;
      }
      default: {
        break;
      }
    }
  }
  return 0;
}