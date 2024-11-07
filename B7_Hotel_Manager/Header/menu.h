/*
* File: menu.h
* Author: Tran Nhat Thai
* Date: 1/03/2024
* Description: This file defines functions and structures related to the user interface and menu system of the application.
*/


#ifndef _MENU_H
#define _MENU_H

#include "../Header/receptionist.h"
#include "../Header/manager.h"

/*
* Function: menuHotel
* Description: This function is used for managing the hotel
* Input:   database (a reference to the Database struct containing employee, room, and service information)
* Output:  return: None
*/
void menuHotel(Database &database) {
    Manager manager;
    Receptionist receptionist;

    while (true) {
        menu_start:
        int choice = 0;
        do {
            system("cls");

            cout << "\t\t\t-----------------------------" << endl;
            cout << "\t\t\t| RESTAURANT MANAGEMENT SYSTEM |" << endl;
            cout << "\t\t\t-----------------------------" << endl;
            cout << "\t\t\t 1. Manager" << endl;
            cout << "\t\t\t 2. Receptionist" << endl;
            cout << "\t\t\t 3. Exit program" << endl;
            cout << "\t\t\t............................" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> choice;

            if (choice == 3) {
                cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
                exit(0);
            }

        } while (choice != 1 && choice != 2);

        switch (choice) {
            case 1:
                // Call menuManager() method from Manager class to manage the hotel as a manager
                manager.menuManager(database);
                break;

            case 2:
                // Call menuReceptionist() method from Receptionist class to manage the hotel as a receptionist
                receptionist.menuReceptionist(database);
                break;

            default:
                break;
        }
    }
}

#endif
