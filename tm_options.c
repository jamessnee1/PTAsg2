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
#include "tm_options.h"

/* add functions here for the implementation of each of the options
 * required to fulfil the requirements of the assignment
 */

/**************************************************************************
* purchase_ticket() - get input from the user about the ticket they wish 
* to purchase, retrieve that ticket from the list and adjust levels of the
* stock and the coins upon payment of the ticket. This function implements
* requirement 4 from the assignment 2 specification.
**************************************************************************/
void purchase_ticket(tm_type * tm)
{
}

/**************************************************************************
* display_tickets() - iterate over the stock list and display a list of 
* tickets in the system according to the format specified in the assignment
* 2 specifications. This option implements requirement 5 from the assignment
* specifications.
**************************************************************************/
void display_tickets(tm_type * tm)
{
	char *print;
	/*Create pointers to the nodes*/
	stock_node *current = NULL;
	
	/*set the node to head*/
	current = tm->stock->head_stock;
	
	printf("Ticket\t\tType\t\tZone\t\tPrice\tQty\n");
	printf("----------\t--------\t--------\t-----   ---\n");
	
	while (current != NULL){
		/*Sets which ticket type*/
		if (current->data->ticket_type == 'F'){
			print = "Full Fare";
		
		}
		else {
			print = "Concession";
		
		}
	
		printf("%s\t\t%s\t%s\t\t$%i\t%i\n", current->data->ticket_name, print, current->data->ticket_zone, current->data->ticket_price, current->data->stock_level);
		

		current = current->next_node;
	}
}

/***************************************************************************
* add_ticket() - Request user input about creating a new ticket type in 
* the system. You need to validate this input and then create and insert 
* a new ticket into the system, sorted by ticket name. this option 
* implements requirement 6 in the assignment 2 specifications.
**************************************************************************/
void add_ticket(tm_type * tm)
{
}

/**************************************************************************
* delete_ticket() - Request user input from the administrator specifying
* the name, type and zone of the ticket. You will then search the stock
* list to delete this ticket. All three fields entered must match for the
* ticket to be deleted. Please ensure that you free any memory that was 
* dynamically allocated. This function implements requirement 7 from the 
* assignment 2 specifications.
**************************************************************************/
void delete_ticket(tm_type * tm)
{
}

/**************************************************************************
* display_coins() - display a list of each of the coin types in the system
* and the count of each coin type according to the format specified in the
* assignment 2 specification. This function implements requirement 8 from
* the assignment 2 specification.
**************************************************************************/
void display_coins(tm_type * tm)
{
}

/**************************************************************************
* restock_tickets() - iterate over the list and set all ticket products
* to the default level specified in tm.h. This function implements the 
* requirement 9 in the assignment 2 specifications.
**************************************************************************/
void restock_tickets(tm_type * tm)
{
}

/**************************************************************************
* restock_coins() - set the total number of coins of each denomination to
* the default number specified in tm.h. This function implements the 
* requirement 10 from the assignment 2 specifications.
**************************************************************************/
void restock_coins(tm_type * tm)
{
}

/**************************************************************************
* save_data() - open the stockfile and the coinsfile for writing and 
* save all the data to these files. You need to ensure that you save data
* to these files in the same format as specified for loading this data in 
* so that your program or any alternate but correct implementation could
* load the resultant data files. This function implements requirement 11
* from the assignment 2 specifications.
**************************************************************************/
void save_data(tm_type * tm, char * stockfile, char * coinsfile)
{
}
