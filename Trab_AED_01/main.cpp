#include <iostream>
#include "menu.h"
#include "company.h"

int main() {
    Menu menu1;
    Company c1;
    switch (menu1.display()) {
        case 1:
            menu1.company_menu(menu1,c1);
        case 2:
            menu1.user_menu(menu1);
    }
}

