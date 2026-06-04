#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evaluasi.h"

void init_queue(Queue* q) {
    q->front = NULL;
    q->rear  = NULL;
    q->size  = 0;
}

void enqueue(Queue* q, Node* node) {
    QueueNode* qn = (QueueNode*)malloc(sizeof(QueueNode));
    if (qn == NULL) return;
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

Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    Node*      node = temp->node;
    q->front        = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    q->size--;
    return node;
}

int queue_kosong(Queue* q) {
    return q->front == NULL;
}

void init_pq(PriorityQueue* pq) {
    pq->head = NULL;
    pq->size = 0;
}

void pq_enqueue(PriorityQueue* pq, Node* node) {
    PQNode* pqn = (PQNode*)malloc(sizeof(PQNode));
    if (pqn == NULL) return;
    pqn->node     = node;
    pqn->prioritas = node->data.total_skor;
    pqn->next     = NULL;

    if (pq->head == NULL || node->data.total_skor > pq->head->prioritas) {
        pqn->next = pq->head;
        pq->head  = pqn;
    } else {
        PQNode* cur = pq->head;
        while (cur->next != NULL && cur->next->prioritas >= node->data.total_skor)
            cur = cur->next;
        pqn->next = cur->next;
        cur->next = pqn;
    }
    pq->size++;
}

Node* pq_dequeue(PriorityQueue* pq) {
    if (pq->head == NULL) return NULL;
    PQNode* temp = pq->head;
    Node*   node = temp->node;
    pq->head     = pq->head->next;
    free(temp);
    pq->size--;
    return node;
}

int pq_kosong(PriorityQueue* pq) {
    return pq->head == NULL;
}

int bandingkan_desil(int desil_sistem) {
    return desil_sistem <= 4;
}

void tentukan_status(Warga* w) {
    if (w->total_skor >= 60)
        strncpy(w->status, "Layak", sizeof(w->status) - 1);
    else if (w->total_skor >= 40)
        strncpy(w->status, "Perlu Verifikasi", sizeof(w->status) - 1);
    else
        strncpy(w->status, "Tidak Layak", sizeof(w->status) - 1);
    w->status[sizeof(w->status) - 1] = '\0';
}

void evaluasi_warga(Node* node, Queue* q_verifikasi, PriorityQueue* pq_layak) {
    Warga* w = &node->data;

    if (!bandingkan_desil(w->desil_sistem)) {
        strncpy(w->status, "Perlu Verifikasi", sizeof(w->status) - 1);
        w->status[sizeof(w->status) - 1] = '\0';
        enqueue(q_verifikasi, node);
        return;
    }

    tentukan_status(w);

    if (strcmp(w->status, "Layak") == 0) {
        pq_enqueue(pq_layak, node);
    } else if (strcmp(w->status, "Perlu Verifikasi") == 0) {
        enqueue(q_verifikasi, node);
    }
}