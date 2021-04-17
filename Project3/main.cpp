/*
CS 22, Prof Tahir Aziz 
Name: Javier Rodriguez
Assignment: Project 3
Due Date: 18 APR 2021

********** Problem 15  **********
Write a program that reads a line of text, changes each uppercase letter to
lowercase, and places each letter both in a queue and onto a stack. The
program should then verify whether the line of text is a palindrome (a set of
letters or numbers that is the same whether read forward or backward).
*/

#include <string>
#include <math.h>
#include <iomanip>
#include "myQueue.h"
#include "myStack.h"
using namespace std;

int main()
{ 
    stackType<char> stringStack(50);
    queueType<char> stringQueue;
    
    string stringText;      // string input will be stored here
    int spaceCounter = 0;   // counts the number of spaces in the text entered
    int countPal = 0;     // checks for status of palindrome
    int stringLength;       // length of stack

	stringStack.initializeStack();
    stringQueue.initializeQueue();
    cout << "\n////////// Project 3 //////////\n\n";
    cout << "\nPlease enter text: ";
    getline(cin, stringText);
    stringLength = stringText.length();

    // ASCII TABLE A-Z : 65-90
    // ASCII TABLE a-z : 97-122

    // Loops through the length of the text and if character is uppercase, converts to lowercase
    // Lowercase character is then pushed to stringStack and added to stringQueue
    // Any spaces are skipped and not added to either stack or queue
    for(int i = 0; i < stringLength; i++) {
        char toLower;
        if(stringText[i] != 32){
            if(stringText[i] >= 65 && stringText[i] <= 90){
            toLower = stringText[i] + 32;
            }
            else{
                toLower = stringText[i];
            }
            stringStack.push(toLower);      // adds character to stack
            stringQueue.addQueue(toLower);  // adds character to queue
        }
        else{
            spaceCounter++; // a space was encountered so we will keep track of the total
        }
    }
    stringLength -= spaceCounter;   // length of the stacks and queues now exclude the spaces that were originally entered

    for (int j = 0; j < stringLength; j++){
        if(stringStack.top() == stringQueue.front()){
            countPal++;
        }
        stringStack.pop();
        stringQueue.deleteQueue();
    }

    if(countPal == stringLength){
        cout << "You have entered a palindrome!\n\n";
    }
    else{
        cout << "You have NOT entered a palindrome!\n\n";
    }

	return 0;
}