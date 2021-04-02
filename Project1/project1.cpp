//This program tests various operation of a linked list
//45 67 23 89 -999

#include <iostream> 
#include <cassert>
#include <string> // added to include the string data type

using namespace std;

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template <class Type>
class circularLinkedList
{
public:
	//Overloads the assignment operator.
	const circularLinkedList<Type>& operator=(const circularLinkedList<Type>& otherList)
	{
		if (this != &otherList) //avoid self-copy
		{
			copyList(otherList);
		}//end else

		return *this;
	}

	//Initializes the list to an empty state.
	//Postcondition: first = NULL, last = NULL,
	//                count = 0
	void initializeList()
	{
		destroyList();
	}

	//Function to determine whether the list is empty. 
	//Postcondition: Returns true if the list is empty; otherwise, returns false.
	bool isEmptyList()
	{
		return (first == NULL);
	}


	void print() const
	{
		nodeType<Type> *current; //pointer to traverse the list

		current = first->link;

		while (current != first) //while more data to print
		{
			cout << current->info << " ";
			current = current->link;
		}

		cout << first->info << " ";
	}

	//Function to return the number of nodes in the list.
	//Postcondition: The value of count is returned.
	int length()
	{
		return count;
	}


	//Function to delete all the nodes from the list.
	//Postcondition: first = NULL, last = NULL, 
	//               count = 0
	void destroyList()
	{
		nodeType<Type> *temp;
		nodeType<Type> *current = NULL;

		if (first != NULL)
		{
			current = first->link;
			first->link = NULL;
		}

		while (current != NULL)
		{
			temp = current;
			current = current->link;
			delete temp;
		}

		first = NULL;	//initialize last to NULL; first has already
						//been set to NULL by the while loop
		count = 0;
	}


	//Function to return the first element of the list.
	//Precondition: The list must exist and must not be empty.
	//Postcondition: If the list is empty, then the program terminates; otherwise, the first element of the list is returned.
	Type front()
	{
		assert(first != NULL);
		return first->link->info; //return the info of the first node	
	}


	//Function to return the last element of the list.
	//Precondition: The list must exist and must not be empty.
	//Postcondition: If the list is empty, then the program terminates; otherwise, the last element of the list is returned.
	Type back()
	{
		assert(first != NULL);
		return first->info; //return the info of the first node	
	}


	//Function to determine whether searchItem is in the list.		
	//Postcondition: Returns true if searchItem is found in the list; otherwise, it returns false.
	bool search(const Type& searchItem)
	{
		nodeType<Type> *current; //pointer to traverse the list
		bool found = false;

		if (first != NULL)
		{
			current = first->link;

			while (current != first && !found)
			{
				if (current->info >= searchItem)
					found = true;
				else
					current = current->link;

				found = (current->info == searchItem);
			}
		}

		return found;
	}


	void insertNode(const Type& newitem)
	{
		nodeType<Type> *current; //pointer to traverse the list
		nodeType<Type> *trailCurrent; //pointer just before current
		nodeType<Type> *newNode;  //pointer to create a node

		bool  found;

		newNode = new nodeType<Type>; //create the node

		newNode->info = newitem;   //store newitem in the node
		newNode->link = NULL;      //set the link field of the node
								   //to NULL

		if (first == NULL)  //Case 1	e.g., 3
		{
			first = newNode;
			first->link = newNode;
			count++;
		}
		else
		{
			if (newitem >= first->info)//e.g., 25 > 3
			{
				newNode->link = first->link;
				first->link = newNode;
				first = newNode;
			}
			else
			{
				trailCurrent = first; //e.g., 1 < 3 
				current = first->link;
				found = false;

				while (current != first && !found)
					if (current->info >= newitem)
						found = true;
					else
					{
						trailCurrent = current;
						current = current->link;
					}

				trailCurrent->link = newNode;
				newNode->link = current;
			}

			count++;
		}//end else
	}

