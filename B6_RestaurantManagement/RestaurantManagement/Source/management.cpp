/*
* File: management.cpp
* Author: Tran Nhat Thai
* Date: 1/3/2023
* Description: This file contains the implementation of functions related to table management in the restaurant.
*/

#include "D:\Embeded_T10\ADVANCED CC++ ALGORITHM T122023_BT\B6_RestaurantManagement\RestaurantManagement\Header\management.hpp"

void Table::oder(ManageDish listD) {
    Dish Order = listD.dish();
    array.push_back(Order);
    SUCCESSFULl 
}

void Table::display() {
    if (array.empty()) {
        FAIL
    } else {
        cout << "Dish List:" << endl;
        for (auto& dish : array) {
            dish.displayInfo();
        }
    }
}

void Table::cancel() {
    display();
    SEARCHID
    auto it = array.begin();
    while (it != array.end()) {
        if (it->getId() == id) {
            it = array.erase(it);
            SUCCESSFULl
            return;
        } else {
            ++it;
        }
    }
    FAIL
}

void Table::change(ManageDish listD) {
    display();
    SEARCHID
    auto it = array.begin();
    while (it != array.end()) {
        if (it->getId() == id) {
            Dish Order = listD.dish();
            *it = Order;
            SUCCESSFULl
            return;
        } else {
            ++it;
        }
    }
    FAIL   
}

void Table::pay() {
    int totalMoney = 0;
    auto it = array.begin();
    while (it != array.end()) {
        totalMoney += it->getPrice();
        it->displayInfo();
        ++it;
    }
    cout << "Total: " << totalMoney << " VND" << endl;
}

void Table::setStatus(bool bStatus) {
    status = bStatus;
}

string Table::getStatus() {
    if (status) {
        return "x";
    }
    return "O";
}

void Management::resizeArray(int newSize) {
    myArray.resize(newSize);
    for (auto i : myArray) {
        i.setStatus(false);
    }
}

void Management::displayTable() {
    int number = 0;
    system("clear");
    cout << setw(20) << left << "Table Number:";
    for (auto i : myArray) {
        cout << setw(4) << left << number;
        number++;
    }
    cout << endl;
    cout << setw(20) << left << "Status:";
    for (auto i : myArray) { 
        cout << setw(4) << left << i.getStatus();
    }
    cout << endl;
    cout << "X Busy" << endl;
    cout << "O Available" << endl;
}

void Management::editTable(int num, int option, ManageDish listd) {
    if (myArray.size() >= num) {
        switch (option) {
            case 1:
                myArray[num - 1].oder(listd);
                break;
            case 2:
                myArray[num - 1].cancel();
                break;
            case 3:
                myArray[num - 1].change(listd);
                break;
            case 4:
                myArray[num - 1].display();
                break;
            case 5:
                myArray[num - 1].pay();
                break;
            default:
                break;
        }
    }
}
