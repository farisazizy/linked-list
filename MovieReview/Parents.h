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


void createListP(List_parent &L);
void insertFirstP(List_parent &L, address_parent P);
void insertAfterP(List_parent &L, address_parent Prec, address_parent P);
void insertLastP(List_parent &L, address_parent P);
void deleteFirstP(List_parent &L, address_parent &P);
void deleteLastP(List_parent &L, address_parent &P);
void deleteAfterP(List_parent &L, address_parent Prec, address_parent &P);
void deleteFilm(List_parent &L, address_parent P);

void alokasiP(address_parent &P, infotype_parent x);
void dealokasiP(address_parent &P);
address_parent findElmP(List_parent L, infotype_parent x);
void printInfoP(List_parent L);

#endif // PARENTS_H_INCLUDED
