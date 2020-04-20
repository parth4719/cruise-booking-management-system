/**
 * @file add_passenger.h
 *
 * @brief This function add the extra passenger details into the file "pass_temp.csv".
 *
 * @author Spandana Manjappa Karehanumannara - kmspandanakarehanuma@cmail.carleton.ca
 *
 */

#ifndef ADD_PASSENGER_H
#define ADD_PASSENGER_H

/**
 * @brief Adds the details of the passengers to "pass_temp.csv" file.
 *
 * @param[in] no_of_passengers The extra number of passengers to be added for the booking
 *
 * @details Stores the passenger details consists of the 1.Name 2.Age 3.Gender 4.Email 5.Disability into an
 * individual rows for every passenger into "pass_temp.csv" file.
 *
 */
void add_passenger(int no_of_passengers);

#endif
