#include <stdio.h>
#include <stdlib.h>

#include "warga.h"
#include "menu.h"
#include "data_structures/linked_list.h"
#include "data_structures/queue.h"
#include "data_structures/priority_queue.h"
#include "logic/evaluasi.h"

int main(void) {
    // Inisialisasi semua struktur data 
    Node         *head    = NULL;
    PriorityQueue pq;
    Queue         q_verif;

    init_pq(&pq);
    init_queue(&q_verif);

    // menu
    jalankan_menu(&head, &pq, &q_verif);

    // free linked list
    hapus_linked_list(head);

    return 0;
}