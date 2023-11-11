#include <iostream>
#include <Windows.h>
#include <string>
#include <time.h>
#include <stdlib.h>


using namespace std;

const int arraySize = 8;

template <class T>
void swappi(T& obj1, T& obj2)
{
	T temp = move(obj1);
	obj1 = move(obj2);
	obj2 = move(temp);

	return;
}

template <class T>
void inputArray(T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 50 - 25;
	}
}

template <class T>
void outputArray(T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}


template <class T>
void bubbleSort(T arr[], int size)
{
	bool flag;

	for (int i = 0; i < size - 1; i++)
	{
		flag = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swappi(arr[j], arr[j + 1]);
				flag = true;
			}
		}

		if (!flag)
		{
			break;
		}
	}
}


template <class T>
void selectionSort(T arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{	
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}

		if (i != min)
		{
			swappi(arr[i], arr[min]);
		}
	}

	return;
}

template <class T>
void insertionSort(T arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		T elem = arr[i];
		int j = i - 1;

		while (j >= 0 && elem < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = elem;
	}

	return;
}

template <class T>
void shellSort(T arr[], int size)
{
	for (int step = size / 2; step > 0; step /= 2)
	{
		for	(int i = step; i < size; i++)
		{
			T elem = arr[i];
			int j = i - step;

			while (j >= 0 && elem < arr[j])
			{
				arr[j + step] = arr[j];
				j -= step;
			}

			arr[j + step] = elem;
		}
	}
	
	return;
}


template <class T>
int partitionHoara(T arr[], int left, int right)
{
	T pivot = arr[(left + right) / 2];
	while (left <= right)
	{
		while (arr[left] < pivot)
		{
			left++;
		}
		while (arr[right] > pivot) 
		{
			right--;
		}

		if (left <= right)
		{
			swappi(arr[left], arr[right]);
			left++;
			right--;
		}
	}

	return left;
}

template <class T>
void sortHoara(T arr[], int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int pos = partitionHoara(arr, start, end);
	sortHoara(arr, start, pos - 1);
	sortHoara(arr, pos, end);

}


template <class T>
int lomutoPartition(T arr[], int start, int end)
{
	int left = start;
	for (int current = left; current < end; current++)
	{
		if (arr[current] < arr[end])
		{
			swappi(arr[current], arr[left]);
			left++;
		}
	}

	swappi(arr[left], arr[end]);

	return left;
}

template <class T>
void sortLomuto(T arr[], int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int pos = lomutoPartition(arr, start, end);
	sortLomuto(arr, start, pos - 1);
	sortLomuto(arr, pos + 1, end);

	return;
}

template <class T>
int binarySearchCycle(T arr[], int size, int value)
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == value)
		{
			return mid;
		}
		if (value < arr[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}

template<class T>
int binarySearchRecursive(T arr[], int left, int right, int value)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == value)
		{
			return mid;
		}
		if (value < arr[mid])
		{
			binarySearchCycle(arr, left, mid - 1);
		}
		else
		{
			binarySearchCycle(arr, mid + 1, right);
		}
	}
	return -1;
}


int main()
{
	time(0);

	int arr[8];

	inputArray(arr, arraySize);
	outputArray(arr, arraySize);

	sortLomuto(arr, 0, 7);

	outputArray(arr, arraySize);
	int index =	binarySearchRecursive(arr, 0, 7, -6);

	cout << index << endl;

	return 0;
}