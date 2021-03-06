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
	/*declare temp variables*/
	
	stock_node *current = NULL;
	struct coin * coinlist = NULL;
	char temp_ticket_name[TICKET_NAME_LEN], temp_ticket_type[1 + EXTRA_SPACES], temp_ticket_zone[TICKET_ZONE_LEN+1];
	char *prompt1 = "Enter a ticket name (1-40 characters): ";
	char *prompt2 = "Enter a ticket type (1 character): ";
	char *prompt3 = "Enter a zone (1, 2, or 1+2): ";
	char * print;
	int returnedprice;
	
	/*set node to head*/
	current = tm->stock->head_stock;
	
	coinlist = tm->coins;
	
	printf("\nPurchase Ticket\n");
	printf("---------------\n\n");
	
		if (stringinput(prompt1, temp_ticket_name, TICKET_NAME_LEN) == FALSE){
			return;
		}
		
		if (charinput(prompt2, temp_ticket_type, 1 + EXTRA_SPACES) == FALSE){
			return;
		}
		
		if (zoneinput(prompt3, temp_ticket_zone, TICKET_TYPE_LEN + EXTRA_SPACES) == FALSE){
			return;
		}
		
		while(current != NULL){
		
			if (strcmp(current->data->ticket_name, temp_ticket_name) == 0 && current->data->ticket_type == temp_ticket_type[0]
			&& strcmp(current->data->ticket_zone, temp_ticket_zone) == 0){

			
				/*Sets which ticket type*/
				if (current->data->ticket_type == 'F'){
					print = "Full Fare";
		
				}
				else {
					print = "Concession";
		
					}
				
				/*send this to enter coins function*/
				if((returnedprice = enter_coin(tm, current->data->ticket_price)) == -1){
					return;
				}
				else{
					/*break out of while loop and process coin return*/
					break;
					}

			}
			
			current = current->next_node;
			if (current->next_node == NULL){
				printf("Error: Could not find ticket!\n");
				return;
			}
		}
		/*decrement the stock items and qty by 1*/
		current->data->stock_level--;
		tm->stock->num_stock_items--;
		printf("Thank you for purchasing a %s %s zone %s ticket.\n", current->data->ticket_name, print, current->data->ticket_zone);
		printf("Your change is: $%.2f\n", (float)(returnedprice * -1) / 100);
		printf("Your change coins are: ");
		
		
		if (returnedprice == 0){
			printf("None\n");
		}
		else if (returnedprice >= -5){
			coinlist[0].count--;
			printf("5c\n");
		}
		else if (returnedprice >= -10){
			coinlist[1].count--;
			printf("10c\n");
		}
		else if (returnedprice >= -20){
			coinlist[2].count--;
			printf("20c\n");
		}
		else if (returnedprice >= -50){
			coinlist[3].count--;
			printf("50c\n");
		}
		else if (returnedprice >= -100){
			coinlist[4].count--;
			printf("$1\n");
		}
		else if (returnedprice >= -200){
			coinlist[5].count--;
			printf("$2\n");
		}
	
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

	printf("\n\nTicket\t\tType\t\tZone\t\tPrice\tQty\n");
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
		
		printf("%s\t\t%s\t%s\t\t$%4.2f\t%3i\n", current->data->ticket_name, print, current->data->ticket_zone, price, current->data->stock_level);
		

		current = current->next_node;
	}
	printf("\n");
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
		
		
	if (zoneinput(prompt3, temp_ticket_zone, TICKET_TYPE_LEN + EXTRA_SPACES) == FALSE){
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
		
		printf("Ticket successfully added to system.\n");
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
	/*Pointers to nodes*/
	struct stock_node *current = NULL, *previous = NULL, *next = NULL;
	/*Temp variables*/
	char temp_ticket_name[TICKET_NAME_LEN], temp_ticket_type[1 + EXTRA_SPACES], temp_ticket_zone[TICKET_ZONE_LEN+1];
	char *print;
	/*prompts*/
	char * prompt1 = "Ticket name (1-40 characters): ";
	char * prompt2 = "Ticket type (1 character): ";
	char * prompt3 = "Ticket zone (1-3 characters): ";
	
	/*point current to head node*/
	current = tm->stock->head_stock;
	
	printf("\nDelete Ticket\n");
	printf("----------------\n\n");
	
	if (stringinput(prompt1, temp_ticket_name, TICKET_NAME_LEN) == FALSE){
		return;
	}
	
	
	if (charinput(prompt2, temp_ticket_type, 1 + EXTRA_SPACES) == FALSE){
		return;
	}
	
		
	if (zoneinput(prompt3, temp_ticket_zone, TICKET_TYPE_LEN + EXTRA_SPACES) == FALSE){
		return;
	}
	
	
	/*Remove from the list*/
	while (current != NULL){
		
		/*If ticket name is the same as the one entered in*/
		if (strcmp(current->data->ticket_name, temp_ticket_name) == 0 && current->data->ticket_type == temp_ticket_type[0]
			&& strcmp(current->data->ticket_zone, temp_ticket_zone) == 0){
				
				/*We have found it*/
				if (current == tm->stock->head_stock){ 
				
					
					/*set the print variable to what type it is*/
					if (current->data->ticket_type == 'F'){
						print = "full fare";
			
					}
					else {
						print = "concession";
			
					}
					
					
					/*set the head stock to next node*/
					tm->stock->head_stock = current->next_node;
					/*decrement stock number by 1*/
					tm->stock->num_stock_items--;
					printf("\nTicket \'%s %s zone %s\' has been removed from ticketing machine.\n", temp_ticket_name, print, temp_ticket_zone);
					return;
				
				}
					else{
					
					/*set the print variable to what type it is*/
					if (current->data->ticket_type == 'F'){
						print = "full fare";
			
					}
					else {
						print = "concession";
			
					}
					/*If the current is not head, set next to current->next and previous->next to next and free*/
					next = current->next_node;
					previous->next_node = next;
					free(current);
					/*decrement stocknumber by 1*/
					tm->stock->num_stock_items--;
					printf("\nTicket \'%s %s zone %s\' has been removed from ticketing machine.\n", temp_ticket_name, print, temp_ticket_zone);
					return;
				
					}
					
				

		}
		

			/*If conditions arent met, iterate through list*/
			previous = current;
			current = current->next_node;
	
		}
		
		printf("Error: Ticket does not exist! Could not delete ticket!\n\n");
		return;
		
}
	
	


