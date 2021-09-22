
#include "Stack.h"
#include "StackD.h"
#include <string.h>
#include "StrangeCalculator.h"



int main(){


    Stack s;

    s.push('a');
    s.push('b');


    for(int i = 0; i < 2; i ++){

        char c;

        s.pop(c);

        std::cout<<"first element= "<<c<<std::endl; 
    }

    std::cout<<"==============================================================="<<std::endl;

    std::string b = "berkan";

    for(int i = 0; i < 6; i ++){
        std::cout<<"b["<<i<<"]="<<b[i]<<std::endl; 

    }    
    

    std::cout<<"==============================================================="<<std::endl;

    std::string ex = " (5+6)*17-9) ";


    std::cout<<"isBalancedInfix(ex)= "<<isBalancedInfix(ex)<<std::endl; 

    std::cout<<"==============================================================="<<std::endl;


    char c2 = '0';


    //std::cout<<(int)c2<<std::endl; 
    //std::cout<<c2 == 48<<std::endl; 

    std::string s3 = "* / 8 2 + 2 2";
    double d;

    d = evaluatePrefix(s3);
    std::cout<<"s3 result= "<< d <<std::endl;

    std::cout<<"==============================================================="<<std::endl;

    std::string s5 = "(7+6)-8*(5-2)";

    std::string s10 = infix2prefix(s5);
    std::cout<<"infix form of s5( "<<s5<<" )= "<< s10 <<std::endl;
    std::cout<<"isbalnaced= "<<isBalancedInfix(s5)<<std::endl;

    std::string s50 = "(5+7)*5*6*(9/3)";

    s10 = infix2prefix(s50);
    std::cout<<"infix form of s50( "<<s50<<" )= "<< s10 <<std::endl;
    std::cout<<"isbalnaced= "<<isBalancedInfix(s50)<<std::endl;

    std::cout<<"==============================================================="<<std::endl;

    evaluateInputPrefixExpression();











    return 0;
}