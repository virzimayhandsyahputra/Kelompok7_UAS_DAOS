#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "scoring.h"
#include "evaluasi.h"

void insert_warga(Node** head, Warga data_baru) {
    // alokasi memori untuk node baru
    Node* node_baru = (Node*)malloc(sizeof(Node));
    if (node_baru == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        return;
    }
    
    //salinn data ke dalam node baru
    node_baru->data = data_baru;
    node_baru->next = NULL;

    if (*head == NULL) {
        *head = node_baru;
        return;
    }

    //cari node terakhir
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    //menyambungkan node baru di akhir
    temp->next = node_baru;
}

void proses_semua_warga(Node* head, Queue* q_verifikasi, PriorityQueue* pq_layak) {
    if (head == NULL) {
        printf("[LinkedList] Data warga kosong.\n");
        return;
    }

    Node* cur = head;
    while (cur != NULL) {
        hitung_skor(&cur->data);
        cur->data.desil_sistem = konversi_ke_desil(cur->data.total_skor);
        evaluasi_warga(cur, q_verifikasi, pq_layak);
        cur = cur->next;
    }
}

Node* tambah_node(Node* head, Warga data) {
    Node* baru = (Node*)malloc(sizeof(Node));
    if (baru == NULL) return head;

    baru->data = data;
    baru->next = NULL;

    if (head == NULL) return baru;

    Node* cur = head;
    while (cur->next != NULL) cur = cur->next;
    cur->next = baru;
    return head;
}

void hapus_linked_list(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}
