
#ifndef StackType_H
#define StackType_H

#include <iostream>
#include <cassert>

#include "stackADT.h"

using namespace std;
        
template <class Type>
class stackType: public stackADT<Type>
{	
private:
    int maxStackSize; 
    int stackTop;     
    Type *list; 
public:
    void initializeStack()
	{
		stackTop = 0;
		// cout << "stackTop " << stackTop << endl;
	}

	void print()
	{
		for(int i=0; i<stackTop; i++)
		{
			cout << list[i] << endl;
		}
	}

    bool isEmptyStack() const
	{
		return(stackTop == 0);
	}

    bool isFullStack() const
	{
		return(stackTop == maxStackSize);
	}

    void push(const Type& newItem)
	{
		if (!isFullStack())
		{
			list[stackTop] = newItem;   
			stackTop++; 
		}
		else
		{
			cout << "Cannot add to a full stack." << endl;
		}
		// cout << "stacktop: " << stackTop << endl;
		
	}

    Type top() const
	{
		assert(stackTop != 0); //if stack is empty, terminate the program.                            
		return list[stackTop - 1];
	}

    void pop()
	{
		if (!isEmptyStack())
			stackTop--; 
		else
			cout << "Cannot remove from an empty stack." << endl;

		// cout << "pop: " << stackTop << endl;
	}

    stackType(int stackSize = 100)
	{
		if (stackSize <= 0)
		{
			cout << "Size of the array to hold the stack must be positive." << endl;
			cout << "Creating an array of size 100." << endl;
			maxStackSize = 100;
		}
		else
		{
			maxStackSize = stackSize;   
			// cout << "maxStackSize "  << maxStackSize << endl;
		}

		stackTop = 0;                  
		list = new Type[maxStackSize];  
	}

    ~stackType()
	{
		delete [] list;
	}        
};

#endif