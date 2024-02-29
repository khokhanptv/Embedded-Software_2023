#ifndef __MANAGEMENT_H__
#define __MANAGEMENT_H__
#include "D:\Embeded_T10\ADVANCED CC++ ALGORITHM T122023_BT\B6_RestaurantManagement\RestaurantManagement\Header\dish.hpp"
#include <algorithm>
#include <vector>

class Table 
{
private:
    list<Dish> array;
    bool status;   
public :
    void setStatus(bool bStatus);
    void oder(ManageDish listD);
    void cancel();
    void change(ManageDish listD);
    void pay();
    void display();
    string getStatus();
};

class Management
{
private:
    vector<Table> myArray;
public:
    void resizeArray(int newSize);
    void displayTable();
    void editTable(int num,int option,ManageDish listd);
};

#endif
