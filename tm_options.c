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
	float price;
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
		
		/*convert cents to dollars and cents*/
		price = (float)current->data->ticket_price / 100;
		
		printf("%s\t\t%s\t%s\t\t$%4.2f\t%i\n", current->data->ticket_name, print, current->data->ticket_zone, price, current->data->stock_level);
		

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
	struct stock_data *data = NULL;
	char temp_ticket_name[TICKET_NAME_LEN], temp_ticket_type[1 + EXTRA_SPACES], temp_ticket_zone[TICKET_ZONE_LEN+1];
	char char_ticket_price[10];	
	unsigned int temp_ticket_price = 0;
	BOOLEAN finished = FALSE;
	char * prompt1 = "Ticket name (1-40 characters): ";
	char * prompt2 = "Ticket type (1 character): ";
	char * prompt3 = "Ticket zone (1-3 characters): ";
	
	printf("\nAdd Ticket\n");
	printf("-----------\n\n");
	
	
	if (stringinput(prompt1, temp_ticket_name, TICKET_NAME_LEN) == FALSE){
		return;
	}
	
	
	if (charinput(prompt2, temp_ticket_type, 1 + EXTRA_SPACES) == FALSE){
		return;
	}
		
		
	if (stringinput(prompt3, temp_ticket_zone, TICKET_ZONE_LEN + 1) == FALSE){
		return;
	}
		
	
	/*Input cents*/
	
	do{
		printf("Price (in cents): ");
		fgets(char_ticket_price, 10, stdin);
	
		if(char_ticket_price[strlen(char_ticket_price) -1] !='\n'){
                printf("Error: Input was too long! Try again.\n");
                read_rest_of_line();
        
            }
        
            else if (strcmp(char_ticket_price, "\n") == 0){
                    return;
            }
            else{
                char_ticket_price[strlen(char_ticket_price) -1] = '\0';
                temp_ticket_price = atoi(char_ticket_price);
				finished = TRUE;
            }
		
	} while (!finished);
	
		
		/*Malloc stock_data*/
		data = (struct stock_data *)malloc(sizeof(struct stock_data));
		
		/*If memory allocation fails*/
		if (!data){
			perror("Error: Memory allocation failed! Exiting...\n");
			free(data);
			exit(EXIT_FAILURE);
		}
		
		/*Add temp variables to struct*/
		strcpy(data -> ticket_name, temp_ticket_name);
		data ->ticket_type = *temp_ticket_type;
		strcpy(data -> ticket_zone, temp_ticket_zone);
		data -> ticket_price = temp_ticket_price;
		data -> stock_level = DEFAULT_STOCK_LEVEL;
		
		/*Send data to add stock function*/
		add_stock_to_node(tm, data);
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
	/*Create pointers to the nodes*/
	stock_node *current = NULL;
	
	/*set the node to head*/
	current = tm->stock->head_stock;
	
	printf("\nRestock Tickets\n");
	printf("---------------\n");
	
	
	while (current != NULL){
	
		/*set default stock level for each node*/
		current->data->stock_level = DEFAULT_STOCK_LEVEL;
	
		current = current->next_node;
	}
	
	printf("All ticket products have been restored to the default level.\n\n");
	
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
