// Prim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int nTotalWeight = 0;
	int nVertice;
	int *nRoot;
	int *nCount;
	int nNoEdge;
	int **nEdge;
	int *nWeight;
	bool *bCheck;
	int *nTrace;

	cin >> nVertice;
	cin >> nNoEdge;

	nEdge = new int*[nVertice];
	nWeight = new int[nVertice];
	bCheck = new bool[nVertice];
	nTrace = new int[nVertice];
	for (int i = 0; i < nVertice; i++)
	{
		nEdge[i] = new int[nVertice];
		nWeight[i] = 100;
		bCheck[i] = true;
		nTrace[i] = -1;
	}

	for (int i = 0; i < nVertice; i++)
	{
		for (int j = 0; j < nVertice; j++)
		{
			nEdge[i][j] = 100;
		}
	}

	for (int i = 0; i < nNoEdge; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		nEdge[u - 1][v - 1] = w;
		nEdge[v - 1][u - 1] = w;
	}

	nWeight[0] = 0;
	int temp = -1;
	int min = 100;
	int nConnectedVertice = 0;
	for(; nConnectedVertice < nVertice; nConnectedVertice++)
	{
		min = 100;
		temp = -1;
		for (int i = 0; i < nVertice; i++)
		{
			if (nWeight[i] < min && bCheck[i])
			{
				min = nWeight[i];
				temp = i;
			}
		}
		if (temp == -1)
		{
			break;
		}
		else
		{
			bCheck[temp] = false;
			if (nTrace[temp] != -1)
			{
				cout << nTrace[temp]+1 << " " << temp+1 << endl;
				nTotalWeight += min;
			}
			for (int i = 0; i < nVertice; i++)
			{
				if (bCheck[i] && nEdge[i][temp] != 100 && nWeight[i] > nEdge[i][temp])
				{
					nWeight[i] = nEdge[i][temp];
					nTrace[i] = temp;
				}
			}
		}
	}
	cout << "Total weight : " << nTotalWeight;
	system("PAUSE");
    return 0;
}

