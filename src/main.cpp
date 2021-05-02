#include "datstruc.cpp"
#include <iostream>

void menu_1 ();
void menu_2 ();
void menu_3 ();
void menu_4 ();
void menu_5 ();
void error_message(std::string s);

int main() {
  int menu;
  do{
    std::cout << "[APLIKASI ANTRIAN KLINIK]\n" 
              << "\nPasien yang dilayani  : -\n";
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
              << "\nPilihan > ";
    std::cin >> menu;
    switch (menu)
    {
    case 1:
      menu_1();
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
      error_message("Pilihan tidak ada dalam menu");
      break;
    }
  } while (menu != 5);

  return 0;
}

void menu_1 (){
  system("pause");
  system("cls");
  int status; // hanya untuk testing, nanti digunakan status dari queue nya
  do{
    std::cout << "[APLIKASI ANTRIAN KLINIK]\n"
              << "\n[Tambah Pasien]\n";

    std::cout << "\n//INFO\n"
              << "Pengelompokkan status pasien :\n"
              << "1. Gawat Darurat (eg. kecelakaan)\n"
              << "2. Darurat Tidak Gawat (eg. luka bakar, demam tinggi)\n"
              << "3. Tidak Darurat Tiadk Gawat (wg. batuk/pilek, luka ringan)\n";
    
    std::cout<<"\n[Input]\n"
            <<"Status > "; 
    std::cin >> status; // testing input status pasien
    
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

  std::cout << "Nama > \n\n"; //input nama

  /*
  if(input nama == nama pasien lain){
    error_message("Nama pasien harus berbeda, gunakan nama lain untuk menambahkan kedalam antrian.");
  } else {
    system("pause");
    system("cls");
  }
  */
  system("pause");
  system("cls");
  refresh1:
  std::cout << '\n';
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

void error_message(std::string s){
  std::cout << "//ERROR\n"; 
  std::cout << s << '\n';
  system("pause");
  system("cls");
}