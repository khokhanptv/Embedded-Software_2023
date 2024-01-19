/*
* File: Customer.h
* Author:Tran Nhat Thai
* Date: 19/0/2024
* Description: Description: This file is the member header file of the apartment management program
*/


#ifndef MEMBER_H
#define MEMBER_H
/*
* Description: Defines a data structure (struct) named Member, containing information about the member, including uid, roomNumber, name, and licensePlate.
*/
typedef struct {
    char uid[20];
    char roomNumber[10];
    char name[50];
    char licensePlate[20];
} Member;
/*
* Description: Defines a linked list node structure (struct) named MemberNode, representing a node in the linked list of members.
*/
typedef struct MemberNode {
    Member data;
    struct MemberNode* next;
} MemberNode;

c
Copy code
/*
* File: Member.h
* Author: Tran Nhat Thai
* Date: 19/01/2024
* Description: This file is the header file for managing members in the apartment management program.
*/

#ifndef MEMBER_H
#define MEMBER_H

/*
* Description: Defines a data structure (struct) named Member, containing information about the member, including uid, roomNumber, name, and licensePlate.
*/
typedef struct {
    char uid[20];            // Unique identifier for the member
    char roomNumber[10];     // Room number associated with the member
    char name[50];           // Name of the member
    char licensePlate[20];   // License plate number of the member
} Member;

/*
* Description: Defines a linked list node structure (struct) named MemberNode, representing a node in the linked list of members.
*/
typedef struct MemberNode {
    Member data;                 // Data (Member) stored in the node
    struct MemberNode* next;     // Pointer to the next node in the linked list
} MemberNode;

/*
* Description: Creates and returns a new MemberNode with the given Member data.
* Input:
*   - member: Member data to be stored in the node
* Output:
*   - Returns a pointer to the newly created MemberNode.
*/
MemberNode* createMemberNode(Member member);
/*
* Description: Adds a new member to the specified file by appending the member's information to the end of the file.
* Input:
*   - filename: The name of the file to which the member information will be added.
*   - member: The Member data to be added.
* Output: None
*/
void addMember(const char* filename, Member member);
/*
* Description: Displays the list of members stored in the specified file.
* Input:
*   - filename: The name of the file from which member information will be displayed.
* Output: None
*/
void displayMembers(const char* filename);
/*
* Description: Searches for a member in the specified file by UID.
* Input:
*   - member: The Member data to be searched.
*   - uid: The UID (Unique Identifier) to search for.
* Output:
*   - Returns 1 if the member with the specified UID is found; otherwise, returns 0.
*/
int searchByUID(const Member* member, const char* uid);
/*
* Description: Searches for a member in the specified file by license plate.
* Input:
*   - member: The Member data to be searched.
*   - licensePlate: The license plate number to search for.
* Output:
*   - Returns 1 if the member with the specified license plate is found; otherwise, returns 0.
*/
int searchByLicensePlate(const Member* member, const char* licensePlate);
/*
* Description: Deletes a member with the specified UID from the specified file.
* Input:
*   - filename: The name of the file from which the member will be deleted.
*   - uid: The UID (Unique Identifier) of the member to be deleted.
* Output: None
*/
void deleteMember(const char* filename, const char* uid);
/*
* Description: Edits the information of a member with the specified UID in the specified file.
* Input:
*   - filename: The name of the file in which the member's information will be edited.
*   - updatedMember: The updated Member data.
* Output: None
*/
void editMember(const char* filename, Member updatedMember);
/*
* Description: Searches for a member in the specified file based on a search value using a specified search function.
* Input:
*   - filename: The name of the file in which the search will be performed.
*   - searchValue: The value to search for.
*   - searchFunc: A function pointer to the search function (searchByUID or searchByLicensePlate).
* Output:
*   - Returns 1 if the member with the specified search value is found; otherwise, returns 0.
*/
int searchMember(const char* filename, const char* searchValue, int (*searchFunc)(const Member*, const char*));

#endif
