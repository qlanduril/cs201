/*
* Eyüp Berkan Sivrikaya
* 21803052
*/

#include "movie.h"

movie::movie()
{
    audienceRadius = 0;
    movieID = 0;

    seatPlan = new linkedList<linkedList<bool> >;

    reservationList = new ReservationList();
}

movie::movie(const long givenID ,
              const int givenRadius)
{
    movieID = givenID;

    seatPlan = new linkedList<linkedList<bool> >;
    reservationList = new ReservationList;

    if(givenRadius >= 0)
    {
        audienceRadius = givenRadius;

        for(int i = 0; i <( 1 + ( ( numOfRow - 1 ) / ( givenRadius + 1 ) ) ) ; i++ )
        {
            linkedList<bool> a;
            
            for(int j = 0; j < 1 + ( ( numOfColumn - 1 ) / ( givenRadius + 1 ) ); j++ )
            {
                a.add(1);
            }
            seatPlan->add(a);
        }
    }

    else
    {
        std::cout<<" Enter a valid radius"<<std::endl;
        audienceRadius = 0;
    }


}

movie::movie(const movie& other){

    movieID = other.movieID;
    audienceRadius = other.audienceRadius;
    seatPlan = new linkedList<linkedList<bool> >(*(other.seatPlan));

}

movie& movie::operator=(const movie& other){ 

    audienceRadius = other.audienceRadius;
    movieID = other.movieID;

    delete seatPlan;

    seatPlan = new linkedList<linkedList<bool> >(*(other.seatPlan)); 

    return *this;

}


movie::~movie(){
    delete seatPlan;
    delete reservationList;
}


long movie::getMovieID() const { return movieID; }


int movie::getAudienceRadius() const{ return audienceRadius; }


bool movie::checkSeat( const int row , const int col ) { return (*seatPlan)[row][col]; }


bool movie::reserveSeat(const int row , const char column , const int reservationCodeSeed , int& resCodee  ) {

    time_t rawtime = movieID;
    if( ( ( row - 1 ) % ( audienceRadius + 1 ) ) == 0 &&
        ( ( column - 65 ) % ( audienceRadius + 1 ) ) == 0 /* if given seat is occupiable */ )
    {
        if(  ( ((*seatPlan)[ ( row - 1 ) / ( audienceRadius + 1 )][ ( column - 65 ) / ( audienceRadius + 1 )] ) == 1 )/* if seat is empty */) {

                ((*seatPlan)[ ( row - 1 ) / ( audienceRadius + 1 )][ ( column - 65 ) / ( audienceRadius + 1 )] ) = 0;/* making seat taken b changin boolean to 0 */

                resCodee = reservationCodeGen(reservationCodeSeed , row , column);

                reservationList->insert( reservationList->getLength() , resCodee);

                std::cout<<" Yo have taken the seat " << row << column<< " at the movie at "<<ctime(&rawtime)<<std::endl;
                std::cout<<std::endl;

                return true;
        }
        else{
            std::cout<<" Given seat "<<row<<column<<" is already taken at the movie at "<<ctime(&rawtime)<<std::endl;
            std::cout<<std::endl;
            return false;
        }
    }
    else{
        std::cout<< " given seat "<<row<<column<<" is not occupiable due to covid-19 restrictions at the movie at "<<ctime(&rawtime)<< std::endl;
        std::cout<<std::endl;
        return false;
    }

}

void movie::printSeatPlan() const {

    using namespace std;
    char c;
    int numOfAvailableSeats = 0;
    
    cout<<endl;
    for(int i = 0; i < 1 + ( ( numOfColumn - 1 ) / ( audienceRadius + 1 ) ) ; i++ )
    {
        c = ( i * ( audienceRadius + 1) )+ 65;
        cout<<"\t"<<c;
    }

    for(int i = 0; i < 1 + ( ( numOfRow - 1 ) / ( audienceRadius + 1 ) ) ; i++ )
    {
        cout<<endl;
        cout<< 1 + i *( audienceRadius + 1 );

        for( int j = 0; j < 1 + ( ( numOfColumn - 1 ) / ( audienceRadius + 1 ) ) ; j++ )
        {
            if(((*seatPlan)[i][j]))
            {
                cout<<"\t"<<"o";//empty seat
                numOfAvailableSeats++;
            }
            else
            {
                cout<<"\t"<<"x";//full seat
            }
        }
    }
    time_t rawtime = movieID;
    cout<<endl;
    cout<<endl;
    cout<<"There are " << numOfAvailableSeats <<" available seats at the movie at "<<ctime(&rawtime)<<endl;
    cout<<endl;
}



void movie::flipTheSeat( const int  row , const char column ) {

    ((*seatPlan)[ ( row - 1 ) / ( audienceRadius + 1 )][ ( column - 65 ) / ( audienceRadius + 1 )]) = !( (*seatPlan)[ ( row - 1 ) / ( audienceRadius + 1 )][ ( column - 65 ) / ( audienceRadius + 1 )]);
}


ReservationList& movie::getReservationList(){ return *reservationList; }


int movie::reservationCodeGen( const int seed , const int rw , const char colum ){

    int codeBase = 2 * (seed + 1);

    int resCode = (codeBase*10000) + (rw*100) + (colum);

    return resCode;
}



//For Testing!!
/*
int main(){
    std::cout<<"========================================================================================================="<<std::endl;
    std::cout<<"program starts!"<<std::endl;

    movie m(5,3);
    

    m.printSeatPlan();

    int a;


    m.reserveSeat(5,'A', 12,a);
    std::cout<<"11111111111111111111111111"<<std::endl;
    m.reserveSeat(5,'E',12,a);
    std::cout<<"222222222222222222222222222"<<std::endl;
    m.reserveSeat(5,'M',12,a);
    std::cout<<"3333333333333333333333333333!"<<std::endl;
    m.reserveSeat(25,'Q',12,a);
    std::cout<<"4444444444444444444444444444"<<std::endl;
    m.printSeatPlan();
    std::cout<<"5555555555555555555555555555"<<std::endl;
    //m.flipTheSeat(5,'A');
    //std::cout<<"666666666666666666666666666666666"<<std::endl;
    //m.flipTheSeat(5,'M');
    //std::cout<<"7777777777777777777777777777777777"<<std::endl;
    m.printSeatPlan();

    

    //movie m3(12,0);
    //m3.printSeatPlan();

    //std::cout<<"m1 seat 0 2 = "<<m1.checkSeat(-1,2)<<" after calling"<<std::endl;


    std::cout<<"program ends!"<<std::endl;

    return 0;
}*/

