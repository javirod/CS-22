#include <iostream>
#include <string>
#include <stdlib.h>
#include <chrono>
#include "sortAlgorithms.h"
   
using namespace std;

int main() 
{
	int randElement;
	int size = 10000;
	int intList[size], intList1[size], intList2[size], intList3[size];
	srand (time(NULL));

	// Create 4 different arrays to sort 4 different ways
	// for each of Parts A, B, C, and D
	createArrays(intList, intList1, intList2, intList3, size);

	int position = int();    
	int number = int(); 

	// ********** Part A **********
	// Sort the array using pivot as the middle element of the array.
	// The character 'r' means we will use the regular middle element as the pivot
	//
	auto startTime = chrono::high_resolution_clock::now();
	quickSort(intList, size, 'r');
	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> totalTime = (endTime - startTime);

	cout << "\nPart A CPU Time: " << totalTime.count() << " sec" << endl;
	cout << endl;

	// ********** Part B **********
	// Sort the array using pivot as the median of the first, last, and middle elements of the array.
	// The character 'm' means we will use the median element as the pivot
	//
	auto startTime1 = chrono::high_resolution_clock::now();
	quickSort(intList1, size, 'm');
	auto endTime1 = chrono::high_resolution_clock::now();
	chrono::duration<double> totalTime1 = (endTime1 - startTime1);
	cout << "\nPart B CPU Time: " << totalTime1.count() << " sec" << endl;
	cout << endl;

	// ********** Part C **********
	// Same as Part A, but when size of sublist < 20, use insertion sort for the sublist
	//
	auto startTime2 = chrono::high_resolution_clock::now();
	quickInsertionSort(intList2, size, 'r');
	auto endTime2 = chrono::high_resolution_clock::now();
	chrono::duration<double> totalTime2 = (endTime2 - startTime2);
	cout << "\nPart C CPU Time: " << totalTime2.count() << " sec" << endl;
	cout << endl;

	// ********** Part D **********
	// Same as Part A, but when size of sublist < 20, use insertion sort for the sublist
	//
	auto startTime3 = chrono::high_resolution_clock::now();
	quickInsertionSort(intList3, size, 'm');
	auto endTime3 = chrono::high_resolution_clock::now();
	chrono::duration<double> totalTime3 = (endTime3 - startTime3);
	cout << "\nPart D CPU Time: " << totalTime3.count() << " sec" << endl;
	cout << endl;

    return 0;
}