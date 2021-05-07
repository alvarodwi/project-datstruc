#include "menu.hpp"

int menu_5(queue::Queue &q)
{
    if (queue::isEmpty(q))
    {
        std::cout << "\nSelamat beristirahat...\n";
        refresh_ui();
        return 5;
    }
    else
    {
        error_message(
            "Masih ada pasien dalam antrian.\nSelesaikan dulu antriannya!");
        return 0;
    }
}