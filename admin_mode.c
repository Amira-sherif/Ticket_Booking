/******************************************************************************/
/*!																			  */
/*!  Created by:  team 3 (SemiColone;)										  */
/*!                                 										  */
/*!                                 										  */
/*!  Rev 1.0   JULY 08, 2023     Initial release                              */
/*!																			  */
/******************************************************************************/

/**********************************Includes************************************/
#include "admin_mode.h" // Include necessary header files
#include <stdio.h>      // Include standard input/output library
#include "app.h"
#include <stdlib.h>

/******************************************************************************/
/*********************** Public Functions Implementation **********************/
/******************************************************************************/

/******************************************************************************/
/*! \Creates menu for admin to choose whether to add or remove a movie        */
/*! \return      None                                                         */
/*! \arguments None                                                           */
/******************************************************************************/

void changeMovie(void)
{
    system("clear"); /*!   clear the terminal    */
    unsigned int option;
    do
    {
        /*!	print the admin option to select from	*/
        printf("************** Change Movie *************\n");
        printf("1. Add Movie\n");
        printf("2. Remove Movie\n");
        printf("0. Return\n");
        printf("Please select an option: ");
        fflush(stdin);
        scanf("%d", &option); /*!	scan the option from the admin	*/
        fflush(stdin);
        if (option > 2 && option < 0) /* Wrong selection */
        {
            option = 3;
        }
        else if (numMovies == 0 && (option != 1 && option != 0)) /* If trying to remove a movie when there are no movies */
        {
            option = 4;
        }
        /*!		switch between admin options	*/
        switch (option)
        {
        case 1:
            addMovie(); /*!	calling function to add movie	*/
            break;
        case 2:
            removeMovie(); /*!	calling function to remove movie  */
            break;
        case 3:
            printf("\033[0;31mWrong Selection\033[0m\n");
            break;
        case 4:
            system("clear"); /*!   clear the terminal    */
            printf("\033[0;31mNo movies in system\033[0m\n");
            break;
        case 0:
            break;
        default:
            system("clear");                         /*!   clear the terminal    */
            printf("\033[0;31m Wrong Selection \033[0m\n"); /*! Handle wrong menu selection	*/
        }
    } while (option);       /*!	repeat untill entering exit option	*/
    system("clear"); /*!   clear the terminal    */
}

/******************************************************************************/
/*! \Adds a movie of admin choice                                             */
/*! \return      None                                                         */
/*! \arguments None                                                           */
/******************************************************************************/

void addMovie(void)
{
    char temp;
    /* increase number of movies and reallocate size to pointer*/
    numMovies++;
    movies = (Movies *)realloc(movies, numMovies * sizeof(Movies));

    int price;
    int Hall_Number;
    printf("************** Add Movie *************\n");
    printf("Movie Name: ");
    scanf("%c", &temp);
    scanf("%[^\n]", movies[numMovies - 1].Movie_Name);
    printf("\nMovie Hall: ");
    scanf("%d", &Hall_Number);
    printf("\nMovie Price: ");
    scanf("%d", &price);
    movies[numMovies - 1].Price = price;
    movies[numMovies - 1].Hall_Number = Hall_Number;
    printf("\nMovie: %s",movies[numMovies - 1].Movie_Name);
    printf("\nPress Enter to Exit"); /*! Enter to Exit */
    scanf("%c", &temp);
    scanf("%c", &temp);
    system("clear"); /*!   clear the terminal    */
    return;
}

/******************************************************************************/
/*! \Removes a movie of admin choice                                          */
/*! \return      None                                                         */
/*! \arguments None                                                           */
/******************************************************************************/

