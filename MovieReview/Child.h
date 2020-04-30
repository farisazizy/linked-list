#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define jumlah(P) P->jumlah



typedef string infotype_child;

typedef struct elmlist_child *address_child;

struct elmlist_child{
    infotype_child info;
    int jumlah;
    address_child next;
};

struct List_child{
    address_child first;
    address_child last;
};

void createListC(List_child &L);
void insertAscendingC(List_child &L, address_child P);
void insertFirstC(List_child &L, address_child P);
void insertLastC(List_child &L, address_child P);
void insertAfterC(address_child Prec, address_child P);
void deleteFirstC(List_child &L, address_child &P);
void deleteLastC(List_child &L, address_child &P);
void deleteAfterC(List_child &L, address_child Prec, address_child &P);
void deleteReviewer(List_child &L, address_child P);

void alokasiC(address_child &P, infotype_child x);
void dealokasiC(address_child &P);
address_child findElmC(List_child L, infotype_child x);
void printInfoC(List_child L);

#endif // CHILD_H_INCLUDED
