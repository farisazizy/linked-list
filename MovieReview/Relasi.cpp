#include "Parents.h"
#include "Relasi.h"
#include "Child.h"
#include "controller.h"


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
    if (next(first(L)) != first(L)) {
        P = first(L);
        address_relasi last = prev(first(L));
        next(last) = next(P);
        prev(next(P)) = last;
        prev(P) = NULL;
        first(L) = next(P);
        next(P) = NULL;
    } else {
        next(P) = NULL;
        prev(P) = NULL;
        first(L) = NULL;
    }
}

void deleteLastR(List_relasi &L, address_relasi &P){
    address_relasi last = prev(first(L));
    prev(first(L)) = prev(last);
    next(prev(last)) = first(L);
    prev(last) = NULL;
    next(last) = NULL;
}

void deleteAfterR(address_relasi Prec, address_relasi &P){
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
}

void deleteReview(List_relasi &L, address_relasi P) {
    if (P == first(L)) {
            deleteFirstR(L, P);
        } else if (P == prev(first(L))) {
            deleteLastR(L, P);
        } else {
            address_relasi curr = first(L);
            while (next(curr) != P) {
                curr = next(curr);
            }

            deleteAfterR(curr, P);
    }
    dealokasiR(P);
}

address_relasi alokasiR( address_parent P, address_child C, infotype_child X){

    address_relasi Q = new elmlist_relasi;
    Q -> child = C;
    parent(Q) = P;
    info(Q) = X;
    next(Q) = NULL;
    prev(Q) = NULL;
    return Q;
}
void dealokasiR(address_relasi &P){

}
address_relasi findElmR(List_relasi L, address_parent P, address_child C){ //by parent & child
    address_relasi curr = first(L);
    if (first(L) == NULL) {
        return NULL;
    } else {
        if ((parent(curr) == P) && (child(curr) == C)) {
            return curr;
        }

        curr = next(curr);
        while ((curr != first(L)) && (parent(curr) != P || child(curr) != C)) {
            curr = next(curr);
        }
        if (curr != first(L)) {
            return curr;
        } else {
            return NULL;
        }
    }
}

address_relasi findElmR2(List_relasi L, infotype_child X){ //by content/info/review
    address_relasi curr = first(L);
    if (first(L) == NULL) {
        return NULL;
    } else {
        if (info(curr) == X) {
            return curr;
        }

        curr = next(curr);
        while ((curr != first(L)) && (info(curr) != X)) {
            curr = next(curr);
        }
        if (curr != first(L)) {
            return curr;
        } else {
            return NULL;
        }
    }
}

void printInfoR(List_relasi L){
    if (first(L) == NULL) {
        cout<<"Review list is still empty."<<endl;
        } else {
            cout<<endl;
            cout<< "Review List: "<<endl<<endl;
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


void printByChild (List_relasi L, address_child P) {
    int i = 0;
    address_relasi curr = first(L);

    if (curr != NULL) {
        if (child(curr) == P) {
            cout<<"Film Title: "<<info(parent(curr))<<endl;
            cout<<"Reviewer: "<<info(child(curr))<<endl;
            cout<<"Review: "<<info(curr)<<endl<<endl;;
            i++;
        }
        curr = next(curr);
    }

    while (curr != first(L)) {
            if (child(curr) == P) {
                cout<<"Film Title: "<<info(parent(curr))<<endl;
                cout<<"Reviewer: "<<info(child(curr))<<endl;
                cout<<"Review: "<<info(curr)<<endl<<endl;
                i++;
            }
            curr = next(curr);
    }
    if (i == 0) {
        cout<<"No reviews yet."<<endl;
    }
}

void printByParent (List_relasi L, address_parent P) {
    int i = 0;
    address_relasi curr = first(L);

    if (curr != NULL) {
        if (parent(curr) == P) {
            cout<<"Film Title: "<<info(parent(curr))<<endl;
            cout<<"Reviewer: "<<info(child(curr))<<endl;
            cout<<"Review: "<<info(curr)<<endl<<endl;
            i++;
        }
        curr = next(curr);
    }

    while (curr != first(L)) {
            if (parent(curr) == P) {
                cout<<"Film Title: "<<info(parent(curr))<<endl;
                cout<<"Reviewer: "<<info(child(curr))<<endl;
                cout<<"Review: "<<info(curr)<<endl<<endl;
                i++;
            }
            curr = next(curr);
    }
    if (i == 0) {
        cout<<"Film doesn't exist or no reviews yet."<<endl;
    }
}

void showNotReviewed(List_parent LP, List_relasi LR, address_child C) {
    address_relasi currR;
    address_parent currP = first(LP);
    int i = 0;
    while (currP != NULL) {
        if (findElmR(LR, currP, C) == NULL) {
            cout<<i+1<<". "<<info(currP)<<endl;
            i++;
        }
        currP = next(currP);
    }

    if (i == 0) {
        cout<<"There's no film or you already gave reviews to all films."<<endl;
    }

}


/*
- createList
- createNewElm
- Insert (first/ last/ after) sesuai requirement tugas besar
- printInfo*/
