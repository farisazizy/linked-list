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

address_relasi findElmR2(List_relasi L, address_child X){ //by content/info/review
    address_relasi curr = first(L);
    if (first(L) == NULL) {
        return NULL;
    } else {
        if (child(curr) == X) {
            return curr;
        }

        curr = next(curr);
        while ((curr != first(L)) && (child(curr) != X)){
            curr = next(curr);
        }
        if (curr != first(L)) {
            return curr;
        } else {
            return NULL;
        }
    }
}


address_relasi findElmR3(List_relasi L, address_parent X){ //by content/info/review
    address_relasi curr = first(L);
    if (first(L) == NULL) {
        return NULL;
    } else {
        if (parent(curr) == X) {
            return curr;
        }

        curr = next(curr);
        while ((curr != first(L)) && (parent(curr) != X)){
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
    int rq = 0;
    address_relasi curr = first(L);

    if (curr != NULL) {
        if (child(curr) == P) {
            rq = jumlah(P);
            cout<<endl<<"Film Title: "<<info(parent(curr))<<endl;
            cout<<"Review: "<<info(curr)<<endl<<endl;;
            i++;
        }
        curr = next(curr);
    }

    while (curr != first(L)) {
            if (child(curr) == P) {
                rq = jumlah(P);
                cout<<"Film Title: "<<info(parent(curr))<<endl;
                cout<<"Review: "<<info(curr)<<endl<<endl;
                i++;
            }
            curr = next(curr);
    }
    cout<<"Review Quantity: "<<rq<<endl;
    if (i == 0) {
        cout<<"Reviewer doesn't exist or no reviews yet."<<endl;
    }
}

void printByParent (List_relasi L, address_parent P) {
    int i = 0;
    int rq = 0;
    address_relasi curr = first(L);

    if (curr != NULL) {
        if (parent(curr) == P) {
            rq = jumlah(parent(curr));
            cout<<"Reviewer: "<<info(child(curr))<<endl;
            cout<<"Review: "<<info(curr)<<endl<<endl;
            i++;
        }
        curr = next(curr);
    }

    while (curr != first(L)) {
            if (parent(curr) == P) {
                rq = jumlah(parent(curr));
                cout<<"Reviewer: "<<info(child(curr))<<endl;
                cout<<"Review: "<<info(curr)<<endl<<endl;
                i++;
            }
            curr = next(curr);
    }
    cout<<"Review Quantity: "<<rq<<endl;
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

void viewMovie(List_parent LP, List_child LC, List_relasi LR) {
    temp tempA[100];
    address_parent curr = first(LP);
    int i = 0;
    while (curr != NULL) {
        tempA[i].info = info(curr);
        tempA[i].jumlah = jumlah(curr);
        curr = next(curr);
        i++;
    }

    // sudah ada array nya, tinggal disorting si array

    int j = 0;
    int k = 0;
    for (j = 0 ; j < 100 ; j++) {
        temp key = tempA[j];
        k = j - 1;
        while (k >= 0 && tempA[k].jumlah < key.jumlah) {
            tempA[k+1] = tempA[k];
            k = k-1;
        }
        tempA[k+1] = key;
    }

    address_parent P;

    for (int l = 0; l < 100; l++) {
        if (tempA[l].info != "") {
            P = findElmP(LP, tempA[l].info);
            if (tempA[l].jumlah != 0 ) {
                cout<<"Film Title : "<<tempA[l].info<<endl;
                printByParent(LR, P);
                cout<<endl;
            } else {
                cout<<tempA[l].info<<" has 0 review."<<endl;
            }

        }

    }

}







/*
- createList
- createNewElm
- Insert (first/ last/ after) sesuai requirement tugas besar
- printInfo*/