	//Function to delete deleteItem from the list.
	//Postcondition: If found, the node containing deleteItem is deleted from the list, first points to the first		
	//                node, and last points to the last node of the updated list. 
	void deleteNode(const Type& deleteItem)
	{
		nodeType<Type> *current; //pointer to traverse the list
		nodeType<Type> *trailCurrent; //pointer just before current
		bool found;

		if (first == NULL)    //Case 1; list is empty. 
			cout << "Can not delete from an empty list." << endl;
		else
		{
			found = false;
			trailCurrent = first;
			current = first->link;

			while (current != first && !found)
				if (current->info >= deleteItem)
					found = true;
				else
				{
					trailCurrent = current;
					current = current->link;
				}

			if (current == first)
			{
				if (first->info == deleteItem)
				{
					if (first == first->link)
						first = NULL;
					else
					{
						trailCurrent->link = current->link;
						first = trailCurrent;
					}
					delete current;

					count--;
				}
				else
					cout << "The item to be deleted is not in the list." << endl;
			}
			else
				if (current->info == deleteItem)
				{
					trailCurrent->link = current->link;
					count--;
					delete current;
				}
				else
					cout << "Item to be deleted is not in the list." << endl;
		} //end else
	}


	//Default constructor
	//Initializes the list to an empty state. 		
	//Postcondition: first = NULL, last = NULL, 
	//               count = 0 
	circularLinkedList()
	{
		first = NULL;
		count = 0;
	}


	//Copy constructor
	circularLinkedList(const circularLinkedList<Type>& otherList)
	{
		first = NULL;
		copyList(otherList);
	}


	//Destructor
	//Deletes all the nodes from the list.
	//Postcondition: The list object is destroyed. 
	~circularLinkedList()
	{
		destroyList();
	}


protected:
	int count;		//variable to store the number of elements in the list
	nodeType<Type> *first; //pointer to the first node of the list
	nodeType<Type> *last;  //pointer to the last node of the list 
private:
	//Function to make a copy of otherList.
	//Postcondition: A copy of otherList is created and assigned to this list.
	void copyList(const circularLinkedList<Type>& otherList)
	{
		nodeType<Type> *newNode;
		nodeType<Type> *current;
		nodeType<Type> *tempFirst;

		if (first != NULL)
			destroyList();

		if (otherList.first == NULL)
		{
			first = NULL;
			count = 0;
		}
		else
		{
			current = otherList.first->link;  //current points to the 
											  //list to be copied
			count = otherList.count;

			//copy the first node
			tempFirst = new nodeType<Type>;  //create the node

			tempFirst->info = current->info; //copy the info
			last = tempFirst;    		     //make last point to the 
											 //first node
			current = current->link;     //make current point to the 
										 //next node

										 //copy the remaining list
			while (current != otherList.first)
			{
				newNode = new nodeType<Type>;  //create a node
				newNode->info = current->info;
				last->link = newNode;
				last = newNode;

				current = current->link;

			}//end while

			if (tempFirst == last)
			{
				first = tempFirst;
				first->link = first;
			}
			else
			{
				newNode = new nodeType<Type>;  //create a node
				newNode->info = current->info;
				last->link = newNode;
				first = newNode;
				first->link = tempFirst;
			}

		}//end else
	}
};

