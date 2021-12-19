#include <iostream>
#include "menu.h"
#include "company.h"
#include "transport.h"

int main() {
    Menu menu1;
    Company c1;

    Local_of_Transport l1;
    switch (menu1.display()) {
        case 1:
            menu1.company_menu(menu1,c1);
        case 2:
            menu1.user_menu(menu1, l1);
    }
}

