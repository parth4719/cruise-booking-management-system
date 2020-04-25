/**
 * @file package_availability.c
 *
 * @brief A Function to check the availability of seats in the particular cruise opted by the customer.
 *
 * @author Spandana Manjappa Karehanumannara - kmspandanakarehanuma@cmail.carleton.ca
 *
 */


#include<stdio.h>
#include<stdlib.h>
#include "../include/package_availability.h"

/**
* @brief Checks the availability of seats in the cruise.
*
* @param[in] cruise_selected     The type of cruise selected for booking.
* @param[in] no_of_pass          Total number of passengers travelling in one booking.
* @param[in] array of total seats    Array of total number of seats available in all the cruise types.
*
* @details Function takes the selected cruise type, number of passengers and total numbers of seats in all the cruise as input,
* and checks the seat availability for number of passengers provided in the particular selected cruise type.
*
*
* @return If seats available returns -1, if seats are not available returns the count of remaining available seats in the cruise.
*/

int package_availability(int cruise_selected,  int no_of_pass, int total_seats[]){
    /**
    * Returns -2 if invalid parameters are provided to the function.
    */
    if(cruise_selected<=0 || no_of_pass <=0 || (total_seats==NULL)){
        printf("%s: Invalid input to the function \n",__func__);
        return -2;
    }
    if(no_of_pass <= total_seats[cruise_selected-1]){
        total_seats[cruise_selected-1] -= no_of_pass;
        /**
         Returns -1 if seats are available in the selected cruise.
        */
        return -1;
    }else{
        /**
        returns the count of remaining number of seats available in the selected cruise.
        */
        return total_seats[cruise_selected-1];
    }
}


