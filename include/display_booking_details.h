/**
* @file: display_booking_details.h
*
* @brief: A function to read  and display the booking details.
*
* @author: vishnurajasekar@cmail.carleton.ca
*
*/

#ifndef DISPLAY_BOOKING_DETAILS.H
#define DISPLAY_BOOKING_DETAILS.H

/**
* @brief Reads the booking id obtained from user
*
* @param[in] id Booking ID obtained from user
*
*@param[in] pass_count The passenger count from the user
*
*@param[in] total_fare The integer array containing total fare of all the packages.
*
*@param[in] cruise_number The cruise number selected by the user
*
*@param[in] rooms The rooms that are available.
*
* @details Function displays booking details corresponding to booking ID obtained from user after reading the details from the file "Bookings_info.csv"
*/
void display_booking_details(int *id, int *pass_count, float *total_fare, int *cruise_number, int *rooms);

#endif /* DISPLAY_BOOKING_DETAILS */
