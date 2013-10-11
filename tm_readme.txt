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

If selected, do you grant permission for your assignment
to be released as an anonymous student sample solution?
--------------------------------------------------------
Yes


Known bugs:
-----------



Incomplete functionality:
-------------------------



Assumptions:
------------
I have assumed that there is only a set list of coins that can be added to the system
in the amounts provided, if these denominations are not found, the program exits.

For my input validation the program sends parameters to functions to check
the length/EOF/return to menu functionality so I have assumed that, even in functions such as
delete_ticket where we have to check for the existence of a ticket, it will automatically rule out
any outrageous values (delete a ticket with a zone of f, for example).

I have assumed that the ticket price can be no greater than $1000 and the highest stock level to be
the default stock level.


Any other notes for the marker:
-------------------------------
Total assignment time = ~30 hours
