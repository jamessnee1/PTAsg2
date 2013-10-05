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


#ifndef TM_OPTIONS_H
#define TM_OPTIONS_H
#include "tm.h"

/* function prototypes you need to implement to fulfil the required options
 */
void purchase_ticket(tm_type_ptr tm);
void display_tickets(tm_type_ptr tm);
void add_ticket(tm_type_ptr tm);
void delete_ticket(tm_type_ptr tm);
void display_coins(tm_type_ptr tm);
void restock_tickets(tm_type_ptr tm);
void restock_coins(tm_type_ptr tm);
void save_data(tm_type_ptr tm, char * stockfile, char * coinsfile);
#endif
