#include <stdlib.h>
#include "../algorithms/merge_sort.h"

// Membagi linked list jadi dua bagian
void splitList(Node* sumber, Node** depan, Node** belakang){
    if (sumber == NULL || sumber->next == NULL){
        *depan = sumber;
        *belakang = NULL;
        return;
    }

    Node* slow = sumber;
    Node* fast = sumber->next;

    while (fast != NULL){
        fast = fast->next;

        if (fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }

    *depan = sumber;
    *belakang = slow->next;
    slow->next = NULL;
}

// Menggabungkan dua linked list yang sudah terurut
Node* merge(Node* kiri, Node* kanan){
    if (kiri == NULL)
        return kanan;

    if (kanan == NULL)
        return kiri;

    Node* hasil = NULL;

    if (kiri->data.total_skor >= kanan->data.total_skor){
        hasil = kiri;
        hasil->next = merge(kiri->next, kanan);
    }
    else{
        hasil = kanan;
        hasil->next = merge(kiri, kanan->next);
    }

    return hasil;
}

// Mengurutkan linked list dengan merge sort
Node* mergeSort(Node* head){
    if (head == NULL || head->next == NULL)
        return head;

    Node* kiri;
    Node* kanan;

    splitList(head, &kiri, &kanan);

    kiri = mergeSort(kiri);
    kanan = mergeSort(kanan);

    return merge(kiri, kanan);
}