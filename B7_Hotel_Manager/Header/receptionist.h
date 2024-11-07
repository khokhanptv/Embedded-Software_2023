 /*
* File: receptionist.h
* Author: Tran Nhat Thai
* Date: 1/03/2024
* Description: This file is a Receptionist header file which contains the declaration of the Receptionist class.
*/

#ifndef _RECEPTIONIST_H
#define _RECEPTIONIST_H

#include "manager.h" // Include the header file for the Manager class

/*
* Class: Receptionist
* Description: This class contains basic properties and methods that help the receptionist manage the hotel system.
*/
class Receptionist {
private:
    int accountt; // Account of the receptionist
    int passwordd; // Password of the receptionist

public:
    // Default constructor
    Receptionist() {
        this->accountt = 0;
        this->passwordd = 0;
    }

    // Setter methods
    void setAccountt(int _accountt);
    void setPasswordd(int _passwordd);

    // Getter methods
    int getAccountt();
    int getPasswordd();

    // Function to check the shift of employees
    void checkShift(Database database);

    // Functions related to check-in and check-out
    void makeCheckIn(Database &database);
    void makeCheckOut(Database &database);

    // Function to show room information
    void showRoom(Database database);

    // Function to display the receptionist menu
    void menuReceptionist(Database &database);
};

#endif
