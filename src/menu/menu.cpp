#include "menu.hpp"

void refresh_ui()
{
    std::cout << "Press any key to continue...";
    std::cin.ignore();
    std::cin.get();
    std::cout << "\033[2J\033[1;1H";
}

void ignore_line()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void error_message(std::string s)
{
    std::cout << "\n//ERROR\n";
    std::cout << s << '\n';
    refresh_ui();
}

void info_message(std::string s)
{
    std::cout << "\n//INFO\n";
    std::cout << s << '\n';
    refresh_ui();
}