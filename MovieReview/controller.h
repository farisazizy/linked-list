#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include <iostream>

using namespace std;

void menu();
void menu_admin();
void menu_reviewer();
void admin(List_parent &LP, List_child &LC, List_relasi &LR);
void reviewer(List_parent &LP, List_child &LC, List_relasi &LR, address_child P);

#endif // CONTROLLER_H_INCLUDED
