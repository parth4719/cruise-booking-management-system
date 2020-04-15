/**
 * @file passenger_details.h
 *
 * @brief Reading the details of the passengers and storing the details into "passenger_details.csv" file
 *
 * @author Thejprabahth Rayasam- thejprabhathrayasam@cmail.carleton.ca
 */

#ifndef passenger_details_h
#define passenger_details_h

/**
* Declaring the name of the csv file
*/
#define filename "passenger_details.csv"

/**
 * @brief Adds the details of the passengers to "passenger_details.csv" file
 *
 * @param[in] no_of_passengers The number of passengers to travel
 *
 * @details Stores the passenger details consists of the 1.Name 2.Age 3.Gender 4.Email 5.Disability into an
 * individual rows for every passenger into "passenger_details.csv" file.
 *
 * @return The number of the row of the first passenger of the booking in the csv file
 */
int passenger_details(int no_of_passengers);

#endif /* passenger_details_h */
