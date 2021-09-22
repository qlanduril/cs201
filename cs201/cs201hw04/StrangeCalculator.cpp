#include "StrangeCalculator.h"



string infix2prefix( const string exp ){

    Stack s;
    std::string prefix = ""; 
    char c; //it is the top element changing at each itaration

    for( int i = exp.length() - 1 ; i >= 0; i--  ){

        if( ((exp[i] <= 57) && (exp[i] >= 48))  ) // if it is an operand
        {
            prefix = exp[i] + prefix; // adding to the result since it is an operand
        }

        else if( exp[i] <= 47 && exp[i] >= 40  ) //if it is an operator
        {

            s.getTop(c);
            switch(exp[i])
            {
                case '+':
                    if(c == '*' || c == '/'  ){ // to see if top has higher presedence

                        prefix = c + prefix; // adding top to the result string since it has higher presedence 
                        s.pop(); // removing the top since we add it to the result string
                        s.push(exp[i]); // pushing the operator with low presedence
                    }
                    else{
                        s.push(exp[i]);
                    }  
                break;

                case '-': // same as '+' case
                    if(c == '*' || c == '/'  ){
                        prefix = c + prefix;
                        s.pop();
                        s.push(exp[i]);
                    }
                    else{
                        s.push(exp[i]);
                    }
                break;

                case '/':
                    s.push(exp[i]);
                break;

                case '*':
                    s.push(exp[i]);
                break;

                case '(':
                    while( c != ')'){ //pop until find ')' and add operators to the result string
                        s.pop(c);
                        if( c!=')' ){ prefix = c + prefix; }
                    }
                break;

                case ')':
                    s.push(exp[i]);                   
                break;
            }

        }
    }

    // removing the last operators
    while( !s.isEmpty() ){
        s.pop(c);
        prefix = c + prefix;
    }

    return prefix;
}

//=================================================================================================================================================================

bool isBalancedInfix( const string exp ){

    Stack s;
    //char c;

    for(int i = 0; i < exp.length(); i ++){

        if( exp[i] == '(' ){ s.push( exp[i] ); }

        else if ( exp[i] == ')' ){

            if ( s.isEmpty() == 0 ){ s.pop(); }

            else{ return 0; }
        }
        
    }

    return s.isEmpty();
}

//=================================================================================================================================================================

double evaluatePrefix( const string exp ){

    double result = 0;
    StackD s;

    for( int i = exp.length() - 1; i >= 0; i--  ){

        if( exp[i] <= 57 && exp[i] >= 48  )// if it is an operand
        {
            s.push((int)(exp[i]) - 48); //pushing the number(operand)
        }

        else if( exp[i] <= 47 && exp[i] >= 42  )//if it is an operator
        {
            //evaluation part
            double operand1,operand2;
            s.pop(operand1);
            s.pop(operand2);

            switch(exp[i])
            {
                case '+':
                    operand1 += operand2;
                    s.push(operand1); 
                break;

                case '-':
                    operand1 -= operand2;
                    s.push(operand1);
                break;

                case '/':
                    operand1 /= operand2;
                    s.push(operand1);

                break;

                case '*':
                    operand1 *= operand2;
                    s.push(operand1);
                break;
            }

        }
    }
    s.pop(result);
    return result;
}

//=================================================================================================================================================================

void evaluateInputPrefixExpression(){

    std::string exp;

    getline( std::cin, exp );

    //removing possible spaces
    for( int i  = 0; i < exp.length(); i++ ){

        if( exp[i] == ' '  ){ exp[i] = (char)0; } //assigning null character to the spaces(' ')
    }
    std::cout<<exp<<std::endl;

    bool isBalanced = isBalancedInfix( exp );

    // checking for unbalanced paranthesis
    if ( isBalanced )
    {
        std::cout<<" The given expression is balanced "<<std::endl;
    }
    else
    {
        std::cout<<" The given expression is unbalanced "<<std::endl;
    }

    // turning into prefix and calculating

    std::string prefix = infix2prefix( exp );
    std::cout<<" prefix form= "<< prefix <<std::endl;

    std::cout<<" The result = "<< evaluatePrefix( prefix )<<std::endl;
    


}

