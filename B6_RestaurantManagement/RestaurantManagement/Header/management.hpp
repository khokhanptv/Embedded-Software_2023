/*
* File: management.h
* Author:Tran Nhat Thai
* Date:1/3/2023
* Description: Header file for managing tables and orders in a restaurant
*/

#ifndef __MANAGEMENT_H__
#define __MANAGEMENT_H__

#include "D:\Embeded_T10\ADVANCED CC++ ALGORITHM T122023_BT\B6_RestaurantManagement\RestaurantManagement\Header\dish.hpp"
#include <algorithm>
#include <vector>

// Class representing a table in the restaurant
class Table 
{
private:
    list<Dish> array;
    bool status;

public:
    // Method to set the status of the table (occupied or not)
    void setStatus(bool bStatus);

    // Method to place an order for dishes
    void order(ManageDish listD);

    // Method to cancel an order
    void cancel();

    // Method to change an order
    void change(ManageDish listD);

    // Method to process payment for the order
    void pay();

    // Method to display information about the table
    void display();

    // Method to get the status of the table
    string getStatus();
};

// Class for managing tables in the restaurant
class Management
{
private:
    vector<Table> myArray;

public:
    // Method to resize the array of tables
    void resizeArray(int newSize);

    // Method to display information about all tables
    void displayTable();

    // Method to edit information about a specific table
    void editTable(int num, int option, ManageDish listd);
};

#endif
