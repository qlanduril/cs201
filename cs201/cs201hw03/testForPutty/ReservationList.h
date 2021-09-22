/*
*Eyüp Berkan Sivrikaya
*21803052
*/
#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>

class ReservationList{

    public:
    ReservationList();
    ReservationList( const ReservationList& aList );
    ~ReservationList();
    ReservationList operator= (const ReservationList& other);

    bool isEmpty() const;
    int getLength() const ;
    bool retrieve( int index, int resCode ) const;
    int retrieve( int index ) const;
    bool insert( int index, int resCode );
    bool remove( int index );

    void printList();



    private:

    struct ReservationNode{
        int Code;
        ReservationNode* next;
    };

    int size;
    
    ReservationNode *head;
    ReservationNode *find(int index) const;

}; 
#endif