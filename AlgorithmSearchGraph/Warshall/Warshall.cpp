// Warshall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int nVertice;
	int nNoEdge;
	int nStart;
	int nEnd;
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

	for (int k = 0; k < nVertice; k++)
	{
		for (int i = 0; i < nVertice; i++)
		{
			for (int j = 0; j < nVertice; j++)
			{
				nEdge[i][j] = nEdge[i][j] || (nEdge[j][k] && nEdge[i][k]);
				nEdge[j][i] = nEdge[i][j];
			}
		}
	}
	for (int i = 0; i < nVertice; i++)
	{
		if (nTrace[i] == -1)
		{
			nTrace[i] = 0;
			cout << i+1 << " ";
			for (int j = 0; j < nVertice; j++)
			{
				if (nTrace[j] == -1 && nEdge[i][j] == 1)
				{
					nTrace[j] = 0;
					cout << j+1 << " ";
				}
			}
			cout << endl;
		}
	}
	cout << endl;
	system("PAUSE");
	return 0;
}

