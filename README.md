# Aplikasi Antrian Pasien dengan Command Line UI menggunakan bahasa C++

Anggota Kelompok:

- Ariq Hakim Ruswadi (140810200001)
- Alvaro Dwi Oktaviano (140810200041)
- Rafiansyah Rasyid Wikawang (140810200049)

---

## Latar Belakang



Antrian akan selalu terjadi apabila jumlah pelanggan lebih banyak dari yang bisa ditangani oleh instansi terkait. Jika terjadi kesalahan dalam manajemennya, bisa saja memberi dampak buruk bagi citra instansi tersebut, terlebih lagi bagi instansi yang bergerak di bidang pelayanan kesehatan, misalnya klinik kesehatan yang umumnya memiliki SDM yang terbatas.
Sistem antrian yang salah, selain dapat menurunkan citra karena ketidakpuasan pelanggan atas pelayanan yang diberikan, bisa juga berakibat fatal apabila kondisi yang darurat tidak diprioritaskan terlebih dulu.

Sistem antrian seperti ini bisa saja dipegang oleh seseorang jika skalanya kecil, namun ketika skalanya meningkat, resiko human-error pun bertambah. Itulah alasan perlunya sebuah sistem antrian yang didukung oleh komputer sehingga menurunkan potensi human-error yang bisa terjadi.

Sistem antrian sederhana yang berjalan di komputer sebetulnya dapat dibuat menggunakan command-line. Salah satu caranya adalah menggunakan bahasa pemrograman C++. Tetapi untuk membuat program yang lebih efisien dalam performa, dibutuhkan pemahaman mengenai topik struktur data untuk membangun program tersebut, terutama bahasan mengenai queue, stack, dan linked list.

Makalah ini dimaksudkan untuk membahas mengenai pembuatan aplikasi sistem antrian menggunakan topik struktur data dengan bahasan stack, queue, serta linked list.

---

## Tujuan dan Manfaat

Tujuan dari proposal ini adalah :
- Memberikan cara pembuatan aplikasi antrian dengan struktur data yang sesuai.
- Mengembangkan aplikasi antrian yang user-friendly serta ringan untuk digunakan.

Manfaat dari proposal ini adalah :
- Sebagai sarana eksplorasi topik struktur data dalam implementasinya untuk kasus nyata.
- Mengeluarkan output aplikasi yang dapat dipakai dalam use-case sistem antrian di klinik.

---

## Penjelasan Aplikasi

Aplikasi yang akan dirancang merupakan aplikasi sistem antrian sederhana yang akan dijalankan melalui command-line oleh operator menggunakan bahasa C++ dengan kapabilitas sebagai berikut :
- Menambah dan mengurangi antrian berdasarkan status pasien (prioritas)
- Menampilkan pasien yang sedang dilayani
- Menampilkan jumlah antrian yang ada.
- Menampilkan detail antrian.
- Mencari pasien dalam antrian
- Menghapus pasien dari antrian
- Mendaftarkan ulang pasien ke dalam antrian

---

## Gambar Rancangan Antar Muka

Link Desain Secara Lengkap : 
https://www.figma.com/file/3xFHwHpOHMRDg7fQSlDAIn/DatStruc

---

## Rencana Pengerjaan Projek

### Pembagian Tugas

Pembagian tugas dilakukan sebagai berikut :
File dikerjakan ada 2, yaitu :

- Main.cpp

    Berisi hal yang di output dan business logic dari program

    Pembagian dilakukan berdasarkan menu dengan rincian :

    - Ariq

        Arsitektur main.cpp, struktur menu, serta Tambah

    - Alvaro

        Cari antrian

    - Rasyid

        Panggil pasien serta Cek antrian

- Datstruc.cpp
	
    Berisi struktur data yang dipakai di dalam program
        
    Rincian pembagian :

    - Alvaro

        Arsitektur datstruc.cpp serta struktur data queue

    - Rasyid

        Struktur data stack

## Metode Pengerjaan

Arsitektur untuk menu utama dan struktur data dibuat terlebih dahulu karena merupakan bagian yang paling dasar. Setelah semua bagian dasar tersebut selesai dibuat, kemudian dilanjutkan dengan pengerjaan menu-menu program yang pembagiannya ada di poin 3.1

## Koordinasi

Koordinasi kami lakukan melalui 2 platform yaitu discord dan line. Discord digunakan untuk koordinasi secara langsung saat bekerja kelompok dan line digunakan untuk arsip link projek aplikasi dan kami menggunakan fitur line schedule sebagai reminder untuk tanggal-tanggal penting dalam projek ini.

Untuk pengerjaan source code digunakan github sebagai version control system (vcs). Pengerjaan dikerjakan di branch main. Berikut link github :
https://github.com/alvarodwi/project-datstruc


## Lisensi

MIT License 2021
