#ifndef PARENTS_H_INCLUDED
#define PARENTS_H_INCLUDED
#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define last(L) L.last
#define info(P) P->info

// first last


typedef string infotype_parent;

typedef struct elmlist_parent *address_parent;

struct elmlist_parent {
    infotype_parent info;
    address_parent next;
};

struct List_parent {
    address_parent first;
    address_parent last;
};


void createList(List_parent &L);
void insertFirst(List_parent &L, address_parent P);
void insertAfter(List_parent &L, address_parent Prec, address_parent P);
void insertLast(List_parent &L, address_parent P);
void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P);

void alokasi(address_parent &P, infotype_parent x);
void dealokasi(address_parent &P);
address_parent findElm(List_parent L, infotype_parent x);
void printInfo(List_parent L);

#endif // PARENTS_H_INCLUDED
