#include "Relasi.h"

void createList(List_relasi &L){

    first(L) = NULL;
}
void insertFirst(List_relasi &L, address_relasi P){

}
void insertLast(List_relasi &L, address_relasi P){

}
void insertAfter(address_relasi Prec, address_relasi P){

}
void deleteFirst(List_relasi &L, address_relasi &P){

}
void deleteLast(List_relasi &L, address_relasi &P){

}
void deleteAfter(address_relasi Prec, address_relasi &P){

}

address_relasi alokasi( address_parent P, address_child C){

    address_relasi Q = new elmlist_relasi;
    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
    prev(Q) = NULL;
    return Q;
}
void dealokasi(address_relasi &P){

}
address_relasi findElm(List_relasi L, address_parent P, address_child C){

}
void printInfo(List_relasi L){

}
