#include "Parents.h"

void createListP(List_parent &L){

    first(L) = NULL;
}

void insertLastP(List_parent &L, address_parent P){

    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertFirstP(List_parent &L, address_parent P){

    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }

}

void insertAfterP(List_parent &L, address_parent Prec, address_parent P){

    next(P) = next(Prec);
    next(Prec) = P;
}


void deleteFirstP(List_parent &L, address_parent &P){

    if(first(L) != NULL){
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}
void deleteLastP(List_parent &L, address_parent &P){

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
void deleteAfterP(List_parent &L, address_parent Prec, address_parent &P){

    P = next(Prec);
    if(P == last(L)){
        deleteLastP(L, P);
    } else {
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

void alokasiP(address_parent &P, infotype_parent x){

    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;

}

void dealokasiP(address_parent &P){

}

address_parent findElmP(List_parent L, infotype_parent x){

    address_parent P = first(L);
    do {
        if(info(P) == x) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;

}
void printInfoP(List_parent L){

    address_parent P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<info(P)<<endl;
            P = next(P);
        } while((P) != NULL);
    }

}
