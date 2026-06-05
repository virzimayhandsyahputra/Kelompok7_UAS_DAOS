#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void init_queue(Queue *q) {
    q->front = NULL;
    q->rear  = NULL;
    q->size  = 0;
}

void enqueue(Queue *q, Node *node) {
    QueueNode *qn = (QueueNode *)malloc(sizeof(QueueNode));
    if (qn == NULL) {
        printf("[Queue] Gagal mengalokasikan memori!\n");
        return;
    }
    qn->node = node;
    qn->next = NULL;

    if (q->rear == NULL) {
        q->front = qn;
        q->rear  = qn;
    } else {
        q->rear->next = qn;
        q->rear       = qn;
    }
    q->size++;
}

Node *dequeue(Queue *q) {
    if (q->front == NULL) return NULL;

    QueueNode *temp = q->front;
    Node      *node = temp->node;
    q->front        = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    q->size--;
    return node;
}

int queue_kosong(Queue *q) {
    return q->front == NULL;
}

void tampil_queue_verifikasi(Queue *q) {
    if (queue_kosong(q)) {
        printf("  (Tidak ada warga dalam antrian verifikasi)\n");
        return;
    }

    printf("\n============================================================\n");
    printf("         ANTRIAN VERIFIKASI  (%d warga)\n", q->size);
    printf("============================================================\n");
    printf("%-4s %-20s %-10s %-11s\n", "No", "Nama", "Skor", "Desil BPJS Sekarang");
    printf("------------------------------------------------------------\n");

    QueueNode *cur = q->front;
    int no = 1;
    while (cur != NULL) {
        printf("%-4d %-20s %-10d %-15d\n", no++, cur->node->data.nama, cur->node->data.total_skor, cur->node->data.desil_bpjs_sekarang);
        cur = cur->next;
    }
    printf("============================================================\n");
}
