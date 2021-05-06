#include <iostream>
#include <iomanip>
#include "./menu/menu.cpp"
#include "./menu/menu_1.cpp"
#include "./menu/menu_2.cpp"
#include "./menu/menu_3.cpp"
#include "./menu/menu_4.cpp"
#include "./menu/menu_5.cpp"

int main()
{
  queue::Queue antrian = queue::createQueue();
  stack::Stack pelayanan = stack::createStack();

  int menu;
  do
  {
    std::cout << "[APLIKASI ANTRIAN KLINIK]\n"
              << "\nPasien yang dilayani\t: ";
    if (stack::isEmpty(pelayanan))
    {
      std::cout << "-\n";
    }
    else
    {
      Pasien top = stack::peek(pelayanan);
      std::cout << top.nama << '\n';
    }
    std::cout << "Jumlah antrian\t\t: ";
    std::cout << queue::size(antrian) << "\n\n";
    std::cout << "[MENU]\n\n"
              << "1. Tambah Pasien\n"
              << "2. Panggil Pasien\n"
              << "3. Cek Antrian\n"
              << "4. Cari Pasien\n"
              << "5. Exit\n"
              << "\nPilihan > ";
    std::cin >> menu;
    switch (menu)
    {
    case 1:
      menu_1(antrian);
      break;

    case 2:
      menu_2(antrian, pelayanan);
      break;

    case 3:
      menu_3(antrian);
      break;

    case 4:
      menu_4(antrian);
      break;

    case 5:
      menu = menu_5(antrian);
      break;

    default:
      error_message("Pilihan tidak ada dalam menu");
      break;
    }
  } while (menu != 5);

  stack::clearStack(pelayanan);
  return 0;
}