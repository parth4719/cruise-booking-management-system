#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * @file passenger_details.h
 *
 * @brief Implementation of the linked list data structure.
 * Implements a linked-list for the purpose of storing the details of the passengers.
 */

/**
 * @brief Defining the structure.
 */

struct details
{
    char name[20];    //Name of the passenger
    int age;          //Age of the passenger
    char gender[10];  //Gender of the passenger
    char email[20];   //Email of the passenger
    struct details *next;
};

/**
 * @brief Creates a linked list which stores the details of the passengers
 *
 * @param[in] no_of_pass  The number of passengers to travel
 *
 * @details Creates a linked list consists of the above details of the passengers
 * which doesnot allow duplicate entries of the passengers
 *
 * @return The memory address of the head of the linked list
 */
int passenger_details(int no_of_pass);