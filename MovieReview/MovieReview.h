#ifndef MOVIEREVIEW_H_INCLUDED
#define MOVIEREVIEW_H_INCLUDED
#define <iostream>

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;

typedef struct elmP1 *adrP1;
typedef struct elmP2 *adrP2;
typedef struct elmR *adrR;

struct elmP1 {
    string judul;
    adrP1 next;
};

struct ListP1 {
    adrP1 first, last;
};

struct elmP2 {
    string nama;
    adrP2 next;
};

struct ListP1 {
    adrP2 first, last;
};

struct elmR {
    adrP1 film;
    adrP2 nama;
    string ulasan;
    adrR next;
};

struct ListR{
    adrR first;
};
/*
- createList
- createNewElm
- Insert (first/ last/ after) sesuai requirement tugas besar
- printInfo
*/

void createListP1 (ListP1 &L);
void createNewElmP1 (ListP1 &L);
void insertLastP1 (ListP1 &L, adrP1 P);
void printInfoP1 (ListP1 L);

void createListP2 (ListP1 &L);
void createNewElmP2 (ListP1 &L);
void insertAscP2 (ListP1 &L, adrP1 P);
void printInfoP2 (ListP1 L);

void createListR (ListR &L);
void createNewElmR (ListR &L);
void insertR (ListR &L, adrP1 judul, adrP2);
void printInfoR (ListR L);

#endif // MOVIEREVIEW_H_INCLUDED
