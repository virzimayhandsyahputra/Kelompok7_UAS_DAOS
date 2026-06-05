#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

// Data structures
#include "data_structures/linked_list.h"
#include "data_structures/queue.h"
#include "data_structures/priority_queue.h"

// algoritma
#include "algorithms/linear_search.h"
#include "algorithms/merge_sort.h"
#include "algorithms/greedy.h"

// logic
#include "logic/scoring.h"
#include "logic/evaluasi.h"
#include "logic/output.h"

static void bersihkan_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static void baca_string(char *buf, int ukuran) {
    if (fgets(buf, ukuran, stdin) != NULL) {
        /* Hapus newline di akhir*/
        buf[strcspn(buf, "\n")] = '\0';
    }
}

// Untuk opsi 1
static void opsi_input_warga(Node **head) {
    Warga w;
    memset(&w, 0, sizeof(Warga));

    printf("\n======= INPUT DATA WARGA =======\n");

    printf("Nama                : ");
    baca_string(w.nama, sizeof(w.nama));

    printf("Pekerjaan\n");
    printf("  (1) Tidak Bekerja\n");
    printf("  (2) Petani / Nelayan\n");
    printf("  (3) Wiraswasta\n");
    printf("  (4) Pegawai Swasta\n");
    printf("  (5) PNS\n");
    printf("Pilihan pekerjaan   : ");
    int pil_pekerjaan;
    scanf("%d", &pil_pekerjaan);
    bersihkan_buffer();
    switch (pil_pekerjaan) {
        case 1: strncpy(w.pekerjaan, "Tidak Bekerja",  sizeof(w.pekerjaan)-1); break;
        case 2: strncpy(w.pekerjaan, "Petani/Nelayan", sizeof(w.pekerjaan)-1); break;
        case 3: strncpy(w.pekerjaan, "Wiraswasta",     sizeof(w.pekerjaan)-1); break;
        case 4: strncpy(w.pekerjaan, "Pegawai Swasta", sizeof(w.pekerjaan)-1); break;
        case 5: strncpy(w.pekerjaan, "PNS",            sizeof(w.pekerjaan)-1); break;
        default:
            printf("[!] Pilihan tidak valid, diset ke 'Tidak Bekerja'\n");
            strncpy(w.pekerjaan, "Tidak Bekerja", sizeof(w.pekerjaan)-1);
    }

    printf("Penghasilan / bulan : Rp ");
    scanf("%ld", &w.penghasilan);
    bersihkan_buffer();

    printf("Jumlah tanggungan   : ");
    scanf("%d", &w.jumlah_tanggungan);
    bersihkan_buffer();

    printf("Kondisi rumah\n");
    printf("  (1) Layak Huni\n");
    printf("  (2) Tidak Layak Huni\n");
    printf("Pilihan kondisi     : ");
    int pil_rumah;
    scanf("%d", &pil_rumah);
    bersihkan_buffer();
    if (pil_rumah == 2)
        strncpy(w.kondisi_rumah, "Tidak Layak Huni", sizeof(w.kondisi_rumah)-1);
    else
        strncpy(w.kondisi_rumah, "Layak Huni", sizeof(w.kondisi_rumah)-1);

    printf("Desil BPJS sekarang (1-10): ");
    scanf("%d", &w.desil_bpjs_sekarang);
    bersihkan_buffer();

    /* Konfirmasi sebelum simpan */
    printf("\n--- Konfirmasi Data ---\n");
    printf("Nama        : %s\n", w.nama);
    printf("Pekerjaan   : %s\n", w.pekerjaan);
    printf("Penghasilan : Rp%ld\n", w.penghasilan);
    printf("Tanggungan  : %d orang\n", w.jumlah_tanggungan);
    printf("Rumah       : %s\n", w.kondisi_rumah);
    printf("Desil BPJS  : %d\n", w.desil_bpjs_sekarang);
    printf("Simpan data? (y/n): ");

    char konfirmasi[5];
    baca_string(konfirmasi, sizeof(konfirmasi));

    if (konfirmasi[0] == 'y' || konfirmasi[0] == 'Y') {
        insert_warga(head, w);
        printf("[+] Data %s berhasil disimpan.\n", w.nama);
    } else {
        printf("[-] Data dibatalkan.\n");
    }
}

// Opsi 2
static void opsi_tampilkan_warga(Node *head) {
    if (head == NULL) {
        printf("\n[!] Belum ada data warga.\n");
        return;
    }

    printf("\n============================================================\n");
    printf("              DAFTAR SELURUH DATA WARGA\n");
    printf("============================================================\n");

    Node *cur = head;
    int no = 1;
    while (cur != NULL) {
        printf("\n[%d] ", no++);
        tampilkanWarga(cur);
        cur = cur->next;
    }
}

// Opsi 3
static void opsi_evaluasi(Node *head, PriorityQueue *pq, Queue *q_verif) {
    if (head == NULL) {
        printf("\n[!] Belum ada data warga untuk dievaluasi.\n");
        return;
    }

    // Reset PQ dan Queue sebelum proses ulang
    init_pq(pq);
    init_queue(q_verif);

    printf("\n[...] Menghitung skor dan mengevaluasi semua warga...\n");

    // masuk PQ atau Queue
    proses_semua_warga(head, q_verif, pq);

    printf("[+] Evaluasi selesai.\n");

    /* Tampilkan ringkasan hasil evaluasi */
    printf("\n============================================================\n");
    printf("                   HASIL EVALUASI\n");
    printf("============================================================\n");
    printf("%-4s %-20s %-6s %-7s %-18s\n",
           "No", "Nama", "Skor", "Desil", "Status");
    printf("------------------------------------------------------------\n");

    Node *cur = head;
    int no = 1;
    while (cur != NULL) {
        printf("%-4d %-20s %-6d %-7d %-18s\n", no++, cur->data.nama, cur->data.total_skor, cur->data.desil_sistem, cur->data.status);
        cur = cur->next;
    }
    printf("============================================================\n");

    tampil_queue_verifikasi(q_verif);

    // Jalankan greedy 
    printf("\nMasukkan kuota bantuan yang tersedia: ");
    int kuota;
    scanf("%d", &kuota);
    bersihkan_buffer();

    alokasi_bantuan(pq, kuota);
}

// Option 4
static void opsi_cari_warga(Node *head) {
    if (head == NULL) {
        printf("\n[!] Belum ada data warga.\n");
        return;
    }

    char nama_cari[100];
    printf("\nMasukkan nama warga yang dicari: ");
    baca_string(nama_cari, sizeof(nama_cari));

    Node *hasil = search_warga(head, nama_cari);
    tampilkanWarga(hasil);
}

// Option 5
static void opsi_urutkan(Node **head) {
    if (*head == NULL) {
        printf("\n[!] Belum ada data warga.\n");
        return;
    }

    // Cek apakah scoring sudah pernah dijalankan
    if ((*head)->data.total_skor == 0 && (*head)->data.desil_sistem == 0) {
        printf("\n[!] Jalankan Opsi 3 terlebih dahulu untuk menghitung skor.\n");
        return;
    }

    printf("\n[...] Mengurutkan data warga berdasarkan skor...\n");
    *head = mergeSort(*head);
    printf("[+] Pengurutan selesai.\n");

    tampil_warga_urut(*head);
}
