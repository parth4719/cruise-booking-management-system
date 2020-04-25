#include "partial_cancel.h"
#define f1 "passenger_details.csv"
#define f2 "delete_pass.csv"

void passenger_remove(int id, int no_of_pass, int pass_remove) {
    FILE *fp, *ft;
    char buf[1024], str[1024];
    int del = 0, ctr = 0;
    int column_count, row_count = id;
    int n1 = no_of_pass, n2 = pass_remove;
    for(int j=0; j<n2; j++) {
        fp = fopen("passenger_details.csv","r");
        if(!fp) {
            printf("CANT OPEN FILE \"passenger_details.csv\" in %s", __func__);
            exit(0);
        }
        while(fgets(buf, 1024, fp));
        row_count = id;
        for(int i=0; i<n1; i++) {
            column_count = 0;
            row_count++;
            if(row_count == 1) {
                continue;
            }
            char *data = strtok(buf, ",");
            while(data) {
            if(column_count == 0) {
                printf("%d. %s", row_count, data);
                }
                data = strtok(NULL, ",");
                column_count++;
            }
        }
        fclose(fp);
        printf("\nPlease select the number of the passenger that you want to delete: ");
		scanf("%d", &del);
		fp = fopen("passenger_details.csv", "r");
	    ft = fopen("pass_remove.csv", "w+");
		while (!feof(fp))
        {
            strcpy(str, "\0");
            fgets(str, 1024, fp);
            if (!feof(fp))
            {
                ctr++;
                if (ctr != del)
                {
                    fprintf(ft, "%s", str);
                }
            }
        }
		fclose(fp);
        fclose(ft);
        remove("passenger_details.csv");
        rename("pass_remove.csv","passenger_details.csv");
    }
}

void modify_suite_selection(int cruise_number, int *rooms, int no_of_pass, int pass_remove) {
    FILE *fp;
    char str[30], buf[1024];
    char *name;
    char *suite_name[10];
    int room_count[10];
    int capacity[10];
    int additional_fare[10];
    float discount[10];
    int i, column_count, row_count = 0;
    int num = no_of_pass - pass_remove;
    int suite_selected;
    char confirm[3];

    snprintf(str, 30, "%d", cruise_number);
    name = strcat(str, "suite_selection.csv");
    fp = fopen(name, "r");
    if(!fp) {
        printf("CANT OPEN FILE \"suite_selection.csv\" in %s", __func__);
        exit(0);
    }
    while(fgets(buf, 1024, fp)) {
        column_count = 0;
        ++row_count;
        if(row_count == 1) {
            continue;
        }
        char *data = strtok(buf, ",");
        while(data){
            if(column_count==0) {
                int len = strlen(data);
                suite_name[row_count-2] = malloc(len+1);
                strncpy(suite_name[row_count-2], data, len+1);
            }
            if(column_count==1)
            {
               room_count[row_count-2] = atoi(data);
            }
            if(column_count==2)
            {
               capacity[row_count-2] = atoi(data);
            }
            if(column_count==3)
            {
            	additional_fare[row_count-2] = atoi(data);
            }
			if(column_count==4)
            {
                discount[row_count-2] = atof(data);
            }
            data = strtok(NULL, ",");
            column_count++;
        }
    }
    fclose(fp);
    for(i=0; i<row_count-1; i++) {
        room_count[i] = room_count[i] + rooms[i];
        rooms[i] = 0;
    }
    label: do{
        printf("\nWhich suite would you like to book among the following for %d people:\n", num);
        for(int i=0; i<row_count-1; i++){
            printf("%d. %s\n", i+1, suite_name[i]);
        }
        printf("\nPlease select one of the suite: ");
        scanf("%d", &suite_selected);
        printf("Rooms remaining = %d\n", room_count[suite_selected-1]);
        if(room_count[suite_selected-1]>0) {
            printf("\nDo you want %s room?(yes/no) :", suite_name[suite_selected-1]);
            scanf("%s", confirm);
            if(strcmp(confirm, "yes")==0) {
                if(num > capacity[suite_selected-1]) {
                    printf("\nBooking is confirmed for %d members!\n", capacity[suite_selected-1]);
                    rooms[suite_selected-1]++;
                    room_count[suite_selected-1]--;
                    num = num - capacity[suite_selected-1];
                    printf("\nPlease book the suite for %d people.\n", num);
                    goto label;
                }
                else {
                    printf("\nSuites are confirmed !!\n");
                    rooms[suite_selected-1]++;
                    room_count[suite_selected-1]--;
                    break;
                }
            }
            else {
                printf("\nPlease select the suites again:\n");
                rooms[suite_selected-1]--;
                goto label;
            }
        }
        else {
            printf("\nSelected suite is not available. Please select another suite\n");
            goto label;
        }
    }while(1);
    fp = fopen(name, "w+");
    if(!fp) {
        printf("CANT OPEN FILE \"suite_selection.csv\" in %s", __func__);
        exit(0);
    }
    fprintf(fp,"%s,%s,%s,%s,%s\n","suite name","room count","capacity","additional fare","discount");
	for(i=0; i<row_count-1; i++){
		fprintf(fp,"%s,%d,%d,%d,%f",suite_name[i-1],room_count[i-1],capacity[i-1],additional_fare[i-1],discount[i-1]);
	}
	fclose(fp);
}

