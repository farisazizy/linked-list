#include "Parents.h"
#include "Relasi.h"
#include "Child.h"
#include "controller.h"

void menu() {
    cout<<endl;
    cout<<"Menu: "<<endl;
    cout<<"1. Login "<<endl;
    cout<<"2. Sign Up Reviewer"<<endl;
    cout<<"3. View Only"<<endl;
    cout<<"4. Quit"<<endl;
    cout<<"Menu: ";
}

void menu_admin() {
    cout<<endl;
    cout<<"Menu Admin: "<<endl;
    cout<<"1. Insert film"<<endl;
    cout<<"2. View film"<<endl;
    cout<<"3. Update film "<<endl;
    cout<<"4. Delete film "<<endl;
    cout<<"5. View reviewer "<<endl;
    cout<<"6. Delete reviewer "<<endl;
    cout<<"7. View all review of specific film "<<endl;
    cout<<"8. View all review of specific reviewer. "<<endl;
    cout<<"9. Back"<<endl;
    cout<<"Menu: ";
}

void menu_reviewer() {
    cout<<endl;
    cout<<"Menu Reviewer: "<<endl;
    cout<<"1. Add review "<<endl;
    cout<<"2. Delete review "<<endl;
    cout<<"3. Show all of your review "<<endl;
    cout<<"4. Show not reviewed movie "<<endl;
    cout<<"5. Update review "<<endl;
    cout<<"6. Change Your username "<<endl;
    cout<<"7. Log out"<<endl;
    cout<<"Menu: ";
}

void admin(List_parent &LP, List_child &LC, List_relasi &LR) {
    int pilmenu;
    string input;

    menu_admin();
    cin>>pilmenu;
    cin.ignore();

    while (pilmenu < 1 || pilmenu > 9) {
        cout<<"\nMaaf, tidak ada pilihan dalam menu\n"<<endl;
        menu_admin();
        cin>>pilmenu;
        cin.ignore();
    }

    while (pilmenu != 9) {
        if (pilmenu == 1) { //insertfilm

            cout<<endl<<"Film Title to input: ";
            getline(cin, input);
            if (findElmP(LP, input) != NULL) {
                cout<<"Sorry, Film already exist."<<endl;
            } else {
                address_parent P;
                alokasiP(P, input);
                insertLastP(LP, P);
            }


        } else if (pilmenu == 2) { //viewfilm
            printInfoP(LP);

        } else if (pilmenu == 3) { //updatefilm
            cout<<endl<<"Film to update: ";
            getline(cin, input);
            address_parent P = findElmP(LP, input);
            if (P == NULL) {
                cout<<"Sorry, film doesn't exist."<<endl;
            } else {
                cout<<"Update the title: ";
                getline(cin, input);
                if (findElmP(LP, input) != NULL) {
                cout<<"Sorry, Film already exist."<<endl;
                } else {
                    info(P) = input;
                }
            }

        } else if (pilmenu == 4) { //deletefilm
            cout<<endl<<"Film to delete: ";
            getline(cin, input);
            address_parent P = findElmP(LP, input);
            if (P == NULL) {
                cout<<"Sorry, film doesn't exist."<<endl;
            } else {
                address_relasi Q = findElmR3(LR, P);
                while(Q != NULL){
                    jumlah(child(Q))--;
                    deleteReview(LR, Q);
                    Q = findElmR3(LR, P);
                }
                deleteFilm(LP, P);
                cout<<"Delete successful."<<endl;
            }

        } else if (pilmenu == 5) { //viewreviewer
            printInfoC(LC);
        } else if (pilmenu == 6) { //deletereviewer
            cout<<endl<<"Reviewer to delete: ";
            getline(cin, input);
            address_child P = findElmC(LC, input);
            if (P == NULL) {
                cout<<"Sorry, reviewer doesn't exist."<<endl;
            } else {
                address_relasi Q = findElmR2(LR, P);
                while(Q != NULL){
                    jumlah(parent(Q))--;
                    deleteReview(LR, Q);
                    Q = findElmR2(LR, P);
                }
                deleteReviewer(LC, P);
                cout<<"Delete successful."<<endl;
            }
        } else if (pilmenu == 7) { //view all review of specific film
            cout<<endl<<"Film Title: ";
            getline(cin, input);
            address_parent P = findElmP(LP, input);
            printByParent(LR, P);
        } else if (pilmenu == 8) { //view all review of specific reviewer
            cout<<endl<<"Reviewer Name: ";
            getline(cin, input);
            address_child C = findElmC(LC, input);
            printByChild(LR, C);
        } else {
            cout<<"Tidak ada pilihan dalam menu."<<endl;
        }
        input = "";
        pilmenu = 0;
        menu_admin();
        cin>>pilmenu;
        cin.ignore();
    }


}

