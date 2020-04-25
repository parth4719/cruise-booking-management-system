/**
* @file full_cancellation.c
*
* @brief Helps in cancelling the tickets.
*
* @author Thejprabhathrayasam - thejprabhathrayasam@cmail.carleton.ca
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../include/full_cancellation.h"
#include "../include/read_file.h"

/**
*@brief A Function to remove the passenger details.
*
*@param[in] id The booking id of the customer.
*
* @details Funtion helps in removing the details of the customers from the id given by them.
*
*/
void remove_passenger_details(int id){
    int ctr=0;
    char str[1024];
    FILE *fa1,*fa2;
    fa1=fopen(fl1,"r");
    if(!fa1){
        /**
        * If we fail to open the file, then we need to abort the program,
        * there is nothing to be done.
         */
        printf("cant open %s\n",fl1);
        exit(1);
    }
    fa2=fopen(fl2,"w+");
    if(!fa2){
        /**
        * If we fail to open the file, then we need to abort the program,
        * there is nothing to be done.
        */
        printf("cant open %s\n",fl2);
        exit(1);
    }
    while(!feof(fa1)){
        strcpy(str, "\0");
        fgets(str, 1024, fa1);
        if (!feof(fa1)){
            ctr++;
            if (ctr != id){
                fprintf(fa2, "%s", str);
            }
        }
    }
    fclose(fa1);
    fclose(fa2);
    /**
    *Removing  the file.
    */
    remove(fl1);
    /**
    * Renaming the file to the previous one.
    */
    rename(fl2,fl1);
 }

/**
* @brief A Function to add  the suite selection details after the cancellation is done.
*
* @param[in] cruise_number The cruise number selected by the customer.
*
* @param[in] rooms The type of room selected by the customer.
*
* @details Funtion helps in increasing the suite count after the cancellation process is done.
*
*/

void add_suite_selection(int cruise_number, int rooms[]){
    printf("Inside add_suite_selection------------");
    FILE *fp;
	int row_count=0,i=0;
    int column_count=0;
    char buf[1024];
	int line_count=0;
    char name[50]="../src/";
	char str[30];

    snprintf(str, 30, "%d", cruise_number);
    strcat(str,"suite_selection.csv");
	strcat(name,str);
	line_count = read_file(name);
	char *suite_name[100];
	int room_count[line_count];
	int room_capacity[line_count];
	int additional_fare[line_count];
	float discount[line_count];

	fp=fopen(name,"r");
    if(!fp){
        printf("cant open\n");
        exit(1);
    }
    while(fgets(buf, 1024, fp)){
        column_count=0;
        row_count++;
        if (row_count ==1){
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
            if(column_count==3)
            {
            	additional_fare[row_count-2] = atoi(file_data);
            }
			if(column_count==4)
            {
                discount[row_count-2] = atof(file_data);
            }
        file_data = strtok(NULL, ",");
        column_count++;
        }
        }
    fclose(fp);

    fp=fopen(strcat("../src/",name),"w+");
    fprintf(fp,"%s,%s,%s,%s,%s\n","suite name","room count","capacity","additional fare","discount");
	for(i=1;i<row_count;i++){
		fprintf(fp,"%s,%d,%d,%d,%f\n",suite_name[i-1], room_count[i-1]+rooms[i-1], room_capacity[i-1], additional_fare[i-1], discount[i-1]);
	}
	fclose(fp);
}

/**
*@brief A Function to add  the passenger count after the cancellation is done.
*
*@param[in] cruise_number The cruise number selected by the customer.
*
*@param[in] pass_count The number of the passenger count selected by the customer.
*
* @details Funtion helps in increasing the passenger count after the cancellation process is done.
*
*/

 void add_details(int cruise_number, int pass_count){
	printf("Inside add_details------------");
    FILE *fp;
    int row_count=0,column_count=0;
    char buf[1024];
    fp = fopen("../src/Details.csv", "r");
    if (!fp) {
        /**
         * If we fail to open the file, then we need to abort the program,
         * there is nothing to be done.
         */
        printf("Can't open file\n");
        exit(1);
    }
    int line_count = read_file("../src/Details.csv");
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
                package_name[row_count-2] =(char *)malloc(sizeof(char)*strlen(file_data)+1);
                if(package_name== NULL){
                    printf("could not allocate memory\n");
                }
                strcpy(package_name[row_count-2],file_data);
            }
            if(column_count==1) {
                fare[row_count-2] = atoi(file_data);
            }
            if(column_count==2){
               total_seats[row_count-2]= atoi(file_data);
            }
        file_data = strtok(NULL, ",");
        column_count++;
        }
        printf("\n");
    }
    fclose(fp);
    fp=fopen("../src/Details.csv","w");
    if(fp == NULL){
        printf("Can't open the file-%s\n", "Details.csv");
        exit(1);
    }
    fprintf(fp,"%s,%s,%s\n","Package Name", "Fare", "Available Seats");
    for(int i=0;i<row_count-1;i++){
        if(i==(cruise_number-1)){
            fprintf(fp,"%s,%d,%d\n", package_name[i], fare[i], total_seats[i]+pass_count);
        }
        else{
            fprintf(fp,"%s,%d,%d\n", package_name[i], fare[i], total_seats[i]);
        }
    }
    fclose(fp);
 }

/**
*@brief A Function to remove the booked ticket of the passenger.
*
*@param[in] id The booking id of the customer.
*
* @details Funtion helps in removing the booked ticket of the passenger from the id that is given.
*
*/
void remove_booking(int id){
    FILE *fp1,*fp2;
    char buff[1024],str[1024];
    int column_count, row_count = 0, row_number=0,ctr=0;
    char book_id[5];
	snprintf(book_id, 5, "%d", id);
	fp1 = fopen("../src/Bookings_info.csv","r");
	if(!fp1){
        printf("File cannot be opened\n");
        exit(0);
	}
	fp2 = fopen("tempo.csv","w+");
    if(!fp2){
        printf("File cannot be opened\n");
        exit(0);
    }
    while (fgets(buff, 1024, fp1)){
        column_count=0;
        row_count++;
        if(row_count == 1) {
            continue;
        }
        char *file_data = strtok(buff, ",");
        while (file_data) {
            if(column_count==0){
                if(!strncmp(file_data,book_id,3)){
                    row_number=row_count;
                }
            }
            file_data = strtok(NULL, ",");
            column_count++;
        }
    }
    fclose(fp1);
    fp1 = fopen("../src/Bookings_info.csv","r");
    while (!feof(fp1)){
        strcpy(str, "\0");
        fgets(str, 1024, fp1);
        if (!feof(fp1)){
            ctr++;
            if (ctr != row_number){
                fprintf(fp2, "%s", str);
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("../src/Bookings_info.csv");
    rename("tempo.csv","../src/Bookings_info.csv");
 }