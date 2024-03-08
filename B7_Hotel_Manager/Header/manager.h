 /*
* File: manager.h
* Author: Tran Nhat Thai
* Date: 1/03/2024
* Description: This file is a Manager header file which helps hotel system work
*/

#ifndef _MANAGER_H
#define _MANAGER_H

#include "../Header/employee.h"
#include "../Header/room.h"
#include "../Header/service.h"

// Enumeration for different functions available to the manager
typedef enum {
    Employee_function,
    Room_function,
    Service_function,
    Back_function,
    Exit_function
} Function;

/*
* Struct: Database
* Description: This struct is used for containing data of hotel
    employee: data of employees
    room: data of rooms
    service: data of services
*/
typedef struct {
    ManageEmployee employee;
    ManageRoom room;
    ManageService service;
} Database;

/*
* Class: Manager
* Description: This class contains basic properties and methods that help manager manage hotel system
*/
class Manager {
private:
    int account;
    int password;

public:
    // Default constructor initializing account and password
    Manager() {
        this->account = 123456789;
        this->password = 123456789;
    }

    // Accessor methods for account and password
    int getAccount();
    int getPassword();
    
    // Method to display the manager menu and perform corresponding actions
    void menuManager(Database &database);
};

#endif
