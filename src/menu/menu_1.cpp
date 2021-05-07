#include "menu.hpp"

void menu_1(queue::Queue &q)
{
    refreshUI();
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
            << "3. Tidak Darurat Tiadk Gawat (wg. batuk/pilek, luka ringan)\n";

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
            error_message("Pilihan tidak ada dalam menu");
            goto refresh1;
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
    refresh1:
        std::cout << "";
    } while (!flag);
}