//linkedList.h
#ifndef  LINKEDLIST_H
#define  LINKEDLIST_H

//include
#include <iostream>
#include <string>


template<class T>
class linkedList{

    private:
        struct node {
            T        data;
            node* next;    
        };

    //varriables
    node* head;
    int size;

    //inner methods
    void removeFirst();

    public:

    linkedList<T>(); //constructor

    linkedList(const linkedList<T>& other);

    ~linkedList(); //destructor

    linkedList<T>& operator=(const linkedList<T>& other);

    void add( const T& aData ); //method to add data to end

    T getAT( const int index ) const; //getting the Nth data

    int getSize() const;

    T &operator[]( const int index ) const ;

    

    void remove( const int index );

};
#endif