#pragma once

#include "menu.hpp"
#include "../datstruc.cpp"

void error_message(std::string s)
{
    std::cout << "\n//ERROR\n";
    std::cout << s << '\n';
    system("pause");
    system("cls");
}

void info_message(std::string s)
{
    std::cout << "\n//INFO\n";
    std::cout << s << '\n';
    system("pause");
    system("cls");
}