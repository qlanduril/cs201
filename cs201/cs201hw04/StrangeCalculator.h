#ifndef _STRANGECALCULATOR_H_
#define _STRANGECALCULATOR_H_
    
    
#include <string>
#include "Stack.h"
#include "StackD.h"
#include <iostream>
using namespace std;

string infix2prefix( const string exp );

double evaluatePrefix( const string exp );

bool isBalancedInfix( const string exp );

void evaluateInputPrefixExpression();




#endif
