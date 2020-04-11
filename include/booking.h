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

 /**
 * @brief Structure to store cruise details
 *
 * @details Structure package stores package name, fare per person and total no. of seats availavle in the cruise type.
 *
 */
struct package{
    char *package_name;
    int *fare;
    int *total_seats;
}cruise;


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

#endif
