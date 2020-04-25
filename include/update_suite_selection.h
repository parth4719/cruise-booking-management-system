/**
 * @file update_suite_selection.h
 *
 * @brief Helps in updating the suite selected to the csv file to keep count of the rooms booked.
 *
 * @author Spandana Manjappa Karehanumannara - kmspandanakarehanuma@cmail.carleton.ca
 *
 */

#ifndef UPDATE_SUITE_SELECTION_H
#define UPDATE_SUITE_SELECTION_H

/**
 * @brief Function updates the rooms count into the suite_selection.csv of selected cruise,everytime the booking is confirmed.
 *
 * @param[in] room_booked[] array of room booked in the cruises.
 *
 * @param[in] cruise_selected the cruise selected value.
 *
 * @details Function updates the rooms count into the suite_selection.csv of selected cruise,everytime the booking is confirmed.
 *
 */
void update_suite_selection(int *room_booked, int cruise_selected);


#endif /*UPDATE_SUITE_SELECTION_H*/


