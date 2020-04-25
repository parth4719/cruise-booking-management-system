/**
 * @file update_seats.h
 *
 * @brief A Function for booking different cruise types.
 *
 * @author Spandana Manjappa Karehanumannara - kmspandanakarehanuma@cmail.carleton.ca
 *
 */

#ifndef UPDATE_SEATS_H
#define UPDATE_SEATS_H

/**
* @brief This function updates the available seats column in "Details.csv" each time the booking is confirmed.
*
* @param[in] row_count The count of no. of rows in the "Detials.csv".
*
* @param[in] *package_name[] The array of strings containing the packages names of all the cruises read from "Details.csv".
*
* @param[in] fare The integer array containing total fare of all the packages.
*
* @param[in] total seats The integer array containing the value of available seats in all the cruises.
*
* @details Everytime the booking is confirmed this function is called to update the available seats column in "Details.csv"
*
*/
void update_seats(int row_count,char *package_name[], int fare[], int total_seats[]);

#endif /* UPDATE_SEATS_H */
