#include "menu.h"
#include "flights.h"
#include <thread>
#include "transport.h"
#include "tickets.h"
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
    cout << "                          12- Do a service\n";
    cout << "                          13- Show last service done\n";
    cout << "                          14- Add service\n";
    cout << "                          15- Update services\n";
    cout << "                          16- exit\n";
    cout << "                                                Choose your option here: ";
    cin >> answer;
    switch (answer) {
        case 1: {
            ifstream f;
            f.open("C:\\Users\\Francisco Prada\\Downloads\\Trab_AED_01\\Trab_AED_01\\planes.txt");
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
            f.open("C:\\Users\\Francisco Prada\\Downloads\\Trab_AED_01\\Trab_AED_01\\planes.txt");
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
            f_2.open("C:\\Users\\Francisco Prada\\Downloads\\Trab_AED_01\\Trab_AED_01\\flight_plan.txt");
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
            int id, available_seats;
            float departure,duration;
            string origin, destination, registration;
            cout << "Add a flight by typing its id: ";
            cin >> id;
 //           cout << "\n and its available seats: ";
 //           cin >> available_seats;
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
            Flight f1(id,available_seats,duration,departure,origin,destination);
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
            f.open("C:\\Users\\Francisco Prada\\Downloads\\Trab_AED_01\\Trab_AED_01\\flight_plan.txt");
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
        case 11:{
            ifstream f_2;
            f_2.open("\\Trab_AED_01\\Trab_AED_01\\services.txt");
            if (!f_2.is_open()) {
                cout << "File not found";
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);
            } else {
                for (int i = 0; i < c1.get_planes().size();i++) {
                    c1.get_planes()[i].set_services(f_2);
                }
                f_2.close();
                menu1.company_menu(menu1, c1);
            }
        }
        case 12:{
            string registration;
            cout << "Insert registration of the plane where the service will be done : ";
            cin >> registration;
            for(int i = 0 ; i >  c1.get_planes().size();i++){
                if (c1.get_planes()[i].get_registration() == registration){
                    c1.get_planes()[i].do_service();
                }
            }
            menu1.company_menu(menu1,c1);
        }
        case 13:{
            string registration;
            cout << "Insert registration of the plane: ";
            cin >> registration;
            for(int i = 0 ; i >  c1.get_planes().size();i++){
                if (c1.get_planes()[i].get_registration() == registration){
                    c1.get_planes()[i].show_last_service_done();
                }
            }
            menu1.company_menu(menu1,c1);
        }
        case 14:{
            int choice;
            string name;
            float data;
            string registration;
            cout << "Insert registration of the plane: ";
            cin >> registration;
            Servicetype type;
            cout << "Service type: maintenance(1) or cleaning(2): ";
            cin >> choice;
            if (choice==1){
                type= maintenance;
            }
            else if (choice==2){
                type= cleaning;
            }
            else {
                cout<<"Invalid input";
                menu1.company_menu(menu1,c1);
            }
            cout << "Insert the data for the service";
            cin >> data;
            cout << "Insert name of the employee: ";
            cin >> name;
            Employee e1 (name);
            Service s1(type,data,e1);
            for(int i = 0 ; i >  c1.get_planes().size();i++){
                if (c1.get_planes()[i].get_registration() == registration){
                    c1.get_planes()[i].add_service(s1);
                }
            }
        }
        case 15:{
            ofstream f;
            f.open("\\Trab_AED_01\\Trab_AED_01\\flight_plan.txt");
            if (!f.is_open()) {
                cout << "File not found";
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);
            }
            else {
                for (int i = 0 ; i < c1.get_planes().size();i++) {
                    c1.get_planes()[i].update_services(f);
                }
                f.close();
                cout << "\nPlanes updated successfully!";
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);
            }

        }

        case 16:{
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
        case 1:{
            int wanted;
            char b = ' ';
            int wishedFlight;
            cout << "What flight do you want to go on? \n";
            cout << "Please insert the id of the flight \n";
            cin >> wishedFlight;
            cout << "How many tickets do you want to buy? ";
            cin >> wanted;
            Company c1;
            for(int i = 0 ; i >  c1.get_planes().size();i++){
                Plane p1 = c1.get_planes()[i];
                p1.seats(wanted, wishedFlight);
            }
            menu2.user_menu(menu2, l2);
            Ticket t1;
/*            if(wanted > t1.getNumberOfTickets())
            {
                cout << "There are no more tickets left for this flight.\n";
                cout << "Please try another one\n";
                //   this_thread::sleep_for(chrono::seconds(4))
                menu2.user_menu(menu2, l2);
            }
            else{
                t1.getNumberOfTickets() - wanted;
                cout << "\nWill you carry any kind of baggage?[y/n] ";
                cin >> b;
                if (tolower(b) == 'n'){
                    cout << "\nOk, thank you for your purchase! ";
                    t1.baggage = false;
                }
                else if(tolower(b)== 'y'){
                    t1.baggage = true;
                    cout << "\nOk, thank you for your purchase! ";
                }
            }
*/
        }
        case 2:{
            ifstream  f;
            f.open("C:\\Users\\Francisco Prada\\Downloads\\Trab_AED_01\\Trab_AED_01\\transp.txt");
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