void modify_package_details(int cruise_number, int no_of_pass, int pass_remove) {
    int row_count, column_count = 0;
    char buf[1024];
    char *package_name[10];
    int fare[10];
    int available_seats[10];
    int num = no_of_pass - pass_remove;
    FILE *fp = fopen("Details.csv","r");
    if(!fp) {
        printf("CANT OPEN FILE \"Details.csv\" in %s", __func__);
        exit(0);
    }
    while(fgets(buf, 1024, fp)){
        column_count=0;
        ++row_count;
        if (row_count == 1) {
            continue;
        }
        char *data = strtok(buf, ",");
        while(data) {
            if(column_count==0) {
                int len = strlen(data);
                package_name[row_count-2] = malloc(len+1);
                strncpy(package_name[row_count-2], data, len+1);
            }
            if(column_count==1) {
                fare[row_count-2] = atoi(data);
            }
            if(column_count==2){
               available_seats[row_count-2]= atoi(data);
            }
        data = strtok(NULL, ",");
        column_count++;
        }
    }
    fclose(fp);
    fp = fopen("Details.csv", "w+");
    if(!fp) {
        printf("CANT OPEN FILE \"Details.csv\" in %s", __func__);
        exit(0);
    }
    fprintf(fp,"%s,%s,%s\n","package name","fare","available seats");
    for(int i=0;i<row_count-1;i++) {
        if(i == (cruise_number-1)) {
            fprintf(fp,"%s,%d,%d\n", package_name[i], fare[i], available_seats[i]+num);
        }
        else{
            fprintf(fp,"%s,%d,%d\n", package_name[i], fare[i], available_seats[i]);
        }
    }
    fclose(fp);
}

void new_fare(int cruise_number, float *fare, float cancel_fee, float refund, int n, int *suites, int cruise_fare) {
    char str[30], buf[1024];
    char *name;
    int column_count, row_count = 0;
    int additional_fare[10];
    float suite_discount[10];
    int room_fare = 0;
    float room_discount = 0.0;
    snprintf(str, 30, "%d", cruise_number);
    name = strcat(str, "suite_selection.csv");
    FILE *fp = fopen(name, "r");
    if(!fp) {
        printf("CANT OPEN FILE \"suite_selection.csv\" in %s", __func__);
        exit(0);
    }
    while(fgets(buf, 1024, fp)) {
        column_count = 0;
        ++row_count;
        if(row_count == 1) {
            continue;
        }
        char *data = strtok(buf, ",");
        while(data) {
            if(column_count == 3) {
                additional_fare[row_count-2] = atoi(data);
            }
            if(column_count == 4) {
                suite_discount[row_count-2] = atof(data);
            }
            data = strtok(NULL, ",");
            column_count++;
        }
    }
    fclose(fp);
    for(int i=0; i<n+1; i++) {
        room_fare = room_fare + (suites[i] * additional_fare[i]);
        room_discount = room_discount + (suites[i] * suite_discount[i] * cruise_fare);
    }
    *fare = *fare - cancel_fee;
    *fare = *fare - refund;
    *fare = *fare + room_fare;
    *fare = *fare - room_discount;
}

void modify_booking(int id, int pass_remove, int *rooms, float f, float cancel_fee, float refund, int cruise_fare, int cruise_no) {
    char buf[1024], bid[5];
    int column_count, row_count = 0;
    int book_id[100];
    int cruise_number[100];
    char *cruise_name[100];
    int pass_count[100];
    float fare[100];
    int suites[100][10];
    int row_no, j, k, i=0;

    snprintf(bid, 5, "%d", id);
    FILE *fp = fopen("Bookings_info.csv", "r");
    if(!fp) {
        printf("CANT OPEN FILE \"Bookings_info.csv\" in %s", __func__);
        exit(0);
    }
    while(fgets(buf, 1024,fp)) {
        column_count = 0;
        ++row_count;
        if(row_count == 1) {
            continue;
        }
        char *data = strtok(buf, ",");
        while(data) {
            if(column_count == 0) {
                book_id[row_count-2] = atoi(data);
                if(!strncmp(data, bid, 3)){
                    row_no = row_count;
                }
            }
            if(column_count == 1) {
                cruise_number[row_count-2] = atoi(data);
            }
            if(column_count == 2) {
                int len = strlen(data);
                cruise_name[row_count-2] = malloc(len+1);
                strncpy(cruise_name[row_count-2], data, len+1);
            }
            if(column_count == 3) {
                pass_count[row_count-2] = atoi(data);
            }
            if(column_count == 4) {
                fare[row_count-2] = atof(data);
            }
            if(column_count>4) {
                suites[row_count-2][i] = atoi(data);
                i++;
            }
            data = strtok(NULL, ",");
            column_count++;
        }
    }
    fclose(fp);
    fp = fopen("Bookings_info.csv","w+");
    if(!fp) {
        printf("CANT OPEN FILE \"Details.csv\" in %s", __func__);
        exit(0);
    }
    fprintf(fp,"%s,%s,%s,%s,%s,","file id","Cruise Number","Cruise Name","No. of pass","total fare");
    fprintf(fp,"%s,%s,%s,%s,%s,%s,%s\n","Inside state room","Outside state rooms","Balcony room","Suite room","Family room","Honeymoon Suite","Solo cabin");
    for(j=0; j<row_count-1; j++) {
        if(j == row_no-2) {
            pass_count[j] = pass_count[j] - pass_remove;
            new_fare(cruise_no, &f, cancel_fee, refund, i, rooms, cruise_fare);
            fprintf(fp,"%d,%d,%s,%d,%f,",book_id[j],cruise_number[j],cruise_name[j],pass_count[j],fare[j]);
            for(k=0; k<i+1; k++) {
                suites[j][k] = rooms[k];
                fprintf(fp,"%d,",suites[j][k]);
            }
            fprintf(fp,"\n");
        }
        else {
            fprintf(fp,"%d,%d,%s,%d,%f,",book_id[j],cruise_number[j],cruise_name[j],pass_count[j],fare[j]);
            for(k=0; k<i+1; k++) {
                fprintf(fp,"%d,",suites[j][k]);
            }
            fprintf(fp,"\n");
        }
    }
}
