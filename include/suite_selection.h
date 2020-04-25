/**
 * @file suite_selection.h
 *
 * @brief A Function to book the different suite types in cruises.
 *
 * @author Vishnu Rajasekar - vishnurajasekar@cmail.carleton.ca
 *
 */

#ifndef SUITE_SELECTION_H
#define SUITE_SELECTION_H

/**
 * @brief Helps in booking different types of rooms for all the cruises.
 *
 * @param[in] no_of_passengers The number of passengers to travel
 *
 * @param[in] room_booked      The array room booked in the cruises.
 *
 * @param[in] cruise_selected  The cruise selected by the passenger.
 *
 * @details User will be given options to select among different room types aviailable in all the cruises.
 *
 */
int suite_selection(int no_of_pass,int *room_booked,int cruise_selected);


#endif /* SUITE_SELECTION_H*/


