#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "warga.h"

Node* mergeSort(Node* head);
Node* merge(Node* kiri, Node* kanan);
void splitList(Node* sumber, Node** depan, Node** belakang);

#endif