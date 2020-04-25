/**
* @file full_cancellation.h
*
* @brief Helps in cancelling the tickets.
*
* @author Thejprabhathrayasam thejprabhathrayasam@cmail.carleton.ca
*/

#ifndef FULL_CANCELLATION_H
#define FULL_CANCELLATION_H

/**
* Define the files passenger_details.csv and remove_pass.csv.
*/
#define fl1 "../src/passenger_details.csv"
#define fl2 "../src/remove_pass.csv"


/**
*@brief A Function to remove the passenger details.
*
*@param[in] id The booking id of the customer.
*
* @details Funtion helps in removing the details of the customers from the id given by them.
*
*/
void remove_passenger_details(int id);


/**
*@brief A Function to add  the suite selection details after the cancellation is done.
*
*@param[in] cruise_number The cruise number selected by the customer.
*
*@param[in] rooms The type of room selected by the customer.
*
* @details Funtion helps in increasing the suite count after the cancellation process is done.
*
*/
void add_suite_selection(int cruise_number, int *rooms);


/**
*@brief A Function to add  the passenger count after the cancellation is done.
*
*@param[in] cruise_number The cruise number selected by the customer.
*
*@param[in] pass_count The number of the passenger count selected by the customer.
*
* @details Funtion helps in increasing the passenger count after the cancellation process is done.
*
*/
void add_details(int cruise_number, int pass_count);


/**
*@brief A Function to remove the booked ticket of the passenger.
*
*@param[in] id The booking id of the customer.
*
* @details Funtion helps in removing the booked ticket of the passenger from the id that is given.
*
*/
void remove_booking(int id);

#endif /* FULL_CANCELLATION_H */



