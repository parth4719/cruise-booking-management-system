/**
 *  @file fare_calculation.c
 *
 * @brief A function to calculate the total fare of a booking made by a user
 *
 * @author Swetha Meenakshi Natarajan - swethameenakshinatar@cmail.carleton.ca
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "fare_calculation.h"

float fare_calculation(int no_of_pass, int package_fare, int cruise_selected, int suite_length, int *room_booked) {
    /**
    *   Initializing the variables
    */
    float total_fare = 0.0;
    float discount = 0.0;
    int passenger_age[100];
    char *passenger_disabled[100];
    int age_group[100];
    float age_discount[100];
    int group_size[20];
    float group_discount[20];
    char disabled[5][4];
    float disability_discount[5];
    int additional_fare[10];
    float suite_discount[10];
    char buf[1024], str[30];
    char *f4name;
    int row_count = 0, rc1 = 0, rc2 = 0, rc3 = 0, rc4 = 0;
    int col_count, cc1, cc2, cc3, cc4;
    int i, j;

    /**
    *   Calculating fare for number of passengers for the cruise selected
    */
    total_fare = total_fare + (no_of_pass * package_fare);

    /**
    *   Opening file to read passengers' details
    */
    FILE *fp = fopen(ftname, "r");
    if(!fp) {
        printf("CANT OPEN FILE \"pass_temp.csv\" in %s ", __func__);
        exit(0);
    }
    while(fgets(buf, 1024, fp)) {
        col_count = 0;
        ++row_count;
        if(row_count == 0) {
            continue;
        }
        char *data = strtok(buf, ",");
        while(data) {
            if(col_count == 1) {
                passenger_age[row_count-2] = atoi(data);
            }
            if(col_count == 4) {
                int len = strlen(data);
                passenger_disabled[row_count-2] = malloc(len+1);
                strncpy(passenger_disabled[row_count-2],data,len+1);
            }
            data = strtok(NULL, ",");
            col_count++;
        }
    }
    fclose(fp);

    /**
    *   Opening file to read discount based on age group and storing data read from each column as different arrays
    */
    FILE *fa = fopen(f1name, "r");
    if(!fa) {
        printf("CANT OPEN FILE \"age_group_discount.csv\" in %s", __func__);
        exit(0);
    }
    while(fgets(buf,1024,fa)) {
        cc1 = 0;
        ++rc1;
        if(rc1 == 1) {
            continue;
        }
        char *data1 = strtok(buf,",");
        while(data1) {
            if(cc1 == 0) {
                age_group[rc1-2] = atoi(data1);
            }
            if(cc1 == 1) {
                age_discount[rc1-2] = atof(data1);
            }
            data1 = strtok(NULL,",");
            cc1++;
        }
    }
    fclose(fa);

    /**
    *   Opening file to read discount based on group size and storing data read from each column as different arrays
    */
    FILE *fg = fopen(f2name, "r");
    if(!fg) {
        printf("CANT OPEN FILE \"group_size_discount.csv\" in %s", __func__);
        exit(0);
    }
    while(fgets(buf,1024,fg)) {
        cc2 = 0;
        ++rc2;
        if(rc2 == 1) {
            continue;
        }
        char *data2 = strtok(buf,",");
        while(data2) {
            if(cc2 == 0) {
                group_size[rc2-2] = atoi(data2);
            }
            if(cc2 == 1) {
                group_discount[rc2-2] = atof(data2);
            }
            data2 = strtok(NULL,",");
            cc2++;
        }
    }
    fclose(fg);

    /**
    *   Opening file to read disability discount and storing data read from each column as different arrays
    */
    FILE *fd = fopen(f3name, "r");
    if(!fd) {
        printf("CANT OPEN FILE \"disability_discount.csv\" in %s", __func__);
        exit(0);
    }
    while(fgets(buf,1024,fd)) {
        cc3 = 0;
        ++rc3;
        if(rc3 == 1) {
            continue;
        }
        char *data3 = strtok(buf,",");
        while(data3) {
            if(cc3 == 0) {
                strcpy(disabled[rc3-2],data3);
            }
            if(cc3 == 1) {
                disability_discount[rc3-2] = atof(data3);
            }
            data3 = strtok(NULL,",");
            cc3++;
        }
    }
    fclose(fd);

    /*
    * Opening file to read the additional fares and discounts applicable for different suites and storing data read from each column as different arrays
    */
    snprintf(str, 30, "%d", cruise_selected);
    f4name = strcat(str, "suite_selection.csv");
    FILE *fs = fopen(f4name, "r");
    if(!fs) {
        printf("CANT OPEN FILE \"suite_selection.csv\" in %s", __func__);
        exit(0);
    }
    while(fgets(buf, 1024, fs)) {
        cc4 = 0;
        ++rc4;
        if(rc4 == 1) {
            continue;
        }
        char *data4 = strtok(buf, ",");
        while(data4) {
            if(cc4 == 3) {
                additional_fare[rc4-2] = atoi(data4);
            }
            if(cc4 == 4) {
                suite_discount[rc4-2] = atof(data4);
            }
            data4 = strtok(NULL, ",");
            cc4++;
        }
    }
    fclose(fs);

    /**
    *   Applying discount based on age group
    */
    for(i=0;i<row_count-1;i++) {
        for(j=0;j<rc1-1;j++) {
            if(age_group[j] == passenger_age[i]) {
                discount = discount + (age_discount[j] * package_fare);
            }
        }
    }

    /**
    *   Applying discount based on group size
    */
    for(i=0;i<rc2-1;i++) {
        if(group_size[i] == no_of_pass) {
            discount = discount + (group_discount[i] * package_fare);
        }
    }

    /**
    *   Apply discount for disabilities
    */
    for(i=0;i<row_count-1;i++) {
        for(j=0;j<rc3-1;j++) {
            if(strncmp(passenger_disabled[i], disabled[j],3)==0) {
                discount = discount + (disability_discount[j] * package_fare);
            }
        }
    }

    /*
    * Apply additonal fare and discount based on selected suite category
    */
    for(i=0; i<suite_length; i++) {
        total_fare = total_fare + (room_booked[i] * additional_fare[i]);
        discount = discount + (room_booked[i] * suite_discount[i] * package_fare);
    }

    /**
    *   Total fare is calculated after applying discounts
    */
    total_fare = total_fare - discount;

    /**
    *   Total fare for the booking is returned
    */
    return total_fare;
}
