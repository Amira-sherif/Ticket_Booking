/******************************************************************************/
/*                                                                            */
/* !Component       : main                                                    */
/* !Description     : Application Entry Point                                 */
/*                                                                            */
/* !Module          : main                                                    */
/* !Description     : Main Module implementation                              */
/*                                                                            */
/* !File            : main.c                                                  */
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

/*! Include compiler types header                                             */
#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "admin_mode.h"
#include "app.h"

int main()
{
    system("clear"); /*!   clear the terminal    */
    InitMovies();
    MenuHandle();
    free(movies);
    return 0;
}
