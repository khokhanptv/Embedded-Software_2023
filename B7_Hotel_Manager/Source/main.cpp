 /*
* File: main.cpp
* Author: Tran Nhat Thai
* Date: 1/03/2024
* Description: This file contains the main function to run the hotel management program.
*/

#include "../Header/menu.h" // Include the menu header file

using namespace std;

int main() {
    Database database; // Create a database object
    menuHotel(database); // Call the menuHotel function to start the hotel management program

    return 0;
}
