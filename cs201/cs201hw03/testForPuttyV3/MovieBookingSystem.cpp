/*
* Eyüp Berkan Sivrikaya
* 21803052
*/

#include "MovieBookingSystem.h"



MovieBookingSystem::MovieBookingSystem(){

    numberOfReservations = 0;
    movieLinkedList = new linkedList<movie>;
}

MovieBookingSystem::MovieBookingSystem( const MovieBookingSystem& other ){  }

MovieBookingSystem& MovieBookingSystem::operator=( const MovieBookingSystem& other ){return *this;}

MovieBookingSystem::~MovieBookingSystem(){ delete movieLinkedList; }


void MovieBookingSystem::addMovie( const long givenMovieID , const int givenAudienceRadius) {
    if(!( givenAudienceRadius <= 7 && givenAudienceRadius >= 0 )){std::cout<<" Not a valid radius!!! "<<std::endl; return;}//radiu must be less than 8 and bigger than or equals 0

    if( checkMovieList( givenMovieID ) ){ movieLinkedList->add(movie( givenMovieID , givenAudienceRadius )); }
    /* checks if there is no movie with given id and adds to the list */
    
    else{ std::cout<<" There is already a movie with same movie Id !!! "<<std::endl; }
}

void MovieBookingSystem::cancelMovie( const long movieID )
{
    //deleting the movie from the list
    for( int i = 0; i < movieLinkedList->getSize(); i++ )
    {
        if( ((*movieLinkedList)[i]).getMovieID() == movieID ){
            movieLinkedList->remove(i);
            std::cout<<"Movie with id "<<movieID<<" is canceled."<<std::endl;
        }
    }
}

void MovieBookingSystem::showMovie( const long movieID ){

    for(int i = 0; i < movieLinkedList->getSize(); i++)
    {
        if(((*movieLinkedList)[i]).getMovieID() == movieID){
            ((*movieLinkedList)[i]).printSeatPlan();
            return;
        }

    }
    std::cout<<"No movie with given movie ID"<<std::endl;

}

void MovieBookingSystem::showAllMovies() const {
    for(int i = 0; i < movieLinkedList->getSize(); i++)
    {
        ((*movieLinkedList)[i]).printSeatPlan();
    }
}


int  MovieBookingSystem::makeReservation( const long movieID, const int row , const char column ){

    int reservationCode;

    for( int i = 0; i < movieLinkedList->getSize(); i++ )
    {
        if( (*movieLinkedList)[i].getMovieID() == movieID ){

            (*movieLinkedList)[i].reserveSeat( row , column , numberOfReservations , reservationCode);
            numberOfReservations++;
            return reservationCode;
        }
    }

    std::cout<<"No movie with given ID"<<std::endl;
    return -1;
}

void MovieBookingSystem::showReservation( const int resCode ){

    for( int i = 0; i < (*movieLinkedList).getSize(); i++ )
    {
        for( int j = 0; j < (*movieLinkedList)[i].getReservationList().getLength(); j++ )
        {
            if((*movieLinkedList)[i].getReservationList().retrieve( j , resCode)) { 

                time_t rawtime = (*movieLinkedList)[i].getMovieID();
                std::cout<<"The seat "<<(resCode % 10000)/100<<(char)(resCode % 100)<<" at the movie at "<<ctime(&rawtime)<<std::endl;
                return;
            }
        }
    }
    std::cout<<"No reservation with given reservation code"<<std::endl;

}

void MovieBookingSystem::cancelReservations( ReservationList resCode ){

    for( int i = 0; i < movieLinkedList->getSize(); i++ )
    {
        for( int j = 0; j < (*movieLinkedList)[i].getReservationList().getLength(); j++ )
        {
            for( int k = 0; k < resCode.getLength(); k++ ){

                if( (*movieLinkedList)[i].getReservationList().retrieve(j) == resCode.retrieve(k)  ){

                    (*movieLinkedList)[i].getReservationList().remove(j);
                    time_t rawtime = (*movieLinkedList)[i].getMovieID();
                    std::cout<<"The reservation with the seat "<<(resCode.retrieve(k)  % 10000)/100<<(char)(resCode.retrieve(k) % 100)<<" at the movie at "<<ctime(&rawtime)<<" has been canceled. "<<std::endl;                   

                    (*movieLinkedList)[i].flipTheSeat( (resCode.retrieve(k)  % 10000)/100 , (char)(resCode.retrieve(k) % 100) );

                }
            }

        }
    }
}
       



bool MovieBookingSystem::checkMovieList(const long movieID)
{
    for(int i = 0; i < movieLinkedList->getSize(); i++)
    {
        if( ((*movieLinkedList)[i]).getMovieID() == movieID )
            return 0;
    }
    return 1;

}














//For Testing
/*
int main(){

    std::cout<<"====================================================================================================="<<std::endl;
    
    std::cout<<"program starts!!!"<<std::endl;
    //int aeeee[10000][12344];

    MovieBookingSystem ms1;

    std::cout<<"adding first movie"<<std::endl;
    std::cout<<"________________________________________________________________________________________________________"<<std::endl;
    ms1.addMovie(1231,3);
    std::cout<<"printing seat plan"<<std::endl;
    ms1.showAllMovies();

    std::cout<<"adding second movie"<<std::endl;
    std::cout<<"________________________________________________________________________________________________________"<<std::endl;
    ms1.addMovie(14121,2);
    std::cout<<"printing seat plan"<<std::endl;

    ms1.showAllMovies();
    
    std::cout<<"adding third movie"<<std::endl;
    std::cout<<"________________________________________________________________________________________________________"<<std::endl;
    ms1.addMovie(1433321,4);
    ms1.showAllMovies();

    std::cout<<"adding movie same id" <<std::endl;
    std::cout<<"________________________________________________________________________________________________________"<<std::endl;
    ms1.addMovie(14121,4);
    ms1.showAllMovies();
    std::cout<<"________________________________________________________________________________________________________"<<std::endl;
    std::cout<<"making reservation" <<std::endl;

    int a = ms1.makeReservation( 1433321 , 6 , 'A' );
    ms1.showReservation(a);
    ms1.showAllMovies();

    //ms1.cancelMovie( 1433321 );

    //ms1.showAllMovies();

    //ms1.showReservation(a);

    ReservationList r;
    r.insert(0,a);

    ms1.cancelReservations(r);
    ms1.showAllMovies();
    ms1.showReservation(a);
    std::cout<<"program ends!!!"<<std::endl;   

    return 0;
}*/