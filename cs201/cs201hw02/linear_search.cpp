/*Eyüp Berkan Sivrikaya
* BILKENT UNIVERSIT CS DEPARTMENT
* 21803052
* CODE EXPLINATION
* for better testing there are two testing methods
* test_method() is for linear_search() and jumpSearh() methods 
* test_method2() is for recursive_linear_search() and binary_seaarch() methods
* In each test methods test_method() and test_method2() there are two methods one of them whic is commented
* for getting the data one must do these;
* only a method should be uncommented inside main(). Either test_method() or test_method2()
* only a method should be uncommented inside test_method(). Either linear_search() or jumpSearch()
* only a method should be uncommented inside test_method2(). Either recursive_linear_search() or binary_search()
* for the data of linear_search() --> Uncomment test_method() from main() method then uncomment the linear_search() method from inside of test_method() 
* for the data of recursive_linear_search() --> Uncomment test_method2() from main() method then uncomment the recursive_linear_search() method from inside of test_method()
* for the data of binary_search() --> Uncomment test_method2() from main() method then uncomment the binary_search() method from inside of test_method()  
* for the data of jumpSearch() --> Uncomment test_method() from main() method then uncomment the jumpSearch() method from inside of test_method() 
*   
*/



#include <iostream>
#include <chrono> // requires to be compiled in c++11 /*g++ -std=c++11 file.cpp -o program*/
#include <math.h>
using namespace std;


int linear_search( const int* arr , const int size , const int value );

int recursive_linear_search( const int* arr,  const int lValue,  const int rValue, const int value);

int binary_search(const int* arr , const int l , const int r , const int value );

int jumpSearch(const int* arr , const int x , const int n);

int** createTestArrays( const int x );

void test_method( int** &arr );

void test_method2( int* &a );

//===========================================================================================================================

//main method
int main(){

    int** a = createTestArrays( 10 );

    
    std::cout<<"testing starts"<<endl;
    
    
    test_method(a); //method to get the data of linear search and jump search
    
    /*TO GET THE BINARY AND RECURSIVE LINEAR SEARCH METHODS' DATA UNCOMMENT HERE*/
    //test_method( a[9] );

    std::cout<<"testing done"<<endl;
    return 0;

}//end

//=======================================================================================================================

//implementations

//linear search
int linear_search( const int* arr , const int size , const int value ) {
    for(int i = 0; i < size; i++ ){
        if(arr[i] == value)
            return i;
    }
    return -1;

}//end

//==================================================================================================================

//recursive linear search
int recursive_linear_search( const int* arr,  const int lValue,  const int rValue, const int value){
    
    if(rValue < lValue){ return -1; }

    if(arr[lValue] == value){ return lValue; }
    
    if(arr[rValue] == value){ return rValue; }
    
    return recursive_linear_search( arr , lValue + 1 , rValue - 1 , value );

}//end

//==================================================================================================================

//binary search
int binary_search(const int* arr , const int l , const int r , const int value ){
    if(r >= l){
        int mid = l + (r - l) / 2;

        //if the element is present at the middle return it
        if(arr[mid] == value)
            return mid;

        //left subarray
        if(arr[mid] > value)
            return binary_search(arr , l , mid - 1 , value );
        
        //right subarray
        if(arr[mid] < value)
            return binary_search( arr , mid + 1 , r , value);
    }
    //item is not present at the list
    return -1;

}//end

//==================================================================================================================

//jumpSearch
int jumpSearch(const int* arr , const int x , const int n) {
    // Finding block size to be jumped
    int step = sqrt(n);
 
    // Finding the block where element is
    // present (if it is present)
    int prev = 0;
    while (arr[min(step, n)-1] < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }
 
    // Doing a linear search for x in block
    // beginning with prev.
    while (arr[prev] < x)
    {
        prev++;
 
        // If we reached next block or end of
        // array, element is not present.
        if (prev == min(step, n))
            return -1;
    }
    // If element is found
    if (arr[prev] == x)
        return prev;
 
    return -1;

}//end

