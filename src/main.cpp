#include "datstruc.cpp"
#include <iostream>
#include <iomanip>

queue::Queue antrian;
stack::Stack pelayanan;

void menu_1();
void menu_2();
void menu_3();
void menu_4();
int menu_5();
void error_message(std::string s);
void info_message(std::string s);

int main()
{
  antrian = queue::createQueue();
  pelayanan = stack::createStack();

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
      menu_1();
      break;

    case 2:
      menu_2();
      break;

    case 3:
      menu_3();
      break;

    case 4:
      menu_4();
      break;

    case 5:
      menu = menu_5();
      break;

    default:
      error_message("Pilihan tidak ada dalam menu");
      break;
    }
  } while (menu != 5);

  // destruktor queue
  // destruktor stack
  return 0;
}

void menu_1()
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

    //   auto it = queue::findByNama(antrian,nama);
    //   if(!it){
    //     std::cout << "Gak Ketemu\n";
    //     error_message("Nama pasien harus berbeda, gunakan nama lain untuk
    //     menambahkan kedalam antrian."); goto refresh1;
    //   }else{
    //     nFlag = true;
    //     std::cout << "Ketemu\n";
    //   }
  } while (!nFlag);

  queue::push(antrian, createNode(Pasien{nama, status}));

  info_message("Data pasien berhasil dimasukkan ke dalam antrian.");
refresh1:
  std::cout << "";
}

void menu_2()
{
  if (queue::isEmpty(antrian))
  {
    error_message("Antrian kosong, belum ada pasien yang terdaftar");
  }
  else
  {
    pNode panggil = queue::pop(antrian);
    stack::push(pelayanan, panggil);
    info_message("Memanggil pasien dengan nama" + panggil->data.nama +
                 "\nUpdate antrian....");
  }
}

void menu_3()
{
  system("pause");
  system("cls");
  std::cout << "[APLIKASI ANTRIAN KLINIK]\n"
            << "\n[Cek Antrian]\n"
            << "Jumlah antrian : \n\n";
  if (queue::isEmpty(antrian))
  {
    info_message("Antrian kosong, belum ada pasien yang terdaftar");
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
    queue::traversal(antrian, [&count](Pasien p) {
      std::cout << std::setw(2) << std::setfill(' ') << std::left << count
                << "| "
                << std::setw(20) << std::setfill(' ') << std::left << p.nama
                << "| "
                << std::setw(30) << std::setfill(' ') << std::left << printStatus(p)
                << "| " << '\n';
      count++;
    });
    system("pause");
    system("cls");
  }
}

void menu_4()
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

    auto it = queue::findByNama(antrian, sNama);
    if (it)
    {
      int index = queue::checkIndex(antrian, it);
      std::cout << "//INFO\n"
                << "Pasien ditemukan dalam antrian.\n";
      std::cout << "Nama\t: " << it->data.nama << "\n"
                << "Status\t: " << printStatus(it->data) << "\n"
                << "Antrian ";
    }

  } while (flag != 0);
}

int menu_5()
{
  if (queue::isEmpty(antrian))
  {
    std::cout << "\nSelamat beristirahat...\n";
    system("pause");
    system("cls");
    return 5;
  }
  else
  {
    error_message(
        "Masih ada pasien dalam antrian.\nSelesaikan dulu antriannya!");
    return 0;
  }
}

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