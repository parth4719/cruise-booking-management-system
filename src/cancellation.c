/**
* @file cancellation.c
*
* @brief A function to cancel existing booking
*
* @author Spandana Manjappa Karehanumannara - kmspandanakarehanuma@cmail.carleton.ca
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/cancellation.h"
#include "../include/refund_calculation.h"
#include "../include/display_booking_details.h"

/**
* @brief A function to cancel existing booking
*
* @details Function helps in cancelling the tickets that are already booked
*/

void cancellation() {
    int id=0, pass_count=0,cruise_number=0;
    char way[5];
    int rooms[20]={0};
    float total_fare=0;
    /**
    *Getting the booking id to cancel the ticket.
     */
    printf("Please provide your booking ID: ");
    scanf("%d",&id);
    /**
    *Displaying the booking details of the customer.
    */
    display_booking_details(&id, &pass_count, &total_fare, &cruise_number, rooms);
    /**
    *Confirming to proceed with the cancellation.
     */
    printf("\nDo you want to proceed with cancellation? (yes/no): ");
    scanf("%s", way);
    /**
    * Calculating the refund amount.
    */
    if(strncmp(way, "no", 2)) {
        refund_calculation(pass_count, total_fare, id, cruise_number, rooms);
    }
    else {
        printf("Have a nice day");
        exit(0);
    }
}
