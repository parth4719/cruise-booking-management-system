/**
 * @file update_seats.c
 *
 * @brief Helps in updating the total seats available in the "Details.csv"
 *
 * @author Spandana Manjappa Karehanumannara - kmspandanakarehanuma@cmail.carleton.ca
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/booking.h"
#include "../include/update_seats.h"
#define filename "../src/Details.csv"

/**
* @brief This function updates the available seats column in "Details.csv" each time the booking is confirmed.
*
* @param[in] row_count The count of no. of rows in the "Detials.csv".
*
* @param[in] *package_name[] The array of strings containing the packages names of all the cruises read from "Details.csv".
*
* @param[in] fare The integer array containing total fare of all the packages.
*
* @param[in] total seats The integer array containing the value of available seats in all the cruises.
*
* @details Everytime the booking is confirmed this function is called to update the available seats column in "Details.csv"
*
*/

void update_seats(int row_count, char *package_name[], int fare[], int total_seats[]){
    /**
    *   Function updates the available seats column in the "Details.csv"
    */
    FILE *fp;
    char *name="Package Name";
    char *fare1="Fare";
    char seats[100]="Available Seats";
    fp=fopen(filename,"w+");
    if(fp == NULL){
        printf("Can't open the file \"Details.csv\" in %s\n", __func__);
        exit(1);
    }
    fprintf(fp,"%s,%s,%s\n",name, fare1, seats);
    for(int i=0;i<row_count-1;i++){
        fprintf(fp,"%s,%d,%d\n", package_name[i], fare[i], total_seats[i]);
    }
    fclose(fp);
}
