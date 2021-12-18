#include <iostream>
#include "menu.h"
#include "company.h"

int main() {
    Menu menu1;
    Company c1;
    switch (menu1.display()) {
        case 1: {
            switch (menu1.company_menu()) {
                case 1: {
                    ifstream f;
                    f.open("/Trab_AED_01/Trab_AED_01/planes.txt");
                    if (!f.is_open()) {
                        cout << "File not found";
                        menu1.company_menu();

                    } else {
                        c1.set_planes(f);
                        f.close();
                        menu1.company_menu();
                    }
                }
                case 2:
                    c1.show_planes();
            }
        }
        case 2:
            break;
        case 3:
            break;
    }
}


