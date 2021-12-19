#include "menu.h"
#include "flights.h"
#include <thread>
#include "transport.h"
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
    cout << "                          6- Load flights from file\n";
    cout << "                          7- View flights\n";
    cout << "                          8- Add flights\n";
    cout << "                          9- Remove flights\n";
    cout << "                          10- Update flights\n";
    cout << "                          11- Load services\n";
    cout << "                          15- exit\n";
    cout << "                                                Choose your option here: ";
    cin >> answer;
    switch (answer) {
        case 1: {
            ifstream f;
            f.open("C:\\Users\\Francisco Prada\\OneDrive\\Ambiente de Trabalho\\Project-A-irlines-ED--main\\Trab_AED_01\\planes.txt");
            if (!f.is_open()) {
                cout << "File not found";
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);

            } else {
                c1.set_planes(f);
                f.close();
                menu1.company_menu(menu1,c1);
            }
        }
        case 2:
            c1.show_planes();
            //   this_thread::sleep_for(chrono::seconds(4));
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
            f.open("C:\\Users\\Francisco Prada\\OneDrive\\Ambiente de Trabalho\\Project-A-irlines-ED--main\\Trab_AED_01\\planes.txt");
            if (!f.is_open()) {
                cout << "File not found";
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);
            } else {
                c1.update(f);
                f.close();
                cout << "\nPlanes updated successfully!";
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);
            }
        }
        case 6:{
            ifstream f_2;
            f_2.open("C:\\Users\\Francisco Prada\\OneDrive\\Ambiente de Trabalho\\Project-A-irlines-ED--main\\Trab_AED_01\\flight_plan.txt");
            if (!f_2.is_open()) {
                cout << "File not found";
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);
            } else {
                for (int i = 0; i < c1.get_planes().size();i++) {
                    c1.get_planes()[i].set_flights(f_2);
                }
                    f_2.close();
                    menu1.company_menu(menu1, c1);
            }
        }
        case 7:{
            for (int i = 0; i < c1.get_planes().size();i++) {
                cout << "plane"<<(i+1)<<endl;
                c1.get_planes()[i].show_flights();
                //   this_thread::sleep_for(chrono::seconds(4));
            }
                menu1.company_menu(menu1, c1);
        }
        case 8:{
            int id;
            float departure,duration;
            string origin, destination, registration;
            cout << "Add a flight by typing its id: ";
            cin >> id;
            cout << "\nand its duration: ";
            cin >> duration;
            cout << "\nand its departure: ";
            cin >> departure;
            cout << "\nand its origin: ";
            cin >> origin;
            cout << "\nand its destination: ";
            cin >> destination;
            cout << "\n to the plane with the registration: ";
            cin >> registration;
            Flight f1(id,duration,departure,origin,destination);
            for (int i = 0 ; i < c1.get_planes().size();i++){
                if (c1.get_planes()[i].get_registration()==registration){
                    c1.get_planes()[i].add_flight(f1);}
            }
            menu1.company_menu(menu1,c1);
        }
        case 9:{
            int id;
            cout << "Insert id of the flight to be removed: ";
            cin >> id;
            for(int i = 0 ; i >  c1.get_planes().size();i++){
                Plane p1 = c1.get_planes()[i];
                p1.cancel_flight(id);
            }
            menu1.company_menu(menu1,c1);
        }
        case 10:{
            ofstream f;
            f.open("C:\\Users\\Francisco Prada\\OneDrive\\Ambiente de Trabalho\\Project-A-irlines-ED--main\\Trab_AED_01\\flight_plan.txt");
            if (!f.is_open()) {
                cout << "File not found";
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);
            }
            else {
                for (int i = 0 ; i < c1.get_planes().size();i++) {
                    c1.get_planes()[i].update(f);
                }
                f.close();
                cout << "\nPlanes updated successfully!";
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);
            }
        }
        case 15:{
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

void Menu::user_menu(Menu menu2, Local_of_Transport l2) {
    int answer;
    int choice;
    cout << string(4, '\n');
    cout << "\b                                            Welcome to the AED Airlines!\n";
    cout << "                                                  How may we help you?\n";
    cout << "                          1- Buy a ticket\n";
    cout << "                          2- See near means of transport\n";
    cout << "                          3- Exit\n";
    cout << "                                                Choose your option here: ";
    cin >> choice;
    switch (choice) {
        case 2:{
            ifstream  f;
            f.open("C:\\Users\\Francisco Prada\\OneDrive\\Ambiente de Trabalho\\Project-A-irlines-ED--main\\Trab_AED_01\\transp.txt");
            if(!f.is_open()){
                cout << "File not found";
                //   this_thread::sleep_for(chrono::seconds(4));
                menu2.user_menu(menu2, l2);
            }
            Local_of_Transport l2;
            l2.readFile(f);
            f.close();
            l2.print();
            this_thread::sleep_for(chrono::seconds(4));
            menu2.user_menu(menu2, l2);
        }

        case 3:{
            char ans = ' ';
            cout << "Are you sure you want to quit? [y/n] ";
            cin >> ans;
            if ((tolower(ans) == 'n'))
                menu2.user_menu(menu2, l2);
            else if ((tolower(ans) == 'y'))
                display();
        }

    }
}