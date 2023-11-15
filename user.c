/******************************************************************************/
/*                                                                            */
/* !Component       : user	                                              */
/* !Description     : user mode related functions                             */
/*                                                                            */
/* !Module          :                                                         */
/* !Description     : 							      */
/*                                                                            */
/* !File            : user.c                                                  */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Ticket Booking exercise project                         */
/*                                                                            */
/* !Target          : Terminal Application                                    */
/*                                                                            */
/*                                                                            */
/* !COPYRIGHT 2023 Strong-Arm EUI                                             */
/*  all rights reserved                                                       */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/*                                                                            */
/* !Designed by     :   						      */
/* !Coded by        : 							      */
/*                                                                            */
/* Rev 1.0   JULY 08, 2023     Initial release                                */
/******************************************************************************/
#include "user.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "app.h"
// #include <windows.h>
/******************************************************************************/
/*************************** Functions Declaration ****************************/
/******************************************************************************/
static void Cancel_Ticket(int Movie_Index);
static int user_printMovies(void);
static void print_Seat(int movie_index);
static void choose_Seat(int movie_Index);
static void purchase_Ticket(int movie_Index);

/******************************************************************************/
/*! \Function Name: User					              */
/*! \Description  :prints out the user menu for movie and seat selection      */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void User(void)
{

	int movie_index, options;
	system("clear"); /*!   clear the terminal    */
	while (1)
	{
		int index = user_printMovies();
		scanf("%d", &movie_index);
		if (movie_index == index) /*Exits of out user*/
		{
			system("clear"); /*!   clear the terminal    */
			return;
		}
		else if (movie_index > index)
		{
			printf("\033[0;31mWrong Selection\033[0m\n");
			continue;
		}
		movie_index--;
		system("clear"); /*!   clear the terminal    */
		printf("*********User Menu*********\n");
		printf("1.Book Ticket\n2.Cancel Ticket\n3.Exit\n");
		fflush(stdout);
		scanf("%d", &options);

		switch (options)
		{
		case 1:
			purchase_Ticket(movie_index);
			break;
		case 2:
			Cancel_Ticket(movie_index);
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}

/******************************************************************************/
/*! \Function Name: Cancel_Ticket					      */
/*! \Description  :Handles cancelation of tickets                             */
/*! \return      None                                                         */
/*! \arguments   the index of the chosen movie  in movies array               */
/******************************************************************************/
static void Cancel_Ticket(int Movie_Index)
{
	char temp;
	int Seat_Index, flag;
	printf("*********User Menu*********\n");
	printf("1.cancel a seat reservation\n2.Exit\n");
	fflush(stdout);
	scanf("%d", &flag);
	if (flag == 2)
	{
		return;
	}
	printf("*********User Menu*********\n");
	printf("1.Enter the seat number: ");
	fflush(stdout);
	scanf("%d", &Seat_Index);
	Seat_Index--;
	if (movies[Movie_Index].Seatings[Seat_Index].Reserved == 0)
	{
		printf("The seat is not reserved before\n");
		return;
	}
	movies[Movie_Index].Seatings[Seat_Index].Reserved = 0;
	printf("Seat is canceled\n");
	printf("Press Enter to Exit"); /*! Enter to Exit */
	scanf("%c", &temp);
	scanf("%c", &temp);
	system("clear"); /*!   clear the terminal    */
}

/******************************************************************************/
/*! \Function Name: user_printMovies			                      */
/*! \Description  :prints out the movies                                      */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
static int user_printMovies(void)
{
	printf("*********Choose movie*********\n");
	int i;
	for (i = 0; i < numMovies; i++)
	{
		printf("%d. %s\n", i + 1, movies[i].Movie_Name);
	}
	printf("%d. Logout\n", i + 1);
	return i + 1;
}
/******************************************************************************/
/*! \Function Name:purchase_Ticket					                          */
/*! \Description  :it handles the display and reservation process    	      */
/*! \return      None                                                         */
/*! \arguments   the index of the chosen movie  in movies array               */
/******************************************************************************/
static void purchase_Ticket(int movie_Index)
{
	system("clear"); /*!   clear the terminal    */
	print_Seat(movie_Index);
	choose_Seat(movie_Index);
}
/******************************************************************************/
/*! \Function Name:print_Seat					              */
/*! \Description  :it displays the seats which are reserved in red and which  */
/* 				   is not in black     								      */
/*! \return      None                                                         */
/*! \arguments   the index of the chosen movie  in movies array               */
/******************************************************************************/
static void print_Seat(int movie_index)
{

	for (int i = 1; i <= NUMBER_SEATS; i++)
	{
		/*check if the seat number i is reserved  */
		if (movies[movie_index].Seatings[i - 1].Reserved == 1)
		{
			/*if it is reserved then print it our with red color*/
			printf("\033[0;31m");
			printf("%d ", i);
			printf("\033[0m");
		}
		else
		{
			/*if it is not reserved print with the default color*/
			printf("%d ", i);
		}
		/*for display format purposes */
		if (i < 10)
		{
			printf(" ");
		}
		if (i % 10 == 0)
		{
			printf("\n");
		}
	}
}

/******************************************************************************/
/*! \Function Name:choose_Seat					                              */
/*! \Description  :it takes an input from user and handle the reservation     */
/*! \return      None                                                         */
/*! \arguments   the index of the chosen movie  in movies array               */
/******************************************************************************/
static void choose_Seat(int movie_Index)
{
	char temp;
	char option;	   /*var to hold the chosen input by user whether to book a seat or return */
	int seatNumber;	   /*var to hold the chosen seat number by user  */
	int numberOfSeats; /*var to hold the number of seats to be reserved */

	printf("Choose an option: \n");
	printf("1. Choose seat\n");
	printf("2. Return\n");
	fflush(stdin);

	scanf("\n%c", &option);

	if (option != '1' || option != '2')
	{
		switch (option)
		{
		case '1':
			printf("Please enter number of seats to be reserved: ");
			fflush(stdin);
			scanf("%d", &numberOfSeats);

			for (int i = 0; i < numberOfSeats; i++)
			{
				printf("Please choose a seat: ");
				fflush(stdin);
				scanf("%d", &seatNumber);
				seatNumber--;
				/*Handling the input to meet seats' valid range */
				if (seatNumber > NUMBER_SEATS - 1 || seatNumber < 0)
				{
					printf("No seat with this number\n");
					i--; /*Revert iteration of wrong input*/
					continue;
				}
				/*checking if the chosen seat is already reserved */
				if (movies[movie_Index].Seatings[seatNumber].Reserved == 1)
				{
					printf("This seat is already reserved.\n");
					i--;
				}
				/*reserve the seat*/
				movies[movie_Index].Seatings[seatNumber].Reserved = 1;
			}

			{ /*Take the personal information of the customer and validate it then save it*/

				/*customer name processing*/
				char name[30];
				int invalid = 0;

				do
				{
					printf("Enter your name: ");
					fflush(stdin);
					scanf("%s", name);
					char itr = 0;
					invalid = 0;
					/*check if any element of the input is not a character*/
					while (name[itr] != '\0')
					{

						if (!((name[itr] >= 'A' && name[itr] <= 'Z') || (name[itr] >= 'a' && name[itr] <= 'z')))
						{
							invalid = 1;
						}
						itr++;
					}
					/* if it is invalid name ask the user to re-enter it*/
					if (invalid == 1)
					{
						printf("\033[0;31m");
						printf("Invalid name \nplease enter a valid one \n");
						printf("\033[0m");
						printf("\a");
						// Beep(750, 800);

						// getch();
					}
					else
					{
						strcpy(movies[movie_Index].Seatings[seatNumber].Client_Name, name);
					}
				} while (invalid == 1);
				int invalid_ph = 0;
				do
				{

					int itr = 0;
					char phone[13];
					printf("Enter phone number: ");
					fflush(stdin);
					scanf("%s", phone);
					// printf("%s",phone);

					/*check the phone code*/
					if ((phone[0] == '0') && (phone[1] == '1') && strlen(phone) == 11)
					{
						if ((phone[2] == '1' || phone[2] == '2') || (phone[2] == '0' || phone[2] == '5'))
						{
							invalid_ph = 0;

							/*phone number processing */
							while (phone[itr] != '\0')
							{

								if (!((phone[itr] >= '0' && phone[itr] <= '9')))
								{
									invalid_ph = 1;
								}
								itr++;
							}

							/* if it is invalid number ask the user to re-enter it*/
							if (invalid_ph == 1)
							{
								printf("\033[0;31m");
								printf("Invalid phone number\nplease enter a valid one \n");
								printf("\033[0m");
								// Beep(750, 800);
								printf("\a");
								printf("\a");
								// getch();
							}

							else
							{
								strcpy(movies[movie_Index].Seatings[seatNumber].Client_Phone_Number, phone);
							}
						}
						else
						{

							invalid_ph = 1;
							printf("\033[0;31m");
							printf("Number must start with (011 or 012 or 010 or 015) \nplease enter a valid one \n");
							printf("\033[0m");
							// Beep(750, 800);
							printf("\a");
							printf("\a");
							// getch();
							continue;
						}
					}
					else
					{

						invalid_ph = 1;
						printf("\033[0;31m");
						printf("invallid number) \nplease enter a valid one \n");
						printf("\033[0m");
						// Beep(750, 800);
						printf("\a");
						printf("\a");
						// getch();
						continue;
					}
				}

				while (invalid_ph == 1);

				/*Display the receipt */
				printf("\n*******Seat Receipt:*******\n");
				printf("Client name: %s\n", movies[movie_Index].Seatings[seatNumber].Client_Name);
				printf("Client phone number: %s\n", movies[movie_Index].Seatings[seatNumber].Client_Phone_Number);
				printf("Seat Number: %d\n", movies[movie_Index].Seatings[seatNumber].Seat_Number + 1);
				movies[movie_Index].Seatings[seatNumber].price = movies[movie_Index].Price;
				printf("Price: %d\n", movies[movie_Index].Seatings[seatNumber].price);
				printf("\n");
			}
		}
	}
}
