# User Manual

**Table of Contents:**
* [Introduction](#introduction)
* [Install](#install)
* [How to Compile](#how-to-compile)
* [Usage](#usage)
* [Testing](#testing)
* [Help](#help)

# Introduction

The cruise booking management system (**CBMS**) helps in booking the tickets for cruises for, different source and destinations. The booking will be made based on the seats and rooms availability of different cruises. The passenger can book the rooms of their own preference, suppose if chosen rooms are not available, the passenger will be allowed to select among the ones which are available for a booking. Discounts will be provided based on the age of the passenger and will be applied automatically if applicable. The user can also cancel the booking made, by providing booking ID. The refund will be displayed after deducting some fixed cancellation charges.

# Install

* Installation steps are mentioned in [INSTALL.md](https://github.com/thej-rayasam/cruise-booking-management-system/blob/master/doc/INSTALL.md)

# How to Compile

* Copy or clone the repository files.

* Use `make clean` to remove the build artifacts during the initialization phase.

* Compile the entire system through `make`.

* Test the program by `make test` to build the test system.

# Usage

* The user needs to input the system with multiple csv files containing the package details along with the suite details for each of these packages which will be taken in as an input at different times of the program.

# Testing
Unit testing is done for the major functions that are defined in the system. the tes cases can be run by using the command:

        ` ./bin/CBMS -t `
# Help
User can run the command that's given below to get some help on the input parameters that are used.

        ` ./bin/CBMS -h `
