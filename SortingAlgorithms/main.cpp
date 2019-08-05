#include <iostream>
#include <limits>
#include <stdio.h>
#include <vector>

using namespace std;


//
// swap()
//
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


//
// partition()
//
int partition(vector< int >& array1, int lowIndex, int highIndex)
{
	int pivot = array1[highIndex];
	int i = lowIndex;

	for (int j = lowIndex; j < highIndex; j++)
	{
		if (array1[j] < pivot)
		{
			// Swap A[i] with A[j].
			swap(&array1[i], &array1[j]);

			i++;
		}
	}

	// Swap A[i] with A[hi].
	swap(&array1[i], &array1[highIndex]);

	return i;
}


//
// quicksort()
//
void quicksort(vector< int >& unsortedArray, int lowIndex, int highIndex)
{
	if (lowIndex < highIndex)
	{
		int p = partition(unsortedArray, lowIndex, highIndex);

		quicksort(unsortedArray, lowIndex, p - 1);
		quicksort(unsortedArray, p + 1, highIndex);
	}
}


//
// combine()
//
void combine(vector< int >& array1, int lowIndex, int middleIndex, int highIndex)
{
	vector< int > L;
	vector< int > R;

	int i = 0;
	int j = 0;

	for (i = 0; i < (middleIndex - lowIndex + 1); i++)
	{
		L.push_back(array1[lowIndex + i]);
	}

	for (j = 0; j < (highIndex - middleIndex); j++)
	{
		R.push_back(array1[middleIndex + j + 1]);
	}

	L.push_back(std::numeric_limits< int >::max());
	R.push_back(std::numeric_limits< int >::max());

	i = 0;
	j = 0;

	for (int k = lowIndex; k <= highIndex; k++)
	{
		if (L[i] <= R[j])
		{
			array1[k] = L[i];
			i++;
		}
		else
		{
			array1[k] = R[j];
			j++;
		}
	}
}


//
// mergeSort()
//
void mergeSort(vector< int >& unsortedArray, int lowIndex, int highIndex)
{
	if (lowIndex < highIndex)
	{
		int middleIndex = (lowIndex + highIndex) / 2;

		mergeSort(unsortedArray, lowIndex, middleIndex);
		mergeSort(unsortedArray, middleIndex + 1, highIndex);
		combine(unsortedArray, lowIndex, middleIndex, highIndex);
	}
}


//
// printArray()
//
void printArray(const vector< int >& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << ' ';
	}
}


//
// main()
//
int main()
{
	/* EXAMPLE 1: Quicksort */
	/* Average Performance: O(n log n) */
	/* Worst-Case Performance: O(n^2) 
	/* Worst-Case Space Complexity: O(log n) */

	cout << "Example 1: Quicksort" << endl;

	vector< int > unsortedArray1 = { 12, 11, 13, 5, 6, 7 };

	quicksort(unsortedArray1, 0, unsortedArray1.size() - 1);

	printArray(unsortedArray1);

	cout << endl << endl;


	/* EXAMPLE 2: Merge Sort */
	/* Average Performance: O(n log n) */
	/* Worst-Case Performance: O(n log n)
	/* Worst-Case Space Complexity: O(n) */

	cout << "Example 2: Merge Sort" << endl;

	vector< int > unsortedArray2 = { 12, 11, 13, 5, 6, 7 };

	mergeSort( unsortedArray2, 0, unsortedArray2.size() - 1 );

	printArray( unsortedArray2 );
	
	return 0;
}