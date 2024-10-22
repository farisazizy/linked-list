#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void menu();
void menu_admin();
void menu_reviewer();
void admin(List_parent &LP, List_child &LC, List_relasi &LR);
void reviewer(List_parent &LP, List_child &LC, List_relasi &LR, address_child C);

#endif // CONTROLLER_H_INCLUDED
