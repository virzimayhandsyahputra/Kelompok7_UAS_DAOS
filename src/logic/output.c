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

void tampil_warga_urut(Node* head)
{
    if (head == NULL)
    {
        printf("Data warga kosong.\n");
        return;
    }

    printf("\nDAFTAR WARGA BERDASARKAN SKOR (TERTINGGI KE TERENDAH)\n");

    printf("============================================================\n");
    printf("%-4s %-20s %-10s %-20s\n",
           "No",
           "Nama",
           "Skor",
           "Status");
    printf("============================================================\n");

    int no = 1;
    Node* current = head;

    while (current != NULL)
    {
        printf("%-4d %-20s %-10d %-20s\n",
               no,
               current->data.nama,
               current->data.total_skor,
               current->data.status);

        current = current->next;
        no++;
    }

    printf("============================================================\n");
}