/**************************************************************************
* display_coins() - display a list of each of the coin types in the system
* and the count of each coin type according to the format specified in the
* assignment 2 specification. This function implements requirement 8 from
* the assignment 2 specification.
**************************************************************************/
void display_coins(tm_type * tm)
{
	int i = 0;
	float total = 0, grandtotal = 0;
	float amount = 0;
	
	/*create pointer to coins list*/
	struct coin *listptr = NULL;
	listptr = tm->coins;
	
	printf("\nCoin\tQuantity\tValue\n");
	printf("----\t--------\t-----\n");
	
	for (i = 0; i < COIN_LENGTH; i++){
	
		
		amount = (float)listptr->denomination / 100;
		total = amount * listptr->count;
		printf("$%.2f\t%i\t\t$%.2f\n", amount, listptr->count, total);
		/*adds all of the totals to grandtotal*/
		grandtotal += total;
		listptr++;
	
	}
	printf("\t\t\t-----\n");
	printf("Total Value: \t\t$%.2f\n", grandtotal);
	
	/*free list pointer*/
	listptr = NULL;
	

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
	
	printf("All ticket products have been restocked to the default level.\n\n");
	
}

/**************************************************************************
* restock_coins() - set the total number of coins of each denomination to
* the default number specified in tm.h. This function implements the 
* requirement 10 from the assignment 2 specifications.
**************************************************************************/
void restock_coins(tm_type * tm)
{
	int i = 0;
	struct coin *listptr;
	
	/*create a ptr to start of coins array*/
	listptr = tm->coins;

	printf("\nRestock Coins\n");
	printf("---------------\n");
	
	for (i = 0; i < COIN_LENGTH; i++){
	
		listptr->count = DEFAULT_COINS_COUNT;
		listptr++;
	
	}
	
	printf("All coins have been restocked to the default level.\n\n");

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
	/*2 Files*/
    FILE *fp1;
    FILE *fp2;
	
	/*Loop counter*/
	int i = 0;
    
    /*Pointers for list*/
    struct stock_node *currentstock = NULL;
    struct coin *currentcoin = NULL;
    
    /*point current to headstock*/
    currentstock = tm->stock->head_stock;
    
    
    /*Open both files to write data*/
    fp1 = fopen(FNAME1, "w");
    fp2 = fopen(FNAME2, "w");
    
    
    /*If program.dat is empty, throw an error*/
    if (fp1 == NULL){
        printf("\nError: Cannot save program.dat! Exiting...\n\n");
        exit(EXIT_FAILURE);
    }
    
    /*If course.dat is empty, throw an error*/
    if (fp2 == NULL){
        printf("\nError: Cannot save course.dat! Exiting...\n\n");
        exit(EXIT_FAILURE);
    }
    
    
    /*Loop through stock list*/
    while (currentstock != NULL){
        
        /*point currentcoin to tm->coins*/
        currentcoin = tm->coins;
    
        fprintf(fp1, "%s,%c,%s,%i,%i\n", currentstock->data->ticket_name, currentstock->data->ticket_type, currentstock->data->ticket_zone,
			currentstock->data->ticket_price, currentstock->data->stock_level);

			
        /*iterate through list*/
        currentstock = currentstock->next_node;
    
    }
	
	/*Loop for coins list*/
	for (i = 0; i < COIN_LENGTH; i++){
	
		fprintf(fp2, "%i,%i\n", currentcoin->denomination, currentcoin->count);
		/*increment counter*/
		currentcoin++;
	}
	
	/*set the ptr to null*/
	currentcoin = NULL;

    /*close files*/
    fclose(fp1);
    fclose(fp2);

}
