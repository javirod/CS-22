/*
CS 22, Prof Tahir Aziz 
Name: Javier Rodriguez
Assignment: Project2
Due Date: 04 APR 2021

********** Problem 9 **********
Write a program that reads a string consisting of a positive integer or a
positive decimal number and converts the number to the numeric format. If
the string consists of a decimal number, the program must use a stack to
convert the decimal number to the numeric format.

*/

#include <string>
#include <math.h>
#include <iomanip>
#include "myStack.h"
using namespace std;

int main()
{ 
    stackType<char> stringStack(50);
    string stringNumber;    // string input will be stored here
    double convNum = 0;     // number converted from string
    int periodIndx = -1;    // index location where string is located in the stack
    int stackLength;        // length of stack
    int numDecimals = 0;    // number of decimals places

	stringStack.initializeStack();
    cout << "\nPlease enter a positive number: ";
    cin >> stringNumber;
    stackLength = stringNumber.length();

    // Loops through the length of the string and pushes each character
    // to stringStack; finds the index of period in the stack
    for(int i = 0; i < stringNumber.length(); i++){
        if(stringNumber[i] == '.'){
            periodIndx = i;
        }
        stringStack.push(stringNumber[i]);
    }
    if (periodIndx == -1){
        stringStack.push('.');
        periodIndx = stackLength;
        stackLength++;
    }
    numDecimals = stackLength - periodIndx - 1;

    // Converts the char to int and finds the place value to multiply the integer by
    // Sums the numbers to output the string value as a number of type double
    // skips over the decimal place and just removes from the stack
    for(int n = (periodIndx + 1) - stackLength; n < periodIndx; n++){
        int intChar;    // convert each character to int in order to find ASCII equivalent
        if(stringStack.top() == '.'){
            stringStack.pop();
            n--;
        }
        else{
            intChar = stringStack.top() - 48;
            convNum += pow(10, n) * intChar;
            stringStack.pop();
        }
    }
    cout << "\nThe numer entered is: " << fixed << setprecision(numDecimals) << convNum << endl << endl;

	return 0;
}