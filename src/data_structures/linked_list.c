#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "scoring.h"
#include "evaluasi.h"

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
