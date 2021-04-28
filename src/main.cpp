#include "datstruc.cpp"
#include <iostream>

int main() {
  int menu;
  do{
    std::cout << "[APLIKASI ANTRIAN KLINIK]\n";

    std::cout << "\nPasien yang dilayani : -\n\n";
    /*
    ambil nilai stack
    if(stack kosoong){
      std::cout << "-\n";
    } else {
      print pasien yg dilayani
    }
    */
    std::cout << "[MENU]\n\n"
              << "1. Tambah Pasien\n"
              << "2. Panggil Pasien\n"
              << "3. Cek Antrian\n"
              << "4. Exit\n"
              << "\nPilihan : ";
    std::cin >> menu;
    switch (menu)
    {
    case 1:
      // push pasien ke queue (input sendiri)
      break;
      
    case 2:
      /* 
      if(isEmpty(stack layanan)){
         std::cout << "Masih terdapat pasien dalam ruangan!\n"
      } else {
        pop pasien dari queue
        push ke stack layanan
      }
      */
      break;

    case 3:
      /* 
      if(isEmpty(queue)){
         std::cout << "Antrian Kosong!\n"
      } else {
        print queue
      }
      */
      break;
      
    case 4:
      //lanjut ke exit
      break;

    default:
      std::cout << "Invalid Input!\n";
      break;
    }
    std::cout << "\n\n";
  } while (menu != 4);

  return 0;
}