#include "../include/menu.h"

Menu::Menu(uint8_t height, uint8_t width, uint8_t y, uint8_t x)
    : m_height(height), m_width(width), m_y(y), m_x(x) {}

bool Menu::init() { return true; }