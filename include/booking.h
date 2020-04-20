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
 * @brief A Function to book tickets for different cruises.
 *
 * @details Funtion helps in booking the tickets for different cruise types.
 *
 *
 */
 int booking(void);

/**
*   File name
*/
 #define filename "Details.csv"


 #define storing_file "Bookings_info.csv"



/**
 * @brief Reads the file pointed by fp.
 *
 * @param[in] char *     File name as input parameter.
 *
 * @details The function reads the file passed as input and counts the number of rows in that file.
 *
 *
 * @return Retunrs integer, the number of rows in the file.
 */
int read_file(char *);


void add_pass();


void write_into_file(int row_count, int file_id, char *cruise_name, int no_of_pass, float total_fare, int *room_booked);

//void update_seats(int seats_in_cruises[], int row_count, struct package *cruise);



#endif



