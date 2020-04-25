/**
 * @file delete_passenger.c
 *
 * @brief A function to calculate the refund for cancelled tickets
 *
 * @author Swetha Meenakshi Natarajan - swethameenakshinatar@cmail.carleton.ca
 */

 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #include "../include/delete_passenger.h"
 #include "../include/refund_calculation.h"
 #include "../include/full_cancellation.h"

/**
 * @brief      Function to delete the records of selected passengers
 *
 * @param[in]  pass_count      Number of passengers in the booking
 *
 * @param[in]  no_of_pass      Number of passengers to be deleted
 *
 * @param[in]  id              Booking ID of ticket to be cancelled
 *
 * @details    Function takes the booking id, number of passengers in booking and number of passengers to be deleted
 * to delete the record of passengers
 */

 void delete_passenger(int no_of_pass, int pass_count, int id) {
    FILE *fp, *fp1;
    char temp[] = "temp1.csv";
    char buf[1024], str[1024];
    int n, cc = 0, rc = 0;
    for(int i=0; i<no_of_pass; i++) {
        fp = fopen(f1, "r");
        if(!fp) {
            /**
             * If we fail to open the file, then we need to abort the program,
             * there is nothing to be done.
             */
            printf("CANT OPEN FILE");
            exit(0);
        }
        for(int j=0; j<pass_count; j++) {
            /**
            * Reads line by line from file pointed by fp
            */
            while(fgets(buf, 1024, fp)) {
                char *data = strtok(buf, ",");
                while(data) {
                    if(cc == 0) {
                        printf("\n%d  %s", rc, data);
                    }
                    data = strtok(NULL, ",");
                    rc++;
                }
            }
        }
        pass_count--;
        printf("\nEnter number of passenger you want to delete  ");
        scanf("%d", &n);
        fp1 = fopen(temp, "w");
        while(!feof(fp)) {
            strcpy(str,"\0");
            fgets(str,1024,fp);
            rc = 0;
            if(!feof(fp)){
                rc++;
                if(rc == 0){
                    continue;
                }
                if(rc != n){
                    /**
                    * Removing the  details row of the passenger.
                     */
                    fprintf(fp1, "%s", str);
                }
            }
        }
    }
    fclose(fp);
    fclose(fp1);
     /**
      * Removing the f1 csv file.
      */
    remove(f1);
     /**
      * Renaming the temp file as the f1 file.
      */
    rename(temp,f1);
 }
