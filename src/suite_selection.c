/**
 * @file suite_selection.c
 *
 * @brief A Function to book the different suite types in cruises.
 *
 * @author Vishnu Rajasekar - vishnurajasekar@cmail.carleton.ca
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/suite_selection.h"
#include "../include/read_file.h"


/**
* @brief Helps in booking different types of rooms for all the cruises.
*
* @param[in] no_of_passengers The number of passengers to travel
*
* @param[in] room_booked   the room booked in the cruises.
*
* @param[in] cruise_selected The cruise selected by the passenger.
*
* @details User will be given options to select among different room types aviailable in all the cruises.
*
*/

int suite_selection(int no_of_pass,int *room_booked,int cruise_selected){
    /**
     * Checking if the number of the passengers,rooms booked or cruise selected is less than zero.
     */
     if(no_of_pass <=0 || (room_booked==NULL) || cruise_selected<0){
        printf("%s: Invalid input to the function \n",__func__);
        return -1;
    }
    int temp;
    int suite_selected_value;
    int row_count=0;
    int column_count=0;
    char buf[1024];
    int suite_selected;
    char confirm_booking[10];
    int line_count =0;
    char name[50]="../src/";
	char str[30];
    /**
    *Displaying the suites that are available.
     */
    snprintf(str, 30, "%d", cruise_selected);
    strcat(str,"suite_selection.csv");
    strcat(name,str);
    line_count = read_file(name);
    char *suite_name[line_count];
    int room_count[line_count];
    int room_capacity[line_count];
    FILE *fp=fopen(name,"r");
    if(!fp){
        /**
        * If we fail to open the file, then we need to abort the program,
        * there is nothing to be done.
        */
        printf("cant open suite_selection.csv\n");
        return -1;
    }
    /**
    * Reads line by line from file pointed by fp
    */
    while(fgets(buf, 1024, fp)){
        column_count=0;
        row_count++;
        if (row_count == 1){
            continue;
        }
        char *file_data = strtok(buf, ",");
        while (file_data){
            if(column_count==0){
                suite_name[row_count-2] =(char *)malloc(sizeof(char)*strlen(file_data)+1);
                strcpy(suite_name[row_count-2],file_data);
            }
            if(column_count==1)
            {
               room_count[row_count-2] = atoi(file_data);
            }
            if(column_count==2)
            {
               room_capacity[row_count-2] = atoi(file_data);
            }
        file_data = strtok(NULL, ",");
        column_count++;
        }
    }
    fclose(fp);
    label:do{
    /**
    * Prints the available room options for the customer to choose from
    */
        printf("\nWhich suite would you like to book among the following for %d people:\n",no_of_pass);
        for(int i=0; i<row_count-1; i++){
            printf("%d. %s -- %d rooms available\n", i+1, suite_name[i], room_count[i]);
        }
        suite_label: printf("\nPlease select one of the suite: ");
        suite_selected_value = scanf("%d", &suite_selected);
        while(suite_selected_value != 1 || suite_selected <= 0 || suite_selected>=row_count){
            while((temp=getchar()) != EOF && temp != '\n');
            printf("Invalid choice\n");
            goto suite_label;
        }
        printf("Rooms remaining = %d\n",room_count[suite_selected-1]);
        if(room_count[suite_selected-1]>0){
            printf("\nDo you want %s room?(yes/no) :",suite_name[suite_selected-1]);
            scanf("%s",confirm_booking);
            if( strcmp( confirm_booking, "yes") == 0 ){
                /**
                *Booking the type of the suite that was elected by the passenger.
                *Makes sure that all the passengers are booked under a room.
                 */
                if(no_of_pass>room_capacity[suite_selected-1]){
                    printf("\nBooking is confirmed for %d members!\n",room_capacity[suite_selected-1]);
                    room_booked[suite_selected-1]++;
                    room_count[suite_selected-1]--;
                    no_of_pass=no_of_pass-room_capacity[suite_selected-1];
                    printf("\nPlease book the suite for %d people.\n",no_of_pass);
                    /**
                    *Loops until all the passengers are booked.
                     */
                    goto label;
                }
                else{
                    /**
                    *Reducing the total rooms available and incresing the overall booking count.
                     */
                    printf("\nSuite Booking is confirmed !!\n");
                    room_booked[suite_selected-1]++;
                    room_count[suite_selected-1]--;
                    return line_count;
                }
            }else{
                /**
                *Allowing the passengers to select a different suite.
                 */
                printf("\nPlease select the suites again:\n");
                room_booked[suite_selected-1]--;
                goto label;
            }
        }else{
            /**
            *Informing of the unavailablity of the suite.
             */
            printf("\nSelected suite is not available. Please select another suite\n");
            goto label;
        }

    }while(1);
}
