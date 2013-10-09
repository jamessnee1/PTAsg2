#include <stdio.h>
#include <stdlib.h>
#define COIN_LENGTH 5



typedef struct stock_list * stock_list_ptr;
typedef struct coin * coin_list_ptr;
typedef struct tm * tm_type_ptr;

typedef struct tm
{
    coin_list_ptr coins;
    stock_list_ptr stock;
} tm_type;

/* specifies the various coin types in the system and their values */
enum coin_types
{
    FIVE_CENTS=5,
    TEN_CENTS=10,
    TWENTY_CENTS=20,
    FIFTY_CENTS=50,
    ONE_DOLLAR=100,
    TWO_DOLLARS=200
};

/* defines a 'coin' in the system. the coinslist is actually an array of 
 * this type
 */
struct coin
{
    enum coin_types denomination;
    unsigned count;
};

void system_init(tm_type_ptr tm);
void system_free(tm_type_ptr tm);

int main(){

	tm_type tm;
	system_init(&tm);
	system_free(&tm);

	return 0;
}

void system_init(tm_type_ptr tm){

	int i = 0;
	tm->coins = (struct coin *)malloc((COIN_LENGTH+1) * sizeof(struct coin));
	
	printf("About to malloc\n");
	for (i = 0; i <= COIN_LENGTH; i++){
		tm->coins[i].denomination = 0;
		tm->coins[i].count = 0;
		printf("tm->coins[%i] denom is %i and count is %i, size of is %i\n", i, tm->coins[i].denomination, tm->coins[i].count, sizeof(tm->coins[i]));

	}





}

void system_free(tm_type_ptr tm){
	int i = 0;
	
	coin_list_ptr *list;
	list = &tm->coins;
	printf("about to free\n");
	
	free(tm->coins);
	for (i = 0; i <= COIN_LENGTH; i++){
	
		
		list++;
	
	}



}