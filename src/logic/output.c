#include <stdio.h>
#include "output.h"

// Menampilkan data warga yang ditemukan
void tampilkanWarga(Node *w)
{
    if (w == NULL)
    {
        printf("\nData warga tidak ditemukan.\n");
        return;
    }

    printf("\n======= DATA WARGA =======\n");
    printf("Nama                : %s\n", w->data.nama);
    printf("Pekerjaan           : %s\n", w->data.pekerjaan);
    printf("Penghasilan         : Rp%ld\n", w->data.penghasilan); 
    printf("Jumlah Tanggungan   : %d\n", w->data.jumlah_tanggungan);
    printf("Kondisi Rumah       : %s\n", w->data.kondisi_rumah);
    printf("Desil BPJS Sekarang : %d\n", w->data.desil_bpjs_sekarang);
    printf("Total Skor          : %d\n", w->data.total_skor);
    printf("Desil Sistem        : %d\n", w->data.desil_sistem);
    printf("Status              : %s\n", w->data.status);
}
