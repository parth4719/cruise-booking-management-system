/**
 * @file booking.c
 *
 * @brief Helps in booking the tickets for various cruise packages provided in the "Details.csv".
 *
 * @author Spandana Manjappa Karehanumannara - kmspandanakarehanuma@cmail.carleton.ca
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/booking.h"
#include "../include/passenger_details.h"
#include "../include/package_availability.h"
#include "../include/suite_selection.h"
#include "../include/update_suite_selection.h"
#include "../include/add_passenger.h"
#include "../include/fare_calculation.h"
#include "../include/remove_passenger.h"
#include "../include/read_file.h"

int booking(void){
    int row_count=0;
    int column_count = 0;
    int line_count=0;
    int suite_length=0;
    int cruise_selected=0;
    int available=0;
    int continue_booking=0;
    int file_identity=0;
    char confirm_booking[6];
    char cancel_booking[6];
    int change_option=0;
    int cruise_sel_value=0;
    int no_of_pass_value=0;
	int add_value=0,remove_value=0;
    int temp=0;
    float total_fare = 0.0;
    static int no_of_pass=0;
    int no_of_pass_temp=0;
    static int room_booked[10]={0};
    char buf[1024];
    line_count = read_file(filename);
    FILE *fp;
    fp = fopen(filename, "r");
    if (!fp) {
        /**
         * If we fail to open the file, then we need to abort the program,
         * there is nothing to be done.
         */
        printf("Can't open the \"Details.csv\" in %s\n", __func__);
        exit(1);
    }
    /**
    * creats the array of package name, fare and available seats, with the size of line_count which is used to store the details read from the "Details.csv".
    */
    char *package_name[line_count];
    int fare[line_count];
    int total_seats[line_count];
    /**
    * Reads line by line from file pointed by fp
    */
    while(fgets(buf, 1024, fp)){
        column_count=0;
        ++row_count;
        if (row_count == 0)
            continue;
        char *file_data = strtok(buf, ",");
        while (file_data) {
            if(column_count==0){
                /**
                * The memory is allocated for package_name array and the values of package name column in the
                * "Details.csv" is stored in this array.
                */
                package_name[row_count-2] =(char *)malloc(sizeof(char)*strlen(file_data)+1);
                if(package_name== NULL){
                    printf("could not allocate memory for package name array\n");
                }
                strcpy(package_name[row_count-2],file_data);
            }
            if(column_count==1) {
                /**
                * The content of the Fare column in "Details.csv" is stored into integer array.
                */
                fare[row_count-2] = atoi(file_data);
            }
            if(column_count==2){
                /**
                * The content of the Total seats column in "Details.csv" is stored into integer array.
                */
               total_seats[row_count-2]= atoi(file_data);
            }
        file_data = strtok(NULL, ",");
        column_count++;
        }
        printf("\n");
    }
    fclose(fp);
    do{
        /**
        * Prints the available cruise options for the customer to choose from
        */
        printf("Which cruise package would you like to book among the following:\n");
        for(int i=0; i<row_count-1; i++){
            printf("%d. %s\n", i+1, package_name[i]);
        }
        label_select1:
                printf("\nPlease select one of the package: ");
				cruise_sel_value = scanf("%d", &cruise_selected);
				while(cruise_sel_value != 1 || cruise_selected>=row_count || cruise_selected <= 0){
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid input!! Please try entering valid number!");
					goto label_select1;
			    }

        /**
        * Taking the count of total passengers travelling for a particular cruise selected from the user.
        */
        label_select2:
                printf("\nPlease provide the total number of passengers travelling:");
                no_of_pass_value = scanf("%d", &no_of_pass);
                while(no_of_pass_value != 1 || no_of_pass <= 0){
                    while((temp=getchar()) != EOF && temp != '\n');
                    printf("Invalid input!! Please try entering valid number!");
                    goto label_select2;
                }
        /**
        * function called to check the availability for requested number of seats in the selected cruise
        */
        available = package_availability(cruise_selected, no_of_pass, total_seats);
        if(available == -1) {
            printf("Requested number of seats are available!\n");
            file_identity = passenger_details(no_of_pass);
			if(file_identity==-1){
				exit(0);
			}
            suite_length = suite_selection(no_of_pass, room_booked, cruise_selected);
            total_fare = fare_calculation(no_of_pass, fare[cruise_selected-1], cruise_selected, suite_length, room_booked);
            printf("\nYour Total fare is = %.2f CAD", total_fare);
        do{
            label_confirm:
                /**
                * Asking for the confirmation of booking from the user
                */
                printf("\nDo you want to confirm the booking? (yes/no):");
                scanf("%s",confirm_booking);
                while(strncmp(confirm_booking, "yes",3) && strncmp(confirm_booking, "no",2)){
                    printf("Invalid input! Please try entering (yes/no) in lower case only!\n");
                    goto label_confirm;
                }
                if(!strncmp(confirm_booking, "yes",3)){
                    printf("Booking is confirmed!\n");
                    printf("note: PLEASE KEEP A NOTE OF YOUR BOOKING ID, YOU NEED TO PROVIDE BOOKING ID FOR CANCELLING YOUR BOOKING\n");
                    printf("\nYour booking ID is %d\n",file_identity);
                    /**
                    * updates the available seats in "Details.csv".
                    */
                    update_seats(line_count, package_name, fare, total_seats);
                    /**
                    * updates the boooking details in "Bookings_info.csv".
                    */
                    write_into_file(suite_length, file_identity, cruise_selected, package_name, no_of_pass, total_fare, room_booked);
                    /**
                    * copies the content from "pass_temp.csv" into "passenger_details.csv" and "pass_temp.csv" is deleted.
                    */
                    add_pass();
                    /**
                    * updates the remaining rooms in the cruises in "suite_selection.csv" once the booking is confirmed.
                    */
                    update_suite_selection(room_booked, cruise_selected);
                }else{
                    label_cancel:
                        printf("\nDo you want to cancel booking? (yes/no):");
                        scanf("%s",cancel_booking);
                        while(strncmp(cancel_booking, "yes",3) && strncmp(cancel_booking, "no",2)){
                            printf("Invalid input! Please try entering again!\n");
                            goto label_cancel;
                        }
                    if(!strncmp(cancel_booking, "yes", 3)){
                        printf("Booking is cancelled!\n");
                        break;
                }else{
                    label_change:
                        /**
                        * Providing options to add passenger, remove passenger before confirmation of booking
                        */
                        printf("\nWhat among the following changes do you want to make? \n1.Add passenger\n2.Remove passenger\n");
                        scanf("%d",&change_option);
                        while(change_option<1 || change_option>2){
                             printf("Please enter a valid input\n");
                             goto label_change;
                        }
                        switch(change_option){
                            /**
                            * Taking the extra passenger information to be added to the booking.
                            */
                            case 1: add_label: 
									printf("\nWhat is the count of extra passengers you would like to add?");
                                    add_value=scanf("%d", &no_of_pass_temp);
									while(add_value != 1 || add_value > 100 || add_value<0){
										while((temp=getchar()) != EOF && temp != '\n');
										printf("Invalid input!! Please try entering valid number!");
										goto add_label;
									}
                                    no_of_pass = no_of_pass + no_of_pass_temp;
                                    available = package_availability(cruise_selected, no_of_pass, total_seats);
                                    if(available == -1) {
                                        printf("Requested number of seats are available!\n");
                                        add_passenger(no_of_pass_temp);
                                        break;
                                    }else{
                                        printf("Sorry:( %d seats are left\n",  available);
                                        }
                                    break;
                            case 2: remove: printf("How many number of passenger would you like to remove?");
                                    remove_value=scanf("%d",&no_of_pass_temp);
									while(remove_value != 1 || remove_value > 100 || remove_value<0){
										while((temp=getchar()) != EOF && temp != '\n');
										printf("Invalid input!! Please try entering valid number!");
										goto remove;
									}
                                    while(no_of_pass_temp>no_of_pass){
                                        printf("You have total of %d passengers in your booking\n",no_of_pass);
                                        goto remove;
                                    }
									if(no_of_pass_temp==no_of_pass){
										printf("All the passengers details are removed !!\n");
										goto label_select2;
									}
                                    /**
                                    * Prints the all the passengers in the booking and deletes the passenger name requested to be removed
                                    * by the user, it can delete one passenger at a time.
                                    */
                                    remove_passenger(no_of_pass_temp);
									total_seats[cruise_selected-1] += no_of_pass_temp;
                                    no_of_pass=no_of_pass-no_of_pass_temp;
                                    break;
                        }
                        printf("\nPlease select the rooms again for all the passengers!\n");
                        /**
                        * Initializing the room booked array to zero and asking to reselect the rooms for all the passengers in the booking.
                        */
                        for(int x=0;x<suite_length-1;x++){
                            room_booked[x]=0;
                        }
                        suite_length = suite_selection(no_of_pass, room_booked, cruise_selected);
                        total_fare = fare_calculation(no_of_pass, fare[cruise_selected-1], cruise_selected, suite_length, room_booked);
                        printf("\nYour Total fare is = %.2f CAD", total_fare);
                       }
                   }
             }while(strncmp(confirm_booking,"yes",3));
        }else{
            printf("\nSorry:( %d seats are left\n",  available);
        }
        printf("\nEnter '1' to continue booking else press '0': ");
        scanf("%d",&continue_booking);
        while(continue_booking<0 || continue_booking>1){
            printf("Oops invalid input!! Please try entering valid number!\n");
            printf("Enter '1' to continue booking else press '0': ");
            scanf("%d", &continue_booking);
        }
   }while(continue_booking == 1);
   return 0;
}