void reviewer (List_parent &LP, List_child &LC, List_relasi &LR, address_child C) {
    int pilmenu;
    string input;

    menu_reviewer();
    cin>>pilmenu;
    cin.ignore();

    while (pilmenu < 1 || pilmenu > 7) {
        cout<<"\nMaaf, tidak ada pilihan dalam menu\n"<<endl;
        menu_reviewer();
        cin>>pilmenu;
        cin.ignore();
    }

    while (pilmenu != 7) {
        if (pilmenu == 1) { //addreview
            cout<<endl<<"Film Title to input the review: ";
            getline(cin, input);
            address_parent P = findElmP(LP, input);

            if (P != NULL){
                address_relasi check = findElmR(LR, P, C);
                if (check != NULL) {
                    cout<<"Sorry, You already gave a review."<<endl;
                } else {
                    string review;
                    cout<<endl<<"Input your review: ";
                    getline(cin, review);

                    jumlah(P)++;
                    jumlah(C)++;

                    address_relasi R = alokasiR(P, C, review);

                    insertFirstR(LR, R);
                }

            } else {
                cout<<"Sorry, film doesn't exist."<<endl;
            }

        } else if (pilmenu == 2) { //deletereview

            cout<<endl<<"Review's film title to delete: ";
            getline(cin, input);
            address_parent P = findElmP(LP, input);

            if (P == NULL) {
                cout<<"Sorry, film doesn't exist."<<endl;
            } else {
                address_relasi R = findElmR(LR, P, C);
                if (R == NULL) {
                    cout<<"Sorry, you don't have any review for this film."<<endl;
                } else {
                    deleteReview(LR, R);
                    jumlah(C)--;
                    jumlah(P)--;
                    cout<<"Delete successful."<<endl;
                }

            }

        } else if (pilmenu == 3) { //showallofmyreview
            printByChild (LR, C);
        } else if (pilmenu == 4) { //shownotreviewed
            showNotReviewed(LP, LR, C);
        } else if (pilmenu == 5) { //updatereview
            cout<<endl<<"Reviewed film title you want to update: ";
            getline(cin, input);
            address_parent P = findElmP(LP, input);

            if (P == NULL) {
                cout<<"Sorry, film doesn't exist."<<endl;
            } else {
                address_relasi R = findElmR(LR, P, C);
                if (R == NULL) {
                    cout<<"Sorry, you don't have any review for this film."<<endl;
                } else {
                    string review;
                    cout<<endl<<"Input your new review: ";
                    getline(cin, review);
                    info(R) = review;
                    cout<<"Review updated."<<endl;
                }
            }
        } else if(pilmenu == 6){ //update username
            string newname;
            cout<<"Current username: "<<info(C)<<endl;
            cout<<"New username: ";
            getline(cin, newname);
            cout<<endl;
            if (findElmC(LC, input) != NULL) {
                cout<<"Sorry, this username already exist."<<endl;
            } else {
                info(C) = newname;
                cout<<"Username changed!"<<endl;
            }

        } else {
            cout<<"Tidak ada pilihan dalam menu."<<endl;
        }
        input = "";
        pilmenu = 0;
        menu_reviewer();
        cin>>pilmenu;
        cin.ignore();
    }



}
