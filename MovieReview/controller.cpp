#include "Parents.h"
#include "Relasi.h"
#include "Child.h"
#include "controller.h"

void menu() {
    cout<<endl;
    cout<<"Menu: "<<endl;
    cout<<"1. Login "<<endl;
    cout<<"2. Sign Up"<<endl;
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
    cout<<"5. Update reviewer's data "<<endl;
    cout<<"6. Back"<<endl;
    cout<<"Menu: ";
}

void admin(List_parent &LP, List_child &LC, List_relasi &LR) {
    int pilmenu;
    string input;

    menu_admin();
    cin>>pilmenu;

    while (pilmenu < 1 || pilmenu > 9) {
        cout<<"\nMaaf, tidak ada pilihan dalam menu\n"<<endl;
        menu_admin();
        cin>>pilmenu;
    }

    while (pilmenu != 9) {
        if (pilmenu == 1) { //insertfilm

            cout<<endl<<"Film Title to input: ";
            cin>>input;
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
            cin>>input;
            address_parent P = findElmP(LP, input);
            if (P == NULL) {
                cout<<"Sorry, film doesn't exist."<<endl;
            } else {
                cout<<"Update the title: ";
                cin>>input;
                if (findElmP(LP, input) != NULL) {
                cout<<"Sorry, Film already exist."<<endl;
                } else {
                    info(P) = input;
                }
            }

        } else if (pilmenu == 4) { //deletefilm
            cout<<endl<<"Film to delete: ";
            cin>>input;
            address_parent P = findElmP(LP, input);
            if (P == NULL) {
                cout<<"Sorry, film doesn't exist."<<endl;
            } else {
                deleteFilm(LP, P);
                cout<<"Delete successful."<<endl;
            }

        } else if (pilmenu == 5) { //viewreviewer

        } else if (pilmenu == 6) { //deletereviewer

        } else if (pilmenu == 7) { //view all review of specific film

        } else if (pilmenu == 8) { //view all review of specific reviewer

        } else {
            cout<<"Tidak ada pilihan dalam menu."<<endl;
        }
        input = "";
        pilmenu = 0;
        menu_admin();
        cin>>pilmenu;
    }


}

void reviewer (List_parent &LP, List_child &LC, List_relasi &LR, address_child P) {
    int pilmenu;
    string input;

    menu_reviewer();
    cin>>pilmenu;

    while (pilmenu < 1 || pilmenu > 6) {
        cout<<"\nMaaf, tidak ada pilihan dalam menu\n"<<endl;
        menu_reviewer();
        cin>>pilmenu;
    }

    while (pilmenu != 6) {
        if (pilmenu == 1) { //addreview
            
        } else if (pilmenu == 2) { //deletereview

        } else if (pilmenu == 3) { //showallofmyreview

        } else if (pilmenu == 4) { //shownotreviewed

        } else if (pilmenu == 5) { //updatereview

        }  else {
            cout<<"Tidak ada pilihan dalam menu."<<endl;
        }
        input = "";
        pilmenu = 0;
        menu_reviewer();
        cin>>pilmenu;
    }



}
