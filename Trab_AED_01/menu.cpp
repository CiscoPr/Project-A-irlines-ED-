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
    cout << "\b                          1- Company Menu\n";                                                            //displays the menu correspondent
                                                                                                                        // to the company
    cout << "                          2- User Menu\n";                                                                 //displays the menu correspondent
                                                                                                                        //to the user/client
    cout << "                          3- exit\n";                                                                      //quits and terminates the program
    cout << "                                                Choose your option here: ";
    cin >> choice;
    if (choice == 3) {                                                                                                  //what happens if the user chooses to quit
        cout << "Are you sure you want to quit? [y/n] ";
        cin >> ch;
        if ((tolower(ch) == 'n'))                                                                                    //if the user chooses not to quit
                                                                                                                        //it returns to the main menu above
            display();
        else if ((tolower(ch) == 'y'))                                                                               //otherwise, if the user chooses to quit
            exit(0);                                                                                              //the program terminates
    }

    return choice;
}
void Menu::company_menu(Menu menu1, Company c1) {                                                                       //company exclusive display
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
        case 1: {                                                                                                       //if the user chooses to load the planes:
            ifstream f;                                                                                                 //this will verify if the file planes txt
            f.open("\\Trab_AED_01\\Trab_AED_01\\planes.txt");                                                        //in which there are vectors with info of each plane stored

            if (!f.is_open()) {                                                                                         //if the file doesn't exist
                cout << "File not found";                                                                               //it prints an error message
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);                                                                           //and returns to the company menu

            } else {
                c1.set_planes(f);                                                                                       //else, it sets the info about the planes
                                                                                                                        //into the file, sorting the planes by registration
                f.close();                                                                                              //finally, it closes the file
                menu1.company_menu(menu1,c1);                                                                           //and returns to the menu
            }
        }
        case 2:                                                                                                         //if the user chooses to view the planes
            c1.show_planes();                                                                                           //the file is printed on the console
            //   this_thread::sleep_for(chrono::seconds(4));
            menu1.company_menu(menu1,c1);                                                                               //finally, it returns to the company menu

        case 3: {                                                                                                       //if the user chooses to add planes:
            string r,t;
            int c;
            cout << "Add a plane by typing its registration: ";                                                         //the program asks the user for a plane registration
            cin >> r;
            cout << "\nand its type: ";                                                                                 //its type
            cin >> t;
            cout << "\nand its capacity: ";                                                                             //and its capacity
            cin >> c;
            c1.add_plane(r, t,c);                                                                 //and it adds to the vector of planes
                                                                                                                        //the vector plane with the mentioned characteristics
            menu1.company_menu(menu1,c1);                                                                               //finally, it returns to the company menu
        }
        case 4: {                                                                                                       //if the user decides to remove a plane:
            string r;
            int c;
            cout << "To remove a plane, insert its registration: ";
            cin >> r;                                                                                                   //the program will ask for the registration
                                                                                                                        //of the plane they want to remove
            c1.remove_plane(r);                                                                               // it removes the plane
            menu1.company_menu(menu1,c1);                                                                               //and, finally, returns to the company menu
        }

        case 5: {                                                                                                       //if the user wants to update the planes:
            ofstream f;                                                                                                 //the program will verify if the file regarding
            f.open("\\Trab_AED_01\\Trab_AED_01\\planes.txt");                                                        //the planes exists
            if (!f.is_open()) {                                                                                         //if it doesn't
                cout << "File not found";                                                                               //an error message is displayed
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);                                                                           //returning to the company menu right after
            } else {
                c1.update(f);                                                                                           //otherwise, it updates teh file with the
                                                                                                                        //current info regarding the planes
                f.close();                                                                                              //closing the file right after
                cout << "\nPlanes updated successfully!";                                                               //and displaying a confirmation message
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);                                                                           //and only then it returns to the company menu
            }
        }
        case 6:{                                                                                                        //if the user decides to load the flights of the planes
            ifstream f_2;                                                                                               //this will check if the file with all the info about
            f_2.open("\\Trab_AED_01\\Trab_AED_01\\flight_plan.txt");                                                 //the flights exists

            if (!f_2.is_open()) {                                                                                       //if it doesn't,an error message is displayed
                cout << "File not found";
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);                                                                           //and returns to the company menu
            } else {
                for (int i = 0; i < c1.get_planes().size();i++) {                                                       //else, it sets the flights for each and
                    c1.get_planes()[i].set_flights(f_2);                                                             //every plane
                }
                    f_2.close();                                                                                        //closing the file
                    menu1.company_menu(menu1, c1);                                                                      //and returning to the company menu right after
            }
        }
        case 7:{                                                                                                        //if the user wants to view the flights of each plane:
            for (int i = 0; i < c1.get_planes().size();i++) {                                                           //a cycle is used to associate each flight plan with
                cout << "plane"<<(i+1)<<endl;                                                                           //every plane, printing it on the console right after
                c1.get_planes()[i].show_flights();
                //   this_thread::sleep_for(chrono::seconds(4));
            }
                menu1.company_menu(menu1, c1);                                                                          //finally, it returns to company menu
        }
        case 8:{                                                                                                        //if the user wishes to add flights:
            int id, available_seats;
            float departure,duration;
            string origin, destination, registration;                                                                   //they are asked for a new
            cout << "Add a flight by typing its id: ";                                                                  //id
            cin >> id;
 //           cout << "\n and its available seats: ";
 //           cin >> available_seats;
            cout << "\nand its duration: ";                                                                             //duration
            cin >> duration;
            cout << "\nand its departure: ";                                                                            //departure
            cin >> departure;
            cout << "\nand its origin: ";                                                                               //origin
            cin >> origin;
            cout << "\nand its destination: ";                                                                          //destination
            cin >> destination;
            cout << "\n to the plane with the registration: ";                                                          //adn registration
            cin >> registration;
            Flight f1(id,available_seats,duration,departure,origin,destination);
            for (int i = 0 ; i < c1.get_planes().size();i++){
                if (c1.get_planes()[i].get_registration()==registration){                                               //the flights are then added to the flight plan
                    c1.get_planes()[i].add_flight(f1);}
            }
            menu1.company_menu(menu1,c1);                                                                               //returning to the company menu as the final step
        }
        case 9:{                                                                                                        //if the user wishes to remove a flight:
            int id;
            cout << "Insert id of the flight to be removed: ";                                                          //they are asked for the id of the flight they wish
            cin >> id;                                                                                                  //to remove
            for(int i = 0 ; i >  c1.get_planes().size();i++){                                                           //a cycle is used in order to get the plane which
                Plane p1 = c1.get_planes()[i];                                                                          //has the wanted flight
                p1.cancel_flight(id);
            }
            menu1.company_menu(menu1,c1);                                                                               //finally it returns to the company menu
        }
        case 10:{                                                                                                       //if the user wants to update the flights file:
            ofstream f;                                                                                                 //the program will verify if the file exists
            f.open("\\Trab_AED_01\\Trab_AED_01\\flight_plan.txt");
            if (!f.is_open()) {                                                                                         //if it doesn't
                cout << "File not found";                                                                               //an error message will be displayed
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);                                                                           //and the user will return to the company menu
            }
            else {
                for (int i = 0 ; i < c1.get_planes().size();i++) {
                    c1.get_planes()[i].update(f);                                                                       //else, the file will be updated with the current info
                                                                                                                        //of every flight
                }
                f.close();                                                                                              //closing the file
                cout << "\nPlanes updated successfully!";                                                               //and displaying a confirmation message right after
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);                                                                           //finally, the user returns to company menu
            }
        }
        case 11:{                                                                                                       //if the user wishes to load the services of a plane:
            ifstream f_2;                                                                                               //the program will check if the file of the services exist
            f_2.open("\\Trab_AED_01\\Trab_AED_01\\services.txt");
            if (!f_2.is_open()) {
                cout << "File not found";                                                                               //if it doesn't, an error message will be displayed
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);                                                                           //returning the user to the company menu right after
            } else {
                for (int i = 0; i < c1.get_planes().size();i++) {                                                       //otherwise, it associates each service with a plane
                    c1.get_planes()[i].set_services(f_2);                                                            //and sets that info
                }
                f_2.close();                                                                                            //closing the file
                menu1.company_menu(menu1, c1);                                                                          //and returning the company menu right after
            }
        }
        case 12:{                                                                                                       //if the user wishes to apply a service:
            string registration;
            cout << "Insert registration of the plane where the service will be done : ";                               //the program will ask the user for a plane's registration
            cin >> registration;                                                                                        //this will be used to register a done service for that plane
            for(int i = 0 ; i >  c1.get_planes().size();i++){
                if (c1.get_planes()[i].get_registration() == registration){                                             //through a cycle, the program will know which
                    c1.get_planes()[i].do_service();                                                                    //service is done, pushing it into a stack of done services
                }
            }
            menu1.company_menu(menu1,c1);                                                                               //finally, the user will return to the company menu
        }
        case 13:{                                                                                                       //if the user wants to know which was the las service done:
            string registration;                                                                                        //the user will be asked for a plane
            cout << "Insert registration of the plane: ";
            cin >> registration;
            for(int i = 0 ; i >  c1.get_planes().size();i++){                                                           //using this cycle, we will know which was the
                if (c1.get_planes()[i].get_registration() == registration){                                             //last service done on that plane
                    c1.get_planes()[i].show_last_service_done();
                }
            }
            menu1.company_menu(menu1,c1);                                                                               //the user will finally return to the company menu
        }
        case 14:{                                                                                                       //if the user wants to add a service:
            int choice;
            string name;
            float data;
            string registration;
            cout << "Insert registration of the plane: ";                                                               //the plan will ask for a plane's registration
            cin >> registration;
            Servicetype type;
            cout << "Service type: maintenance(1) or cleaning(2): ";                                                    //then, it will ask them what kind of service do they want
            cin >> choice;
            if (choice==1){
                type= maintenance;                                                                                      //it's either maintenance
            }
            else if (choice==2){
                type= cleaning;                                                                                         //or cleaning
            }
            else {
                cout<<"Invalid input";                                                                                  //other kind of inputs will drive to an error message
                menu1.company_menu(menu1,c1);                                                                           //and return the user to the company menu
            }
            cout << "Insert the data for the service";                                                                  //the user will then asked for the data of the service
            cin >> data;
            cout << "Insert name of the employee: ";                                                                    //the name of the employee
            cin >> name;
            Employee e1 (name);
            Service s1(type,data,e1);
            for(int i = 0 ; i >  c1.get_planes().size();i++){                                                           //and add this service to the vector of the services of
                if (c1.get_planes()[i].get_registration() == registration){                                             //the wished plane
                    c1.get_planes()[i].add_service(s1);
                }
            }
        }
        case 15:{                                                                                                       //if the user wishes to update the services:
            ofstream f;
            f.open("\\Trab_AED_01\\Trab_AED_01\\flight_plan.txt");                                                   //the program will check if the file of the services exist
            if (!f.is_open()) {
                cout << "File not found";                                                                               //printing an error message
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);                                                                           //and returning to the company menu  if not
            }
            else {
                for (int i = 0 ; i < c1.get_planes().size();i++) {                                                      //else, it updates the services file
                    c1.get_planes()[i].update_services(f);                                                              //with the current info of this class
                }
                f.close();
                cout << "\nPlanes updated successfully!";
                //   this_thread::sleep_for(chrono::seconds(4));
                menu1.company_menu(menu1,c1);
            }

        }

        case 16:{                                                                                                       //if the user wishes to quit:
            char ans = ' ';
            cout << "Are you sure you want to quit? [y/n] ";                                                            //the program will ask if the user really wants to quit
            cin >> ans;
            if ((tolower(ans) == 'n'))                                                                               //if they don't, they will return to the company menu
                menu1.company_menu(menu1, c1);
            else if ((tolower(ans) == 'y'))                                                                          //else, the program will return to the main display
                display();

        }
    }
}

