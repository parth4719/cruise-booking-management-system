#include<stdio.h>
#include<string.h>
#include "passenger_details.h"

void remove_passenger(int no_of_pass){
	char buf[1024],str[1024];
	FILE *fp1;
	FILE *fp;
	int column_count=0,delete=0;
	int row_count=1;
	int i=0,ctr=0;

	for(i=0;i<=no_of_pass-1;i++){
		fp=fopen("pass_temp.csv","r");
		if(fp == NULL){
			printf("Can't open the file %s\n", fname);
			exit(1);
		}
		row_count=1;
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
		printf("\nPlease select the number of the passenger that you want to delete: ");
		scanf("%d",&delete);
		fp=fopen("pass_temp.csv","r");
	    fp1=fopen("temporary.csv","w+");
		while (!feof(fp))
        {
            strcpy(str, "\0");
            fgets(str, 1024, fp);
            if (!feof(fp))
            {
                ctr++;
                if (ctr != delete)
                {
                    fprintf(fp1, "%s", str);
                }
            }
        }
		fclose(fp);
        fclose(fp1);
        remove("pass_temp.csv");
        rename("temporary.csv","pass_temp.csv");
	}
}
