#include "menu.hpp"

void menu_4(queue::Queue &q)
{
    refresh_ui();
    bool flag = false;
    int pilihan;
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
            std::cout << "  1. Daftarkan Ulang\n"
                      << "  2. Hapus dari Antrian\n"
                      << "  3. Kembali\n\n";

            std::cout << "Pilihan > ";
            ignore_line();
            std::cin >> pilihan;

            switch (pilihan)
            {
            case 1:
                int statusBaru;
                std::cout << "\n//INFO\n"
                          << "Pengelompokkan status pasien :\n"
                          << "1. Gawat Darurat (eg. kecelakaan)\n"
                          << "2. Darurat Tidak Gawat (eg. luka bakar, demam tinggi)\n"
                          << "3. Tidak Darurat Tidak Gawat (wg. batuk/pilek, luka ringan)\n";
                std::cout << "\n[Daftar Ulang]\n"
                          << "Status Baru > ";
                std::cin >> statusBaru;
                if (statusBaru == it->data.status)
                {
                    flag = true;
                    error_message("Status Pasien sama dengan sebelumnya, antrian pasien tidak diubah");
                    goto refresh;
                }
                else
                {
                    switch (statusBaru)
                    {
                    case 1:
                    case 2:
                    case 3:
                        queue::eraseByNama(q, sNama);
                        queue::push(q, createNode(Pasien{sNama, statusBaru}));
                        info_message("Pasien dengan nama " + sNama + " telah diubah statusnya\nPasien berhasil didaftarkan ulang ke dalam antrian");
                        goto refresh;
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
                    flag = true;
                }
                break;

            case 2:
                flag = true;
                queue::eraseByNama(q, sNama);
                info_message("Pasien dengan nama " + sNama + " telah dihapus dari antrian");
                goto refresh;
                break;

            case 3:
                flag = true;
                break;

            default:
                error_message("Pilihan tidak ada dalam menu");
                goto refresh;
                break;
            }
        }
        else
        {
            std::cout << "\n//INFO\n"
                      << "Pasien tidak ditemukan dalam antrian.\n\n"
                      << "  1. Cari Ulang\n"
                      << "  2. Kembali\n\n";

            std::cout << "Pilihan > ";
            std::cin >> pilihan;
            switch (pilihan)
            {
            case 1:
                break;

            case 2:
                flag = true;
                break;

            default:
                error_message("Pilihan tidak ada dalam menu");
                goto refresh;
                break;
            }
        }
        refresh_ui();
    refresh:
        std::cout << "";
    } while (!flag);
}