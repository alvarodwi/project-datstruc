#include "datstruc.cpp"
#include <iostream>

void menu_1 ();
void menu_2 ();
void menu_3 ();
void menu_4 ();
void menu_5 ();

int main() {
  int menu;
  do{
    std::cout << "[APLIKASI ANTRIAN KLINIK]\n";

    std::cout << "\nPasien yang dilayani  : -\n";
    /*
    ambil nilai stack
    if(stack kosong){
      std::cout << "-\n";
    } else {
      print pasien yg dilayani
    }
    */
    std::cout<<"Jumlah antrian             : \n\n";
    // hitung antrian falam pasien
    std::cout << "[MENU]\n\n"
              << "1. Tambah Pasien\n"
              << "2. Panggil Pasien\n"
              << "3. Cek Antrian\n"
              << "4. Cek Antrian\n"
              << "5. Exit\n"
              << "\nPilihan : ";
    std::cin >> menu;
    switch (menu)
    {
    case 1:
      // implementasi dari menu_1
      break;
      
    case 2:
      // implementasi dari menu_2
      break;

    case 3:
      // implementasi dari menu_3
      break;
    
    case 4:
      // implementasi dari menu_4
      break;

    case 5:
      // implementasi dari menu_5
      break;

    default:
      std::cout << "Pilihan tidak ada dalam menu\n";
      system("pause");
      system("cls");
      break;
    }
  } while (menu != 5);

  return 0;
}

void menu_1 (){
  //implementasikan
}

void menu_2 (){
  //implementasikan
}

void menu_3 (){
  //implementasikan
}

void menu_4 (){
  //implementasikan
}

void menu_5 (){
  //implementasikan
}