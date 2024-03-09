 /*
* File: air_control.h
* Author: Tran Nhat Thai
* Date: 8/03/2024
* Description: Header file for air control functions.
*/

#ifndef AIR_CONTROL_H
#define AIR_CONTROL_H

#include <mutex>

typedef enum {
    INCREASE,
    DECREASE,
    OFF
} Air_condition_status;

typedef enum {
    AIR_MODE_ON,
    AIR_MODE_OFF
} Air_mode;

// Declare variables and functions defined in air_control.cpp
extern std::mutex mtx_sensor_outside, mtx_sensor_inside, mtx_cout, mtx_sensor_wind, mtx_key_input;
extern double sensor_outside;
extern double sensor_inside;
extern int sensor_wind;
extern double temp_display;
extern int wind_display;
extern Air_condition_status air_status;
extern Air_mode air_mode;

/*
* Function: display_air_condition
* Description: Display the operating status of the air conditioner
* Input:   
* Output:  return: 
*/
void display_air_condition();

#endif // AIR_CONTROL_H
