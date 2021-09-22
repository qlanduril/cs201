/*
* Eyüp Berkan Sivrikaya
* 21803052
*/

#ifndef MOVIE_H
#define MOVIE_H
#include <ctime>
#include <iostream>
#include "linkedList.h"
#include "ReservationList.h"



class movie
{
    public:
        const static int numOfRow = 30;
        const static int numOfColumn = 26;

        movie();
        movie(const long givenID,
              const int givenRadius);
        
        /*
        ~movie();
        
        movie(const movie& other);
        movie& operator=(const movie& other);
        */



        //member functions
        long getMovieID() const;
        int getAudienceRadius() const;
        bool checkSeat(const int row,
                       const int col);
        void printSeatPlan() const;

        bool reserveSeat(const int  row,
                         const char column, 
                         const int reservationCodeSeed, 
                         int& resCode );

        void flipTheSeat( const int  row ,
                          const char column );

        ReservationList& getReservationList();




    private:
        long movieID;
        int audienceRadius;
        linkedList<linkedList<bool> > seatPlan;
        ReservationList reservationList;


        int reservationCodeGen( const int seed, const int row , const char colum  );
};

#endif // MOVIE_H
