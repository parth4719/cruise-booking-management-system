/**
*  @file delete_passenger.h
*
* @brief A function to calculate the refund for cancelled tickets
*
* @author Swetha Meenakshi Natarajan - swethameenakshinatar@cmail.carleton.ca
*/

#ifndef DELETE_PASSENGER_H
#define DELETE_PASSENGER_H


#define f  "../src/Bookings_info.csv"
#define f1 "../src/passenger_details.csv"

/**
 * @brief      Function to delete the records of selected passengers
 *
 * @param[in]  pass_count      Number of passengers in the booking
 *
 * @param[in]  no_of_pass      Number of passengers to be deleted
 *
 * @param[in]  id              Booking ID of ticket to be cancelled
 *
 * @details    Function takes the booking id, number of passengers in booking and number of passengers to be deleted
 *             to delete the record of passengers
 */
 void delete_passenger(int no_of_pass, int pass_count, int id);

#endif /* DELETE_PASSENGER_H */


