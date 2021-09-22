/*
*Eyüp Berkan Sivrikaya
*21803052
*/
#ifndef MOVIEBOOKINGSYSTEM_H
#define MOVIEBOOKINGSYSTEM_H
#include <iostream>
#include "movie.h"
#include "linkedList.h"
#include "ReservationList.h"

class MovieBookingSystem
{
    public:
        const static int numOfRow = 30;
        const static int numOfColumn = 26;

        MovieBookingSystem();
        /*~MovieBookingSystem();
        MovieBookingSystem( const MovieBookingSystem& other );
        MovieBookingSystem& operator=( const MovieBookingSystem& other );*/

        //member functions
        void addMovie( const long movieID, const int audienceRadius );
        void cancelMovie( const long movieID );
        void showAllMovies() const;
        void showMovie( const long movieID );
        int  makeReservation( const long movieID, const int row , const char column );
        void cancelReservations( ReservationList resCode );
        void showReservation( const int resCode );
        void showAllReservations();
        


    private:
        //varriables

        linkedList<movie> movieLinkedList;

        int numberOfReservations; //for giving the reservation codes

        //inner methods
        bool checkMovieList( const long movieID );

        movie& getMovie( const long movieID );
};

#endif // MOVIEBOOKINGSYSTEM_H
