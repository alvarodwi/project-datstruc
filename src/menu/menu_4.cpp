#include "menu.hpp"

void menu_4(queue::Queue q)
{
    refresh_ui();
    bool flag = false;
    do
    {
        std::string sNama;
        std::cout << "[APLIKASI ANTRIAN KLINIK]\n"
                  << "\n[Cari Pasien]\n";

        std::cout << "Nama\t> ";
        std::cin >> sNama;

        auto it = queue::findByNama(q, sNama);
        if (it)
        {
            flag = true;
            int index = queue::checkIndex(q, it);
            std::cout << "\n//INFO\n"
                      << "Pasien ditemukan dalam antrian.\n";
            std::cout << "Nama\t: " << it->data.nama << "\n"
                      << "Status\t: " << printStatus(it->data) << "\n"
                      << "Antrian\t: ke-" << index << "\n\n";
        }
        else
        {
            int pilihan;
            std::cout << "\n//INFO\n"
                      << "Pasien tidak ditemukan dalam antrian.\n\n"
                      << "  1. Cari Ulang\n"
                      << "  2. Kembali\n\n";

            std::cout << "Pilihan > ";
            std::cin >> pilihan;
            flag = (pilihan == 1) ? false : true;
        }
        refresh_ui();
    } while (!flag);
}