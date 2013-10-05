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
#ifndef TM_COINS_H
#define TM_COINS_H
#include "tm.h"

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

/*Function Prototypes*/
BOOLEAN tokenize_coins_file(tm_type_ptr tm, char *coinsfile);
BOOLEAN add_coin_to_node(tm_type_ptr tm, struct coin *data);

#endif
