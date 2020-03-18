#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Creating the structure to store the details
struct details
{
    char name[20];
    int age;
    char gender[10];
    char email[20];
    struct details *next;
};
//Function that stores the passenger details into a linked list and return the head address
int passenger_details(int no_of_pass)
{
    int track = 1,k = no_of_pass, count = 1;
    char name[20];
    int age;
    char gender[10];
    char email[20];
    struct details *head = NULL;
    struct details *passenger = NULL;
    struct details *temp = NULL;
    printf("\nEnter passenger details :\n");
    for(no_of_pass;no_of_pass!=0;no_of_pass--)
    {
        //Getting the details and storing in a structure
        passenger = (struct details*)malloc(sizeof(struct details));
        printf("Enter the name of passenger-%d \n",track);
        scanf("%s",&name);
        strcpy(passenger->name,name);
        printf("Enter the age of passenger-%d \n",track);
        scanf("%d",&age);
        passenger->age=age;
        printf("Enter the gender of passenger-%d \n",track);
        scanf("%s",&gender);
        strcpy(passenger->gender,gender);
        printf("Enter the email of passenger-%d \n",track);
        scanf("%s",&email);
        strcpy(passenger->email,email);
        //Adding first passenger to the linked list
        if (head == NULL)
        {
            head = passenger;
            head->next = NULL;
        }
        //Adding next passenger to the end of the linked list
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = passenger;
        passenger->next = NULL;
        track++;
    }
    //Printing the passenger details
    temp=head;
    printf("\nThe passenger details are:\n\n");
    for(k;k!=0;k--)
    {
        if(head==NULL)
        {
            printf("Empty list !!");
            return 0;
        }
        printf("passenger-%d details:\n",count);
        printf("Name : %s\n",temp->name);
        printf("Age : %d\n",temp->age);
        printf("Gender : %s\n",temp->gender);
        printf("Email : %s\n",temp->email);
        printf("\n");
        temp = temp->next;
        count++;
    }
    return head; //returning the head address of the linked list
}
void main()
{
    int no_of_pass = 0, head_address = 0;
    printf("Input number of passangers:\n");
    scanf("%d",&no_of_pass);
    if(no_of_pass <= 0)
    {
        printf("No passengers to be added");
        exit(0);
    }
    head_address = passenger_details(no_of_pass);
    printf("The memory address is %d \n",head_address);
}
