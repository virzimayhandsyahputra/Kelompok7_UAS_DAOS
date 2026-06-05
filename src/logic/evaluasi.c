#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evaluasi.h"

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