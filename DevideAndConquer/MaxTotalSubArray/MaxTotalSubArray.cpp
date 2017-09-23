// MaxTotalSubArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <limits>

using namespace std;
int negativeLimit = numeric_limits<int>().min();

int findMax(int a[], int start, int middle, int end)
{
	int lMax = negativeLimit, rMax = negativeLimit;
	int temp = 0;
	for (int i = middle; i >= start; i--)
	{
		temp += a[i];
		if (temp > lMax)
		{
			lMax = temp;
		}
	}
	temp = 0;
	for (int i = middle + 1; i <= end; i++)
	{
		temp += a[i];
		if (temp > rMax)
		{
			rMax = temp;
		}
	}
	return lMax + rMax;
}

int max2Num(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}


int max3Num(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
		{
			return a;
		}
		else
		{
			return c;
		}
	}
	else
	{
		if (b > c)
		{
			return b;
		}
		else
		{
			return c;
		}
	}
}

int findMaxTotalArray(int a[], int start, int end)
{
	if (start == end - 1)
	{
		return a[end] + a[start];
	}
	else if(start >= end)
	{
		return negativeLimit;
	}
	int mid = (start + end) / 2;
	return max3Num(findMax(a, start, mid, end), findMaxTotalArray(a, start, mid), findMaxTotalArray(a, mid + 1, end));
}

int findMaxTotalArray(int a[], int size)
{
	int *b = new int[size];
	memset(b, 0, sizeof(int) * size);
	b[1] = a[1] + a[0];
	int curMax = b[1];
	for (int i = 2; i < size; i++)
	{
		b[i] = max2Num(b[i - 1] + a[i], a[i] + a[i-1]);
		if (b[i] > curMax)
		{
			curMax = b[i];
		}
	}
	return curMax;
}

int main()
{
	int a[] = {13,-3,-25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	int max = findMaxTotalArray(a, sizeof(a) / sizeof(int));
	system("PAUSE");
    return 0;
}

