#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * @brief structure to store the travel package details selected by the passenger
 */
struct package_choosen
{
    char package[100];
    char travel_length[100];
    int fare;
};

/**
 * @brief Maximum number of seats available in all the cruises
 */
#define CRUISE_TOTAL_SEATS 100


/**
 * @brief Checks the availability of the requested number of seats in the particular cruise
 * 
 * @param[in] travel_package      type of travel package selected
 * @param[in] trip_length         number of nights of travel
 * @param[in] no_of_passengers    Total number of passengers travelling
 * 
 * @return  1 if seats available, else return 0.
 */
 int package_availability(int travel_package,int trip_length,int no_of_passengers);


/**
 * @brief Stores the details of all the passengers travelling
 * 
 * @param[in] no_of_passengers    Total number of passengers travelling
 * 
 * @return returning the head address of the linked list
 */
int passenger_details(int  num_of_pass);

/**
 * @brief available number of seats is updated after every booking confirmation
 */
int available_seats;

/*
* @brief Keeps track of the booked number of seats of Cape Liberty to Bermuda - 5 Nights Cruise
*/
static int cape_5_nyt_seats_alloted = 0;

/*
* @brief Keeps track of the booked number of seats of Cape Liberty to Bermuda - 7 Nights Cruise
*/
static int cape_7_nyt_seats_alloted = 0;

/*
* @brief Keeps track of the booked number of seats of Barcelona to Europe - 7 Nights Crusie
*/
static int barcelona_seats_alloted = 0;

/*
* @brief Keeps track of the booked number of seats of Honolulu to Hawaii - 7 Nights Crusie
*/
static int honolulu_7_nyt_seats_alloted = 0;

/*
* @brief Keeps track of the booked number of seats of Honolulu to Hawaii - 10 Nights Crusie
*/
static int honolulu_10_nyt_seats_alloted = 0;


