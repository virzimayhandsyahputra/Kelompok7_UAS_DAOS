#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

void init_pq(PriorityQueue *pq) {
    pq->head = NULL;
    pq->size = 0;
}

void pq_enqueue(PriorityQueue *pq, Node *node) {
    PQNode *pqn = (PQNode *)malloc(sizeof(PQNode));
    if (pqn == NULL) {
        printf("[PriorityQueue] Gagal mengalokasikan memori!\n");
        return;
    }
    pqn->node      = node;
    pqn->prioritas = node->data.total_skor;
    pqn->next      = NULL;

    // masukkan di posisi yang tepat agar tetap urut menurun
    if (pq->head == NULL || node->data.total_skor > pq->head->prioritas) {
        pqn->next = pq->head;
        pq->head  = pqn;
    } else {
        PQNode *cur = pq->head;
        while (cur->next != NULL && cur->next->prioritas >= node->data.total_skor)
            cur = cur->next;
        pqn->next = cur->next;
        cur->next = pqn;
    }
    pq->size++;
}

Node *pq_dequeue(PriorityQueue *pq) {
    if (pq->head == NULL) return NULL;

    PQNode *temp = pq->head;
    Node   *node = temp->node;
    pq->head     = pq->head->next;
    free(temp);
    pq->size--;
    return node;
}

int pq_kosong(PriorityQueue *pq) {
    return pq->head == NULL;
}