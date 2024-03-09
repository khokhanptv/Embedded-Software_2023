#include "D:\Embeded_T10\ADVANCED CC++ ALGORITHM T122023_BT\Apartment_Manager\Header\member.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DATA_FILE "10000_Members.CSV"
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

                addMember("DATA_FILE", newMember);
                printf("Member has been added.\n");
                break;
            }
            case delete_member: {
                char deleteUID[20];
                printf("Enter the UID of the member to delete: ");
                scanf("%s", deleteUID);
                deleteMember("DATA_FILE", deleteUID);
                printf("Member has been deleted.\n");
                break;
            }
            case find_UID_member: {
                printf("Enter the UID to search: ");
                scanf("%s", searchValue);
                searchMember("DATA_FILE", searchValue, searchByUID);
                break;
            }  

            case find_licensePlates_member: {
                printf("Enter the license plate to search: ");
                scanf("%s", searchValue);
                searchMember("DATA_FILE", searchValue, searchByLicensePlate);
                break;
            }
            case update_member: {
                Member updatedMember;
                printf("Enter the UID of the member to update: ");
                scanf("%s", updatedMember.uid);

                printf("Enter the new information:\n");
                printf("Room Number: ");
                fflush(stdin);
                fgets(updatedMember.roomNumber, sizeof(updatedMember.roomNumber), stdin);
                updatedMember.roomNumber[strcspn(updatedMember.roomNumber, "\n")] = '\0';

                printf("Name: ");
                fflush(stdin);
                fgets(updatedMember.name, sizeof(updatedMember.name), stdin);
                updatedMember.name[strcspn(updatedMember.name, "\n")] = '\0';

                printf("License Plate: ");
                fflush(stdin);
                fgets(updatedMember.licensePlate, sizeof(updatedMember.licensePlate), stdin);
                updatedMember.licensePlate[strcspn(updatedMember.licensePlate, "\n")] = '\0';

                editMember("DATA_FILE", updatedMember);
                printf("Member information has been updated.\n");
                break;
            }
            case out:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }

    } while (choice != out);

    return 0;
}
