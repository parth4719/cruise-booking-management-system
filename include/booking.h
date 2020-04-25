/**
 * @file booking.h
 *
 * @brief A Function for booking different cruise types.
 *
 * @author Spandana Manjappa Karehanumannara - kmspandanakarehanuma@cmail.carleton.ca
 *
 */

#ifndef BOOKING_H
#define BOOKING_H


/**
*   File name containg the details of bookings confirmed.
*/
#define storing_file "../src/Bookings_info.csv"




/**
*   File name containg the details of cruise name, total fare and available seats.
*/
#define filename "../src/Details.csv"



/**
 * @brief A Function to book tickets for different cruises.
 *
 * @details Funtion helps in booking the tickets for different cruise types.
 *
 *
 */
 int booking(void);


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



/**
 * @brief This function replace the content from "pass_temp.csv" into "passenger_details.csv".
 *
 * @details This function copies the content from "pass_temp.csv" and stores in "passenger_details.csv" , and deletes the "pass_temp.csv".
 *
 */
void add_pass();



/**
 * @brief This function updates the available seats column in "Details.csv" each time the booking is confirmed.
 *
 * @param[in] row_count The count of no. of rows in the "Detials.csv".
 *
 * @param[in] file_id The row value of the first passenger belonging to particular booking stored in "passenger_details.csv".
 *
 * @param[in] cruise_selected  The number of cruise selected.
 *
 * @param[in] cruise_name The name of the cruise selected.
 *
 * @param[in] no_of_pass  the total number of passengers in the specific booking.
 *
 * @param[in] total_fare  the total fare value of specific booking.
 *
 * @param[in] room_booked  The array contaning the no. of rooms booked and types of rooms booked of specific booking.
 *
 * @details After the booking is confirmed this function is called to store the all the booking details into "Bookings_info.csv".
 *
 */
void write_into_file(int suite_length, int file_id, int cruise_selected, char *package_name[], int no_of_pass, float total_fare, int *room_booked);


#endif
