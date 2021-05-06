#include "menu.hpp"

void error_message(std::string s)
{
    std::cout << "\n//ERROR\n";
    std::cout << s << '\n';
    refreshUI();
}

void info_message(std::string s)
{
    std::cout << "\n//INFO\n";
    std::cout << s << '\n';
    refreshUI();
}