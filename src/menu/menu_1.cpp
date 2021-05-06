#include "menu.hpp"

void menu_1(queue::Queue &q)
{
    system("pause");
    system("cls");
    int status;
    bool nFlag = false;
    std::string nama;
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
    } while (status <= 1 && status >= 3);

    do
    {
        std::cout << "Nama > ";
        std::cin >> nama;
        nFlag = true;

        //   auto it = queue::findByNama(q,nama);
        //   if(!it){
        //     std::cout << "Gak Ketemu\n";
        //     error_message("Nama pasien harus berbeda, gunakan nama lain untuk
        //     menambahkan kedalam antrian."); goto refresh1;
        //   }else{
        //     nFlag = true;
        //     std::cout << "Ketemu\n";
        //   }
    } while (!nFlag);

    queue::push(q, createNode(Pasien{nama, status}));

    info_message("Data pasien berhasil dimasukkan ke dalam antrian.");
refresh1:
    std::cout << "";
}