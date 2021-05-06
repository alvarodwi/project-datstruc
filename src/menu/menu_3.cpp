#include "menu.hpp"

void menu_3(queue::Queue q)
{
      refresh_ui();
      std::cout << "[APLIKASI ANTRIAN KLINIK]\n"
                << "\n[Cek Antrian]\n"
                << "Jumlah antrian : " << queue::size(q) << "\n\n";
      if (queue::isEmpty(q))
      {
            info_message("Antrian kosong, belum ada pasien yang terdaftar.");
      }
      else
      {
            int count = 1;
            std::cout << std::setw(2) << std::setfill(' ') << std::left << "No"
                      << "| "
                      << std::setw(20) << std::setfill(' ') << std::left << "Nama"
                      << "| "
                      << std::setw(30) << std::setfill(' ') << std::left << "Status"
                      << "| " << '\n';
            queue::traversal(q, [&count](Pasien p) {
                  std::cout << std::setw(2) << std::setfill(' ') << std::left << count
                            << "| "
                            << std::setw(20) << std::setfill(' ') << std::left << p.nama
                            << "| "
                            << std::setw(30) << std::setfill(' ') << std::left << printStatus(p)
                            << "| " << '\n';
                  count++;
            });
            refresh_ui();
      }
}