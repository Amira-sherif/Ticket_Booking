/******************************************************************************/
/*                                                                            */
/* !Component       : app                                                     */
/* !Description     : Application Handling Module                             */
/*                                                                            */
/* !Module          : app                                                     */
/* !Description     : application Module Header                               */
/*                                                                            */
/* !File            : app.h                                                   */
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

#ifndef APP
#define APP

/******************************************************************************/
/****************************** Macro Definitions *****************************/
/******************************************************************************/
#define ADMIN_PASSWORD 1234
#define USER_PASSWORD  4321
#define PASSWORD_TRIALS 3




/******************************************************************************/
/*************************** Functions Declaration ****************************/
/******************************************************************************/
void InitMovies(void);
void MenuHandle(void);


#endif //APP
