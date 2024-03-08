 /*
* File: room.h
* Author: Tran Nhat Thai
* Date: 1/03/2024
* Description: This file is a Room header file which manages rooms of the hotel.
*/

#ifndef _ROOM_H
#define _ROOM_H

#include "service.h" // Include the header file for the Service class

using namespace std;

// Structure to store check-in and check-out time
typedef struct {
    string Time;
    string Date;
} CheckTime;

// Structure to store order details
typedef struct {
    Service typeService;
    int numService;
} Order;

/*
* Class: Customer
* Description: This class contains basic properties and methods of a Customer object.
*/
class Customer {
private:
    string nameCustomer; // Name of the customer
    int phoneCustomer; // Phone number of the customer
    CheckTime checkIn; // Check-in time of the customer
    CheckTime checkOut; // Check-out time of the customer
    string feedback; // Feedback from the customer

public:
    // Default constructor
    Customer() {}

    // Setter methods
    void setNameCustomer(string _name);
    void setPhoneCustomer(int _phone);
    void setCheckIn(CheckTime _checkIn);
    void setCheckOut(CheckTime _checkOut);
    void setFeedback(string _feedback);

    // Getter methods
    string getNameCustomer();
    int getPhoneCustomer();
    CheckTime getCheckIn();
    CheckTime getCheckOut();
    string getFeedback();
};

// Enumeration for room status
typedef enum {
    U, // Unavailable
    A // Available
} Status;

// Inline function to convert room status to string
inline string changeStatus(Status _status) {
    string status = "";
    if (_status == U) status = "U";
    else if (_status == A) status = "A";

    return status;
}

/*
* Class: Room
* Description: This class contains basic properties and methods of a Room object.
*/
class Room {
private:
    string roomID; // Room ID
    Status status; // Status of the room
    list<Order> orderService; // List of orders for services
    int totalBill; // Total bill for the room
    list<Customer> customerList; // List of customers in the room

public:
    // Default constructor
    Room() {
        this->roomID = "";
        status = A;
    }

    // Getter methods
    list<Order> getOrderService();
    list<Customer> getCustomerList();
    string getRoomID() const;

    // Setter methods
    void setRoomID(string _roomID);
    void setStatus(Status _status);

    // Other methods
    void getRoom();
    void resetTable();
    void addOrder(ManageService manageService);
    void getOrderList();
    void getBill();

    // Operator overloading
    bool operator < (const Room &other) {
        return this->getRoomID() < other.getRoomID();
    }
};

/*
* Class: ManageRoom
* Description: This class contains basic properties and methods that manage rooms of the hotel.
*/
class ManageRoom {
private:
    list<Room> roomList; // List of rooms

public:
    // Default constructor
    ManageRoom() {}

    // Getter methods
    list<Room> getRoomList();

    // Other methods
    bool isFull();
    void addRoom(string _roomID);
    void deleteRoom(string _ID);
    void sort_room();
    void showRoom();
    void getInfor(string _ID);

    // Function to display the room management menu
    void menuManageRoom();
};

#endif
