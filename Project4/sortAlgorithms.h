using namespace std;

template <class elemType>
void createArrays(elemType list[], elemType list1[], elemType list2[], elemType list3[], int arraySize)
{
    int elem;
	for (int i = 0; i< arraySize; i++)
	{
		elem = rand() % 100;
        list[i] = elem;
        list1[i] = elem;
        list2[i] = elem;
        list3[i] = elem;
	}
} //end swap

template <class elemType>
void swap(elemType list[], int first, int second)
{
    elemType temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
} //end swap

template <class elemType>
void insertionSort(elemType list[], int length)
{
	for (int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
	{
		if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
		{
			elemType temp = list[firstOutOfOrder];
			int location = firstOutOfOrder;

			do
			{
				list[location] = list[location - 1];
				location--;
			} while (location > 0 && list[location - 1] > temp);

			list[location] = temp;
		}
	}
} //end insertionSort

template <class elemType>
int medianPivot(elemType list[], int first, int last)
{
    // Order the first last and middle elements to find the median
    // Return the index of the median element
    int middle = (first + last) / 2;
    elemType medArray[] = {list[first], list[middle], list[last]};
    // Find the median element out of first, middle, and last
    if (medArray[2] < medArray[0])
    {
        swap(medArray, 0, 2);
    }
    if (medArray[1] < medArray[0])
    {
        swap(medArray, 1, 0);
    }
    if (medArray[2] < medArray[1])
    {
        swap(medArray, 1, 2);
    }
    // Return the index of the median element
    if (medArray[1] == list[first])
    {
        return first;
    }
    else if (medArray[1] == list[last])
    {
        return last;
    }
    else
    {
        return middle;
    }
} // end medianPivot

template <class elemType>
int partition(elemType list[], int first, int last, char pivotType)
{
    elemType pivot;
    int swapIndex;

    int index, smallIndex;
    if (pivotType == 'm')
    {
        swapIndex = medianPivot(list, first, last);
    }
    else if (pivotType == 'r')
    {
        swapIndex = (first + last) / 2;
    }

    swap(list, first, swapIndex);

    pivot = list[first];
    smallIndex = first;

	for (index = first + 1; index <= last; index++)
	{
		if (list[index] < pivot)
		{
			smallIndex++;
			swap(list, smallIndex, index);
		}
	}
    swap(list, first, smallIndex);

    return smallIndex;
} //end partition

template <class elemType>
void recQuickSort(elemType list[], int first, int last, char pivotType)
{
    int pivotLocation = 0;
    int size = (last + 1) - first;

    if (first < last)
    {
        pivotLocation = partition(list, first, last, pivotType);
        recQuickSort(list, first, pivotLocation - 1, pivotType);
        recQuickSort(list, pivotLocation + 1, last, pivotType);
    }
} //end recQuickSort

template <class elemType>
void quickSort(elemType list[], int length, char pivotType)
{
    recQuickSort(list, 0, length - 1, pivotType);
} //end quickSort

template <class elemType>
void recQuickInsertionSort(elemType list[], int first, int last, char pivotType)
{
    int pivotLocation = 0;
    int size = (last + 1) - first;
    if (first < last)
    {
        if (size > 19)
        {
            pivotLocation = partition(list, first, last, pivotType);
            recQuickSort(list, first, pivotLocation - 1, pivotType);
            recQuickSort(list, pivotLocation + 1, last, pivotType);
        }
        else
        {
            insertionSort(list, size);
        }
    }

} //end recQuickSort

template <class elemType>
void quickInsertionSort(elemType list[], int length, char pivotType)
{
    recQuickInsertionSort(list, 0, length - 1, pivotType);
} //end quickSort