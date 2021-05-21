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
#include <iterator>
 
using namespace std;

int main()
{
    double GPA;
    double highestGPA;
    string name;
    list<string> strList;
    ostream_iterator<string> screen(cout, " ");

    cout << endl;
    cout << "__________STL list:__________\n\n";

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
            strList.clear();
            strList.push_back(name);

            highestGPA = GPA;
        }
        else if (GPA == highestGPA)
        {
            strList.push_back(name);
        }
        infile >> GPA >> name;
    }
    cout << "Highest GPA = " << highestGPA
         << endl;
    cout << "The students holding the "
         << "highest GPA are:" << endl;

    copy(strList.begin(), strList.end(), screen);

    cout << endl << endl;

    return 0;
}