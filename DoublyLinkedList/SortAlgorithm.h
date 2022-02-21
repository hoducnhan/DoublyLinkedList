#pragma once
#include<iostream>
template<typename T>
class SortAlgorithm
{
private:
	void swapValue(T* a, T*b)
	{
		T temp = *a;
		*a = *b;
		*b = temp;
	}
	void Heapify(T a[], int length, int largestTemp)
	{
		int largest = largestTemp;
		int leftChild = (2 * largestTemp + 1);
		int rightChild = (2 * largestTemp + 2);
		if (leftChild<length&&a[leftChild]>a[largest])
		{
			largest = leftChild;
		}
		if (rightChild<length&&a[rightChild]>a[largest])
		{
			largest = rightChild;
		}
		if (largest != largestTemp)
		{
			swapValue(&a[largest], &a[largestTemp]);
			Heapify(a, length, largest);
		}
	}
public:
	//just a attempt to sort ascending order;
	
	void HeapSort(T a[], int length)
	{
		for (int i = length / 2 - 1; i >= 0; i--)
		{
			Heapify(a, length, i);
		}
		for (int i = length - 1; i >= 0; i--)
		{
			swapValue(&a[0], &a[i]);
			Heapify(a, i, 0);
		}
	}
	void InsertionSort(T A[], int length)
	{
		int j = 0,x = 0;
		for (int i = 1; i < length; ++i)
		{
			j = i - 1;
			x = A[i];
			while (j > -1 && A[j] > x)
			{
				A[j + 1] = A[j];
				j--;
			}
			A[j + 1] = x;
		}
	}
	int MedianOfThree(int a, int b, int c)
	{
		if (a < b && b < c)
			return (b);

		if (a < c && c <= b)
			return (c);

		if (b <= a && a < c)
			return (a);

		if (b <c && c <= a)
			return (c);

		if (c <= a && a < b)
			return (a);

		if (c <= b && b <= a)
			return (b);
	}
	int Partition(T A[], int l, int h)
	{
		int pivot = A[l];
		int i = l, j = h;
		do
		{
			do { i++; } while (A[i] <= pivot);
			do { j--; } while (A[j] > pivot);
			if (i < j)swapValue(&A[i], &A[j]);
		} while (i < j);
		swapValue(&A[l], &A[j]);
		return j;
	}
	//int *Partition(int arr[], int low, int high)
	//{
	//	int pivot = arr[high]; // pivot
	//	int i = (low - 1); // Index of smaller element

	//	for (int j = low; j <= high - 1; j++) {
	//		// If current element is smaller than or
	//		// equal to pivot
	//		if (arr[j] <= pivot) {
	//			// increment index of smaller element
	//			i++;

	//			swap(arr[i], arr[j]);
	//		}
	//	}
	//	swap(arr[i + 1], arr[high]);
	//	return (arr + i + 1);
	//}
	void UtilityIntroSort(T A[], int l, int h, int depthLimit)
	{
		int size = h-l;
		if (size < 17)
		{
			InsertionSort(A, size+1);
			return;
		}
		if (depthLimit == 0)
		{
			HeapSort(A, size+1);
			return;
		}
		int pivot = MedianOfThree(l, (h + l) / 2, h);
		swapValue(&A[pivot], &A[h]);
		int j = Partition(A, l, h);
		UtilityIntroSort(A, l, j-1, depthLimit - 1);
		UtilityIntroSort(A, j + 1, h, depthLimit - 1);
	}
	void IntroSort(T A[], int l, int h)
	{
		int depthLimit = 2 * log(h - l);
		UtilityIntroSort(A, l, h, depthLimit);
	}

};

