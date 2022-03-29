#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int  Partition(int *arr, int low, int high)
{
	while (low < high)
	{
		while (low < high)
		{
			if (arr[low] > arr[high])
			{
				swap(arr[low], arr[high]);
				break;
			}
			high--;
		}
		while (low < high)
		{
			if (arr[low] > arr[high])
			{
				swap(arr[low], arr[high]);
				break;
			}
			low++;
		}
	}
	return low;
}

void QSort(int *arr, int low, int high)
{
	if (low < high)
	{
		int q = Partition(arr, low, high);
		QSort(arr, 0, q - 1);
		QSort(arr, q+1, high);
	}
}

void QuickSort(int *arr, int size)
{
	QSort(arr, 0, size - 1);
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[10] = { 2,1,2,3,1,2,7,2,2,2 };

	QuickSort(arr, 10);
	
	return 0;
}

