#include "menu.hpp"

void menu_2(queue::Queue &q, stack::Stack &s)
{
    if (queue::isEmpty(q))
    {
        error_message("Antrian kosong, belum ada pasien yang terdaftar");
    }
    else
    {
        pNode panggil = queue::pop(q);
        stack::push(s, panggil);
        info_message("Memanggil pasien dengan nama " + panggil->data.nama +
                     "\nUpdate antrian...");
    }
}