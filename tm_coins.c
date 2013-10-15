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
	char *buffer = NULL;
	struct coin *data = NULL;
	int temp_coin = 0;
	unsigned int temp_count = 0;
	int count = 1;

	/*Malloc coins_data*/
	data = (struct coin *)malloc(sizeof(struct coin));

	/*initialise to 0*/

	data->denomination = 0;
	data->count = 0;


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
					else{
						perror("Error: Invalid coin data! Exiting...\n");
						exit(EXIT_FAILURE);
					
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
		
		/*add to array here*/
		add_coin_to_node(tm, data);
	
	}
	
	buffer = strtok(NULL, DELIM);
	
}


return TRUE;
}


BOOLEAN add_coin_to_node(tm_type_ptr tm, struct coin *data){
	
		if (data->denomination == FIVE_CENTS){
			tm->coins[0] = *data;
			free(data);

		}
		else if (data->denomination == TEN_CENTS){
			tm->coins[1] = *data;
			free(data);
			
		}
		else if (data->denomination == TWENTY_CENTS){
			tm->coins[2] = *data;
			free(data);
			
		}
		else if (data->denomination == FIFTY_CENTS){
			tm->coins[3] = *data;
			free(data);
			
		}
		else if (data->denomination == ONE_DOLLAR){
			tm->coins[4] = *data;
			free(data);
			
		}
		else if (data->denomination == TWO_DOLLARS){
			tm->coins[5] = *data;
			free(data);
			
		}
		else {
		
			printf("Error: Invalid coin type in data file! Exiting...\n");
			exit(EXIT_FAILURE);
		
		
		}

return TRUE;
}
