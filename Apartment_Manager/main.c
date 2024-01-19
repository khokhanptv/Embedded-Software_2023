#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define add_member 0
#define delete_member 1
#define find_UID_member 2
#define find_licensePlates_member 3
#define update_member 4
#define out 5

// Structure to store basic information about residents
typedef struct {
    char uid[20];          // RFID UID
    char roomNumber[10];   // Room Number
    char name[50];         // Name
    char licensePlate[20]; // License Plate Number
} Member;

// Node structure in linked list containing Member information
typedef struct MemberNode {
    Member data;
    struct MemberNode* next;
} MemberNode;

// Function to create a new MemberNode
MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}

// Function to add a member and write to the CSV file
void addMember(const char* filename, Member member) {
    FILE* file = fopen(filename, "a");

    if (file == NULL) {
        perror("Unable to open CSV file");
        return;
    }

    fprintf(file, "%s,%s,%s,%s\n", member.uid, member.roomNumber, member.name, member.licensePlate);
    fclose(file);
}

// Function to display the list of members from the CSV file
void displayMembers(const char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        perror("Unable to open CSV file");
        return;
    }

    printf("List of Members:\n");
    printf("UID\t\tRoom\tName\t\tLicense Plate\n");

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        char* token = strtok(line, ",");
        while (token != NULL) {
            printf("%s\t", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose(file);
}

// Function to search based on UID
int searchByUID(const Member* member, const char* uid) {
    return strcmp(member->uid, uid) == 0 ? 1 : 0;
}

// Function to search based on license plate number
int searchByLicensePlate(const Member* member, const char* licensePlate) {
    return strcmp(member->licensePlate, licensePlate) == 0 ? 1 : 0;
}

// Function to delete a member based on UID from the CSV file
void deleteMember(const char* filename, const char* uid) {
    FILE* file = fopen(filename, "r");
    FILE* tempFile = fopen("temp.csv", "w");

    if (file == NULL || tempFile == NULL) {
        perror("Error opening CSV file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        char tempUID[20];
        sscanf(line, "%[^,],", tempUID); // Read UID from the line

        // If UID does not match, write to the temp file
        if (strcmp(tempUID, uid) != 0) {
            fprintf(tempFile, "%s", line);
        }
    }

    fclose(file);
    fclose(tempFile);

    // Delete the original file and rename the temp file to the original filename
    remove(filename);
    rename("temp.csv", filename);
}

// Function to edit member information based on UID in the CSV file
void editMember(const char* filename, Member updatedMember) {
    FILE* file = fopen(filename, "r");
    FILE* tempFile = fopen("temp.csv", "w");

    if (file == NULL || tempFile == NULL) {
        perror("Error opening CSV file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        char tempUID[20];
        sscanf(line, "%[^,],", tempUID); // Read UID from the line

        // If UID does not match, write to the temp file
        if (strcmp(tempUID, updatedMember.uid) != 0) {
            fprintf(tempFile, "%s", line);
        } else {
            // If UID matches, write the updated information to the temp file
            fprintf(tempFile, "%s,%s,%s,%s\n", updatedMember.uid, updatedMember.roomNumber, updatedMember.name, updatedMember.licensePlate);
        }
    }

    fclose(file);
    fclose(tempFile);

    // Delete the original file and rename the temp file to the original filename
    remove(filename);
    rename("temp.csv", filename);
}

// Function to search for a member based on UID or license plate number
int searchMember(const char* filename, const char* searchValue, int (*searchFunc)(const Member*, const char*)) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        perror("Unable to open CSV file");
        return -1;
    }

    Member member;
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%[^,],%[^,],%[^,],%s", member.uid, member.roomNumber, member.name, member.licensePlate);

        // If the search value is found, display member information and close the file
        if (searchFunc(&member, searchValue) == 1) {
            printf("Member Information:\n");
            printf("UID: %s\n", member.uid);
            printf("Room: %s\n", member.roomNumber);
            printf("Name: %s\n", member.name);
            printf("License Plate: %s\n", member.licensePlate);
            fclose(file);
            return 1;
        }
    }

    printf("Member not found with value: %s\n", searchValue);
    fclose(file);
    return 0;
}

int main() {
     SetConsoleOutputCP(65001);
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

        switch (choice) {
            case add_member: {
                Member newMember;
                printf("Enter information for the new member:\n");
                printf("UID: ");
                scanf("%s", newMember.uid);
                printf("Room Number: ");
                scanf("%s", newMember.roomNumber);
                printf("Name: ");
                scanf("%s", newMember.name);
                printf("License Plate: ");
                scanf("%s", newMember.licensePlate);
                addMember("10000_Members.CSV", newMember);
                printf("Member has been added.\n");
                break;
            }
            case delete_member: {
                char deleteUID[20];
                printf("Enter the UID of the member to delete: ");
                scanf("%s", deleteUID);
                deleteMember("10000_Members.CSV", deleteUID);
                printf("Member has been deleted.\n");
                break;
            }
            case find_UID_member: {
                printf("Enter the UID to search: ");
                scanf("%s", searchValue);
                searchMember("10000_Members.CSV", searchValue, searchByUID);
                break;
            }
            case find_licensePlates_member: {
                printf("Enter the license plate to search: ");
                scanf("%s", searchValue);
                searchMember("10000_Members.CSV", searchValue, searchByLicensePlate);
                break;
            }
            case update_member: {
                Member updatedMember;
                printf("Enter the UID of the member to update: ");
                scanf("%s", updatedMember.uid);
                printf("Enter the new information:\n");
                printf("Room Number: ");
                scanf("%s", updatedMember.roomNumber);
                printf("Name: ");
                scanf("%s", updatedMember.name);
                printf("License Plate: ");
                scanf("%s", updatedMember.licensePlate);
                editMember("10000_Members.CSV", updatedMember);
                printf("Member information has been updated.\n");
                break;
            }
            case out:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }

    } while (choice != 5);

    return 0;
}
