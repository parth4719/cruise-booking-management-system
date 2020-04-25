/**
 * @file remove_passenger.c
 *
 * @brief This function removes the passenger details from the file "pass_temp.csv".
 *
 * @author Thejprabhath Rayasam - thejprabhathrayasam@cmail.carleton.ca
 *
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../include/passenger_details.h"
#define fname "../src/pass_temp.csv"
/**
* @brief Removes the details of the passengers from "pass_temp.csv" file.
*
* @param[in] no_of_pass The number of passengers that needs to be removed for the booking
*
* @details Removes the passenger details consists of the 1.Name 2.Age 3.Gender 4.Email 5.Disability from "pass_temp.csv" file.
*
*/

void remove_passenger(int no_of_pass){
	char buf[1024],str[1024];
	FILE *fp1;
	FILE *fp;
	int column_count=0,delete_num=0;
	int row_count=1;
	int i=0,ctr=0;
	for(i=0;i<=no_of_pass-1;i++){
		fp=fopen(fname,"r");
		if(fp == NULL){
            /**
            * If we fail to open the file, then we need to abort the program,
            * there is nothing to be done.
            */
			printf("Can't open the pass_temp.csv file in %s\n", fname);
			exit(1);
		}
		row_count=1;
        /**
        * Reads line by line from file pointed by fp
        */
		while(fgets(buf,1024,fp)){
		column_count=0;
		row_count++;
		char *file_data = strtok(buf, ",");
		while (file_data) {
			if(column_count==0) {
				/**
				* data read from 1st column of every row in the file is printed
				*/
				printf("%d. %s\n",row_count-1,file_data);
			}
			file_data = strtok(NULL, ",");
			column_count++;
			}
		printf("\n");
		}
		fclose(fp);
        /**
        * Requesting for the count of the passengers to be removed.
         */
		printf("\nPlease select the number of the passenger that you want to delete: ");
        scanf("%d",&delete_num);
		fp=fopen(fname,"r");
	    fp1=fopen("temporary.csv","w+");
		while (!feof(fp)){
            strcpy(str, "\0");
            fgets(str, 1024, fp);
            if (!feof(fp)){
                ctr++;
                if (ctr != delete_num){
                    /**
                    *Removing the row of the passenger detail that needs to be deleted.
                     */
                    fprintf(fp1, "%s", str);
                }
            }
        }
		fclose(fp);
        fclose(fp1);
        /**
        *Removing the fname csv file.
         */
        remove(fname);
        /**
        *Renaming the temporary csv file and the fname file.
         */
        rename("temporary.csv",fname);
	}
}
