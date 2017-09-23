// DaySoNguyenTo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

bool checkPrime(int n)
{
	if (n == 2 || n == 3)
		return true;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int nA[] = {1, 2, 4, 3 ,7, 8, 11, 5};
	int nVertice = sizeof(nA)/sizeof(int);
	int **nEdge;
	int **nTrace;
	int **nWeight;
	int v1, v2, weight;
	nEdge = new int*[nVertice];
	nTrace = new int*[nVertice];
	nWeight = new int*[nVertice];
	for (int i = 0; i < nVertice; i++)
	{
		nEdge[i] = new int[nVertice];
		nWeight[i] = new int[nVertice];
		nTrace[i] = new int[nVertice];
	}
	for (int i = 0; i < nVertice; i++)
	{
		for (int j = 0; j < nVertice; j++)
		{
			nEdge[i][j] = 0;
			nWeight[i][j] = 0;
		}
	}

	for (int i = 0; i < nVertice; i++)
	{
		for(int j = i + 1; j < nVertice; j++)
		{
			if (checkPrime(nA[i] + nA[j]))
			{
				nEdge[i][j] = 1;
			}
		}
	}

	//Floyd
	for (int k = 0; k < nVertice; k++)
	{
		for (int i = 0; i < nVertice; i++)
		{
			for (int j = i+1; j < nVertice; j++)
			{
				if (nEdge[k][j] > 0 && nWeight[i][j] < nWeight[i][k] + nEdge[k][j])
				{
					nWeight[i][j] = nWeight[i][k] + nEdge[k][j];
					nTrace[i][j] = k;
				}
			}
		}
	}
	int nStart, nEnd, nMax = -1;
	for (int i = 0; i < nVertice;i++)
	{
		for (int j = i+1; j < nVertice; j++)
		{
			if (nMax < nWeight[i][j])
			{
				nMax = nWeight[i][j];
				nStart = i;
				nEnd = j;
			}
		}
	}
	int nTemp = nEnd;
	do
	{
		cout << nA[nTemp] << " ";
		nTemp = nTrace[nStart][nTemp];
	} while (nTemp != nStart);
	cout << nA[nStart] << endl;
	system("PAUSE");
	return 0;
}

