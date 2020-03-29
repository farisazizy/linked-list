#include "Parents.h"

void createList(List_parent &L){

    first(L) = NULL;
}
void insertFirst(List_parent &L, address_parent P){

    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }

}
void insertLast(List_parent &L, address_parent P){

    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfter(List_parent &L, address_parent Prec, address_parent P){

    next(P) = next(Prec);
    next(Prec) = P;
}

void deleteFirst(List_parent &L, address_parent &P){

    if(first(L) != NULL){
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}
void deleteLast(List_parent &L, address_parent &P){

    address_parent Q = first(L);
    if(first(L) != NULL){
        P = last(L);
        while(next(Q) != last(L)){
            Q = next(Q);
        }
        last(L) = Q;
        next(last(L)) = NULL;
    }
}
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P){

    P = next(Prec);
    if(P == last(L)){
        deleteLast(L, P);
    } else {
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

void alokasi(address_parent &P, infotype_parent x){

    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;

}

void dealokasi(address_parent &P){

}

address_parent findElm(List_parent L, infotype_parent x){

    address_parent P = first(L);
    do {
        if(info(P) == x) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;

}
void printInfo(List_parent L){

    address_parent P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<info(P)<<endl;
            P = next(P);
        } while((P) != NULL);
    }

}
