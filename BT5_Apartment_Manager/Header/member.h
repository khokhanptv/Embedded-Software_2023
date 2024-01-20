/*
* File: Member.h
* Author: Tran Nhat Thai
* Date: 19/01/2024
* Description: This file is the header file for managing members in the apartment management program.
*/

#ifndef MEMBER_H
#define MEMBER_H

typedef struct {
    char uid[20];            // Unique identifier for the member
    char roomNumber[10];     // Room number associated with the member
    char name[50];           // Name of the member
    char licensePlate[20];   // License plate number of the member
} Member;

typedef struct MemberNode {
    Member data;                 // Data (Member) stored in the node
    struct MemberNode* next;     // Pointer to the next node in the linked list
} MemberNode;

MemberNode* createMemberNode(Member member);
void addMember(const char* filename, Member member);
void displayMembers(const char* filename);
int searchByUID(const Member* member, const char* uid);
int searchByLicensePlate(const Member* member, const char* licensePlate);
void deleteMember(const char* filename, const char* uid);
void editMember(const char* filename, Member updatedMember);
int searchMember(const char* filename, const char* searchValue, int (*searchFunc)(const Member*, const char*));

#endif