//==================================================================================================================

//testMethod
void test_method( int** &arr){
    
    int N; //to store the number of elements in arrays

    const int NUMBER_OF_TRYs = 100000; // to loop the method in order to get a better result

    for(int i = 0; i < 10; i++){

        N = ( i % 2 == 1 ) ? ( 2 * N ) : ( 2 * pow( 3 , i + 1 ) );

        int tries = NUMBER_OF_TRYs / pow( 2 , 2 * ( i - 5 ) ); //to reduce the number for bigger arrays
        
        //a b c d part
        for(int j = 0; j < 4; j++){

            char c = j + 97;
            int value;

            //loops for storing index of data to be searched
            if (j == 0){ value = arr[i][ N / 5 ]; }

            else if (j == 1){ value = arr[i][ N / 2 ]; }

            else if (j == 2){ value = arr[i][ 4 * N / 5] ; }

            else if (j == 3) { value = INT_FAST32_MAX; }
        
            //start time
            chrono::time_point<chrono::system_clock> startTime;
            chrono::duration< double , milli > elapsedTime;
            startTime = chrono::system_clock::now();
            
            //method calling
            //multiple calling for better approximation
            for(int k = 0; k <  tries; k++){

                //linear_search(arr[i],N-1,value); 
                
                jumpSearch(arr[i] , value , N);
            }
            
            elapsedTime = (std::chrono::system_clock::now() - startTime) ;//storing passed time
        

            //printing tme results
            std::cout<<"input size= "<< N <<endl;
            std::cout<<"Part "<<c<<endl;
            std::cout << "Execution took " << elapsedTime.count()/ ( tries ) << " milliseconds." << endl;

        }
    }

}//end

//==================================================================================================================


void test_method2( int* &a){
    
    int N; //number of elements

    int value; // value to be searched

    const int NUMBER_OF_TRYS = 100000;

    for(int i = 0; i < 10; i ++){

        N = ( i % 2 == 1 ) ? ( 2 * N ) : ( 2 * pow( 3 , i + 1 ) ); 

        for(int j = 0; j < 4; j ++){

            char c = j + 97; 

            //loops for storing index of data to be searched
            if (j == 0){ value = a[ N / 5 ]; }

            else if (j == 1){ value = a[ N / 2 ]; }

            else if (j == 2){ value = a[ 4 * N / 5] ; }

            else if (j == 3) { value = INT_FAST32_MAX; } //a[ N - 1 ] + 17; }


            //start time
            chrono::time_point<chrono::system_clock> startTime;
            chrono::duration< double , milli > elapsedTime;
            startTime = chrono::system_clock::now();

            int tries = NUMBER_OF_TRYS; /// (  pow( 10 , i - 2 ) ); // to cahnge NUMBER_OF_TRYS according to the size of array

            for(int k = 0 ; k < tries; k++){

                //recursive_linear_search( a , 0 , N - 1, value );

                binary_search( a , 0 , N - 1, value );
            }

            elapsedTime = (std::chrono::system_clock::now() - startTime) ;//storing passed time
        

            //printing tme results
            std::cout<<"input size= "<< N <<endl;
            std::cout<<"Part "<<c<<endl;
            std::cout << "Execution took " << elapsedTime.count()/ ( tries ) << " milliseconds." << endl;


        }

        
    }
}

//==================================================================================================================

//createTestArrays
int** createTestArrays( const int x ) {

    //initializing the array
    int** a = new int*[ x ];

    //initializing the inner arrays
    for(int i = 0; i < x; i++){

        a[i] = new int[(int)pow( 7 , i + 1 )];

        for(int j = 0; j < (int)pow( 7 , i + 1 ); j++){
            a[i][j] = ( j + 1 ) * 3 ;
        }
    }
    
    //returning a
    return a;

}//end