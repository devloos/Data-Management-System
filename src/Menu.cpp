#include "../include/menu.h"

Menu::Menu(uint8_t height, uint8_t width, uint8_t y, uint8_t x, uint8_t lines,
                 uint8_t cols)
    : m_height(height), m_width(width), m_y(y), m_x(x), m_lines(lines), m_cols(cols) {}

bool Menu::init() {
  initscr();
	cbreak();
	keypad(stdscr, TRUE);

	printw("Press F1 to exit");
	refresh();
	m_win = newwin(m_height, m_width, m_y, m_x);
	box(m_win, 0 , 0);		/* 0, 0 gives default characters */
	wrefresh(m_win);		/* Show that box 		*/
}

void Menu::resize() {
	wborder(m_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(m_win);
	delwin(m_win);
	m_y = (LINES - m_height)/2;
	m_x = (COLS - m_width)/2;
	m_win = newwin(m_height, m_width, m_y, m_x);
	box(m_win, 0, 0);
	wrefresh(m_win);
}