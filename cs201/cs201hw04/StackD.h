#ifndef _STACKD_H_
#define _STACKD_H_

#include <iostream>



const int MAX_STACKD = 50;
typedef double StackItemTypeD;

class StackD{

public:
   StackD();
   StackD(const StackD& aStack);
   ~StackD();

   bool isEmpty() const;
   bool push(StackItemTypeD newItem);
   bool pop();
   bool pop(StackItemTypeD& stackTop);
   bool getTop(StackItemTypeD& stackTop) const;

private:
   struct StackNode {            // a node on the stack
      StackItemTypeD item;        // a data item on the stack
      StackNode    *next;        // pointer to next node
   };

   StackNode *topPtr;     // pointer to first node in the stack
};

#endif