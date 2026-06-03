#ifndef WARGA_H
#define WARGA_H

//struct menyimpan informasi ekonomi warga
typedef struct {
    char nama[50];
    long penghasilan;
    char pekerjaan[50];
    int jumlah_tanggungan;
    char kondisi_rumah[100];
    int desil_bpjs_sekarang;

    //variabel tambahan untuk opsi 3
    int total_skor;
    int desil_sistem;
    char status[30]; // "Layak", "Perlu Verifikasi", "Tidak Layak"
} Warga;

//struct node untuk linked list
typedef struct Node {
    Warga data;
    struct Node* next;
} Node;

#endif