/*
* Eyüp Berkan Sivrikaya
* 21803052
*/

#include "ReservationList.h"

ReservationList::ReservationList(){

    head = NULL;
    size = 0;
}

ReservationList::ReservationList(const ReservationList& other){

    ReservationNode* curr;
    size = 0;

    for(int i = 0; i < other.getLength(); i++){

        curr = other.find(i);
        insert( size , curr->Code );
    }
}

ReservationList::~ReservationList(){

    while( head != NULL ){ remove(0); }
}

ReservationList ReservationList::operator= ( const ReservationList& other){ return *this; }


bool ReservationList::isEmpty() const { return ( head == NULL && size == 0 ); }

int ReservationList::getLength() const { return size; }

bool ReservationList::retrieve(int index, int resCode) const { return find(index)->Code == resCode; }

int ReservationList::retrieve( int index ) const{ return find(index)->Code; }

bool ReservationList::insert( int index, int resCode ){

    if( index < 0 || index > size){ return 0; }

    //making node to be added
    ReservationNode *tmp = new ReservationNode;

    tmp->Code = resCode;
    tmp->next = NULL;


    if ( (index == 0) && (size == 0) ){ 

        head = tmp;
        size++;
        return 1; 
    }
    else if ( (index == 0) ){

        tmp->next = head;
        head = tmp;
        size++;
        return 1;

    }

    ReservationNode  *curr , *prev; 
    curr = find( index );
    prev = find( index - 1 );

    tmp->next = curr;
    prev->next = tmp;
    size++;
    return 1;

}

bool ReservationList::remove( int index ){

    //empty list and out of bound index conditions
    if(index < 0 || index >= size || size < 1 ){ return 0; }
    
    ReservationNode *curr, *prev;

    //deleting head
    if( index == 0 && size == 1){

        curr = head;
        head = NULL;
        delete curr;
        size--;
        return 1;
    }
    else if( index == 0 ){

        curr = head;
        head = head->next;
        curr->next = NULL;
        delete curr;
        size--;
        return 1; 
    }

    curr = find( index );
    prev = find( index - 1 );

    //deleting the given index and connecting the chains
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    size--;

    return 1;

}


ReservationList::ReservationNode* ReservationList::find(int index) const{

    ReservationNode* curr = head;

    for( int i = 0; i < index ; i++ ){ curr = curr->next; }

    return curr;

}


void ReservationList::printList(){ 

    for(int i = 0; i < getLength(); i++){ std::cout<<"ls["<<i<<"]== "<<find(i)->Code<<std::endl; }
}


 //For Testing!!!!!
 /*
int main(){

    ReservationList r;

    std::cout<<"program starts!"<<std::endl;

    std::cout<<"before printing empty list"<<std::endl;
    r.printList();
    std::cout<<"after printing empty list"<<std::endl;

    std::cout<<"inserting starts!"<<std::endl;
    r.insert(0,1);
    r.printList();
    std::cout<<"after inserting 1"<<std::endl;
    r.insert(0,2);
    r.printList();
    std::cout<<"after inserting 2"<<std::endl;
    r.insert(0,3);
    r.printList();
    std::cout<<"after inserting 3"<<std::endl;
    r.insert(0,4);
    r.printList();
    std::cout<<"after inserting 4"<<std::endl;
    r.insert(0,5);
    r.printList();
    std::cout<<"after inserting 5"<<std::endl;
    
    std::cout<<"============================================================================================================"<<std::endl;
    std::cout<<"Testing for remove"<<std::endl;
    std::cout<<std::endl;

    std::cout<<"removing element"<<std::endl;
    r.remove(0);
    r.printList();


    

    std::cout<<"============================================================================================================"<<std::endl;
    std::cout<<"Testing for copy"<<std::endl;

    ReservationList r2(r);
    std::cout<<"r2"<<std::endl;
    r2.printList();
    std::cout<<"r1"<<std::endl;
    r.printList();
    

    return 0;

}*/










