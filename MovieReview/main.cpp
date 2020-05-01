#include "iostream"
#include "Parents.h"
#include "Relasi.h"
#include "Child.h"
#include "controller.h"

using namespace std;

int main()
{
    cout << "Bentuk III - Movie Review" << endl;

    List_parent LP;
    List_child LC;
    List_relasi LR;
    address_child C;
    address_parent P;
    address_relasi R;

    createListP(LP);
    createListC(LC);
    createListR(LR);

    int pilmenu = 0;
    string ans;

    menu();
    cin>>pilmenu;

    while (pilmenu < 1 || pilmenu > 4) {
        cout<<"\nMaaf, tidak ada pilihan dalam menu\n"<<endl;
        menu();
        cin>>pilmenu;
    }

    while (pilmenu != 4) {
        if (pilmenu == 1) { // Login
            cout<<endl<<"Menu: "<<endl;
            cout<<"1. Login Admin"<<endl;
            cout<<"2. Login Reviewer"<<endl;
            cout<<"3. Back"<<endl;
            cout<<"Menu: ";
            cin>>pilmenu;
            if (pilmenu == 1) {
                string id, pass;
                cout<<endl;
                cout<<"Username: ";
                cin.get();
                getline(cin, id);
                cout<<"Password: ";
                getline(cin, pass);
                if ((id == "admin") && (pass == "admin")) {
                    cout<<endl<<"You have logged in as admin.";
                    admin(LP,LC,LR);
                } else {
                    cout << "Username or Password is wrong.";
                }
            } else if (pilmenu == 2) {
                string id;
                cout<<endl;
                cout<<"Reviewer Name: ";
                cin.get();
                getline(cin, id);
                C = findElmC(LC, id);
                if (C == NULL) {
                    cout<<"You name isn't registered. Please sign up first."<<endl;
                } else {
                    cout<<"You have logged in as "<<info(C)<<endl;
                    reviewer(LP, LC, LR, C);
                }
            } else if (pilmenu == 3) {

            } else {
                cout<<"Tidak ada pilihan dalam menu."<<endl;
            }


        } else if (pilmenu == 2) {

            string input;
            cout<<endl<<"Insert your name: ";
            cin.get();
            getline(cin, input);
            if (findElmC(LC, input) != NULL) {
                cout<<"Sorry, your account already exist."<<endl;
            } else {
                address_child C;
                alokasiC(C, input);
                insertAscendingC(LC, C);
            }

        } else if (pilmenu == 3) { // harus diubah, ini hanya untuk test
            viewMovie(LP,LC,LR);
        }

        cout<<endl<<"Quit from the Application?(Y/N): ";
        cin>>ans;
        if (ans == "Y" || ans == "y") {
            pilmenu = 4;
        } else {
            menu();
            pilmenu = 0;
            cin>>pilmenu;
            while (pilmenu < 1 || pilmenu > 4) {
                cout<<"\nMaaf, tidak ada pilihan dalam menu\n"<<endl;
                menu();
                cin>>pilmenu;
            }
        }


    }

}
