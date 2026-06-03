#include <string.h>
#include "linear_search.h"

// Melakukan pencarian nama pada linked list
Node* search_warga(Node *head, const char *nama) {
    Node *current = head;

    // Menelusuri node satu per satu
    while (current != NULL) {
        // Jika nama ditemukan
        if (stricmp(current->data.nama, nama) == 0) {
            return current;
        }
        current = current->next;
    }
    // Nama tidak ditemukan
    return NULL;
}
