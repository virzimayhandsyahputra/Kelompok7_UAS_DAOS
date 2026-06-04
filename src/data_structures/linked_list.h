#ifndef linked_list_h
#define linked_list_h

#include "warga.h"

Node* tambah_node(Node* head, Warga data);
void  proses_semua_warga(Node* head, Queue* q_verifikasi, PriorityQueue* pq_layak);
void  hapus_linked_list(Node* head);

#endif 