void Menu::user_menu(Menu menu2, Local_of_Transport l2) {                                                               //client exclusive display
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
        case 1:{                                                                                                        //if the client wishes to buy a ticket:
            int wanted;
            char b = ' ';
            int wishedFlight;
            cout << "What flight do you want to go on? \n";                                                             //the user will be asked for the flight they want
            cout << "Please insert the id of the flight \n";                                                            //to attend
            cin >> wishedFlight;
            cout << "How many tickets do you want to buy? ";                                                            //and how many tickets they wish to buy
            cin >> wanted;
            Company c1;
            for(int i = 0 ; i >  c1.get_planes().size();i++){                                                           //if the user wishes for more tickets than
                                                                                                                        //they are available, an error will come out
                Plane p1 = c1.get_planes()[i];                                                                          //else, they will be able to buy tickets
                p1.seats(wanted, wishedFlight);
            }

            Ticket t1;
            cout << "\nWill you carry any kind of baggage?[y/n] ";                                                      //next, the user will be asked if they wish to carry
            cin >> b;                                                                                                   //any baggage
            if (tolower(b) == 'n'){                                                                                  //if they don't, the bool baggage wil turn false
                cout << "\nOk, thank you for your purchase! ";
                t1.baggage = false;
            }
            else if(tolower(b)== 'y'){                                                                               //otherwise, it will be true
                t1.baggage = true;
                cout << "\nOk, thank you for your purchase! ";
            }
            menu2.user_menu(menu2, l2);                                                                                 //after that, the user returns to the client menu


        }
        case 2:{                                                                                                        //if the user wants to see near means of transport
            ifstream  f;
            f.open("\\Trab_AED_01\\Trab_AED_01\\transp.txt");                                                        //this will check if the file correspondent to the
                                                                                                                        //means of transport exists
            if(!f.is_open()){
                cout << "File not found";                                                                               //if it doesn't, an error message will be displayed
                //   this_thread::sleep_for(chrono::seconds(4));
                menu2.user_menu(menu2, l2);                                                                             //and the user will return to the client menu
            }
            Local_of_Transport l2;                                                                                      //else, the binary search tree will be read
            l2.readFile(f);                                                                                             //and the file with transports will be displayed
            f.close();
            l2.print();
            this_thread::sleep_for(chrono::seconds(4));
            menu2.user_menu(menu2, l2);                                                                                 //finally, the user will return to the client menu
        }

        case 3:{                                                                                                        //if the user wishes to exit:
            char ans = ' ';
            cout << "Are you sure you want to quit? [y/n] ";                                                            //the program will ask if the user really wants to quit
            cin >> ans;
            if ((tolower(ans) == 'n'))                                                                               //if not, the user will return to the client menu
                menu2.user_menu(menu2, l2);
            else if ((tolower(ans) == 'y'))                                                                          //otherwise, the user will return to the main display
                display();
        }


    }
}