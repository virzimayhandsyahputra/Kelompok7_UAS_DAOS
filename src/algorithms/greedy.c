#include <stdio.h>
#include "../algorithms/greedy.h"
#include "../logic/evaluasi.h"

void alokasi_bantuan(PriorityQueue *pq, int kuota) {
    if (pq_kosong(pq)) {
        printf("\n[Greedy] Tidak ada warga layak dalam antrian.\n");
        return;
    }

    if (kuota <= 0) {
        printf("\n[Greedy] Kuota tidak valid.\n");
        return;
    }

    printf("\n============================================================\n");
    printf("     HASIL ALOKASI BANTUAN  (Kuota: %d orang)\n", kuota);
    printf("============================================================\n");
    printf("%-4s %-20s %-10s %-12s\n", "No", "Nama", "Skor", "Desil Sistem");
    printf("------------------------------------------------------------\n");

    int dialokasikan = 0;

    // ambil dari head (skor tertinggi) sampai kuota habis
    while (!pq_kosong(pq) && dialokasikan < kuota) {
        Node *warga = pq_dequeue(pq);
        dialokasikan++;
        printf("%-4d %-20s %-10d %-12d\n",
               dialokasikan,
               warga->data.nama,
               warga->data.total_skor,
               warga->data.desil_sistem);
    }

    printf("============================================================\n");
    printf("Total dialokasikan : %d warga\n", dialokasikan);

    if (!pq_kosong(pq)) {
        printf("Sisa antrian layak : %d warga (kuota penuh)\n", pq->size);
    }
    printf("============================================================\n");
}
