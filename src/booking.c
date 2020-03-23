#include "booking.h"
#include "main.h"
void booking()
{
    int travel_package;
    int trip_length;
    int no_of_passengers;
    int booking_id;
    int continue_booking;
    int available;
    extern int available_seats;
    do{
        printf("\nWhich of the following round-trip packages would you like to book:\n1.Cape Liberty to Bermuda\n2.Barcelona to Europe\n3.Honolulu to Hawaii\n");
        printf("\nSelect option 1,2 or 3: ");
        scanf("%d",&travel_package);
        switch(travel_package){
            case 1: printf("\nHow many days would you like to travel:\n1.5 Nights with fare of 799 CAD/person\n2.7 Nights with fare of 999 CAD/person\n");
                    scanf("%d",&trip_length);
                    break;
            case 2: printf("How many days would you like to travel: 1. 7 Nights with fare of 1299 CAD/person\n");
					scanf("%d",&trip_length);
					break;
            case 3: printf("How many days would you like to travel: 1.7 Nights with fare of 1499 CAD/person\n 2.10 Nights with fare of 1999 CAD/person\n");
					scanf("%d",&trip_length);
					break;
        }
        printf("\nEnter the total number of passengers travelling? ");
        scanf("%d",&no_of_passengers);
        available = package_availability(travel_package, trip_length, no_of_passengers);
        if(available == 1)
        {
            booking_id = passenger_details(no_of_passengers);
            /*suite_selection();
            calculate total fair and display bill.*/
            printf("booking ID = %d\n",booking_id);
        }
        else
        {
            printf("Sorry only %d seats are available!\n",available_seats);
        }
        printf("\nEnter '1' to continue booking else press '0': ");
		scanf("%d",&continue_booking);
    }while(continue_booking==1);
}



