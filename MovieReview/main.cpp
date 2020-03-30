#include "iostream"
#include "Parents.h"
#include "Relasi.h"
#include "Child.h"

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

    infotype_child c = "Aditya";
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

    printInfoR(LR);
}
