#include <iostream>
#include <fstream>
#include "menu.h"
#include "company.h"

int main() {
    Menu menu1;
    Company c1;
    switch (menu1.display()) {
        case 1:
            menu1.company_menu();
        case 2:
            break;
        case 3:
            break;
    }
    switch (menu1.company_menu()) {
        case 1: {
            ifstream f;
            f.open("planes.txt");
            if (!f.is_open()) {
                cout << "File not found";
                menu1.company_menu();
            } else {
                c1.set_planes(f);
            }
        }
        case 2: {
            c1.show_planes();
        }
    }
}


