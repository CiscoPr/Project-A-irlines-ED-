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
        case 3: {                                       //adiciona aviões
            string r;
            int c;
            cout << "Add a plane by typing its registration: ";
            cin >> r;

            cout << "\nand its capacity: ";
            cin >> c;
            c1.add_plane(r, c);

        }
        case 4:{                                        //remove aviões
            string r;
            int c;
            cout << "To remove a plane, insert its registration: ";
            cin >> r;
            c1.remove_plane(r);

        }

        case 5: {                                       //dá update aos aviões
            ofstream f;
            f.open("/Trab_AED_01/Trab_AED_01/planes.txt");
            if (!f.is_open()) {
                cout << "File not found";
                menu1.company_menu();
            }else {
                c1.update(f);
                f.close();
                cout << "\nPlanes updated successfully!";
            }
        }

    }
}


