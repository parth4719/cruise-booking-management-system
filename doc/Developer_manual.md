# Introduction

Cruise Booking Management System (**CBMS**) is a software prototype developed based on the requirements of a cruise company to provide their customers with a booking platform. This is a prototype whose functionality can be tested on a single computer. The software helps in booking the tickets for the cruises for different destinations. It allows to book the tickets according to the availability of seats and suites in the specific cruise opted by the user. If there is no availability, the user will be able to book among the ones which are available. It calculates the total fare based on the given cruise fare/per person. It also applies specified discount automatically to the total fare, based on age of passengers, group size and also according to types of suites selected for each booking. The software will be able to do partial and full cancellation using the booking ID provided to the user. In partial cancellation, software helps in removing the passengers from the booking and re-calculates the total fare according to the changes, and in full cancellation, the software cancels the whole booking and calculates the refundable amount, by deducting the cancellation charges from the total amount paid by the users. 

 The cruise company offers various packages and discounts based on the user-preferred categories. The booking is made depending on the availability of rooms. The passenger can also select the type of room they want to book. If the passenger falls under a category which has a discount, it is applied accordingly. The food and all the other facilities such as gym, pools etc., can be accessed by all the passengers. They can also cancel the tickets and the refund will be processed after deduction of certain charges. The data required to make bookings, cancellations and the data obtained during booking are all stored in files. Since this is a protoype, it only obtains information about cancellations and gives information about refund. The cancellation of tickets is done in this project, but the refunds are not being processed or tracked. The cruise booking management system (CBMS) software helps in booking the tickets for the cruises for different source and destination places. 
 
# Requirement
Software needs to book the tickets for different cruise packages mentioned in the "Details.csv" , which will be read and printed  for the user to select from. The software should check the availability of rooms for given number of passengers for the respective cruise selected by the users. If seats are available, the software should ask the passengers to provide thier details like name, age, gender, email and if specially disabled (yes/no). The software should read the file "suite_selection.csv" of the selected cruise and display the suites available for the user to select from. It also should check the availability of suites for the requested number of passengers. If particular selected suite is not available the user should be asked to select among the ones which are available. The software should be able to calculate the total fare by considering the fare provided in "Details.csv" and different suite fares given in "suite_selection.csv". The software should also check if the passenger's age is eligible for specific discounts. The total fare should be calculated and asked for the confirmation of booking from the user. If user confirms, the booking ID will be provided.

After each booking is confirmed, the software should automatically do the following:
-  update the seats available for each cruise in "Details.csv".
-  update the available no. of rooms  in "suite_selection.csv" 
-  The passenger details should get stored in "Passenger_details.csv" 
-  Information about count of each type of suite booked and cruise name will be stored  in "Bookings_info.csv".

For Cancelllation of booking, the software needs to ask the user to provide booking ID and display the booking details consisting of booking Id, cruise number, cruise name, total no. of passsengers , total fare and type of suites booked. The software needs to provide two options for cancellation, i.e. 1.Full Cancellationand 2. Partial Cancellation. If Full cancellation is choosen by user, the software should calculate the refundable amount by deducting some fixed cancellation charges and ask for the confirmation of cancelling. If the passenger requets for partial cancellation, the software will ask for the names in that particular booking to be deleted , and it should ask the passengers to rebook the rooms for the updated number of passengers, and total fare will be calculated and asks for the confirmation.

* Each time the Full cancellation is confirmed by the user, the software should automatically do the following :
  - The available seats in the respective cruise will be updated in the "Details.csv", by increasing the no. of seats count that were cancellled.
  - The available suite types will be updated in the respective "suite_selection.csv" by increasing the respective suite count by adding the number of suites that were cancelled.
  - The passenger details of that particular booking cancelled, will be deleted from the "Passenger_details.csv".
  - The row with the booking ID gets deleted from the "Bookings_info.csv".
* Each time the Partial cancellation is confirmed by the user, the software needs to   
 update the following automatically:
  - The requested names to be removed from the respective booking  will be deleted from the "Passengers_details.csv".
  

