/**
 *  @file fare_calculation.h
 *
 * @brief A function to calculate the total fare of a booking made by a user.
 *
 * @author Swetha Meenakshi Natarajan - swethameenakshinatar@cmail.carleton.ca
 */

#ifndef FARE_CALCULATION_H
#define FARE_CALCULATION_H

#define ftname "../src/pass_temp.csv"
#define f1name "../src/age_group_discount.csv"
#define f2name "../src/group_size_discount.csv"
#define f3name "../src/disability_discount.csv"

 /**
  * @brief      Calculates the total fare of a booking
  *
  * @param[in]  no_of_pass          Number of passengers in the booking
  *
  * @param[in]  package_fare        Array of the fares for the available cruises read from the file
  *
  * @details    Function takes the number of passengers for the cruise selected, the cruise fare, the types of rooms selected,
  * the fares and discounts for different types of rooms as input
  * and applies discounts for specially abled, different age groups of passengers and group size to calculate the total fare of that booking
  *
  * @return     Returns the total fare of the booking
  */

 float fare_calculation(int no_of_pass, int package_fare, int cruise_selected, int suite_length, int *room_booked);


#endif /* FARE_CALCULATION_H */


