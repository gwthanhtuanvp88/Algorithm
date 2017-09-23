// Invertion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <limits>
#include <iostream>

using namespace std;

int Merge(int a[], int start, int middle, int end)
{
	int nCountInvertion = 0;
	int *b = new int[middle - start + 2];
	int *c = new int[end - middle+1];
	memcpy(b, a + start, (middle - start + 1) * sizeof(int));
	memcpy(c, a + middle + 1, (end - middle) * sizeof(int));
	b[middle - start + 1] = numeric_limits<int>().max();
	c[end - middle] = numeric_limits<int>().max();
	int posB = 0;
	int posC = 0;
	for (int i = start; i <= end; i++)
	{
		if (b[posB] <= c[posC])
		{
			a[i] = b[posB];
			posB++;
		}
		else
		{
			a[i] = c[posC];
			posC++;
			nCountInvertion += (middle - start + 1) - posB;
		}
	}
	return nCountInvertion;
}

int MergeSort(int a[], int start, int end)
{
	int nCountInvertion = 0;
	if (start >= end)
		return 0;
	int middle = (start + end) / 2;
	nCountInvertion += MergeSort(a, start, middle);
	nCountInvertion += MergeSort(a, middle + 1, end);
	nCountInvertion += Merge(a, start, middle, end);
	return nCountInvertion;
}

int main()
{
	int a[] = {5,4,3,2,1};
	int nInvertion = MergeSort(a, 0, sizeof(a) / sizeof(int) - 1);
	system("PAUSE");
	return 0;
}

