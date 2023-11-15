/*
	team: 3
	history: 6 / 8 / 2023

*/

#ifndef ADMIN_MODE
#define ADMIN_MODE

/**********************Includes********************/
#include "user.h"

extern unsigned int numMovies;

/**********************Function Prototype********************/
void view_reserved_tickets(void);
void admin_printMovies();
void admin_changePrice();
void Admin(void);
void changeMovie(void);
void addMovie(void);
void removeMovie(void);

#endif // ADMIN_MODE
