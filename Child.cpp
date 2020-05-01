#include "Parents.h"
#include "Relasi.h"
#include "Child.h"
#include "controller.h"

void createListC(List_child &L){

    first(L) = NULL;
}

void insertAscendingC(List_child &L, address_child P) {
    string X = info(P);
    if (first(L) == NULL) {
        insertFirstC(L, P);
    } else {
        if (X <= info(first(L))) {
            insertFirstC(L, P);
        } else if (X >= info(last(L))) {
            insertLastC(L, P);
        } else {
            address_child curr = first(L);
            while (info(next(curr)) <= X) {
                curr = next(curr);
            }
            insertAfterC(curr, P);
        }
    }
}

void insertFirstC(List_child &L, address_child P){

    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLastC(List_child &L, address_child P){

    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfterC(address_child Prec, address_child P){

    next(P) = next(Prec);
    next(Prec) = P;
}

void deleteFirstC(List_child &L, address_child &P){

    if(first(L) != NULL){
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLastC(List_child &L, address_child &P){

    address_child Q = first(L);
    if(first(L) != NULL){
        P = last(L);
        while(next(Q) != last(L)){
            Q = next(Q);
        }
        last(L) = Q;
        next(last(L)) = NULL;
    }
}

void deleteAfterC(List_child &L, address_child Prec, address_child &P){

    P = next(Prec);
    if(P == last(L)){
        deleteLastC(L, P);
    } else {
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

void deleteReviewer(List_child &L, address_child P) {


    if (P == first(L)) {
        deleteFirstC(L, P);
    } else if (P == last(L)) {
        deleteLastC(L, P);
    } else {
        address_child curr = first(L);
        while (next(curr) != P) {
            curr = next(curr);
        }
        deleteAfterC(L, curr, P);
    }
    dealokasiC(P);
}

void alokasiC(address_child &P, infotype_child x){

    P = new elmlist_child;
    info(P) = x;
    jumlah(P) = 0;
    next(P) = NULL;
}

void dealokasiC(address_child &P){
    //isi ya
}


address_child findElmC(List_child L, infotype_child x){

    address_child curr = first(L);
    while (curr != NULL && info(curr) != x) {
        curr = next(curr);
    }
    if (curr != NULL) {
        return curr;
    } else {
        return NULL;
    }

}

void printInfoC(List_child L){

    address_child P = first(L);
    int i = 1;
    if(first(L)!=NULL) {
        cout<< "Reviewer List: "<<endl;
        do {
            cout<<i<<". "<<info(P)<<endl;
            P = next(P);
            i++;
        } while((P) != NULL);
    }else {
        cout<<"Reviewer list is still empty."<<endl;
    }
    cout<<endl;
}

