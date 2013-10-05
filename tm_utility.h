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
#ifndef TM_UTILITY_H
#define TM_UTILITY_H
#include "tm.h"

/* function prototypes for functions implemented in tm_utility.c
 * These are generic helper functions that provide support to the rest
 * of your application.
 *
 * Remember that we will assess the level to which you provide some level
 * of functional abstraction here.
 */
void read_rest_of_line(void);
BOOLEAN system_init(tm_type_ptr tm);
BOOLEAN load_data(tm_type_ptr tm, char * stockfile, char * coinsfile);
void system_free(tm_type_ptr);
#endif
