#include "package_availability.h"

/* function check the availability of the seats in the selected cruise and returns 1 if available and returns 0 if cruise doesnot have requested number of seats.*/
int package_availability(int travel_package,int trip_length,int no_of_passengers)
{
    switch(travel_package)
		{
		case 1: if(trip_length == 1)
				{
					if(no_of_passengers <= (CRUISE_TOTAL_SEATS - cape_5_nyt_seats_alloted))
                	{
						struct package_choosen cape_5;
						strcpy(cape_5.package,"Cape Liberty to Bermuda");
                        strcpy(cape_5.travel_length,"5 Nights");
						cape_5.fare = 799;
						printf("Travel Package: %s\n",cape_5.package);
						printf("Travel length: %s\n",cape_5.travel_length);
						printf("Fare per person: %d\n",cape_5.fare);
						cape_5_nyt_seats_alloted += no_of_passengers;
					 	available_seats = CRUISE_TOTAL_SEATS - cape_5_nyt_seats_alloted;
					 	return 1;
					}
					else
					{
						//printf("Sorry only %d seats are available!\n",available_seats);
						return available_seats;
					}
				}
				else
				{
					if(no_of_passengers <= (CRUISE_TOTAL_SEATS - cape_7_nyt_seats_alloted))
					{
						struct package_choosen cape_7;
						strcpy(cape_7.package,"Cape Liberty to Bermuda");
                        strcpy(cape_7.travel_length,"7 Nights");
						cape_7.fare = 999;
						printf("Travel Package: %s\n",cape_7.package);
						printf("Travel length: %s\n",cape_7.travel_length);
						printf("Fare per person: %d\n",cape_7.fare);
						cape_7_nyt_seats_alloted += no_of_passengers;
						available_seats = CRUISE_TOTAL_SEATS - cape_7_nyt_seats_alloted;
						return 1;
					}
					else
					{
						return available_seats;
					}
				}
				break;
			case 2: if(trip_length == 1)
					{
						if(no_of_passengers <= (CRUISE_TOTAL_SEATS - barcelona_seats_alloted))
						{
							struct package_choosen berec_7;
                            strcpy(berec_7.package,"Barcelona to Europe");
                            strcpy(berec_7.travel_length,"7 Nights");
                            berec_7.fare = 1299;
                            printf("Travel Package: %s\n",berec_7.package);
                            printf("Travel length: %s\n",berec_7.travel_length);
                            printf("Fare per person: %d\n",berec_7.fare);
							barcelona_seats_alloted += no_of_passengers;
							available_seats = CRUISE_TOTAL_SEATS - barcelona_seats_alloted;
							return 1;
						}
						else
						{
							return available_seats;
						}
					}
					break;
            case 3: if(trip_length == 1)
					{
						if(no_of_passengers <= (CRUISE_TOTAL_SEATS - honolulu_7_nyt_seats_alloted))
						{
							struct package_choosen Honolu_7;
                            strcpy(Honolu_7.package,"Honolulu to Hawaii");
                            strcpy(Honolu_7.travel_length,"7 Nights");
                            Honolu_7.fare = 1499;
                            printf("Travel Package: %s\n",Honolu_7.package);
                            printf("Travel length: %s\n",Honolu_7.travel_length);
                            printf("Fare per person: %d\n",Honolu_7.fare);
							honolulu_7_nyt_seats_alloted += no_of_passengers;
							available_seats = CRUISE_TOTAL_SEATS - honolulu_7_nyt_seats_alloted;
							return 1;
						}
						else
						{
							return available_seats;
						}
					}
					else
					{
						if(no_of_passengers <= (CRUISE_TOTAL_SEATS - honolulu_10_nyt_seats_alloted))
						{
							struct package_choosen Honolu_10;
                            strcpy(Honolu_10.package,"Honolulu to Hawaii");
                            strcpy(Honolu_10.travel_length,"10 Nights");
                            Honolu_10.fare = 1999;
                            printf("Travel Package: %s\n",Honolu_10.package);
                            printf("Travel length: %s\n",Honolu_10.travel_length);
                            printf("Fare per person: %d\n",Honolu_10.fare);
							honolulu_10_nyt_seats_alloted += no_of_passengers;
							available_seats = CRUISE_TOTAL_SEATS - honolulu_10_nyt_seats_alloted;
							return 1;
						}
						else
						{
							return available_seats;
						}
					}
					break;
		}

}


