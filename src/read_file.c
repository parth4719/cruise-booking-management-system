/**
 * @file read_file.c
 *
 * @brief Read the file provided as input and retunrs the number of rows.
 *
 * @author Thejprabhath Rayasam- thejprabhathrayasam@cmail.carleton.ca
 *
 */

#include<stdlib.h>
#include<stdio.h>
#include "../include/read_file.h"

/**
* @brief This function takes the file name as input and returns the count of rows in that file.
*
* @param[in] *file Name of the file to be read.
*
* @details This function takes the file name as input and returns the count of rows in that file.
*
*/

int read_file(char *file){
    char c[1024];
    int count=0;
    FILE *fp = fopen(file, "r");
    if (!fp) {
        /**
         * If we fail to open the file, then we need to abort the program,
         * there is nothing to be done.
         */
        printf("Can't open %s in %s\n",file,__func__);
        exit(1);
    }
    /**
    * Reads line by line from file pointed by fp
    */
    while(fgets(c, 1024, fp)!=NULL)
	{
	 count++;
	}
	return count;
    fclose(fp);
}
