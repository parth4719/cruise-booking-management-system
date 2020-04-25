/**
 *  @file refund_calculation.h
 *
 * @brief A function to calculate the refund for cancelled tickets
 *
 * @author Swetha Meenakshi Natarajan - swethameenakshinatar@cmail.carleton.ca
 */

 #ifndef REFUND_CALCULATION_H
 #define REFUND_CALCULATION_H


 #define f  "../src/Bookings_info.csv"
 #define f1 "../src/passenger_details.csv"

 /**
  * @brief      Calculates the refund for cancellation
  *
  * @param[in]  pass_count      Number of passengers in the booking
  *
  * @param[in]  total_fare      Total fare of the booking
  *
  * @param[in]  id              Booking ID of ticket to be cancelled
  *
  * @param[in] cruise_number Cruise number entered by the customer
  *
  * @param[in] rooms The room type entered by the customer
  *
  * @details    Function takes the booking details and calculates the cancellation fee and refund for cancelling the tickets
  */

 void refund_calculation(int pass_count, float total_fare, int id, int cruise_number, int rooms[]);

 #endif /* REFUND_CALCULATION_H */



