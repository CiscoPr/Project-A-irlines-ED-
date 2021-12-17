#include "menu.h"
#include <thread>
#include <iostream>


using namespace std;
using namespace chrono;
void Menu::display() {
    int choice;
    char answer = ' ';
    string bruh = "         ";

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
    cout << "\n                                                 AED Airlines                        "<< endl;
    this_thread::sleep_for(chrono::seconds(4));

    do {
        cout << string(4, '\n');
        cout << "\b                                                Company Interface\n";
        cout << "                                                 ?\n";
        cout << "                          1- Update nos aviões\n";
        cout << "                          2- \n";
        cout << "                          3- \n";
        cout << "                          4-
        cout << "                          5- exit\n";
        cout << "                                                Choose your option here: ";
        cin >> choice;
    }



    //    do{
//        cout << string(4, '\n');
//        cout << "\b                                            Welcome to the AED Airlines!\n";
//        cout <<"                                                  How may we help you?\n";
//        cout << "                          1- I want to buy a ticket\n";
//        cout << "                          2- Available flights\n";
//        cout << "                          3- Means of transport near the airport\n";
//        cout << "                          4- Something else\n";
//        cout << "                          5- exit\n";
//        cout << "                                                Choose your option here: ";
//        cin >> choice;
//        switch(choice){
//            case 1:
//                break;
//            case 2:
//                break;
//            case 3:
//                break;
//            case 4:
//                break;
//            case 5:
//                    cout << "Are you sure you want to quit? [y/n] ";
//                    cin >> answer;
//                    if ((tolower(answer) == 'n'))
//                        break;
//
//        }

   // }while(answer != 'y');
//}

