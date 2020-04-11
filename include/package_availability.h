/**
 * @file package_availability.h
 *
 * @brief A Function to check the availability of seats in the particular cruise opted by the customer.
 *
 * @author Spandana Manjappa Karehanumannara - kmspandanakarehanuma@cmail.carleton.ca
 *
 */


#ifndef PACKAGE_AVAILABILITY_H
#define PACKAGE_AVAILABILITY_H


 /**
 * @brief Checks the availability of seats in the cruise.
 *
 * @param[in] cruise_selected     The type of cruise selected for booking.
 * @param[in] no_of_pass          Total number of passengers travelling in one booking.
 * @param[in] array of integer    Array of total number of seats available in all the cruise types.
 *
 * @details Function takes the selected cruise type, number of passengers and total numbers of seats in all the cruise as input,
 * and checks the seat availability for number of passengers provided in the particular selected cruise type.
 *
 *
 * @return If seats available returns -1, if seats are not available returns the count of remaining available seats in the cruise.
 */
int package_availability(int cruise_selected, int no_of_pass,int []);


#endif
