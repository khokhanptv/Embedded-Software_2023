/*
* File: menu.h
* Author:Tran Nhat Thai
* Date:1/3/2023
* Description: Header file for defining menu macros and functions for the restaurant management system
*/
#ifndef __MENU_H__
#define __MENU_H__

#include "D:\Embeded_T10\ADVANCED CC++ ALGORITHM T122023_BT\B6_RestaurantManagement\RestaurantManagement\Header\management.hpp"

// Macro for displaying the main menu
#define MENU            system("clear");\
                        cout<<"----------------Restaurant__Management----------------"<<endl;\
                        cout<<"| *Choose program function:                          |"<<endl;\
                        cout<<"|>1. Management                                      |"<<endl;\
                        cout<<"|>2. Staff                                           |"<<endl;\
                        cout<<"------------------------------------------------------"<<endl;\
                        cout<<"   Input choose program function: ";\
                        cin>>option;\
                        cout<<"------------------------------------------------------"<<endl;\
                        fflush(stdin);

// Macro for displaying the management menu
#define MANAGEMENT      system("clear");\
                        cout<<"----------------MANAGEMENT-----------------------------"<<endl;\
                        cout<<"| *Choose program function:                           |"<<endl;\
                        cout<<"|>1. Setup table number                              |"<<endl;\
                        cout<<"|>2. Addition dish                                   |"<<endl;\
                        cout<<"|>3. Edit dish                                       |"<<endl;\
                        cout<<"|>4. Erase dish                                      |"<<endl;\
                        cout<<"|>5. Dish list                                       |"<<endl;\
                        cout<<"|>0. Exit                                            |"<<endl;\
                        cout<<"------------------------------------------------------"<<endl;\
                        cout<<"   Input choose program function: ";\
                        cin>>option;\
                        cout<<"------------------------------------------------------"<<endl;\
                        fflush(stdin);

// Macro for displaying the option menu
#define OPTION          system("clear");\
                        cout<<"------------------------------------------------------"<<endl;\
                        cout<<"| *Choose program function:                           |"<<endl;\
                        cout<<"|>1. Order food                                      |"<<endl;\
                        cout<<"|>2. Cancel order                                    |"<<endl;\
                        cout<<"|>3. Change order                                    |"<<endl;\
                        cout<<"|>4. List of ordered dishes                          |"<<endl;\
                        cout<<"|>5. Pay                                             |"<<endl;\
                        cout<<"|>0. Exit                                            |"<<endl;\
                        cout<<"------------------------------------------------------"<<endl;\
                        cout<<"   Input choose program function: ";\
                        cin>>option;\
                        cout<<"------------------------------------------------------"<<endl;\
                        fflush(stdin);

// Macro for setting up the table number
#define TABLENUMBER     system("clear");\
                        cout<<"Setup table number"<<endl;\
                        cout<<"Enter table number: ";\
                        cin >> option;

// Macro for choosing a table
#define CHOOSETABLE     cout<<"Choose table: ";\
                        cin>>numTable;\
                        cout<<endl;

// Function declaration for displaying the main menu
void menu();

#endif
