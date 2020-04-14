/**
 * @file booking.c
 *
 *
 * @author Spandana Manjappa Karehanumannara - kmspandanakarehanuma@cmail.carleton.ca
 *
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include "booking.h"
#include "package_availability.h"
#include "passenger_details.h"


int read_file(char *file){
    char c[1024];
    int count=0;
    FILE *fp = fopen(file, "r");
    if (!fp) {
        /*
         * If we fail to open the file, then we need to abort the program,
         * there is nothing to be done.
         */
        printf("Can't open file\n");
        exit(1);
    }
    while(fgets(c, 1024, fp)!=NULL)
	{
	 count++;
	}
	return count;
    fclose(fp);
}

int booking(void) {
    /*
    * Initializing local variables
    */
    char buf[1024];
    int i=0;
    int column_count=0;
    int row_count=0;
    int cruise_selected=0;
    int no_of_pass=0;
    int available=0;
    int continue_booking=0;
    int booking_id;
    char confirm_booking[6];
    char cancel_booking[6];
    int change_option;
    int line_count =0;


    line_count = read_file(filename);

    /*
    * Opening the file to read the details of all cruise types.
    */
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        /*
         * If we fail to open the file, then we need to abort the program,
         * there is nothing to be done.
         */
        printf("Can't open file\n");
        exit(1);
    }

    /*
    * Allocating memory for array of structures
    */
    struct package *cruise = (struct package *)malloc(sizeof(struct package *) * line_count);
    if(!cruise){
        fprintf(stderr, "Could not allocate the array of struct record \n ");
        exit(1);
    }

    /*
    * Reads line by line from file pointed by fp
    */
    while (fgets(buf, 1024, fp)) {
        column_count=0;
        row_count++;

        if (row_count == 0)
            continue;

        char *file_data = strtok(buf, ",");
        while (file_data) {
            if(column_count==0) {
                /*
                * Allocating memory for structure member package_name
                */
                cruise[row_count].package_name =(char *)malloc(80);
                /*
                *   data read from 1st column of every row in the file is stored into structure member package_name
                */
                strcpy(cruise[row_count].package_name,file_data);
            }
            if(column_count==1) {
                /*
                * Allocating memory for structure member fare
                */
                cruise[row_count].fare = (int *)malloc(sizeof(int));
                /*
                * data read from 2nd column of every row in the file is stored into structure member fare.
                */
                *cruise[row_count].fare = atoi(file_data);
            }
            if(column_count==2){
                /*
                * Allocating memory for structure member total_seats
                */
                cruise[row_count].total_seats = (int *)malloc(sizeof(int));
                /*
                *   data read from 3rd column of every row in the file is stored into structure member total_seats.
                */
                *cruise[row_count].total_seats = atoi(file_data);
            }
        file_data = strtok(NULL, ",");
        column_count++;
        }
        printf("\n");
    }
    fclose(fp);
    int seats_in_cruises[row_count];

    /*
    * Making a copy of all the structure member total_seats into an new integer array seats_in_cruises[]
    */
    for(i=2;i<=row_count;i++){
        seats_in_cruises[i]= *cruise[i].total_seats;
    }
    do{
        /*
        * Prints the available cruise options for the customer to choose from
         */
        system ("cls");
        printf("Which cruise package would you like to book among the following:\n");
        for(i=2; i<=row_count; i++){
            printf("%d. %s\n", i-1, cruise[i].package_name);
        }
        printf("\nPlease select one of the package: ");
        scanf("%d", &cruise_selected);

        /*
        * Taking the count of total passengers travelling for a particular cruise selected
        */
        printf("\nPlease provide the total number of passengers travelling: ");
        scanf("%d", &no_of_pass);

        /*
        * function called to check the availability for requested number of seats in the selected cruise
        */
        available = package_availability(cruise_selected, no_of_pass, seats_in_cruises);
        if(available == -1) {
            printf("Requested number of seats are available!\n");
            booking_id = passenger_details(no_of_pass);
            /*
            * To Do -- call funtions suite_selection and fare_calcultion
            */
            do{
                printf("\nDo you want to confirm the booking? (yes/no):  ");
                scanf("%s",confirm_booking);
                if( strcmp( confirm_booking, "yes") == 0 ){
                    printf("Booking is confirmed!\n");
                    printf("Your booking ID is: %d", booking_id);
                    break;
                }else{
                    printf("\nDo you want to cancel booking? (yes/no):   ");
                    scanf("%s",cancel_booking);
                    if( strcmp( cancel_booking, "yes") == 0 ){
                        printf("Booking is cancelled\n");
                        /*
                        * To Do need to delete all the details of that particular booking ID
                        */
                        break;
                    }else{
                       printf("\nWhat among the following changes do you want to make? \n1.Add passenger\n2.Remove passenger\n3.Room changes\n");
                       scanf("%d",&change_option);
                       switch(change_option){
                            case 1: printf("\nWhat is the count of extra passengers you would like to add?");
                                    scanf("%d",&no_of_pass);
                                    available = package_availability(cruise_selected, no_of_pass, seats_in_cruises);
                                    if(available == -1){
                                        printf("Requested number of seats are available!\n");
                                        booking_id = passenger_details(no_of_pass);
                                        /*
                                        * To Do -- add funtions suite_selection and fare_calcultion
                                        */
                                        break;
                                    }else{
                                         printf("Sorry:( %d seats are left\n",  available);
					 printf("Do you want to continue with existing booking? Press '1' to contiue '0' to exit.");
                                         scanf("%d",&continue_booking);
                                         if(continue_booking){
                                            /*
					    *  TO DO -- Call fair_calculation function
					    */
                                            break;
                                         }else{
                                             printf("Thankyou..See you again!\n");
                                             break;
                                         }
                                    }
                            case 2: printf("What is the name of the passenger you would like to remove? \n");
                                    /*
                                    * TO DO call funtion to remove passsengers
                                    */
                                    break;
                            case 3: printf("Make room changes\n");
                                    /*
                                    * TO DO call suite_selection function
                                    */
                                    break;
                      }
                   }
               }
             }while(strcmp( confirm_booking, "yes") != 0);
        }else{
            printf("Sorry:( %d seats are left\n",  available);
        }
        printf("\nEnter '1' to continue booking else press '0': ");
        scanf("%d",&continue_booking);
        }while(continue_booking == 1);
    return 0;
}


