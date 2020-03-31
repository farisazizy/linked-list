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
            cout<<"3. Quit"<<endl;
            cout<<"Menu: ";
            cin>>pilmenu;
            if (pilmenu == 1) {
                string id, pass;
                cout<<endl;
                cout<<"Username: ";
                cin>>id;
                cout<<"Password: ";
                cin>>pass;
                if ((id == "admin") && (pass == "admin")) {
                    cout<<endl<<"Anda berhasil login sebagai admin.";
                    admin(LP,LC,LR);
                } else {
                    cout << "Username atau password salah.";
                }
            } else if (pilmenu == 2) {

            } else if (pilmenu == 3) {

            } else {
                cout<<"Tidak ada pilihan dalam menu."<<endl;
            }


        } else if (pilmenu == 2) {

        } else if (pilmenu == 3) {

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








    /*infotype_child c = "Aditya";
    infotype_parent p = "Hawaii Five-0";
    infotype_relasi r = "Police Procedural yang membuat penontonnya merasa seperti berada di dalam film.";

    alokasiC(C, c);
    alokasiP(P, p);
    R = alokasiR(P, C, r);

    insertLastP(LP, P);
    insertFirstR(LR, R);
    insertAscendingC(LC, C);

    c = "Farishadi";
    p = "Dora The Explorer";
    r = "Film yang tepat untuk dinikmati saat Work From Home.";

    alokasiC(C, c);
    alokasiP(P, p);
    R = alokasiR(P, C, r);

    insertLastP(LP, P);
    insertFirstR(LR, R);
    insertAscendingC(LC, C);



    c = "Irfan";
    p = "Barbie";
    r = "Saya merasa tenang menonton film ini.";

    alokasiC(C, c);
    alokasiP(P, p);
    R = alokasiR(P, C, r);

    insertLastP(LP, P);
    insertFirstR(LR, R);
    insertAscendingC(LC, C);

    printInfoR(LR);*/
}
