#ifndef evaluasi_h
#define evaluasi_h

#include "../warga.h"
#include "../data_structures/queue.h"
#include "../data_structures/priority_queue.h"

int  bandingkan_desil(int desil_sistem);
void tentukan_status(Warga* w);
void evaluasi_warga(Node* node, Queue* q_verifikasi, PriorityQueue* pq_layak);

#endif