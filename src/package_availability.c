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
#include "package_availability.h"



int package_availability(int cruise_selected,  int no_of_pass, int seats_in_cruises[]){
    if(no_of_pass <= seats_in_cruises[cruise_selected+1]){
        seats_in_cruises[cruise_selected+1] -= no_of_pass;
        /*
         Returns -1 if seats are available in the selected cruise.
        */
        return -1;
    }else
    {
        /*
        returns the count of remaining number of seats available in the selected cruise.
        */
        return seats_in_cruises[cruise_selected+1];
    }
}

