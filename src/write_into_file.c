/**
 * @file write_into_file.c
 *
 * @brief Helps in updating the seat availability  in the "Details.csv"
 *
 * @author Spandana Manjappa Karehanumannara - kmspandanakarehanuma@cmail.carleton.ca
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/booking.h"
#include "../include/write_into_file.h"
#define storing_file "../src/Bookings_info.csv"

/**
* @brief This function updates the available seats column in "Details.csv" each time the booking is confirmed.
*
* @param[in] row_count The count of no. of rows in the "Detials.csv".
*
* @param[in] file_id The row value of the first passenger belonging to particular booking stored in "passenger_details.csv".
*
* @param[in] cruise_selected  The number of cruise selected.
*
* @param[in] cruise_name The name of the cruise selected.
*
* @param[in] no_of_pass  the total number of passengers in the specific booking.
*
* @param[in] total_fare  the total fare value of specific booking.
*
* @param[in] room_booked  The array contaning the no. of rooms booked and types of rooms booked of specific booking.
*
* @details After the booking is confirmed this function is called to store the all the booking details into "Bookings_info.csv".
*
*/

void write_into_file(int suite_length, int file_id, int cruise_selected, char *package_name[], int no_of_pass, float total_fare, int *room_booked){
    FILE *fp=fopen(storing_file,"a");
    if(fp == NULL){
        /**
        * If we fail to open the file, then we need to abort the program,
        * there is nothing to be done.
         */
        printf("Can't open the file \"Bookins_info.csv\" in %s\n",__func__);
        exit(0);
    }
    /**
    * Storing the details into the "bookings_info.csv" file
    */
    fprintf(fp,"%d,%d,%s,%d,%f,",file_id, cruise_selected, package_name[cruise_selected-1], no_of_pass, total_fare);
    for(int i=0;i<suite_length-1;i++){
        fprintf(fp,"%d,",room_booked[i]);
    }
    fprintf(fp,"\n");
    fclose(fp);
}

