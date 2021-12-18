#include "menu.h"
#include <thread>
#include <iostream>


using namespace std;
using namespace chrono;
int Menu::display() {
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
    cout << "\n                                                 AED Airlines                        " << endl;
//   this_thread::sleep_for(chrono::seconds(4));
    cout << string(4, '\n');
        cout << "\b                          1- Company Menu\n";
        cout << "                          2- User Menu\n";
        cout << "                          3- exit\n";
        cout << "                                                Choose your option here: ";
        cin >> choice;
        return choice;
    }



int Menu::company_menu() {
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
    return answer;
}

    /*
int Menu(){

}
     */