/**
* @file: display_booking_details.c
*
* @brief: A function to read  and display the booking details.
*
* @author: vishnurajasekar@cmail.carleton.ca
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/read_file.h"
#include "../include/cancellation.h"
#include "../include/refund_calculation.h"
#include "../include/display_booking_details.h"

/**
* @brief Reads the booking id obtained from user
*
* @param[in] id Booking ID obtained from user
*
*@param[in] pass_count The passenger count from the user
*
*@param[in] total_fare The integer array containing total fare of all the packages.
*
*@param[in] cruise_number The cruise number selected by the user
*
*@param[in] rooms The rooms that are available.
*
* @details Function displays booking details corresponding to booking ID obtained from user after reading the details from the file "Bookings_info.csv"
*/

void display_booking_details(int *id, int *pass_count, float *total_fare, int *cruise_number1, int rooms[]){
    FILE *fp;
    char cruise_name[50];
    char str[30],name[30]="../src/";
    char buff[1024];
    int column_count, row_count = 0;
    static int line_count=5;
    char book_id[5];
    snprintf(book_id, 5, "%d", *id);
	fp = fopen("../src/Bookings_info.csv","r");
    if(!fp){
        printf("Booking_info.csv cannot be opened\n");
        exit(0);
    }
    while (fgets(buff, 1024, fp)){
        column_count=0;
        row_count++;
        if(row_count == 1) {
            continue;
        }
        char *file_data = strtok(buff, ",");
        while (file_data) {
            if(column_count==0){
                if(!strncmp(file_data,book_id,3)){
                    printf("book_id : %s",book_id);
                    int i=0;
                    while(column_count<line_count+4){
                        if(column_count == 1){
                            *cruise_number1 = atoi(file_data);
                            printf("cruise_number : %d",*cruise_number1);
                            snprintf(str, 30, "%d", *cruise_number1);
							strcat(name,str);
                            line_count = read_file(strcat(name,"suite_selection.csv"));
                        }
                        if(column_count == 2){
							strcpy(cruise_name,file_data);
                            printf("cruise_name : %s",cruise_name);
                        }
                        if(column_count == 3){
                            *pass_count = atoi(file_data);
                            printf("pass_count :  %d",*pass_count);
                        }
                        if(column_count == 4){
                            *total_fare = atof(file_data);
                            printf("total_fare : %f",*total_fare);
                        }
                        if(column_count>4){
                                rooms[i]= atoi(file_data);
                                i++;
                        }
                        printf("\n");
                        file_data = strtok(NULL, ",");
                        column_count++;
                    }
                }
            }
            file_data = strtok(NULL, ",");
            column_count++;
        }
    }
    fclose(fp);
}