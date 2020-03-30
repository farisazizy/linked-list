#include "Parents.h"
#include "Relasi.h"
#include "Child.h"


void createListR(List_relasi &L){

    first(L) = NULL;
}
void insertFirstR(List_relasi &L, address_relasi P){
    if (first(L) == NULL) {
        first(L) = P;
        next(P) = P;
        prev(P) = P;
    } else {
        address_relasi last = prev(first(L));
        address_relasi Q = first(L);
        first(L) = P;
        next(P) = Q;
        prev(P) = last;
        prev(Q) = P;
        if (prev(P) != NULL) {
            next(prev(P)) = P;
        }
    }
}
void insertLastR(List_relasi &L, address_relasi P){

}
void insertAfterR(address_relasi Prec, address_relasi P){

}
void deleteFirstR(List_relasi &L, address_relasi &P){

}
void deleteLastR(List_relasi &L, address_relasi &P){

}
void deleteAfterR(address_relasi Prec, address_relasi &P){

}

address_relasi alokasiR( address_parent P, address_child C, infotype_child X){

    address_relasi Q = new elmlist_relasi;
    child(Q) = C;
    parent(Q) = P;
    info(Q) = X;
    next(Q) = NULL;
    prev(Q) = NULL;
    return Q;
}
void dealokasiR(address_relasi &P){

}
address_relasi findElmR(List_relasi L, address_parent P, address_child C){
    return 0;
}
void printInfoR(List_relasi L){
    if (first(L) == NULL) {
        cout<<"List Kosong"<<endl;
        } else {
            cout<<endl;
            cout<<"Film Title: "<<info(parent(first(L)))<<endl;
            cout<<"Reviewer: "<<info(child(first(L)))<<endl;
            cout<<"Review: "<<info(first(L))<<endl;
            address_relasi curr = next(first(L));

            while (curr !=first(L)) {
                cout<<endl;
                cout<<"Film Title: "<<info(parent(curr))<<endl;
                cout<<"Reviewer: "<<info(child(curr))<<endl;
                cout<<"Review: "<<info(curr)<<endl;
                curr = next(curr);
            }
        cout<<endl;
    }
}
/*
- createList
- createNewElm
- Insert (first/ last/ after) sesuai requirement tugas besar
- printInfo*/