void removeMovie(void)
{
    char temp;
    unsigned int count = numMovies;
    unsigned int option;
    int flag = 0;
    do
    {
        printf("************** Remove Movie *************\n");
        admin_printMovies();
        printf("0 to cancel or Choose Movie to remove: ");
        scanf("%d", &option);
        /* if wrong selection set flag */
        if (option < 0 || option - 1 > numMovies)
        {
            flag = 1;
        }
        /* if 0 is entered exit menu */
        if (option == 0)
        {
            return;
        }
    } while (flag); /* Repeat until correct selection */
    printf("Movie removed: %s",movies[option-1].Movie_Name);
    /* Loop over movies and move removed movie to end of list */
    for (int i = option - 1; i < numMovies - 1; i++)
    {
        movies[i] = movies[i + 1];
    }
    numMovies--;
    if (numMovies == 0)
    {
        /* Change Pointer size */
        movies = (Movies *)realloc(movies, 1 * sizeof(Movies));
    }else{
        movies = (Movies *)realloc(movies, numMovies * sizeof(Movies));
    }
    printf("\nPress Enter to Exit"); /*! Enter to Exit */
    scanf("%c", &temp);
    scanf("%c", &temp);
    system("clear"); /*!   clear the terminal    */
}

/******************************************************************************/
/*! \Prints a ticket for the given movie and seat                             */
/*! \return      None                                                         */
/*! \arguments (movie option ,seat number)                                    */
/******************************************************************************/

void printTicket(int movie_option, int seat_index)
{

    /*!       Print Ticket Header           */
    printf("\033[0;31m************** ticket *************\033[0m\n");

    // Print Name
    /*!                 */
    printf("\033[0;31m*\033[0m\033[0;32m Name  :\033[0m  ");
    for (int i = 0; i < 20; i++)
    {
        printf("%c", movies[movie_option - 1].Seatings[seat_index].Client_Name[i] == 0 ? ' ' : movies[movie_option - 1].Seatings[seat_index].Client_Name[i]);
    }
    printf("   \033[0;31m*\033[0m\n");

    /*!      Print Mobile Number           */
    printf("\033[0;31m*\033[0m\033[0;32m Mobile:\033[0m  ");
    for (int i = 0; i < 13; i++)
    {

        /*!      If the value is NULL print space else print the value           */
        printf("%c", movies[movie_option - 1].Seatings[seat_index].Client_Phone_Number[i] == '\0' ? ' ' : movies[movie_option - 1].Seatings[seat_index].Client_Phone_Number[i]);
    }
    printf("          \033[0;31m*\033[0m\n");

    /*!     Print Ticket Price            */
    printf("\033[0;31m*\033[0m\033[0;32m Price :\033[0m  ");

    /*!    check if the price is less than 3 digits print space             */
    if (movies[movie_option - 1].Seatings[seat_index].price < 100)
    {
        printf(" ");

        /*!    check if the price is less than 2 digits print space             */
        if (movies[movie_option - 1].Seatings[seat_index].price < 10)
        {
            printf(" ");
        }
    }

    /*!    print price value             */
    printf("%d", movies[movie_option - 1].Seatings[seat_index].price);
    printf("                    \033[0;31m*\033[0m\n");

    /*!    Print Seat Number             */
    printf("\033[0;31m*\033[0m\033[0;32m Seat NO.\033[0m ");

    /*!    check if the seat number is less than 3 digits print space             */
    if (seat_index + 1 < 100)
    {
        printf(" ");

        /*!    check if the seat number is less than 2 digits print space             */
        if (seat_index + 1 < 10)
        {
            printf(" ");
        }
    }
    printf("%d", seat_index + 1); /*!    print Seat Number     */
    printf("                    \033[0;31m*\033[0m\n");

    /*!    Print Ticket Footer             */
    printf("\033[0;31m***********************************\033[0m\n");
}

/******************************************************************************/
/*! \Displays reserved tickets for a selected movie                           */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/

