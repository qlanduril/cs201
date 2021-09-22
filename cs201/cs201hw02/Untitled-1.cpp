// Example program
#include <iostream>
#include <string>
#include <math.h>

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
}


int** createTestArrays( const int x ) {
    
   // int y; //sizes of second arrays
    
    //initializing the array
    int** a = new int*[x];

    //initializing the inner arrays
    for(int i = 0; i < x; i++){
        //y = ( ( i + 1 ) % 2 == 0 ) ? y = 5 * y : pow( 10 , i + 1 ) ;
        a[i] = new int[(int)pow( 7 , i + 1 )];

        for(int j = 0; j < (int)pow( 7 , i + 1 ); j++){
            a[i][j] = ( j + 1 ) * 5 ;
        }


    }
    return a;
}
int recursive_linear_search( const int* arr,  const int lValue,  const int rValue, const int value){
    
    if(rValue < lValue){ return -1; }

    if(arr[lValue] == value){ return lValue; }
    
    if(arr[rValue] == value){ return rValue; }
    
    return recursive_linear_search( arr , lValue + 1 , rValue - 1 , value );

}//end



int main()
{
    //int** b = createTestArrays( 10 );
    int* a;
    const int s =20000;
    a = new int[ s ];
    for(int i = 0; i < s; i++){
        a[i] = (i+1)*7;
    }
    int x = recursive_linear_search(a,0,s,INT_FAST32_MAX);//binary_search(a , 0 , 19 , 28);
    
    
    std::cout<< x <<" , a["<<x<<"]= "<<a[x]<<std::endl;

    /*
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < pow(7,i+1); j++){
            std::cout<<"b["<<i<<"]["<<j<<"]= "<<b[i][j]<<std::endl;
        }
    }*/
    return 0;


    
}