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


#ifndef TM_H
#define TM_H
#define NUM_COINS 6
#define TICKET_NAME_LEN 40
#define TICKET_ZONE_LEN 10
#define DEFAULT_STOCK_LEVEL 10
#define DEFAULT_COINS_COUNT 50
#define NUM_ARGS 3
#define MENUINPUT 1
#define EXTRA_SPACES 2
#define FNAME1 "stock.csv"
#define FNAME2 "coins.csv"
#define MAX_CHARS 30
#define DELIM ","
#define TICKET_TYPE_LEN 3
#define COIN_LENGTH 6
#define COIN_INPUT_LENGTH 3
#define MAX_TICKET_PRICE 100000


typedef struct tm * tm_type_ptr;

typedef enum truefalse
{
    FALSE, TRUE
} BOOLEAN;


/* global type definitions */
typedef struct stock_list * stock_list_ptr;
typedef struct coin * coin_list_ptr;
typedef struct tm
{
    coin_list_ptr coins;
    stock_list_ptr stock;
} tm_type;


/* global constants for the program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tm_options.h"
#include "tm_stock.h"
#include "tm_coins.h"
#include "tm_utility.h"

#endif
