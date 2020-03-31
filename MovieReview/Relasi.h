#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "Parents.h"
#include "Child.h"

using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define info(P) P->info
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

void createListR(List_relasi &L);
void insertFirstR(List_relasi &L, address_relasi P);
void insertLastR(List_relasi &L, address_relasi P);
void insertAfterR(address_relasi Prec, address_relasi P);
void deleteFirstR(List_relasi &L, address_relasi &P);
void deleteLastR(List_relasi &L, address_relasi &P);
void deleteAfterR(address_relasi Prec, address_relasi &P);
void deleteReview(List_relasi &L, address_relasi P);


address_relasi alokasiR( address_parent P, address_child C, infotype_child X);
void dealokasiR(address_relasi &P);
address_relasi findElmR(List_relasi L, address_parent P, address_child C);
//address_relasi findElmR2(List_relasi L, infotype_child X);
void printInfoR(List_relasi L);
void printByChild (List_relasi L, address_child P);
void printByParent (List_relasi L, address_parent P);

#endif // RELASI_H_INCLUDED
