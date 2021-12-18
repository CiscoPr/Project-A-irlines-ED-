#include "menu.h"
#include <thread>
#include <iostream>
using namespace std;
using namespace chrono;
int Menu::display() {
    int choice;
    char ch = ' ';

    cout << "                   -------------------------------------------------------------------------\n";
    cout << "                   |                        || _________                                   |\n";
    cout << "                   |                      -=|c´´´´´´´´´´´)                                 |\n";
    cout << "                   |                         `~~~~~/ /~~`                                  |\n";
    cout << "                   |                           -==/ /                                      |\n";
    cout << "                   |                              _  _                                     |\n";
    cout << "                   |                            ( `   )_                                   |\n";
    cout << "                   |                          (    )    `)                                 |\n";
    cout << "                   |                         (_   (_ .  _) _)               _              |\n";
    cout << "                   |                                                       (  )            |\n";
    cout << "                   |                        _ .                         ( `  ) . )         |\n";
    cout << "                   |                      (  _ )_                      (_, _(  ,_)_)       |\n";
    cout << "                   |                    (_  _(_ ,)                                         |\n";
    cout << "                   -------------------------------------------------------------------------\n";
    cout << "\n                                                 AED Airlines                        " << endl;

    //   this_thread::sleep_for(chrono::seconds(4));
    cout << string(4, '\n');
    cout << "\b                          1- Company Menu\n";
    cout << "                          2- User Menu\n";
    cout << "                          3- exit\n";
    cout << "                                                Choose your option here: ";
    cin >> choice;
    if (choice == 3) {
        cout << "Are you sure you want to quit? [y/n] ";
        cin >> ch;
        if ((tolower(ch) == 'n'))
            display();
        else if ((tolower(ch) == 'y'))
            exit(0);
    }

    return choice;
}
void Menu::company_menu(Menu menu1, Company c1) {
    int answer;
    int choice;
    cout << string(4, '\n');
    cout << "\b                                            Welcome to the AED Airlines!\n";
    cout << "                                                  How may we help you?\n";
    cout << "                          1- Load planes from file\n";
    cout << "                          2- View planes\n";
    cout << "                          3- Add planes\n";
    cout << "                          4- Remove planes\n";
    cout << "                          5- Update planes\n";
    cout << "                          6- exit\n";
    cout << "                                                Choose your option here: ";
    cin >> answer;
    switch (answer) {
        case 1: {
            ifstream f;
            f.open("/Trab_AED_01/Trab_AED_01/planes.txt");
            if (!f.is_open()) {
                cout << "File not found";
                menu1.company_menu(menu1,c1);

            } else {
                c1.set_planes(f);
                f.close();
                menu1.company_menu(menu1,c1);
            }
        }
        case 2:
            c1.show_planes();
            menu1.company_menu(menu1,c1);

        case 3: {                                       //adiciona aviões
            string r,t;
            int c;
            cout << "Add a plane by typing its registration: ";
            cin >> r;
            cout << "\nand its type: ";
            cin >> t;
            cout << "\nand its capacity: ";
            cin >> c;
            c1.add_plane(r, t,c);
            menu1.company_menu(menu1,c1);
        }
        case 4: {                                        //remove aviões
            string r;
            int c;
            cout << "To remove a plane, insert its registration: ";
            cin >> r;
            c1.remove_plane(r);
            menu1.company_menu(menu1,c1);
        }

        case 5: {                                       //dá update aos aviões
            ofstream f;
            f.open("/Trab_AED_01/Trab_AED_01/planes.txt");
            if (!f.is_open()) {
                cout << "File not found";
                menu1.company_menu(menu1,c1);
            } else {
                c1.update(f);
                f.close();
                cout << "\nPlanes updated successfully!";
                menu1.company_menu(menu1,c1);
            }
        }
        case 6:{
            char ans = ' ';
            cout << "Are you sure you want to quit? [y/n] ";
            cin >> ans;
            if ((tolower(ans) == 'n'))
                menu1.company_menu(menu1, c1);
            else if ((tolower(ans) == 'y'))
                display();

        }
    }
}