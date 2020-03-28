#include "Child.h"

void createList(List_child &L){

    first(L) = NULL;
}
void insertFirst(List_child &L, address_child P){

    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLast(List_child &L, address_child P){

    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfter(address_child Prec, address_child P){

    next(P) = next(Prec);
    next(Prec) = P;
}

void deleteFirst(List_child &L, address_child &P){

    if(first(L) != NULL){
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLast(List_child &L, address_child &P){

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

void deleteAfter(address_child Prec, address_child &P){

    P = next(Prec);
    if(P == last(L)){
        deleteLast(L, P);
    } else {
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

address_child alokasi(infotype_child x){

    address_child P;
    P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void dealokasi(address_child &P){

}

address_child findElm(List_child L, infotype_child x){

    address_child P = first(L);
    do {
        if(info(P) == x) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}

void printInfo(List_child L){

    address_child P = first(L);
    while(P !=NULL) {
        cout<<" "<<info(P);
        P = next(P);
    }

    cout<<endl;
}

