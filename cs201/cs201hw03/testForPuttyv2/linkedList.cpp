/*
* Eyüp Berkan Sivrikaya
* 21803052
*/

#include "linkedList.h"
#include "movie.h"

//constructor
template <class T>
linkedList<T>::linkedList(){
    head = NULL;
    size = 0;
}


template <class T>
linkedList<T>::linkedList(const linkedList<T>& other){

    if( other.head != NULL ){

        size = other.size;

        head = new node;
        head->data = other.head->data;

        node* newNode = head;

        for( node* curr = other.head->next ; curr != NULL; curr = curr->next ){

            newNode->next = new node;
            newNode = newNode->next;
            newNode->data = curr->data;
        }

        newNode->next = NULL;
    }
   
}



template<class T>
linkedList<T>::~linkedList(){

while( head != NULL ){ removeFirst(); }

head = NULL;

}

template<class T>
linkedList<T>& linkedList<T>::operator=(const linkedList<T>& other){
    
    if(this == &other){ return *this; } // self assignment

    size = other.size;

    while( head != NULL ){ removeFirst(); }

    head = NULL;

    if(other.head == NULL ){ head = NULL; return *this; }

        
    if( other.head != NULL ){

        head = new node;
        head->data = other.head->data;

        node* newNode = head;

        for( node* curr = other.head->next ; curr != NULL; curr = curr->next ){

            newNode->next = new node;
            newNode = newNode->next;
            newNode->data = curr->data;
        }

        newNode->next = NULL;
    }

    return *this;

}


    
//method to add element to the end
template <class T>
void linkedList<T>::add( const T& aData ) {
    
    //for iterating trough list
    node* curr;
    
    //building node to be added
    node* a = new node;
    a->data = aData;
    a->next = NULL;
    
    if ( head == NULL ) { head = a; size++; return; }
    
    for( curr = head; curr->next != NULL; curr = curr->next ){ }

    curr->next = a;
    size++;

}

template <class T>
T linkedList<T>::getAT( const int index ) const {
    //std::cout<<"checkpoint2 1 "<<std::endl;
    if(size == 0 || index > size || index <= 0 ){ return head->data; std::cout<<"NOT A VALIS INDEX "<<std::endl;}
    node* curr;
    curr = head; 
    for( int i = 1; i <= size; i++ , curr = curr->next ) { /*std::cout<<"checkpoint2-loop "<<i<<std::endl;*/ if( i == index ) { break; }  }
    return (curr->data);
}

template <class T>
int linkedList<T>::getSize() const{
    return size;
}

template <class T>
T& linkedList<T>::operator[]( const int index ) const {
    
    if(size == 0 || index >= size || index < 0 ){ std::cout<<"NOT A VALIS INDEX so head->data returned "<<std::endl; return head->data; }
    if( index == 0 ){ return head->data; }
    
    node* curr;
    curr = head; 
    
    for( int i = 1; i <= size; i++ , curr = curr->next ) { if( i == index + 1 ) { break; }  }
    return (curr->data);

}

template<class T>
void linkedList<T>::removeFirst(){

    if( head == NULL ){ return; }
    node* curr = head;
    head = head->next;
    delete curr;
    size--;
}

template <class T>
void linkedList<T>::remove( const int index ){

    if( index < 0 || index >= size ) { std::cout<<"Not a valid index!!!"<<std::endl; return; }

    if( index == 0 ) { removeFirst(); return; }

    int i = 0;
    node* itemToBeRemoved;
    

    for( node* curr = head; curr->next!= NULL; curr = curr->next ){

        if( /*( i != 0 ) && */( i < size ) && ( ( i + 1 ) == index ) ){

            itemToBeRemoved = curr->next;
            curr->next = itemToBeRemoved->next;
            itemToBeRemoved->next = NULL;
            delete itemToBeRemoved;
            size--;
            return;
        }
        i++;
    }
}





//template<typename T>
/*
void printList( linkedList<int>& aList , const int aSize ){
    for(int i = 0; i < aSize; i++){
        std::cout<< aList[i] <<std::endl;
    }

}*/

