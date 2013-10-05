###############################################################################
# COSC1283/1284 - Programming Techniques
# Semester 2 2013 Assignment #2 - SCSIT Program Management System
# Full Name        : James Snee
# Student Number   : s3369721
# Yallara Username : s3369721
# Course Code      : COSC1284
# Program Code     : BP094
# Start up code provided by Paul Miller and Lin Padgham
################################################################################

tm: tm.o tm_coins.o tm_options.o tm_stock.o tm_utility.o
	@echo Making all files...
	@gcc -ansi -Wall -pedantic -o tm tm.o tm_coins.o tm_options.o tm_stock.o tm_utility.o 

tm.o: tm.c tm.h
	@echo making tm.o
	@gcc -ansi -Wall -pedantic -c -g tm.c

tm_coins.o: tm_coins.c tm_coins.h
	@echo making tm_coins.o
	@gcc -ansi -Wall -pedantic -c -g tm_coins.c

tm_options.o: tm_options.c tm_options.h
	@echo making tm_options.o
	@gcc -ansi -Wall -pedantic -c -g tm_options.c

tm_stock.o: tm_stock.c tm_stock.h
	@echo making tm_stock.o
	@gcc -ansi -Wall -pedantic -c -g tm_stock.c

tm_utility.o: tm_utility.c tm_utility.h
	@echo making tm_utility.o
	@gcc -ansi -Wall -pedantic -c -g tm_utility.c

clean:
	rm -f *.o main

.PHONY:archive
archive:
	zip $(USER)-a2.zip tm.c tm.h tm_coins.c tm_coins.h tm_options.c tm_options.h \
	tm_stock.c tm_stock.h tm_utility.c tm_utility.h tm_readme.txt Makefile coins.csv stock.csv

