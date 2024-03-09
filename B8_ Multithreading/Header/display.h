/*
* File: display.h
* Author: Tran Nhat Thai
* Date: 8/03/2024
* Description: Header file for display functions.
*/

#ifndef DISPLAY_H
#define DISPLAY_H

extern double temp_display;
extern int wind_display;
extern Air_mode air_mode;

/*
* Function: display
* Description: Display the current temperature, wind level, and air mode
* Input:   
* Output:  return: 
*/
void display();

/*
* Function: display_fan
* Description: Display the current wind level
* Input:   
* Output:  return: 
*/
void display_fan();

/*
* Function: display_sensor_inside
* Description: Display the temperature inside the room
* Input:   
* Output:  return: 
*/
void display_sensor_inside();

/*
* Function: display_sensor_outside
* Description: Display the temperature outside the room
* Input:   
* Output:  return: 
*/
void display_sensor_outside();

#endif // DISPLAY_H
