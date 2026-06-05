#ifndef QUEUE_H
#define QUEUE_H

#include "../warga.h"

void  init_queue(Queue *q);
void  enqueue(Queue *q, Node *node);
Node *dequeue(Queue *q);
int   queue_kosong(Queue *q);
void  tampil_queue_verifikasi(Queue *q);

#endif 