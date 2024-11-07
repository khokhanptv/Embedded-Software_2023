/*
* File:dish.cpp
* Author:Tran Nhat Thai
* Date:1/3/2023
* Description: This file contains the implementation of functions related to managing dishes in a restaurant.
*/

#include "D:\Embeded_T10\ADVANCED CC++ ALGORITHM T122023_BT\B6_RestaurantManagement\RestaurantManagement\Header\dish.hpp"

/*
Funtion Name: getId
Function description : return id food
Input parameters: NONE
Output: id
*/
int Dish::getId() const {
    return id;
}

/*
Funtion Name: getName
Function description : return name food
Input parameters: NONE
Output: name food
*/
string Dish::getName() {
    return name;
}

/*
Funtion Name: getPrice
Function description : return Price of food
Input parameters: NONE
Output: price
*/
int Dish::getPrice() {
    return price;
}

/*
Funtion Name: displayInfo
Function description : show information food
Input parameters: NONE
Output: NONE
*/
void Dish::displayInfo() {
    cout << "Information: " << endl;
    cout << setw(5) << left << "ID";
	cout << setw(30) << left << "NAME";
	cout << setw(20) << right << "PRICE" << endl;
	cout << setfill('-');
	cout << setw(55) << "-" << endl;
	cout << setfill(' ');	
	cout << setw(5) << left << getId();
	cout << setw(30) << left << getName();
	cout << setw(20) << right << getPrice()<< endl;
}

/*
Funtion Name: addDish
Function description : add new food in list
Input parameters: NONE
Output: NONE
*/
void ManageDish::addDish() {
    INPUTDISH
	Dish newDish(name, price);
    array.push_back(newDish);
    SUCCESSFULl
}

/*
Funtion Name: displayDish
Function description : show information list Dish
Input parameters: NONE
Output: NONE
*/
void ManageDish::displayDish() {
    if (array.empty()) {
        FAIL
    } else {
        cout << "Dish List:" << endl;
        for (auto& dish : array) {
            dish.displayInfo();
        }
    }
}

/*
Funtion Name: editDish
Function description : edit information food
Input parameters: NONE
Output: NONE
*/
void ManageDish::editDish() {
	SEARCHID
    bool found = false;
    for (auto& dish : array) {
        if (dish.getId() == id) {
            INPUTDISH            
            dish = Dish(name, price);
            found = true;
            SUCCESSFULl
            break;
        }
    }
    
    if (!found) {
        FAIL
    }
}

/*
Funtion Name: eraseDish
Function description : erase food in list food
Input parameters: NONE
Output: NONE
*/
void ManageDish::eraseDish() {
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

/*
Funtion Name: dish
Function description :search food by id
Input parameters: NONE
Output: NONE
*/
Dish ManageDish::dish() {
	SEARCHID
	auto it = array.begin();
    while (it != array.end()) {
        if (it->getId() == id) {
            SUCCESSFULl
            return *it;
        } else {
            ++it;
        }
    }
	FAIL
}
