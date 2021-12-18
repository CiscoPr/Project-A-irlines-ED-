#ifndef TRAB_AED_01_MENU_H
#define TRAB_AED_01_MENU_H
#include "company.h"
#include "flights.h"

using namespace std;



class Menu{
public:
    int display();
    void user_menu();
    void company_menu(Menu menu1, Company c1);
};

#endif
