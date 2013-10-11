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
#include "tm_stock.h"

/* add functions here to manipulate the stock list */


BOOLEAN tokenize_stock_file(tm_type_ptr tm, char *stockfile){

/*create new struct variable and temp variables*/
struct stock_data *data = NULL;
char *buffer;
int count = 1;
char temp_ticket_name[TICKET_NAME_LEN], temp_ticket_type, temp_ticket_zone[TICKET_NAME_LEN];
char char_ticket_price[10], char_stock_level[10];	
unsigned int temp_ticket_price, temp_stock_level;

/*Malloc stock_data*/
data = (struct stock_data *)malloc(sizeof(struct stock_data));




/*tokenize passed in line to buffer variable*/
buffer = strtok(stockfile, DELIM);

/*while buffer is not empty*/
while(buffer != NULL){


switch(count){
	
	case 1:
		strcpy(temp_ticket_name, buffer);
		if (strlen(temp_ticket_name) > TICKET_NAME_LEN + 1){
			printf("Error: corrupted data when loading Ticket name! Exiting...\n");
			exit(EXIT_FAILURE);
		}
		strcpy(data -> ticket_name, temp_ticket_name);
		break;
	case 2:
		if (*buffer == 'F'){
			temp_ticket_type = 'F';
		}
		else {
			temp_ticket_type = 'C';
		
		}

		data ->ticket_type = temp_ticket_type;
		break;
	case 3:
		strcpy(temp_ticket_zone, buffer);
			if (strlen(temp_ticket_name) > TICKET_NAME_LEN + 1){
				printf("Error: corrupted data when loading Ticket zone! Exiting...\n");
				exit(EXIT_FAILURE);
			}
		strcpy(data->ticket_zone, temp_ticket_zone);
		break;
	case 4:
		strcpy(char_ticket_price, buffer);
			if (strlen(char_ticket_price) > 100000){
				printf("Error: corrupted data when loading Ticket price! Exiting...\n");
				exit(EXIT_FAILURE);
			}
		temp_ticket_price = atoi(char_ticket_price);
		data->ticket_price = temp_ticket_price;
		break;
	case 5:
		strcpy(char_stock_level, buffer);
			if (strlen(char_stock_level) > DEFAULT_STOCK_LEVEL){
				printf("Error: corrupted data when loading Stock level! Exiting...\n");
				exit(EXIT_FAILURE);
			}
		temp_stock_level = atoi(char_stock_level);
		data->stock_level = temp_stock_level;
		break;


}
	count++;

	if (count == 5){
	
		/*add stock to node here*/
		add_stock_to_node(tm, data);
	
	}
	
buffer = strtok(NULL, DELIM);
}

 
 return TRUE;
}

BOOLEAN add_stock_to_node(tm_type_ptr tm, struct stock_data *data){

	stock_node *currentItem = NULL, *previousItem = NULL, *newItem = NULL;

	
	/*malloc new item*/
	newItem = (stock_node *)malloc(sizeof(stock_node));

	
	if (!newItem){
		perror("Error: Memory allocation failed! Exiting...\n");
		free(newItem);
		exit(EXIT_FAILURE);
	
	}
	
	/*set new item data*/
	newItem->data = data;
	
	/*set next to null*/
	newItem->next_node = NULL;
	
	
	/*If the head stock node is null, set newItem to head*/
	if (tm->stock->head_stock == NULL){
		
		tm->stock->head_stock = newItem;
	}
	else{
		
		/*There is already a head, set currentItem to head*/
		currentItem = tm->stock->head_stock;
	
		/*list traversal*/
		while(currentItem != NULL && stock_cmp(currentItem->data, data) < 0){
		
			previousItem = currentItem;
			currentItem = currentItem->next_node;
		
		}
		/*If no previous item, we are at the head. Set currentItem to next_node and newItem to head*/
		if (previousItem == NULL){
			
			newItem->next_node = tm->stock->head_stock;
			tm->stock->head_stock = newItem;
		
		
		}
		else{
		
			newItem->next_node = currentItem;
			previousItem->next_node = newItem;
		
		
		}
	}
	
	/*If everything went to plan, increase the list count by 1*/
	tm->stock->num_stock_items++;
	
	return TRUE;
}

/*this function compares data in two nodes*/
int stock_cmp(struct stock_data *first, struct stock_data *second){
    
	int cmp = 0;
    cmp = strcmp(first->ticket_name, second->ticket_name);
    if(cmp != 0){
        return cmp;
	}
    return strcmp(first->ticket_name, second->ticket_name);
}
