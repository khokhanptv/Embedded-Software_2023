 /*
* File: main.cpp
* Author: Tran Nhat Thai
* Date: 8/03/2024
* Description:  Description: This file contains the main function of the program. It initializes threads for input, sensor monitoring, air conditioner control,
 fan control, and display. It also provides user options and handles program logic.
*/





#include "air_control.h"
#include "display.h"
#include "input.h"
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int main() {
    // Initialize threads
    thread thread_input_key(inputKey);
    thread thread_sensor_outside(display_sensor_outside);
    thread thread_sensor_inside(display_sensor_inside);
    thread thread_fan(display_fan);
    thread thread_air_condition(display_air_condition);
    thread thread_display(display);

    // Print user options
    cout << "-------------BUTTON------------------" << endl;
    cout << "1. Increase temperature " << endl;
    cout << "2. Decrease temperature " << endl;
    cout << "3. Increase wind level " << endl;
    cout << "4. Decrease wind level " << endl;
    cout << "5. Turn on air mode " << endl;
    cout << "6. Turn off air mode " << endl;

    while (1) {
        // Program logic here
    }

    // Wait for threads to finish before exiting
    thread_input_key.join();
    thread_display.join();
    thread_air_condition.join();
    thread_fan.join();
    thread_sensor_inside.join();
    thread_sensor_outside.join();

    return 0;
}
