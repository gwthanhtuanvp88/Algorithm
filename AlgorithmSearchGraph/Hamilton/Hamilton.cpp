// Hamilton.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int x[100];

void Try(int p, int nVertice, int **nEdge, int *nTrace)
{
	for (int i = 0; i < nVertice; i++)
	{
		if (nEdge[i][x[p-1]] == 1 && nTrace[i] == -1)
		{
			x[p] = i;
			if (p == nVertice-1)
			{
				if (nEdge[x[nVertice - 1]][x[0]])
				{
					for (int i = 0; i < nVertice; i++)
					{
						cout << x[i] + 1 << " ";
					}
					cout << x[0];
					cout << endl;
				}
			}
			else
			{
				nTrace[i] = p;
				Try(p+1, nVertice, nEdge, nTrace);
				nTrace[i] = -1;
			}
		}
	}
}

int main()
{
	int nVertice;
	int nNoEdge;
	int **nEdge;
	int *nTrace;
	int nPE1;
	int nPE2;
	cin >> nVertice;
	cin >> nNoEdge;
	nTrace = new int[nVertice];
	nEdge = new int*[nVertice];
	for (int i = 0; i < nVertice; i++)
	{
		nEdge[i] = new int[nVertice];
		nTrace[i] = -1;
	}
	for (int i = 0; i < nVertice; i++)
	{
		for (int j = 0; j < nVertice; j++)
		{
			nEdge[i][j] = 0;
		}
	}

	for (int i = 0; i < nNoEdge; i++)
	{
		cin >> nPE1;
		cin >> nPE2;
		nEdge[nPE1 - 1][nPE2 - 1] = 1;
		nEdge[nPE2 - 1][nPE1 - 1] = 1;
	}

	x[0] = 0;
	nTrace[0] = 0;
	Try(1, nVertice, nEdge, nTrace);
	
	system("PAUSE");
	return 0;
}

