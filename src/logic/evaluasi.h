#ifndef evaluasi_h
#define evaluasi_h

#include "warga.h"

void  init_queue(Queue* q);
void  enqueue(Queue* q, Node* node);
Node* dequeue(Queue* q);
int   queue_kosong(Queue* q);

void  init_pq(PriorityQueue* pq);
void  pq_enqueue(PriorityQueue* pq, Node* node);
Node* pq_dequeue(PriorityQueue* pq);
int   pq_kosong(PriorityQueue* pq);

int  bandingkan_desil(int desil_sistem);
void tentukan_status(Warga* w);
void evaluasi_warga(Node* node, Queue* q_verifikasi, PriorityQueue* pq_layak);

#endif