#include<iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include "Sorts.h"
#include <cstdlib>
#include <Windows.h>
using namespace std;

template <typename arrayType> void Sorts<arrayType>::mergeSort(int start, int end)
{
	if (end - start > 0)
	{
		mergeSort(start, (start + end - 1) / 2);
		mergeSort((start + end + 1) / 2, end);
	}
	arrayType* tempTable = new arrayType[end - start+1];
	int firstHalfIter = start, secondHalfIter = (start + end + 1) / 2;
	for (int i = 0; i <= (end - start); i++)
	{
		if (firstHalfIter == ((start + end + 1) / 2))
		{
			while (secondHalfIter <= end && i <= end - start)
			{
				tempTable[i] = myArray[secondHalfIter];
				i++;
				secondHalfIter++;
			}

		}
		else
		{
			if (secondHalfIter == end + 1)
			{
				while (firstHalfIter <= end && i <= end - start)
				{
					tempTable[i] = myArray[firstHalfIter];
					i++;
					firstHalfIter++;
				}
			}
			else
			{
				if (myArray[firstHalfIter] > myArray[secondHalfIter])
				{
					tempTable[i] = myArray[secondHalfIter];
					secondHalfIter++;
				}
				else
				{
					tempTable[i] = myArray[firstHalfIter];
					firstHalfIter++;
				}

			}


		}
	}
	int j = 0;
	for (int i = start; i <= end; i++)
	{
		myArray[i] = tempTable[j];
		j++;
		
	}
	delete[] tempTable;
}

template<typename arrayType> void Sorts<arrayType>::mergeSort()
{
	mergeSort(0, lenght-1);
}

template<typename arrayType> void Sorts<arrayType>::display()
{
	for (int i = 0; i < lenght; i++) cout << myArray[i] << " ";
}

template<typename arrayType> void Sorts<arrayType>::swap(int first, int second)
{
	int chair = myArray[first];
	myArray[first] = myArray[second];
	myArray[second] = chair;
}

template<typename arrayType> void Sorts<arrayType>::quickSort(int start, int end) {
	int i = start, j = end;
	int pivot = myArray[start + (end - start) / 2];

	while (i <= j) {

		while (myArray[i] < pivot) {
			i++;
		}

		while (myArray[j] > pivot) {
			j--;
		}

		if (i <= j) {
			swap(i, j);
			i++;
			j--;
		}
	}
	if (start < j) {
		quickSort(start, j);
	}

	if (i < end) {
		quickSort(i, end);
	}

}

template<typename arrayType> void Sorts<arrayType>::quickSort()
{
	quickSort(0, lenght - 1);
}

template<class arrayType>
template<typename myArrayType>
inline void Sorts<arrayType>::heapify(int size, int position, arrayType* tempTable)
{
	int peak, temp;
	int left = 2 * position, right = 2 * position + 1;
	if (left <= size && tempTable[left] > tempTable[position]) peak = left;
	else peak = position;
	if (right <= size && tempTable[right] > tempTable[peak]) peak = right;
	if (peak != position)
	{
		temp = tempTable[peak];
		tempTable[peak] = tempTable[position];
		tempTable[position] = temp;
		heapify<myArrayType>(size, peak, tempTable);
	}

}


template<class arrayType>
template<typename myArrayType>
inline void Sorts<arrayType>::heapSort(int start, int end)
{
	int j = 0;
	int size = end - start;
	myArrayType* tempTable = new myArrayType[size+1];
	for (int i = start; i <= end; i++)  tempTable[j++] = myArray[i]; //Check this out if sth doesnt work
	int chair, newStart = 0, newEnd = size;
	for (int i = size / 2; i > 0; i--) // At first time we only build our heap
	{
		heapify<myArrayType>(size, i, tempTable);
	}
	for (int i = size; i > 1; i--)
	{
		chair = tempTable[i];
		tempTable[i] = tempTable[1];
		tempTable[1] = chair;
		size--;
		heapify<myArrayType>(size, 1, tempTable);
	}
	j = 0;
	for (int i = start; i <= end; i++)  myArray[i]=tempTable[j++];
	j = 1;
	if(myArray[start]>myArray[start+1])
		while (myArray[start + j - 1] > myArray[start + j]) { swap(start + j - 1, start + j); j++; }

	delete[] tempTable;
}

template<typename arrayType> void Sorts<arrayType>::heapSort()
{
	heapSort<arrayType>(0, lenght-1);
}

template<class arrayType>
void Sorts<arrayType>::introSort(int start, int end, int count)
{
	if (count)
	{
		int i = start, j = end;
		int pivot = myArray[start + (end - start) / 2];

		while (i <= j)
		{

			while (myArray[i] < pivot)
			{
				i++;
			}

			while (myArray[j] > pivot)
			{
				j--;
			}

			if (i <= j)
			{
				swap(i, j);
				i++;
				j--;
			}
		}
		count--;
		if (start < j)
		{
			quickSort(start, j);
		}


		if (i < end)
		{
			quickSort(i, end);
		}
	}
	else
	{
		heapSort<arrayType>(start, end);
	}

}


template<class arrayType>
void Sorts<arrayType>::introSort()
{
	int repeat = floor(2 * log2(lenght));
	introSort(0, lenght - 1, repeat);
}
template class Sorts<int>;

