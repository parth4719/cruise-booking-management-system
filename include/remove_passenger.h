/**
 * @file remove_passenger.h
 *
 * @brief This function removes the passenger details from the file "pass_temp.csv".
 *
 * @author Thejprabhath Rayasam - thejprabhathrayasam@cmail.carleton.ca
 *
 */

#ifndef REMOVE_PASSENGER_H
#define REMOVE_PASSENGER_H


/**
 * @brief Removes the details of the passengers from "pass_temp.csv" file.
 *
 * @param[in] no_of_pass The number of passengers that needs to be removed for the booking
 *
 * @details Removes the passenger details consists of the 1.Name 2.Age 3.Gender 4.Email 5.Disability from "pass_temp.csv" file.
 *
 */
void remove_passenger(int no_of_pass);

#endif /* REMOVE_PASSENGER_H */


