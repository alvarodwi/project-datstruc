#include "menu.hpp"

void menu_4(queue::Queue q)
{
    system("pause");
    system("cls");
    int flag;
    do
    {
        std::string sNama;
        std::cout << "[APLIKASI ANTRIAN KLINIK]\n"
                  << "\n[Cari Pasien]\n";

        std::cout << "Nama\t>";
        std::cin >> sNama;

        auto it = queue::findByNama(q, sNama);
        if (it)
        {
            int index = queue::checkIndex(q, it);
            std::cout << "//INFO\n"
                      << "Pasien ditemukan dalam antrian.\n";
            std::cout << "Nama\t: " << it->data.nama << "\n"
                      << "Status\t: " << printStatus(it->data) << "\n"
                      << "Antrian ";
        }

    } while (flag != 0);
}