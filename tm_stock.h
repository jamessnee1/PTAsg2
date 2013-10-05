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
#ifndef TM_STOCK_H
#define TM_STOCK_H
#include "tm.h"


struct stock_data 
{
    char ticket_name[TICKET_NAME_LEN+1];
    char ticket_type;
    char ticket_zone[TICKET_ZONE_LEN+1];
    unsigned int ticket_price;
    unsigned int stock_level;
};
typedef struct stock_node 
{
    struct stock_data * data;
    struct stock_node * next_node;
} stock_node;

struct stock_list
{
    stock_node * head_stock;
    unsigned int num_stock_items;
};

/*Function Prototypes*/
BOOLEAN tokenize_stock_file(tm_type_ptr tm, char *stockfile);
BOOLEAN add_stock_to_node(tm_type_ptr tm, struct stock_data *data);
#endif
