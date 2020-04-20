#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "booking.h"
#include "passenger_details.h"
#include "package_availability.h"
#include "suite_selection.h"
#include "update_suite_selection.h"
#include "add_passenger.h"
//#include "fare_calculation.h"
#include "remove_passenger.h"

void update_seats(int row_count,char *package_name[], int fare[], int total_seats[]){
    FILE *fp;
    char *name="Package Name";
    char *fare1="Fare";
    char seats[100]="Available Seats";
    fp=fopen("Details.csv","w");
    if(fp == NULL){
        printf("Can't open the file-%s\n", "Details.csv");
        exit(1);
    }
    fprintf(fp,"%s,%s,%s\n",name, fare1, seats);
    for(int i=0;i<row_count-1;i++){
        fprintf(fp,"%s,%d,%d\n", package_name[i], fare[i], total_seats[i]);
    }
    fclose(fp);
}

void add_pass(){
    char buffe[1024];
    FILE *f1 = fopen(ffname,"a");
    FILE *f2 = fopen(fname,"r");
    while (fgets(buffe, 1024, f2)){
        fprintf(f1,"%s",buffe);
    }
    fclose(f1);
    fclose(f2);
    remove("pass_temp.csv");
}

void write_into_file(int suite_length, int file_id, char *cruise_name, int no_of_pass, float total_fare, int *room_booked){
    FILE *fp=fopen(storing_file,"a");
    if(fp == NULL){
        printf("Can't open the file %s\n",storing_file);
        exit(0);
    }
    /**
    * Storing the details into the "bookings_info.csv" file
    */
    fprintf(fp,"%d,%s,%d,%f,",file_id, cruise_name,no_of_pass,total_fare);
    for(int i=0;i<suite_length-1;i++){
        fprintf(fp,"%d,",room_booked[i]);
    }
    fprintf(fp,"\n");
    fclose(fp);
}

int read_file(char *file){
    char c[1024];
    int count=0;
    FILE *fp = fopen(file, "r");
    if (!fp) {
        printf("Can't open the file %s\n",file);
        printf("Error - %s\n", strerror(errno));
        exit(1);
    }
    while(fgets(c, 1024, fp)!=NULL)
	{
	 count++;
	}
	return count;
    fclose(fp);
}
int booking(){
    int row_count=0;
    int column_count = 0;
    int line_count;
    int suite_length;
    int cruise_selected=0;
    int available=0;
    int continue_booking=0;
    int file_identity;
    char confirm_booking[6];
    char cancel_booking[6];
    int change_option;
    int cruise_sel_value;
    int no_of_pass_value;
    int temp;
    float total_fare=0;
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
        printf("Can't open file\n");
        exit(1);
    }
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
    do{
        /**
        * Prints the available cruise options for the customer to choose from
         */
        printf("Which cruise package would you like to book among the following:\n");
        for(int i=0; i<row_count-1; i++){
            printf("%d. %s\n", i+1, package_name[i]);
        }
        select1:
                printf("\nPlease select one of the package: ");
				cruise_sel_value = scanf("%d", &cruise_selected);
				while(cruise_sel_value != 1 || cruise_selected>=row_count || cruise_selected <= 0){
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid input!! Please try entering valid number!");
					goto select1;
			    }

        /**
        * Taking the count of total passengers travelling for a particular cruise selected
        */
        select2:
                printf("\nPlease provide the total number of passengers travelling:");
                no_of_pass_value = scanf("%d", &no_of_pass);
                while(no_of_pass_value != 1 || no_of_pass <= 0){
                    while((temp=getchar()) != EOF && temp != '\n');
                    printf("Invalid input!! Please try entering valid number!");
                    goto select2;
                }
        /**
        * function called to check the availability for requested number of seats in the selected cruise
        */
        available = package_availability(cruise_selected, no_of_pass, total_seats);
        if(available == -1) {
            printf("Requested number of seats are available!\n");
            file_identity = passenger_details(no_of_pass);
            suite_length = suite_selection(no_of_pass, room_booked, cruise_selected);
            //total_fare = fare_calculation(no_of_pass, fare[cruise_selected-1]);
            printf("\nYour Total fare is = %f", total_fare);
        do{
            confirm:
                printf("\nDo you want to confirm the booking? (yes/no):");
                scanf("%s",confirm_booking);
                while(strncmp(confirm_booking, "yes",3) && strncmp(confirm_booking, "no",2)){
                printf("Invalid input! Please try entering (yes/no) in lower case only!\n");
                goto confirm;
                }
                if(!strncmp(confirm_booking, "yes",3)){
                    printf("Booking is confirmed!\n");
                    update_seats(line_count, package_name, fare, total_seats);
                    write_into_file(suite_length, file_identity, package_name[cruise_selected-1], no_of_pass, total_fare, room_booked);
                    add_pass();
                    update_suite_selection(room_booked, cruise_selected);
                }else{
                    cancel:
                        printf("\nDo you want to cancel booking? (yes/no):");
                        scanf("%s",cancel_booking);
                        while(strncmp(cancel_booking, "yes",3) && strncmp(cancel_booking, "no",2)){
                            printf("Invalid input! Please try entering again!\n");
                            goto cancel;
                        }
                    if(!strncmp(cancel_booking, "yes", 3)){
                        printf("Booking is cancelled\n");
                        /**
                        * To Do need to delete all the details of that particular booking ID
                        */
                        break;
                }else{
                    change:
                        printf("\nWhat among the following changes do you want to make? \n1.Add passenger\n2.Remove passenger\n");
                        scanf("%d",&change_option);
                        while(change_option<1 || change_option>2){
                             goto change;
                        }
                        switch(change_option){
                            case 1: printf("\nWhat is the count of extra passengers you would like to add?");
                                    scanf("%d", &no_of_pass_temp);
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
                            case 2: printf("How many number of passenger would you like to remove? \n");
                                    scanf("%d",&no_of_pass_temp);
                                    remove_passenger(no_of_pass_temp);
                                    no_of_pass=no_of_pass-no_of_pass_temp;
                                    break;
                        }
                        printf("Make room changes\n");
                        for(int x=0;x<suite_length-1;x++){
                            room_booked[x]=0;
                        }
                        suite_length = suite_selection(no_of_pass, room_booked, cruise_selected);
                        //total_fare = fare_calculation(no_of_pass, fare[cruise_selected-1]);
                        printf("\nYour Total fare is = %f", total_fare);
                       }
                   }
             }while(strncmp(confirm_booking,"yes",3));
        }else{
            printf("Sorry:( %d seats are left\n",  available);
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

