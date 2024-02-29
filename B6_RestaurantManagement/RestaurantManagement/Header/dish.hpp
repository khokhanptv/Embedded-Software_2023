#ifndef __DISH_H__
#define __DISH_H__
#include <iostream>
#include <list>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

#define INPUTDISH   string name;\
                    int price;\
                    system("clear");\
                    cout << "Enter name of dish: ";\
                    cin.ignore();\
                    getline(cin, name);\
                    cout << "Enter price of dish: ";\
                    cin >> price;

#define SEARCHID    if (array.empty())\
                    cout << "No dishes available to edit." << endl;\
                    int id;\
                    cout << "Enter ID of dish to edit: ";\
                    cin >> id;
    
#define SUCCESSFULl cout << " Successfully!" << endl;
#define FAIL        cout << " Fail!" << endl;




class Dish
{
private:
    string name;
    int price;
    int id;
public:
    Dish(string sName = "", int iPrice = 0) : name(sName), price(iPrice){
        static int Id;
        Id++;
        id = Id;
    }
    string getName();
    int getPrice();
    int getId()const;
    void displayInfo();
};



class ManageDish{
private:
    list<Dish> array;
public:
    void addDish();
    void editDish();
    void eraseDish();
    void displayDish();
    Dish dish();
};



#endif