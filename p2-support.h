#define MAILBOX_SIZE 2000
#define ADDRESS_SIZE 50
#define SUBJECT_SIZE 200
#define BODY_SIZE 2000
#define NAME_SIZE 20
//CHANGE the email below to your vcu email
#define user_email "hailuea@vcu.edu"
////add other define Macros as needed
 
// This is is an email struct that contains sender, receiver, subject, body, and id. 
// As well as a nested date struct that contains month day and year.
struct Email
{
	char sender[ADDRESS_SIZE];
	char receiver[ADDRESS_SIZE];
	char subject[SUBJECT_SIZE];
	char body[BODY_SIZE];

	struct date { 
		int month, day, year;
	}date;

	int id;	 
};


// This is a Mailbox struct that contains an Email array and a variable for size. 
struct Mailbox
{
	int size;
	struct Email *emails; 
	//add other struct members as needed/
};



/////////////////////////////////////////////////////////////////////////////////////
//// Function     : initialize
//// Description  : Initializes the database for CMSC257 project #2 by manually entering // the records using create_email function
//// Inputs       : struct Mailbox* - pointer to the database    
//// Outputs      : void
void initialize (struct Mailbox *ib);  

/////////////////////////////////////////////////////////////////////////////////////
////// Function     : create_email
////// Description  : Creates an email and adds it to an array
////// Inputs       : char sender, receiver, subject, body - used
//		      int month, day, year - each used to store month, day, year
//		      struct Mailbox *ib - pointer to the database    
////// Outputs      : void
void create_email(char sender[], char *receiver, char *subject, char *body, int month, int day, int year, struct Mailbox *ib);

/////////////////////////////////////////////////////////////////////////////////////
//////// Function     : display_inbox_menu
//////// Description  : Displays the inbox menu
//////// Inputs       : struct Mailbox* - pointer to the database    
//////// Outputs      : void
void display_inbox_menu(struct Mailbox *ib);

/////////////////////////////////////////////////////////////////////////////////////
//////// Function     : show_inbox
//////// Description  : Shows e-mail inbox
//////// Inputs       : struct Mailbox* - pointer to the database    
//////// Outputs      : void
void show_inbox(struct Mailbox *ib); 

/////////////////////////////////////////////////////////////////////////////////////
//////// Function     : show_email
//////// Description  : Creates an email and adds it to an array
//////// Inputs       : struct Mailbox* - poitner to the database   
//////// Outputs      : void
void show_email_id(int id, struct Mailbox *ib);

/////////////////////////////////////////////////////////////////////////////////////
//////// Function     : sort
//////// Description  : sorts the array (emails) lexicographically by sender
//////// Inputs       : const void* a/b = points to a function in an array
//////// Outputs      : int
int sort(const void* a, const void* b);

/////////////////////////////////////////////////////////////////////////////////////
//////// Function     : sort_id
//////// Description  : sorts the array (emails) bby the ID
//////// Inputs       : const void* a/b = points to a function in an array   
//////// Outputs      : int
int sort_id(const void* a, const void* b);

/////////////////////////////////////////////////////////////////////////////////////
//////// Function     : search_keyword
//////// Description  : Searches for  a keyword with a 10 char limit in the body of each email
////////// Inputs     : char word - stores the string
//			struct Mailbox* - pointer to the database	  
//////// Outputs      : void
void search_keyword(char word[], struct Mailbox *ib);

/////////////////////////////////////////////////////////////////////////////////////
//////// Function     : delete_email
//////// Description  : deletes the id email of the user input 
//////// Inputs       : int a - the id that's meant to be deleted
//                      struct Mailbox* - pointer to the database
//////// Outputs      : void
void delete_email(int a, struct Mailbox *ib);
