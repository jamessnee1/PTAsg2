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
#include "tm_coins.h"

/* add functions here for the manipulation of the coins list (array) */

BOOLEAN tokenize_coins_file(tm_type_ptr tm, char *coinsfile){

/*create variables*/
char *buffer;
struct coin *data = NULL;
int temp_coin;
unsigned int temp_count;
int count = 1;

/*Malloc coins_data*/
data = (struct coin *)malloc(sizeof(struct coin));



/*tokenize into a buffer*/
buffer = strtok(coinsfile, DELIM);


while (buffer != NULL){

	
	switch(count){
	
		case 1:
			/*convert the coin to an int*/
			temp_coin = atoi(buffer);
			/*check what coin it is*/
			if (temp_coin == 5){
				data->denomination = FIVE_CENTS;

			}
			else if (temp_coin == 10){
				data->denomination = TEN_CENTS;

			}
			else if (temp_coin == 20){
				data->denomination = TWENTY_CENTS;

			}
			else if (temp_coin == 50){
				data->denomination = FIFTY_CENTS;

			}
			else if (temp_coin == 100){
				data->denomination = ONE_DOLLAR;

			}
			else if (temp_coin == 200){
				data->denomination = TWO_DOLLARS;
				
			}
			break;
		case 2:
			/*convert buffer to an int*/
			temp_count = atoi(buffer);
			data->count = temp_count;
			break;
		default:
			break;
			
			

	}
	
		count++;

	if (count == 3){
	
		add_coin_to_node(tm, data);
	
	}
	
	buffer = strtok(NULL, DELIM);
	
}


return TRUE;
}


BOOLEAN add_coin_to_node(tm_type_ptr tm, struct coin *data){



return TRUE;
}
