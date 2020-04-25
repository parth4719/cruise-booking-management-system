/**
* @file main.h
*
* @brief A Function for starting the booking procedure.
*
* @author Vishnu Rajasekar - vishnurajasekar@cmail.carleton.ca
*
*/

#include<stdio.h>
#include<stdlib.h>

#include "../include/booking.h"
#include "../include/cancellation.h"

/**
* @brief A Function for starting the booking procedure.
*
* @details A Function to initiate the booking of the ticket process.
*/

int main(int argc, char *argv[]){
	int opt;

	while ((opt = getopt(argc, argv, "hat")) != -1){
		switch(opt){
            case 'h':
                    printf("-t will run all the unit tests\n");
                    printf("-r will run the main program\n");
                    return 0;
                    break;
            case 't':/* runs unit testing */
                    printf("\nRunning unit tests\n");
                  //  run_all_tests();
                    printf("\nTesting is completed !!\n");
                    return 0;
                    break;
            case 'r':
                    printf("Running Cruise Booking Management System\n");
                    int temp;
                    int option;
                    int option_value;
                    printf("************************************************************************************\n");
                    printf("******************                                                 *****************\n");
                    printf("**************      WELCOME TO  CRUISE BOOKING MANAGEMENT SYSTEM      **************\n");
                    printf("******************                                                 *****************\n");
                    printf("************************************************************************************\n\n");
                    printf("\nWhich among the following option would you like to select:\n1.Booking\n2.Cancellation of existing booking\n3.Exit\n");
                    printf("Please type '1' or '2' or '3':    ");
                    choose: option_value = scanf("%d", &option);
                    while(option_value != 1 || option>3 || option<1){
                        while((temp=getchar()) != EOF && temp != '\n'){}
                            printf("Invalid input!! Please try entering valid number!");
                            goto choose;
                        }
                    if(option == 1){
                        printf("\nThank you for choosing CBMS");
                        booking();
                    }else if(option == 2){
                        printf("\nWelcome again\n");
                        cancellation();
                    }else{
                        printf("\nHave a nice day");
                        exit(1);
                    }
		}
	}
}
