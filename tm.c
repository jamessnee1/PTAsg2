/***************************************************************************
* COSC1283/1284 - Programming Techniques
* Semester 2 2013 Assignment #2 - SCSIT Program Management System
* Full Name        : James Snee
* Student Number   : s3369721
* Yallara Username : s3369721
* Course Code      : COSC1284
* Program Code     : BP094
* Start up code provided by Paul Miller and Lin Padgham
***************************************************************************/
/**************************************************************************
* main() - this is the entry point into your program. You need to follow 
* the steps in the comments provided as these are the steps required to 
* run your program. Please ensure that you use all function prototypes and 
* datatype declarations provided as not doing so will result in a 
* substantial mark penalty as well as missing out on some important learning
* opportunities.
**************************************************************************/
#include "tm.h"

int main(int argc, char** argv)
{
	int input;
	char charInput[MENUINPUT + EXTRA_SPACES];
    tm_type tm;
    BOOLEAN quit = FALSE;
    /* check command line arguments */
	if (argc != 3){
		printf("Usage: tm <stock.csv> <coins.csv>\n");
		exit(EXIT_FAILURE);
	
	}
	else{
	
		/*Check if what the user has entered as 
		arguments match stock.csv and coins.csv*/
        if (strcmp(argv[1], FNAME1) && strcmp(argv[2], FNAME2) != 0){
            printf("\nError: Cannot load stock.csv and coins.csv! Exiting...\n\n");
            exit(EXIT_FAILURE);
        }
	
	
	
	
	}

    /* initialise data structures */
	system_init(&tm);
    /* load data */
        load_data(&tm, argv[1], argv[2]);

    /* test that everything has gone in initialisation and loading */

    while(!quit)
    {
		/* display menu */
		printf("\nMain Menu\n");
		printf("1) Purchase Ticket\n");
		printf("2) Display Tickets\n");
		printf("3) Save and Exit\n");
		printf("Administrator-Only Menu\n");
		printf("4) Add Ticket\n");
		printf("5) Remove Ticket\n");
		printf("6) Display Coins\n");
		printf("7) Restock Tickets\n");
		printf("8) Restock Coins\n");
		printf("9) Abort\n\n");
        printf("Select your option (1-9): ");
		
        /* perform menu choice */
		fgets(charInput, MENUINPUT + EXTRA_SPACES, stdin);
		
		/*Convert menu input to an int for use in switch statement*/
		input = atoi(charInput);
		
		switch(input){
		case 0:
			printf("Error: Not a valid option! Please try again.\n\n");
			break;
		case 1:
			purchase_ticket(&tm);
			break;
		case 2:
			display_tickets(&tm);
			break;
		case 3:
			break;
		case 4:
			add_ticket(&tm);
			break;
		case 5:
			delete_ticket(&tm);
			break;
		case 6:
			display_coins(&tm);
			break;
		case 7:
			restock_tickets(&tm);
			break;
		case 8:
			break;
		case 9:
			quit = TRUE;
			break;

		
		}
		
		
    }

    /* free memory */
	system_free(&tm);
	
    /* leave program */
	exit(EXIT_SUCCESS);
}

