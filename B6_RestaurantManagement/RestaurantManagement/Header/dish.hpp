/*
* File: dish.h
* Author:Tran Nhat Thai
* Date:1/3/2023
* Description: Header file for managing dishes
*/
#ifndef __DISH_H__
#define __DISH_H__

#include <iostream>
#include <list>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

// Macro for inputting dish details
#define INPUTDISH   string name;\
                    int price;\
                    system("clear");\
                    cout << "Enter name of dish: ";\
                    cin.ignore();\
                    getline(cin, name);\
                    cout << "Enter price of dish: ";\
                    cin >> price;

// Macro for searching dish by ID
#define SEARCHID    if (array.empty())\
                    cout << "No dishes available to edit." << endl;\
                    int id;\
                    cout << "Enter ID of dish to edit: ";\
                    cin >> id;
    
// Macro for displaying success or failure message
#define SUCCESSFULl cout << " Successfully!" << endl;
#define FAIL        cout << " Fail!" << endl;

// Class representing a dish
class Dish
{
private:
    string name;
    int price;
    int id;

public:
    // Constructor to initialize dish with name and price
    Dish(string sName = "", int iPrice = 0) : name(sName), price(iPrice){
        static int Id;
        Id++;
        id = Id;
    }

    // Getter method for name
    string getName();

    // Getter method for price
    int getPrice();

    // Getter method for ID
    int getId() const;

    // Method to display dish information
    void displayInfo();
};

// Class for managing dishes
class ManageDish{
private:
    list<Dish> array;

public:
    // Method to add a new dish
    void addDish();

    // Method to edit an existing dish
    void editDish();

    // Method to erase a dish
    void eraseDish();

    // Method to display all dishes
    void displayDish();

    // Method to create a new dish object
    Dish dish();
};

#endif