void view_reserved_tickets(void)
{

    unsigned int movie_option = 0;
    unsigned char temp = 0;
    unsigned char flag = 0;

    system("clear"); /*!   clear the terminal    */
    do
    {

        flag = 0;            /*!    Reset the flag to indicate valid input             */
        admin_printMovies(); /*!    calling function to print the valid movies         */

        printf("Please Select the Movie: ");
        scanf("%d", &movie_option); /*!	scan the movie from the admin	*/
        fflush(stdin);

        /*!		Check if the selected movie_option is within the valid range		*/
        if ((movie_option < 1) || (movie_option > 3))
        {

            flag = 1;                                   /*! Set flag to indicate invalid input  */
            system("clear");                     /*!   clear the terminal    */
            printf("\033[0;31m Wrong movie \033[0m\n"); /*! Handle wrong movie selection */
        }

    } while (flag); /*! Repeat if the flag is set (invalid input)  */

    system("clear"); /*!   clear the terminal    */
    printf("Movie Name: %s\n", movies[movie_option - 1].Movie_Name);

    /*!	iterate the seats	*/
    for (unsigned char iterator = 0; iterator < 50; iterator++)
    {

        /*!	checking if the seat is reserved */
        if (movies[movie_option - 1].Seatings[iterator].Reserved == 1)
        {

            temp = 1;                            /*!set temp to indicate reserved seat */
            printTicket(movie_option, iterator); /*! calling function to print the reserved ticket */
        }
    }
    /*!	checking if there is no booked tickets  */
    if (temp == 0)
    {
        printf("No Booked Seats\n"); /*!	handle no booking seats  */
    }
    else
    {
        /*! Nothing */
    }

    printf("Press Enter to Exit"); /*! Enter to Exit */
    scanf("%c", &temp);
    scanf("%c", &temp);
    system("clear"); /*!   clear the terminal    */
}

/******************************************************************************/
/*! \Displays the names of available movies                           		  */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/

void admin_printMovies(void)
{
    for (int i = 0; i < numMovies; i++)
    {
        printf("%d. %s\n", i + 1, movies[i].Movie_Name);
    }
}

/******************************************************************************/
/*! \Allows the admin to change the ticket price for a selected movie         */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/

void admin_changePrice(void)
{
    int movie_option;
    int newPrice;
    unsigned char flag;

    system("clear"); /*!   clear the terminal    */
    do
    {
        flag = 0;            /*! Reset the flag to indicate valid input  */
        admin_printMovies(); /*! Calling function to print the movies  */
        printf("Enter Movie Number: ");
        scanf("%d", &movie_option); /*!  scan the movie from the admin  */
        fflush(stdin);

        /*!   Check if the chosen movie is valid    */
        if ((movie_option < 1) || (movie_option > 3))
        {

            flag = 1;                                   /*!  Set the flag to indicate wrong movie selection  */
            system("clear");                     /*!   clear the terminal    */
            printf("\033[0;31m Wrong movie \033[0m\n"); /*! Handle wrong movie selection  */
        }

    } while (flag); /*!  Repeat until a valid movie is selected */

    system("clear"); /*!   clear the terminal    */
    /*!print the old price of the movie		*/
    printf("Movie Name: %s\n", movies[movie_option - 1].Movie_Name);
    printf("Old price: %d\n", movies[movie_option - 1].Price);
    //*
    printf("Please Enter New Price: ");
    scanf("%d", &newPrice); /*!	scan the new price from the admin	*/
    fflush(stdin);

    movies[movie_option - 1].Price = newPrice; /*! 	change the price	*/
    system("clear");                    /*!   clear the terminal    */
    
}

/******************************************************************************/
/*! \Admin menu that handles various admin actions					          */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/

void Admin(void)
{
    unsigned int option;
    do
    {

        /*!	print the admin option to select from	*/
        printf("*************** Admin Menu ***************\n");
        printf("1. Change Price\n");
        printf("2. Print Booked tickets\n");
        printf("3. Change Movies\n");
        printf("0. Logout\n");

        printf("Please select an option: ");
        fflush(stdin);
        scanf("%d", &option); /*!	scan the option from the admin	*/
        fflush(stdin);

        if ((option != 3 && option != 0) && numMovies == 0)
        {
            option = 4;
        }

        /*!		switch between admin options	*/
        switch (option)
        {
        case 1:
            admin_changePrice(); /*!	calling function to change the price	*/
            break;
        case 2:
            view_reserved_tickets(); /*!	calling function to print the reserved tickts  */
            break;
        case 3:
            changeMovie();
            break;
        case 4:
            system("clear");                         /*!   clear the terminal    */
            printf("\033[0;31mNo movies in system\033[0m\n");
            break;
        case 0:
            break;
        default:
            system("clear");                         /*!   clear the terminal    */
            printf("\033[0;31m Wrong Selection \033[0m\n"); /*! Handle wrong menu selection	*/
        }
    } while (option);       /*!	repeat untill entering exit option	*/
    system("clear"); /*!   clear the terminal    */
}
