/**
 * @file add_pass.c
 *
 * @brief Helps for adding the passengers into the file  "passenger_details.csv".
 *
 * @author Thejprabhath Rayasam- thejprabhathrayasam@cmail.carleton.ca
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
#include "../include/add_pass.h"
#define fy1 "../src/pass_temp.csv"
#define fy2 "../src/passenger_details.csv"

/**
* @brief This function replace the content from "pass_temp.csv" into "passenger_details.csv".
*
* @details This function copies the content from "pass_temp.csv" and stores in "passenger_details.csv" , and deletes the "pass_temp.csv".
*
*/


void add_pass(void){
    /**
    *   This function copies the content from "pass_temp.csv" and stores in "passenger_details.csv" , and deletes the "pass_temp.csv".
    */
    char buffe[1024];
    FILE *f1 = fopen(fy2,"a");
    FILE *f2 = fopen(fy1,"r");
    if(f2 == NULL){
        printf("Can't open the file \"pass_temp.csv\" in %s\n", __func__);
        exit(1);
    }
    if(f1 == NULL){
        printf("Can't open the file \"passenger_details.csv\" in %s\n", __func__);
        exit(1);
    }
    while (fgets(buffe, 1024, f2)){
        fprintf(f1,"%s",buffe);
    }
    fclose(f1);
    fclose(f2);
    remove("../src/pass_temp.csv");
}
