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
#include "tm_utility.h"

/* add any 'helper' functions here that provide generic service to your 
 * application. read_rest_of_line() is provided here as an example of this
 */
 
/*String Input function that takes in a prompt, storage var and a size as a param*/
char * stringinput(char * prompt, char * storage, int size){
	
	BOOLEAN finished = FALSE;
	
	do{
        printf("%s", prompt);
        fgets(storage, size, stdin);
       
            if(storage[strlen(storage) -1] !='\n'){
                printf("Error: Input was too long! Try again.\n");
                read_rest_of_line();
        
            }
        
            else if (strcmp(storage, "\n") == 0){
                    return FALSE;
            }

            else{
                storage[strlen(storage) -1] = '\0';
                finished = TRUE;
            }
        
        }while(!finished);

	return storage;	
}





/*Char Input function that takes in a prompt, storage var and a size as a param*/
char * charinput(char * prompt, char * storage, int size){
	
	BOOLEAN finished = FALSE;
	
	do{
        printf("%s", prompt);
        fgets(storage, size, stdin);
       
            if(storage[strlen(storage) -1] !='\n'){
                printf("Error: Input was too long! Try again.\n");
                read_rest_of_line();
        
            }
        
            else if (strcmp(storage, "\n") == 0){
                    return FALSE;
            }
            else{
                storage[strlen(storage) -1] = '\0';
                finished = TRUE;
            }
        
        }while(!finished);

	return storage;	
}


/***************************************************************************
* read_rest_of_line() - reads characters from the input buffer until 
* all characters have been cleared. You will need to call this in 
* association with fgets().
***************************************************************************/
void read_rest_of_line(void)
{
    int ch;
    while(ch=getc(stdin), ch!=EOF && ch!='\n') 
        ;
    clearerr(stdin);
}

/***************************************************************************
* system_init() - allocate memory if necessary and initialise the struct tm
* to safe initial values.
***************************************************************************/
BOOLEAN system_init(tm_type * tm)
{
	int i = 0;
	/*Malloc space for the tm->stock list*/
	tm->stock = (struct stock_list *)malloc(sizeof(struct stock_list));
	
	if (!tm->stock){
		perror("Error: Memory allocation failed! Exiting...\n");
		return EXIT_FAILURE;
	
	}
	
	/*Malloc pointer for the coin list, for 6 spaces*/
	/*tm->coins = (struct coin *)calloc(COIN_LENGTH, sizeof(struct coin));*/
	
	for (i = 0; i < COIN_LENGTH; i++){
	
		tm->coins = (struct coin *)malloc(sizeof(struct coin));
		printf("TM COINS MALLOC!\n");
		tm->coins++;
	
	}

	if (!tm->coins){
		perror("Error: Memory allocation failed! Exiting...\n");
		return EXIT_FAILURE;
	
	}
    /*initialise the tm system to null everything*/
	tm->stock->head_stock = NULL;
	tm->stock->num_stock_items = 0;
	tm->coins->denomination = 0;
	tm->coins->count = 0;
    
    
    return TRUE;
}

/***************************************************************************
* load_data() - load data from both the stock file and the coins file and 
* populate the datastructures keeping in mind data validation and sorting 
* requirements. This function implements the requirement 2 from the 
* assignment 2 specifications.
***************************************************************************/
BOOLEAN load_data(tm_type * tm, char * stockfile, char * coinsfile)
{
    /*declaring file variables*/
    FILE *file1, *file2;
	/*declare two variables to store each line of the file*/
    char stockline[MAX_CHARS], coinsline[MAX_CHARS];
	

    /*Open files to read data*/
    file1 = fopen(FNAME1, "r");
    file2 = fopen(FNAME2, "r");

    /*Test files to make sure they can be opened*/
    if (file1 == NULL){
	printf("\nError: Cannot open stock.csv! Exiting...\n");
	exit(EXIT_FAILURE);

    }

    if (file2 == NULL){
	printf("\nError: Cannot open coins.csv! Exiting...\n");
	exit(EXIT_FAILURE);
    }

    /*do load data here*/
    while(fgets(stockline, MAX_CHARS+1, file1) != NULL){
         tokenize_stock_file(tm, stockline);	
    }

     while(fgets(coinsline, MAX_CHARS+1, file2) != NULL){
         tokenize_coins_file(tm, coinsline);	
    }

    /*close files*/
    fclose(file1);
    fclose(file2);
    
    return TRUE;
}

/**************************************************************************
* system_free() - free all memory allocated for the tm datastructure.
**************************************************************************/
void system_free(tm_type_ptr tm)
{
	int i = 0;
	/*Create pointers to the lists*/
	stock_node *currentItem = NULL, *nextItem = NULL;
	
	struct coin *listptr = NULL;
	
	printf("In system free\n");
	
	
	/*set current to head*/
	currentItem = tm->stock->head_stock;
	
	/*set listptr to head*/
	listptr = &tm->coins[0];
	
	
	while (currentItem != NULL){
	
		nextItem = currentItem->next_node;
		
	
		/*free all data*/
		free(currentItem->data);
		free(currentItem);
		printf("Freed data and currentitem\n");
		currentItem = nextItem;
	
	}
	
	
	/*free coins list*/

	for (i = 0; i < COIN_LENGTH; i++){
	
		free(tm->coins);
		printf("TM COINS FREE!\n");
		tm->coins++;
	
	}
	
	
	
	
	/*finally, free tm->stock and coins*/
	free(tm->stock);
	free(tm->coins);
	printf("Freed stock and coins ptrs\n"); 

}
