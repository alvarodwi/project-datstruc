#include "menu.hpp"

void menu_1(queue::Queue &q)
{
    refresh_ui();
    int status;
    bool flag = false;
    std::string nama;
    pNode it;
    do
    {
        std::cout << "[APLIKASI ANTRIAN KLINIK]\n"
                  << "\n[Tambah Pasien]\n";

        std::cout
            << "\n//INFO\n"
            << "Pengelompokkan status pasien :\n"
            << "1. Gawat Darurat (eg. kecelakaan)\n"
            << "2. Darurat Tidak Gawat (eg. luka bakar, demam tinggi)\n"
            << "3. Tidak Darurat Tidak Gawat (wg. batuk/pilek, luka ringan)\n";

        std::cout << "\n[Input]\n"
                  << "Status > ";
        std::cin >> status;

        switch (status)
        {
        case 1:
        case 2:
        case 3:
            break;

        default:
            error_message("Status tidak boleh diluar interval 1-3");
            if (std::cin.fail())
            {
                std::cin.clear();
                ignore_line();
                std::cout << "Input tidak boleh berupa string atau karakter!\n\n";
            }
            goto refresh;
            break;
        }

        std::cout << "Nama > ";
        std::cin >> nama;

        it = queue::findByNama(q, nama);
        if (it != nullptr)
        {
            error_message("Nama pasien harus berbeda, gunakan nama lain untuk menambahkan kedalam antrian.");
        }
        else
        {
            flag = true;
            queue::push(q, createNode(Pasien{nama, status}));
            info_message("Data pasien berhasil dimasukkan ke dalam antrian.");
        }
    refresh:
        std::cout << "";
    } while (!flag);
}