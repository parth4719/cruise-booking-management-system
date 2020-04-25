/**
* @file write_into_file.h
*
* @brief Helps in updating the seat availability in the "Details.csv".
*
* @author Spandana Manjappa Karehanumannara - kmspandanakarehanuma@cmail.carleton.ca
*/


#ifndef WRITE_INTO_FILE_H
#define WRITE_INTO_FILE_H

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

#endif /* WRITE_INTO_FILE_H */
