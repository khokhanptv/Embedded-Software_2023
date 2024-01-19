/*
* File: main.c
* Author: Tran Nhat Thai
* Date: 19/01/2024
* Description: Main program file for managing apartment members
*/

#include "D:\TEST\Header\member.h"
#include <stdio.h>
#include <stdlib.h>

#define add_member 0
#define delete_member 1
#define find_UID_member 2
#define find_licensePlates_member 3
#define update_member 4
#define out 5

int main() {
    int choice;
    char searchValue[20];

    do {
        printf("\nMenu:\n");
        printf("0 - Add member\n");
        printf("1 - Delete member\n");
        printf("2 - Search by UID\n");
        printf("3 - Search by license plate\n");
        printf("4 - Update member\n");
        printf("5 - Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        getchar(); // Read and discard the newline character left in the input buffer

        switch (choice) {
            case add_member: {
                Member newMember;
                printf("Enter information for the new member:\n");
                
                printf("UID: ");
                fgets(newMember.uid, sizeof(newMember.uid), stdin);
                newMember.uid[strcspn(newMember.uid, "\n")] = '\0';

                printf("Room Number: ");
                fflush(stdin);
                fgets(newMember.roomNumber, sizeof(newMember.roomNumber), stdin);
                newMember.roomNumber[strcspn(newMember.roomNumber, "\n")] = '\0';

                printf("Name: ");
                fflush(stdin);
                fgets(newMember.name, sizeof(newMember.name), stdin);
                newMember.name[strcspn(newMember.name, "\n")] = '\0';

                printf("License Plate: ");
                fflush(stdin);
                fgets(newMember.licensePlate, sizeof(newMember.licensePlate), stdin);
                newMember.licensePlate[strcspn(newMember.licensePlate, "\n")] = '\0';

                addMember("10000_Members.CSV", newMember);
                printf("Member has been added.\n");
                break;
            }
            // ... (Add similar handling for other cases)
        }
    } while (choice != 5);

    return 0;
}
