/**
* @file update_suite_selection.h
*
* @brief Helps in updating the suite selected to the csv file to keep count of the rooms booked.
*
* @author Spandana Manjappa Karehanumannara - kmspandanakarehanuma@cmail.carleton.ca
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/update_suite_selection.h"
#include "../include/read_file.h"

/**
 * @brief Function updates the rooms count into the suite_selection.csv of selected cruise,everytime the booking is confirmed.
 *
 * @param[in] room_booked[] array of room booked in the cruises.
 *
 * @param[in] cruise_selected the cruise selected value.
 *
 * @details Function updates the rooms count into the suite_selection.csv of selected cruise,everytime the booking is confirmed.
 *
 */

void update_suite_selection(int *room_booked, int cruise_selected){
	FILE *fp;
	int row_count=0,i=0;
    int column_count=0;
    char buf[1024];
	int line_count=0;
    char name[50]="../src/";
	char str[30];

    snprintf(str, 30, "%d", cruise_selected);
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
        /**
        * If we fail to open the file, then we need to abort the program,
        * there is nothing to be done.
        */
        printf("cant open the file in %s\n", __func__);
        exit(1);
    }
    /**
    * Reads line by line from file pointed by fp
    */
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
    /**
    * Overwriting the file with the new information.
    */
    fp=fopen(name,"w+");
    fprintf(fp,"%s,%s,%s,%s,%s\n","suite name","room count","capacity","additional fare","discount");
	for(i=1;i<row_count;i++){
		fprintf(fp,"%s,%d,%d,%d,%f\n",suite_name[i-1], room_count[i-1]-room_booked[i-1], room_capacity[i-1], additional_fare[i-1], discount[i-1]);
	}
	fclose(fp);
}
