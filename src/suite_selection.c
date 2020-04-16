//
//  main.c
//  test
//
//  Created by VISHNU RAJASEKAR on 2020-04-15.
//  Copyright © 2020 VISHNU RAJASEKAR. All rights reserved.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<windows.h>
#define filename "suite_selection.csv"
struct suite{
    char *suite_name;
    int *numbers;
    int *capacity;
    int *additional_fare;
}room;
int read_file(char *file)
{
    char c[1024];
    int count=0;
    FILE *fp=fopen(filename,"w+");
    if(!fp)
    {
        printf("cant open\n");
        exit(1);
    }
    while(fgets(c,1024,fp)!=NULL)
    {
        count++;
    }
    return count;
    fclose(fp);
}
int suite_selection(int no_of_pass)
{
    int row_count=0;
    int column_count=0;
    char buf[1024];
    //int count=0;
    int suite_selected;
    int room_count[30];
    int room_capacity[30];
    char confirm_booking[10];
    int room_booked[30]={0};
    int line_count =0;
    line_count = read_file(filename);
    FILE *fp=fopen(filename,"w+");
    if(!fp){
        printf("cant open\n");
        exit(1);
    }
    struct suite *room = (struct suite *)malloc(sizeof(struct suite *) * line_count);
    if(!room){
        fprintf(stderr, "Could not allocate the array of struct record \n ");
        exit(1);
    }
    while (fgets(buf, 1024, fp)){
        column_count=0;
        row_count++;
        if (row_count == 0)
            continue;
        char *file_data = strtok(buf, ",");
        while (file_data){
            if(column_count==0){
            /**
            * Allocating memory for structure member suite_name
            */
                room[row_count].suite_name =(char *)malloc(80);
            /**
            * data read from 1st column of every row in the file is stored into structure member suite_name
            */
                strcpy(room[row_count].suite_name,file_data);
            }
            if(column_count==1)
            {
            /**
            * Allocating memory for structure member number of rooms
            */
                room[row_count].numbers = (int *)malloc(sizeof(int));

            /**
            * data read from 2nd column of every row in the file is stored into structure member number of rooms.
            */
                *room[row_count].numbers = atoi(file_data);
                room_count[row_count-1] = atoi(file_data);
            }
            if(column_count==2)
            {
            /**
            * Allocating memory for structure member total_seats
            */
                room[row_count].capacity = (int *)malloc(sizeof(int));
            /**
            *   data read from 3rd column of every row in the file is stored into structure member total_seats.
            */
                *room[row_count].capacity = atoi(file_data);
                room_capacity[row_count-1] = atoi(file_data);
            }
            if(column_count==3)
            {
            /**
            * Allocating memory for structure member additional fare
            */
                room[row_count].additional_fare = (int *)malloc(sizeof(int));
            /**
            * data read from 4th column of every row in the file is stored into structure member additional fare.
            */
                *room[row_count].additional_fare = atoi(file_data);
            }
        file_data = strtok(NULL, ",");
        column_count++;
        }
        printf("\n");
    }
    fclose(fp);
    //system ("cls");
    //int total_rooms[row_count];
    /**
    * Making a copy of all the structure member total_seats into an new integer array total_rooms[]
    */
    //for(int i=1;i<=row_count;i++){
    //    printf("%d",*room[i].numbers);//total_rooms[i]= *rooms[i].numbers;
    //}
    label:do{
    /**
    * Prints the available room options for the customer to choose from
    */
        printf("Which suite would you like to book among the following for %d people\n",no_of_pass);
        for(int i=2; i<=row_count; i++){
            printf("%d. %s\n", i-1, room[i].suite_name);
        }
        printf("Please select one of the suite:\n");
        scanf("%d", &suite_selected);
        printf("room_count[suite_selected+1]--%d\n",room_count[suite_selected]);
        if(room_count[suite_selected]!=0){
            printf("Do you want %s room?(yes/no)\n",room[suite_selected+1].suite_name);
            scanf("%s",confirm_booking);
            if( strcmp( confirm_booking, "yes") == 0 ){
                if(no_of_pass>room_capacity[suite_selected]){
                printf("Booking is confirmed for %d members!\n",*room[suite_selected+1].capacity);
                //sleep(5);
                room_booked[suite_selected]++;
                room_count[suite_selected]--;
                no_of_pass=no_of_pass-room_capacity[suite_selected];
                printf("Please book the suite for %d people\n",no_of_pass);
                goto label;//suite_selection(no_of_pass);
                }
                else{
                    printf("Booking is confirmed for %d members!\n",no_of_pass);
                    //sleep(5);
                    room_booked[suite_selected]++;
                    room_count[suite_selected]--;
                    printf("Thanks for booking");
                    exit(0);
                }
            }
            else{
                printf("Please select the suites again:\n");
                goto label;//suite_selection(no_of_pass);
            }
        }
        else{
            printf("Selected suite is not available. Please select another suite\n");
            goto label;//suite_selection(no_of_pass);
        }
    }while(1);
    return 0;
}
int main()
{
    int n;
    printf("enter the total no of passengers");
    scanf("%d",&n);
    suite_selection(n);
}