/*
int main()
{
    
    linkedList<int> l;
    
    std::cout<<"checkpoint 1 "<<std::endl;
    l.add(5);
    l.add(12);
    l.add(14);
    l[2] = 76;
    l.add(13);
    std::cout<<"checkpoint 2 "<<std::endl;
    int a = l.getAT(1);
    int b = l.getAT(2);
    std::cout<<"checkpoint 3 "<<"    l[0]= "<<a<< std::endl;
    std::cout<<"checkpoint 3 "<<"    l["<<3<<"]= "<<l.getAT(3) <<" == "<<l[l.getSize()-1]<<" size= "<<l.getSize()<< std::endl;
    printList(l,l.getSize());
    linkedList<linkedList<int> > l2;



    //l3 = l2;
    std::cout<<"checkpoint 4 "<<std::endl;

    
    l2.add(l);

    int i = 2;
    

    std::cout<<"l2[0]["<<i<<"]= "<<l2[0][1]<<std::endl; //"=="<<l3[0][4]<<"(l3[0][4])"<<


    
    std::cout<<"checkpoint 5 "<<std::endl;
    l.remove(2);
    printList(l,l.getSize());

    std::cout<<"checkpoint 6 "<<std::endl;
    l.remove(0);
    l.remove(0);
    printList(l,l.getSize());
    std::cout<<"after first printing "<<std::endl;
    l.remove(0);
    std::cout<<"after last remove "<<std::endl;
    printList(l,l.getSize());
    std::cout<<"checkpoint 7 "<<std::endl;
    std::cout<<"=============================================================================================="<<std::endl;
    
    std::cout<<"testing add functionality "<<std::endl;
    
    std::cout<<std::endl;
    
    linkedList<int> lst;
    
    std::cout<<"before printing empty list"<<std::endl;
    
    printList(lst,lst.getSize());
    
    std::cout<<"after printing empty list"<<std::endl;
    std::cout<<std::endl;
    
    std::cout<<"adding first elemnt"<<std::endl;
    lst.add(12);
    std::cout<<"size of lst= "<<lst.getSize()<<std::endl;
    printList(lst,lst.getSize());
    
    std::cout<<"adding second element"<<std::endl;
    lst.add(22);
    std::cout<<"size of lst= "<<lst.getSize()<<std::endl;
    printList(lst,lst.getSize());
    
    std::cout<<"adding third elemnt"<<std::endl;
    lst.add(32);
    std::cout<<"size of lst= "<<lst.getSize()<<std::endl;
    printList(lst,lst.getSize());
    
    std::cout<<"adding fourth element"<<std::endl;
    lst.add(51);
    std::cout<<"size of lst= "<<lst.getSize()<<std::endl;
    printList(lst,lst.getSize());
    
    std::cout<<"adding fifth element"<<std::endl;
    lst.add(67);
    std::cout<<"size of lst= "<<lst.getSize()<<std::endl;
    printList(lst,lst.getSize());
    std::cout<<std::endl;
    std::cout<<"end of adding"<<std::endl;

    std::cout<<"_____________________________________________________________________________________________________"<<std::endl;
    std::cout<<"testing operator[] "<<std::endl;
    std::cout<<std::endl;
    
    for(int i = -1; i <= lst.getSize(); i++) {
        std::cout<<"lst["<<i<<"]= "<< lst[i]<<std::endl;
    }
    

    std::cout<<"_____________________________________________________________________________________________________"<<std::endl;
    std::cout<<"testing remove functionality "<<std::endl;
    std::cout<<std::endl;
    

    std::cout<<"before Removing last element"<<std::endl;
    std::cout<<"size of lst= "<<lst.getSize() <<std::endl;
    printList(lst,lst.getSize());
    lst.remove( lst.getSize() - 1 );
    std::cout<<"size of lst= "<<lst.getSize() <<std::endl;
    printList(lst,lst.getSize());
    std::cout<<"afterRemoving last element"<<std::endl;
    std::cout<<std::endl;
    


    std::cout<<"before Removing arbitrary element"<<std::endl;
    std::cout<<"size of lst= "<<lst.getSize() <<std::endl;
    printList(lst,lst.getSize());
    lst.remove( 1 );
    std::cout<<"size of lst= "<<lst.getSize() <<std::endl;
    printList(lst,lst.getSize());
    std::cout<<"afterRemoving arbitrary element"<<std::endl;
    std::cout<<std::endl;
    

    std::cout<<"before Removing first element"<<std::endl;
    std::cout<<"size of lst= "<<lst.getSize() <<std::endl;
    printList(lst,lst.getSize());
    lst.remove( 0 );
    std::cout<<"size of lst= "<<lst.getSize() <<std::endl;
    printList(lst,lst.getSize());
    std::cout<<"afterRemoving first element"<<std::endl;
    std::cout<<std::endl;

    return 0;

}
*/

template class linkedList<int>;
template class linkedList<bool>;
template class linkedList<linkedList<bool> >;
template class linkedList<movie>;