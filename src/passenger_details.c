/**
 * @file passenger_details.c
 *
 * @brief Reading the details of the passengers and storing the details into "passenger_details.csv" file.
 *
 * @author Thejprabhath Rayasam- thejprabhathrayasam@cmail.carleton.ca
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../include/passenger_details.h"

/**
* @brief Adds the details of the passengers to "passenger_details.csv" file
*
* @param[in] no_of_passengers The number of passengers to travel
*
* @details Stores the passenger details consists of the 1.Name 2.Age 3.Gender 4.Email 5.Disability into an
* individual rows for every passenger into "passenger_details.csv" file.
*
* @return The number of the row of the first passenger of the booking in the csv file
*/

int passenger_details(int no_of_passengers){
    if(no_of_passengers <= 0){
        printf("Invalid input in %s function\n", __func__);
        return -1;
    }
    /**
    * Declaring the variables
    */
    FILE *fp;
    int i=0,count=0;
    int age_value=0,temp=0;
    char buff[1024];
    char name[20];
    int age = 0;
    char gender[10];
    char email[20];
    char disability[20];

    fp=fopen(ffname,"r+");
    /**
    * Checking whether the file is opened properly in reading mode
    */
    if(fp == NULL){
        printf("File passenger_details.csv does not exist/The file is open.\n");
        return -1;
    }
    /**
    * Counting the number of rows in the file
    */
    while(fgets(buff,1024, fp)!=NULL){
        count++;
}
    fclose(fp);
    fp=fopen(fname,"w+");
    if(fp == NULL){
        printf("\"pass_temp.csv\" file cannot be created! \n");
        return -1;
    }
    for(i = 1; i <= no_of_passengers; i++){
        /**
        * Asking for the passenger's name
        */
        printf("\nEnter the passenger-%d name:\n",i);
        scanf("%s",name);
        /**
        * Asking for the passenger's age
        */
        printf("Enter the passenger-%d age:\n",i);
        age_value = scanf("%d",&age);
        while(age_value != 1 || age<0 || age>100){
            while((temp=getchar()) != EOF && temp != '\n');
            printf("Please enter a valid number for age of the passenger.\n");
            printf("Enter the passenger-%d age:\n",i);
            age_value = scanf("%d",&age);
        }
        /**
        * Asking for the passenger's gender
        */
        printf("Enter the passenger-%d gender:\n",i);
        scanf("%s",gender);
        /**
        * Asking for the passenger's email address
        */
        printf("Enter the passenger-%d email:\n",i);
        scanf("%s",email);
        /**
        * Asking for the passenger disability
        */
        printf("Enter whether the passenger-%d is disabled(yes/no): \n",i);
        scanf("%s",disability);
        while(strncmp(disability, "yes",3) && strncmp(disability, "no",2)){
            printf("Invalid input! Please try entering (yes/no) in lower case only!\n");
            printf("Enter whether the passenger-%d is disabled(yes/no): \n",i);
            scanf("%s",disability);
        }
        /**
        * Storing the details into the "passenger_details.csv" file
        */
        fprintf(fp,"%s,%d,%s,%s,%s\n",name, age, gender, email, disability);
    }
    fclose(fp);
    if(fclose(fp)){
        printf("\"pass_temp.csv\" file is not closed! \n");
        return -1;
    }
    printf("Passenger details are successfully saved.\n");
    return count+1;
}
