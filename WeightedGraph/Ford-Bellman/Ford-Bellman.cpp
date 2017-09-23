// Ford-Bellman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int nVertice;
	int **nEdge;
	int *nTrace;
	int *nWeight;
	int v1, v2, weight;
	int nNoEdge;
	int nStart;
	int nEnd;
	cin >> nVertice;
	cin >> nNoEdge;
	cin >> nStart;
	cin >> nEnd;
	nEdge = new int*[nVertice];
	nTrace = new int[nVertice];
	nWeight = new int[nVertice];
	for (int i = 0; i < nVertice; i++)
	{
		nEdge[i] = new int[nVertice];
		nWeight[i] = 100;
	}
	nWeight[0] = 0;
	for (int i = 0; i < nVertice; i++)
	{
		for (int j = 0; j < nVertice; j++)
		{
			nEdge[i][j] = 100;
		}
	}

	for (int i = 0; i < nNoEdge; i++)
	{
		cin >> v1 >> v2 >> weight;
		nEdge[v1-1][v2-1] = weight;
	}

	//Ford Bellman
	bool bCheck = true;
	while (bCheck)
	{
		bCheck = false;
		for (int i = 0; i < nVertice; i++)
		{
			for (int j = 0; j < nVertice; j++)
			{
				if (nEdge[j][i] < 100)
				{
					if (nWeight[i] > nWeight[j] + nEdge[j][i])
					{
						bCheck = true;
						nTrace[i] = j;
						nWeight[i] = nWeight[j] + nEdge[j][i];
					}
				}
			}
		}
	}
	int nTemp = nEnd - 1;
	do
	{
		cout << nTemp+1 << " -> ";
		nTemp = nTrace[nTemp];
	} while (nTemp != nStart - 1);
	cout << nStart<< endl;
	system("PAUSE");
    return 0;
}

