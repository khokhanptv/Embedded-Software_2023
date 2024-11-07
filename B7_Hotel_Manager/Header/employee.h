 /*
* File: employee.h
* Author: Tran Nhat Thai
* Date: 1/03/2024
* Description: This file is a header file for managing employees of a hotel
*/

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

// Enumeration for different shifts
enum Time { Morning, Afternoon, Evening, No_Shift };

// Struct for setting weekly shifts
struct Shift {
    Time Mon[2];
    Time Tue[2];
    Time Wed[2];
    Time Thur[2];
    Time Fri[2];
};

// Function to get string representation of time
inline string getTime(Time _time) {
    string time;
    switch (_time) {
        case Morning:
            time = "Morning";
            break;
        case Afternoon:
            time = "Afternoon";
            break;
        case Evening: 
            time = "Evening";
            break;
        case No_Shift:
            time = "    x    ";
            break;
        default:
            break;
    }
    return time;
}

/*
*Class: Employee
*Description: This class contains basic properties and methods of an Employee object
*/
class Employee {
private:
    int ID;
    string name;
    string title;
    int phone;
    Shift shift; 

public:
    // Constructor
    Employee() {
        static int _ID = 1;
        this->ID = _ID++;
        this->name = "";
        this->title = "";
        this->phone = 0;
    }

    // Setter and Getter methods
    void setID(int _ID);
    int getID();

    void setName(string _name);
    string getName();

    void setTitle(string _title);
    string getTitle();

    void setPhone(int _phone);
    int getPhone();

    void setData();

    void setShift(Shift _shift);
    Shift getShift();
};

/*
*Class: ManageEmployee
*Description: This class contains basic properties and methods for managing employees of a hotel
*/
class ManageEmployee {
private:
    list<Employee> employeeList;
public:
    // Constructor
    ManageEmployee() {}

    // Methods for managing employees
    void addEmployee(); 
    void editEmployee(int _ID); 
    void deleteEmployee(int _ID); 

    void setTimePerDay(Time day[2]);
    void setShift(int _ID); 

    void showEmployeeList(); 
    void tableShift(); 

    void menuManageEmployee(); 
};

#endif