# Assumption
1. **"Details.csv"** ---> Contains information regarding cruise package name, total fare per person and available no. of seats in all the cruises mentioned. For now, five cruises are considered:
  ---1. Cape Liberty to Bermuda - 5 nights
  ---2. Cape Liberty to Bermuda - 7 nights
  ---3. Berceleno to Europe - 7 nights
  ---4. Honolulu to Hawaii - 7 nights
  ---5. Honolulu to Hawaii - 10 nights

   - User can add more cruise options by providing details like source and destination, total fare per person and also the total seats available in all the cruises  in the [Details.csv](https://github.com/thej-rayasam/cruise-booking-management-system/blob/master/src/Details.csv)
   
2.  **"suite_selection.csv"** ---> Contains information regarding different types of suite names, no. of suites available, suite capacity, additonal fare and discounts. For now the following suite types are considered.
 ---1. Inside state room - 10 rooms
 ---2. Outside state room - 8 rooms
 ---3. Balcony room - 6 rooms
 ---4. Suite room - 4 rooms
 ---5. Family room - 4 rooms
 ---6. Honeymoon suite - 2 rooms
 ---7. Solo cabin - 4 rooms
    - User can add more suite options by updating the information in [Suite_selection.csv](https://github.com/thej-rayasam/cruise-booking-management-system/blob/master/src/1suite_selection.csv)
	- The user should name the files suiteselction.csv in series providing the number of the cruise as a prefix for the file name. Example: [1Suite_selection](https://github.com/thej-rayasam/cruise-booking-management-system/blob/master/src/1suite_selection.csv) belongs to package name 1 mentioned in the [Details.csv](https://github.com/thej-rayasam/cruise-booking-management-system/blob/master/src/Details.csv). 
(*****************Complete this line properly****).
	- Suppose if the client wants to add extra type of room only in one of the cruises. The client should add the details of that particular room in the respective "suite_selection.csv" file. And also has to update the other suite_selection files, with the new room type, but keeping the room count as zero, just for the consistency of the workflow. 


# Program Flow
The program flow for the application is as follows:
- The main.c file calls the booking.c or cancellation.c based on the input from the user.
- The **booking.c** file helps in booking the tickets for different crusies.
- The booking.c file calls:
  - The **package_availability.c** ---> This function is used to check the availabilty of 
     the seats in the particular cruise selected by the user.
  - The **passenger_details.csv** --->  This function gets the passenger name, age , gender, email and if specially abled(yes/no) as a input from the user.
  - The **suite_selection.c** ---> This function is called from booking.c to help the user select different types of suites in the cruises, It also checks if the selected suite is available for the given number of passengers, if not the user will be allowed to select among the other suites which are available.
  - The **fare_calculation.c** ---> This function is called from booking.c ,it helps to calculate the total fare of the all the bookings made by the user.
- Once the booking is confirmed by the user, it calls the functions in booking.c to automatically update the following files:
  - **"Details.csv"** ---> The count of available seats will be modified each time the booking is confirmed by reducing the number of seats booked for the respective cruises.
  -  **"Passenger_details.csv"**---> Everytime the  booking is confirmed the passenger details of the respective booking gets stored into this file.
  -  **"Bookings-info.csv"**---> After every booking confirmation,  information about selected crusie type, and count of each suites type booked will be updated in this file.
  -  **"Suite_selction.csv"**---> After the confirmation of every booking, the count of each type of suites left available in all the cruises, will be updated into respective cruise suite_selection.csv file. 
  - The cancellation.c is called to ask the user for 1. Full Cancellation or 2. Partial Cancelaltion.
  - If the user selects Full Cancellation, the full_cancellation.c function is called, it displays the booking details using the booking ID, and Total fare will be displayed by reducing the cancellation chanrges. The user will be asked for the confirmation. IF the user confirms, all the detials of that particular booking will be deleted from the files.
