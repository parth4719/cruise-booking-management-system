/**
 * @file add_passenger.c
 *
 * @brief This function add the extra passenger details into the file "pass_temp.csv".
 *
 * @author Spandana Manjappa Karehanumannara - kmspandanakarehanuma@cmail.carleton.ca
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include "passenger_details.h"
#include "add_passenger.h"

void add_passenger(int no_of_passengers){
    FILE *fp;
    int i=0;
    int age_value=0,temp=0;
    char name[20];
    int age = 0;
    char gender[10];
    char email[20];
    char disability[20];
	fp=fopen(fname,"a");

	if(fp == NULL){
        printf("Can't open the file %s\n", fname);
        exit(0);
    }
    for(i = 1; i <= no_of_passengers; i++){
        /**
        * Asking for the passenger's name
        */
        printf("Enter the passenger-%d name:\n",i);
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
        fprintf(fp,"%s,%d,%s,%s,%s\n",name,age,gender,email,disability);
    }
    fclose(fp);
}
