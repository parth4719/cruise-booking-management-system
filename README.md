# GROUP-G CRUISE BOOKING MANAGEMENT SYSTEM
* [Application Overview](#application-overview)
* [Group Information](#group-information)
* [Installation](#file-structure)
* [File Structure](#file-structure)
* [Documentation](#documentation)


## Application Overview
  The cruise booking management system (**CBMS**) helps in booking the tickets for cruises for, different source and destinations. The booking will be made based on the seats and suites availability of different cruises. The passenger can book the suites of their own preference, suppose if chosen suites are not available, the passenger will be allowed to select among the ones which are available for a booking. Discounts will be provided based on the age of the passenger and will be applied automatically if applicable. The user can also make cancellation of the booking, by providing booking ID. The refund will be displayed after deducting some fixed cancellation charges.

## Group Information

**Organization:**  Carleton University (SYSC 5709W)

### Authors 

1.	** Spandana Manjappa Karehanumannara ** - kmspandanakarehanuma@cmail.carleton.ca
       * GITHUB: Spandukm

3.	 ** Swetha Meenakshi Natarajan ** - swethameenakshinatar@cmail.carleton.ca
       * GITHUB: swethameenakshinatarajan

4.	 ** Thejprabhath Rayasam ** - thejprabhathrayasam@cmail.carleton.ca
       * GITHUB: thej-rayasam

5.	 ** Vishnu Rajasekar ** - vishnurajasekar@cmail.carleton.ca
	   * GITHUB: vishnurajasekar25
	   

## Installation

Installation steps are mentioned in [INSTALL.md](*********Provide the link for Install.md****)


## File Structure
The following file structure is used to organize files in this repository:
```
├── assets      -> Flowchart 
├── bin 	-> Binary directory
│   ├── CBMS.exe
├── doc 	-> Usage file
│   ├── User_Manual.md
│   ├── Developer_Manual.md
│   ├── INSTALL.md -> Installation Guide
│   └── html 	-> Doxygen document
│   ├── latex
│   └── man/man3
│   ├── rtf
│   └── xml  	
├── include 	-> Header files
│   ├── add_passenger.h
│   ├── booking.h
│   ├── cancellation.h
│   └── fare_calculation.h
│   ├── fare_cancellation.h
│   ├── main.h
│   ├── package_availability.h
│   ├── passenger_details.h
│   ├── read_file.h
│   ├── refund_calculation.h
│   └── remove_passenger.h
│   ├── suite_selection.h
│   ├── update_suite_selection.h
├── obj 	-> Object files
├── src 	-> Source files 
│   ├── 1suite_selection.csv
│   ├── 2suite_selection.csv 
│   ├── 3suite_selection.csv
│   ├── 4suite_selection.csv
│   ├── 5suite_selection.csv
│   └── add_pass.c
│   ├──	add_passenger.c     
│   ├── age_group_discount.csv
│   ├── booking.c 
│   ├── Bookings_info.csv
│   ├── cancellation.c  
│   ├── delete_passenger.c        
│   └── Details.csv
│   ├── disability_discount.csv 
│   ├── display_booking_details.c    
│   ├── fare_calculation.c      
│   ├── full_cancellation.c
│   ├── group_size_discount.csv
│   └── main.c       
│   ├── package_availability.c
│   ├── passenger_details.c       
│   ├── passenger_details.csv
│   ├── read_file.c        
│   ├── refund_calculation.c       
│   └── remove_passenger.c        
|   ├── suite_selection.c     
|   ├── update_seats.c  
|   ├── update_suite_selection.c 
│   └── write_into_file.c       
└── test
│   ├── include		-> Header file for unit test
│     └── test.h
│   ├── test.c 
├── Doxyfile_config	-> Doxygen file 
├── LICENSE 	-> License file
├── Makefile 	-> Makefile
├── README.md 	-> Readme file

```
## DOCUMENTATION


## Usage
To run, you must first install it. Then you can follow instructions mentioned in [User_Manual.md](***provide link for user_manual.md***).


## For Developers
 
The developer manual is available  [Developer_Manual.md](**provide the link for [Developer_Manual.md]*** ).


##  License

This project is licensed under the GPL 2.0 License - see the LICENSE.md file for details

## Acknowledgements

Thanks to **Dr. Cristina Ruiz Martin** for providing guidance on how to develop the software.
