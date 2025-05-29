#include "p2-support.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////
////
//// File           : p2-support.c
//// Description    : This is a set of functions used to create/operate a menu driven email client, used for CMSC 257 project #2. Fall 2022
//// Author         : ***Ebenezer Hailu ***
//// Date           : ***11/11***
//// Notes          : ***align show inbox and indent   

void initialize (struct Mailbox *ib) {
	//allocate memory for 2000 emails
	ib->emails = malloc (sizeof (struct Email) * MAILBOX_SIZE);
	ib->size = 0;
	create_email ("asonmez@mail.com", user_email, "Welcome to your inbox.",
			"Welcome to your inbox, just wanted to say hi. Here's hoping you get all your code done.",
			11,20,2020, ib);
	create_email ("mmartinez@mail.com", user_email, "Padding out your inbox.",
			"Yet another email just to pad out your inbox, have fun!",
			11,30,2020, ib);
	create_email ("dboyle@mail.com", user_email, "3rd email!",
			"Alright, time for another email for your inbox. Not going too lie, it's a bit of a pain coming up with stuff for these strings. Anyways, have fun with your code!",
			12,2,2020, ib);
	create_email ("cbluer@mail.com", user_email, "4th email!",
			"Content of fourth email. More coding, more fun!",
			12,8,2020, ib);
	create_email ("cboyle@mail.com", user_email, "5th email!",
			"Content of fifth email. Coding is fun-tastic!",
			12,18,2020, ib);
	create_email ("sblack@mail.com", user_email, "6th email!",
			"Content of fifth email. Coding is fun-tastic!",
			1,1,2021, ib);
	create_email ("sblack@mail.com", user_email, "7th email!",
			"Body of sixth email. Coding is fun-tastic!",
			1,5,2021, ib);
	create_email ("sblack@mail.com", user_email, "8th email!",
			"Body of eighth email. Coding is fun-tastic!",
			2,15,2021, ib);
	create_email ("sblack@mail.com", user_email, "9th email!",
			"Body of ninth email. Coding is fun-tastic!",
			2,25,2021, ib);
	create_email ("dboyle@mail.com", user_email, "Last email!",
			"Body of tentth email. Coding is fun-tastic!",
			3,15,2021, ib);
}



void create_email(char sender[], char receiver[], char subject[], char body[], int month, int day, int year, struct Mailbox *ib) {
	strcpy(ib->emails[ib->size].sender, sender);
	strcpy(ib->emails[ib->size].receiver, receiver);
	strcpy(ib->emails[ib->size].body, body);
	strcpy(ib->emails[ib->size].subject, subject);
	ib->emails[ib->size].date.month = month;
	ib->emails[ib->size].date.day = day;
	ib->emails[ib->size].date.year = year;
	ib->emails[ib->size].id = ib->size;
	ib->size++;
}

// 1, GOOD

void display_inbox_menu(struct Mailbox *ib) {
	int num;
	int place = 1;
	while (place == 1) {
		char asterik[] = "***************";
		printf("\n%s\t HAILUEA@VCU.EDU INBOX \t%s\n", asterik, asterik);
		printf("%s\t Total Inbox: %04d\t%s\n", asterik, ib->size, asterik);

		printf("\n1. Show Inbox\n2. Show Email by ID\n3. Sort Inbox by Sender\n4. Sort Inbox by ID\n5. Search Inbox by Keyword\n6. Delete\n7. Exit Inbox\n\n");
		scanf("%d", &num);

		if (num == 1) {
			show_inbox(ib);
		}

		else if (num == 2) {
			printf("\nEnter the ID of the email you want to read:\n");
			int id;
			scanf("%d", &id);
			show_email_id(id, ib);  
		}

		else if (num == 3) { 
			qsort(ib->emails, ib->size, sizeof(struct Email), sort); 
		}

		else if (num == 4) {
			qsort(ib->emails, ib->size, sizeof(struct Email), sort_id);
		}

		else if (num == 5) {
			printf("\nEnter the keyword you are searching for:\n");
			char word[10];
			scanf("%s", word);
			printf("\n");
			search_keyword(word, ib); 
		}

		else if (num == 6) {
			printf("\nEnter the ID of the e-mail you want to delete:\n");
			int id;
			scanf("%d", &id);
			delete_email(id, ib);
		}
		else if (num == 7) {
			place = 0; 
			printf("\nExiting e-mail client - Good Bye!\n\n");
			free(ib->emails);
		}
		else {
			printf("Input a number that is on screen.");
		}
	}
}

// 1, GOOD
void show_inbox(struct Mailbox *ib) {
	printf("\nID\tSENDER--------------\tMM/DD/YYYY\tSUBJECT--------\n");
	printf("--\t--------------------\t--/--/----\t---------------\n");

	for (int i = 0; i < ib->size; i++) {
		printf("%02d\t%-20.20s\t%d/%d/%d\t%-15.15s\n", ib->emails[i].id, ib->emails[i].sender, ib->emails[i].date.month, ib->emails[i].date.day, ib->emails[i].date.year, ib->emails[i].subject);
	}
}

// 2, GOOD
void show_email_id(int a, struct Mailbox *ib) {
	for (int i = 0; i < ib->size; i++) {
		if (ib->emails[i].id == a) {
			printf("\n%s - %s\n", ib->emails[i].sender, ib->emails[i].subject);
			printf("Email Received on: %d/%d/%d\n\n", ib->emails[i].date.month, ib->emails[i].date.day, ib->emails[i].date.year);
			printf("%s\n\n", ib->emails[i].body);
		}
	}
}

// 3, GOOD, only error is it shifts the ID
int sort(const void* a, const void* b) {
	struct Email *one = (struct Email*) a;
	struct Email *two = (struct Email*) b;

	return strcmp(one->sender, two->sender); 
}


// 4
int sort_id(const void* a, const void* b) {
	struct Email *one = (struct Email*) a;
	struct Email *two = (struct Email*) b;

	return one->id > two->id;
}



// 5, GOOD
void search_keyword(char word[10], struct Mailbox *ib) {
	printf("ID\tSENDER--------------\tMM/DD/YYYY\tSUBJECT--------\n");
	printf("--\t--------------------\t--/--/----\t---------------\n");
	for (int i = 0; i < ib->size; i++) {
		if (strstr(ib->emails[i].body, word) || strstr(ib->emails[i].sender, word)) { 
			printf("%02d\t%-20.20s\t%d/%d/%d\t%-15.15s\n", ib->emails[i].id, ib->emails[i].sender, ib->emails[i].date.month, ib->emails[i].date.day, ib->emails[i].date.year, ib->emails[i].subject);
		}

	}
}


//6
void delete_email(int a, struct Mailbox *ib) {
	if (a >= 0 && a < ib->size) {
		for (int i = 0; i < ib->size; i++) { 
			if (ib->emails[i].id == a) {
				for (int j = i ; j < ib->size - 1; j++) {
					ib->emails[j] = ib->emails[j+1];
				}
				ib->size--;
				printf("Email with ID = %d is deleted\n", a);
				return;
			}

		} 
	}
	else
		printf("ID is not between 0 and the size (%d)", ib->size);
}

