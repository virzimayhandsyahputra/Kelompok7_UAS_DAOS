#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "../warga.h"

void  init_pq(PriorityQueue *pq);
void  pq_enqueue(PriorityQueue *pq, Node *node);
Node *pq_dequeue(PriorityQueue *pq);
int   pq_kosong(PriorityQueue *pq);

#endif 
