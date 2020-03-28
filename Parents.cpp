#include "Parents.h"

void createList(List_parent &L){

    first(L) = NULL;
}
void insertFirst(List_parent &L, address_parent P){

    address_parent Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }

}
void insertAfter(List_parent &L, address_parent Prec, address_parent P){

}
void insertLast(List_parent &L, address_parent P){

}
void deleteFirst(List_parent &L, address_parent &P){

}
void deleteLast(List_parent &L, address_parent &P){

}
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P){

}

address_parent alokasi(infotype_parent x){

    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    return P;

}
void dealokasi(address_parent &P){

}
address_parent findElm(List_parent L, infotype_parent x){

}
void printInfo(List_parent L){

}
