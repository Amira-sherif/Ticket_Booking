#ifndef AA
#define AA

typedef struct
{
  char Client_Name[20];
  char Client_Phone_Number[13];
  int Seat_Number;
  int price;
  int Reserved;
} Seats;

typedef struct
{
  char Movie_Name[35];
  int Price;
  int Hall_Number;
  Seats Seatings[50];
} Movies;

#define NUMBER_SEATS 50

extern unsigned int numMovies;
extern Movies *movies;
void User(void);

#endif // AA