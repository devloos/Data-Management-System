#ifndef MENU_OPTIONS_H_
#define MENU_OPTIONS_H_

namespace Menu {
namespace Options {
enum struct Main { Create = 1, Reset, Remove, Exit };
enum struct Login { Student = 1, Teacher, Proctor, Admin, Exit };
}  // namespace MenuOptions
}

#endif  // MENU_OPTIONS_H_