int main()
{
	// circularLinkedList<int> list1, list2; // can these objects be created once a data type is selected by the user?
	// int num;
    // char singleChar;
    // string stringName;

    int inputDataType;
    cout << "\nPlease select the data type to be added to the linked list: " << endl;
    cout << "\t(1) whole numbers" << endl;
    cout << "\t(2) double numbers" << endl;
    cout << "\t(3) single characters" << endl;
    cout << "\t(4) strings" << endl;
    cout << "Please enter 1, 2, 3, or 4: ";

    cin >> inputDataType;

    switch (inputDataType)
    {
    case 1:
    {
        circularLinkedList<int> list1, list2;
        int num;
        cout << "Enter info of appropriate data type ending with -999" << endl;
        cin >> num;
        while (num != -999)
        {
            list1.insertNode(num);
            cin >> num;
        }

        cout << endl;

        cout << "List 1: ";
        list1.print();
        cout << endl;

        cout << "Length List 1: " << list1.length() << endl;

        cout << "Enter the number to be searched:  ";
        cin >> num;
        cout << endl;

        if (list1.search(num))
            cout << num << " found in the list" << endl;
        else
            cout << num << " not in the list" << endl;

        cout << "Enter the number to be deleted: ";
        cin >> num;
        cout << endl;

        list1.deleteNode(num);

        cout << "After deleting the node, "
            << "List 1: ";
        list1.print();
        cout << endl;

        cout << "Length List 1: " << list1.length() << endl;

        list2 = list1;

        cout << "List 2: ";
        list2.print();
        cout << endl;

        cout << "Length List 2: " << list2.length() << endl;

        cout << "List 1: ";
        list1.print();
        cout << endl;
        break;
    }
        case 2:
    {
        circularLinkedList<double> doubleList1, doubleList2;
        double doubleNum;
        cout << "Enter info of appropriate data type ending with -999" << endl;
        cin >> doubleNum;
        while (doubleNum != -999)
        {
            doubleList1.insertNode(doubleNum);
            cin >> doubleNum;
        }

        cout << endl;

        cout << "List 1: ";
        doubleList1.print();
        cout << endl;

        cout << "Length List 1: " << doubleList1.length() << endl;

        cout << "Enter the number to be searched:  ";
        cin >> doubleNum;
        cout << endl;

        if (doubleList1.search(doubleNum))
            cout << doubleNum << " found in the list" << endl;
        else
            cout << doubleNum << " not in the list" << endl;

        cout << "Enter the number to be deleted: ";
        cin >> doubleNum;
        cout << endl;

        doubleList1.deleteNode(doubleNum);

        cout << "After deleting the node, "
            << "List 1: ";
        doubleList1.print();
        cout << endl;

        cout << "Length List 1: " << doubleList1.length() << endl;

        doubleList2 = doubleList1;

        cout << "List 2: ";
        doubleList2.print();
        cout << endl;

        cout << "Length List 2: " << doubleList2.length() << endl;

        cout << "List 1: ";
        doubleList1.print();
        cout << endl;
        break;
    }
    case 3:
    {
        char singleChar;
        circularLinkedList<char> charList1, charList2;
        cout << "Enter character ending with the asterisk symbol *" << endl;
        cin >> singleChar;
        while (singleChar != '*')
        {
            charList1.insertNode(singleChar);
            cin >> singleChar;
        }

        cout << endl;

        cout << "List 1: ";
        charList1.print();
        cout << endl;

        cout << "Length List 1: " << charList1.length() << endl;

        cout << "Enter the character to be searched:  ";
        cin >> singleChar;
        cout << endl;

        if (charList1.search(singleChar))
            cout << singleChar << " found in the list" << endl;
        else
            cout << singleChar << " not in the list" << endl;

        cout << "Enter the character to be deleted: ";
        cin >> singleChar;
        cout << endl;

        charList1.deleteNode(singleChar);

        cout << "After deleting the node, "
            << "List 1: ";
        charList1.print();
        cout << endl;

        cout << "Length List 1: " << charList1.length() << endl;

        charList2 = charList1;

        cout << "List 2: ";
        charList2.print();
        cout << endl;

        cout << "Length List 2: " << charList2.length() << endl;

        cout << "List 1: ";
        charList1.print();
        cout << endl;
        break;
    }
    case 4:
    {
        string stringName;
        circularLinkedList<string> stringList1, stringList2;
        cout << "Enter info ending with the asterisk symbol *" << endl;
        cin >> stringName;
        while (stringName != "*")
        {
            stringList1.insertNode(stringName);
            cin >> stringName;
        }

        cout << endl;

        cout << "List 1: ";
        stringList1.print();
        cout << endl;

        cout << "Length List 1: " << stringList1.length() << endl;

        cout << "Enter the string to be searched:  ";
        cin >> stringName;
        cout << endl;

        if (stringList1.search(stringName))
            cout << stringName << " found in the list" << endl;
        else
            cout << stringName << " not in the list" << endl;

        cout << "Enter the string to be deleted: ";
        cin >> stringName;
        cout << endl;

        stringList1.deleteNode(stringName);

        cout << "After deleting the node, "
            << "List 1: ";
        stringList1.print();
        cout << endl;

        cout << "Length List 1: " << stringList1.length() << endl;

        stringList2 = stringList1;

        cout << "List 2: ";
        stringList2.print();
        cout << endl;

        cout << "Length List 2: " << stringList2.length() << endl;

        cout << "List 1: ";
        stringList1.print();
        cout << endl;
        break;
    }
    default:
        break;
    }

	return 0;
}