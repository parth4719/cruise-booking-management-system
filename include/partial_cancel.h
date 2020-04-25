#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int get_fare(int cruise_no);

void modify_passenger_details(int n);

void passenger_remove(int id, int no_of_pass, int pass_remove);

void modify_suite_selection(int cruise_number, int *rooms, int no_of_pass, int pass_remove);

void modify_package_details(int cruise_number, int no_of_pass, int pass_remove);

void new_fare(int cruise_number, float *fare, float cancel_fee, float refund, int n, int *suites, int cruise_fare);

void modify_booking(int id, int pass_remove, int *rooms, float f, float cancel_fee, float refund, int cruise_fare, int cruise_no);
