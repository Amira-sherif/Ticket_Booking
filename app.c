/******************************************************************************/
/*                                                                            */
/* !Component       : app                                                     */
/* !Description     : Application Handling Module                             */
/*                                                                            */
/* !Module          : app                                                     */
/* !Description     : application Module implementation                       */
/*                                                                            */
/* !File            : app.c                                                   */
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
/* !Designed by     : Mahmoud Emara - Amira Sherif     !Date : JULY 08, 2023  */
/* !Coded by        : Mahmoud Emara - Amira Sherif     !Date : JULY 08, 2023  */
/*                                                                            */
/* Rev 1.0   JULY 08, 2023     Initial release                                */
/******************************************************************************/

/*! Include basic types header                                                */
#include "app.h"
#include "user.h"
#include "admin_mode.h"
#include <stdio.h>
#include <stdlib.h>

/******************************************************************************/
/****************************** Global Variables ******************************/
/******************************************************************************/
static int trailsFlag = PASSWORD_TRIALS;
static int ExitFlag = 0;

unsigned int numMovies = 0;
Movies *movies;

/******************************************************************************/
/*********************** Public Functions Implementation **********************/
/******************************************************************************/

/******************************************************************************/
/*! \Description Initialize the Movies Global Array                           */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void InitMovies()
{
    movies = (Movies *)malloc(1 * sizeof(Movies));
}
/******************************************************************************/
/*! \Description Handling the main menu terminal                              */
/*! \return      None                                                         */
/*! \arguments   None                                                         */
/******************************************************************************/
void MenuHandle()
{
    /*!     declare local var for scaning the user entry             */
    int AdminPassword;
    int UserPassword;
    int personChoose;

    /*!     print the welcome menu                           */
    printf("***********************************\n");
    printf("***********CINEMA Tickets**********\n");
    printf("*******Welcome to Our Cinema*******\n");
    printf("***********************************\n");

    while (1) /*!   main menu Super loop         */
    {
        if (ExitFlag == 0) /*!   Exit flag Checking         */
        {
            printf("Login as :\n 1.ADMIN \n 2.USER\n 3.EXIT \n");
            scanf("%d", &personChoose); /*!   scan the person Choice       */
            system("clear");     /*!   clear the terminal    */
            if(personChoose == 2 && numMovies == 0){
                personChoose = 4;
            }
            switch (personChoose)       /*!   switch between modes    */
            {
            case 1:
                printf("Enter Admin Password : \n");
                scanf("%d", &AdminPassword);         /*!   scan the password from the user    */
                system("clear");              /*!   clear the terminal    */
                if (AdminPassword == ADMIN_PASSWORD) /*!   password checking    */

                {
                    Admin(); /*!   calling Admin fun to enter the admin Mode    */
                }
                else
                {
                    printf("\033[0;31m wrong Password\033[0m\n\n"); /*!   wrong password handling     */
                }
                break;

            case 2:
                printf("Enter User Password : \n");
                scanf("%d", &UserPassword);        /*!   scan the password from the user    */
                system("clear");            /*!   clear the terminal    */
                if (UserPassword == USER_PASSWORD) /*!   password checking    */
                {
                    trailsFlag = PASSWORD_TRIALS;
                    User(); /*!   calling User fun to enter the user Mode    */
                }
                else
                {
                    if (trailsFlag != 0)
                    {

                        printf("\033[0;31m wrong Password\033[0m\n"); /*!   wrong password handling     */
                        printf("\033[0;31m you have %d trials left\033[0m\n\n", trailsFlag);
                        trailsFlag--;
                    }
                    else
                    {
                        printf("\033[0;31m you have no trials left to reset enter the admin password :\033[0m\n");
                        scanf("%d", &AdminPassword);         /*!   scan the password from the user    */
                        system("clear");              /*!   clear the terminal    */
                                                             //                            system("cls");
                        if (AdminPassword == ADMIN_PASSWORD) /*!   password checking    */

                        {
                            trailsFlag = PASSWORD_TRIALS;
                        }
                        else
                        {
                            printf("\033[0;31m wrong Password\033[0m\n\n"); /*!   wrong password handling     */
                        }
                    }
                }
                break;

            case 3:
                printf("\033[0;31mSystem Shutdown\033[0m\n");
                ExitFlag = 1;
                break;
            case 4:
                printf("\033[0;31mNo movies in system\033[0m\n");
                break;
            default:
                printf("\033[0;31mPlease Enter the right choice\033[0m\n\n"); /*!   wrong entry handling    */
            }
        }
        else
        {
            break;
        }
    }
}
