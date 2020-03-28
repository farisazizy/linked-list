#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent

// CDLL first
typedef string infotype_relasi;
typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    infotype_relasi info;
    address_relasi next;
    address_relasi prev;
    address_child child;
    address_parent parent;
};

struct List_relasi{
    address_relasi first;
};

void createList(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void deleteAfter(address_relasi Prec, address_relasi &P);

address_relasi alokasi( address_parent P, address_child C);
void dealokasi(address_relasi &P);
address_relasi findElm(List_relasi L, address_parent P, address_child C);
void printInfo(List_relasi L);

#endif // RELASI_H_INCLUDED
