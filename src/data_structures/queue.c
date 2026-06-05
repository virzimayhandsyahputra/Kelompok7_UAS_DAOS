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
