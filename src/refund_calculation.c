/**
 * @file refund_calculation.c
 *
 * @brief A function to calculate the refund for cancelled tickets
 *
 * @author Swetha Meenakshi Natarajan - swethameenakshinatar@cmail.carleton.ca
 */

 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #include "../include/refund_calculation.h"
 #include "../include/full_cancellation.h"


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

 void refund_calculation(int pass_count, float total_fare, int id, int cruise_number, int rooms[]) {
	/**
    * Initializing the variables
    */
    int c=0, continue_cancel=0;
    int reply=0;
    float refund = 0.0, cancel_charge = 0.0;
    int no_of_pass=pass_count;

    do {
        /**
        * Getting user choice
        */
        redo: printf("\nPlease choose your option:\n1.Full Cancellation\n2.Partial Cancellation\n");
        scanf("%d", &c);
		printf("\nPlease choose your option:\n1.Full Cancellation\n2.Partial Cancellation\n");
        while(c<1 || c>2) {
            printf("Please choose valid option.");
            goto redo;
        }
        /**
        * Performing operation based on user choice
        */
        switch(c) {
            case 1:
                /**
                * Performing full cancellation
                */
                cancel_charge = (0.4 * total_fare);
                refund = (total_fare - cancel_charge);
                printf("\nThe cancellation fee is %.2lf CAD and the eligible refund is %.2lf CAD for your booking\n",cancel_charge,refund);
                printf("\nDo you want to proceed with cancellation? Press 1 for yes/0 for no:\n");
                scanf("%d", &reply);
				while(reply>1 || reply<0){
                    printf("Please choose valid option  ");
                    scanf("%d", &reply);
                }
                if(reply==1){
                    add_suite_selection(cruise_number,rooms);
                    add_details(cruise_number,no_of_pass);
                    remove_booking(id);
                    printf("\nBooking is cancelled");
                }
                else {
                    printf("\nEnter '1' to continue with cancellation else enter '0'    ");
                    scanf("%d", &continue_cancel);
                    while(continue_cancel>1 || continue_cancel<0) {
                        printf("Please choose valid option  ");
                        scanf("%d", &continue_cancel);
                    }
                }
                break;

        }
    } while(continue_cancel == 1);
 }

