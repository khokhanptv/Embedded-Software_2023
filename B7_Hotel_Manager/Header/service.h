 /*
* File: service.h
* Author: Tran Nhat Thai
* Date: 1/03/2024
* Description: This file is a Service header file which manages types of services of the hotel.
*/

#ifndef _SERVICE_H
#define _SERVICE_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

/*
* Class: Service
* Description: This class contains basic properties and methods of a Service object.
*/
class Service {
private:
    int serviceID; // ID of the service
    string name; // Name of the service
    int price; // Price of the service

public:
    // Default constructor
    Service() {
        static int _serviceID = 1;
        this->serviceID = _serviceID;
        _serviceID++;

        this->name = "";
        this->price = 0;
    }

    // Setter methods
    void setID(int _serviceID);
    void setName(string _name);
    void setPrice(int _price);
    void setData(string _name, int _price);

    // Getter methods
    int getID();
    string getName();
    int getPrice();
};

/*
* Class: ManageService
* Description: This class contains basic properties and methods that manage types of services of the hotel.
*/
class ManageService {
private:
    list<Service> dish; // List of dish services
    list<Service> pool; // List of pool services
    list<Service> gym; // List of gym services
    list<Service> laundry; // List of laundry services

public:
    // Default constructor
    ManageService() {}

    // Getter methods
    list<Service> getDish();
    list<Service> getPool();
    list<Service> getGym();
    list<Service> getLaundry();

    // Other methods
    void addService(string _name, int _price, list<Service> &service);
    void deleteService(int ID_input, list<Service> &service);
    void showService(list<Service> service);
    void editService(int ID_input, list<Service> &service);

    // Function to display the service management menu
    void menuManageService();
};

#endif
