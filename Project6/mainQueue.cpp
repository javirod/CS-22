/*
CS 22, Prof Tahir Aziz 
Name: Javier Rodriguez
Assignment: Project 6
Due Date: 23 MAY 2021
*/

#include <iostream>  
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
#include <queue>
 
using namespace std;

int main()
{
    double GPA;
    double highestGPA;
    string name;
    queue<string> strQueue;

    cout << endl;
    cout << "__________STL queue:__________\n\n";

    ifstream infile;

    infile.open("HighestGPAData.txt");

    if (!infile)
    {
        cout << "The input file does not "
             << "exist. Program terminates!"
             << endl;
        return 1;
    }

    cout << fixed << showpoint;
    cout << setprecision(2);

    infile >> GPA >> name;

    highestGPA = GPA;

    while (infile)
    {
        if (GPA > highestGPA)
        {
            while(!strQueue.empty())
            {
                strQueue.pop();
            }

            strQueue.push(name);

            highestGPA = GPA;
        }
        else if (GPA == highestGPA)
        {
            strQueue.push(name);
        }
        infile >> GPA >> name;
    }
    cout << "Highest GPA = " << highestGPA
         << endl;
    cout << "The students holding the "
         << "highest GPA are:" << endl;

    while(!strQueue.empty())
    {
        cout << strQueue.front() << " ";
        strQueue.pop();
    }

    cout << endl << endl;

    return 0;
}