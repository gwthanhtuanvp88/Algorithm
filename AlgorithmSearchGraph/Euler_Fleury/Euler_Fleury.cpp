// Euler_Fleury.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

bool BFS(int start, int end, int nVertice, int **nEdge, int *nTrace, queue<int> &qV)
{
	int p;
	bool bResult = false;
	nEdge[start][end]--;
	nEdge[end][start]--;
	while (!qV.empty())
	{
		p = qV.back();
		if (p == end)
		{
			bResult = true;
			break;
		}
		qV.pop();
		for (int i = 0; i < nVertice; i++)
		{
			if (nEdge[i][p] > 0)
			{
				qV.push(i);
			}
		}
	}
	nEdge[start][end]++;
	nEdge[end][start]++;
	return bResult;
}

int main()
{
	int nVertice;
	int **nEdge;
	bool *bCheck;
	int *nTrace;
	int *nMin;
	int nPE1;
	int nPE2;
	int nV;
	int nCount = 0;
	cin >> nVertice;
	bCheck = new bool[nVertice];
	nTrace = new int[nVertice];
	nMin = new int[nVertice];
	nEdge = new int*[nVertice];
	for (int i = 0; i < nVertice; i++)
	{
		nEdge[i] = new int[nVertice];
		bCheck[i] = true;
		nTrace[i] = -1;
	}
	for (int i = 0; i < nVertice; i++)
	{
		for (int j = 0; j < nVertice; j++)
		{
			nEdge[i][j] = 0;
		}
	}

	for (int i = 0; i < nVertice; i++)
	{
		cin >> nPE1;
		cin >> nPE2;
		cin >> nV;
		nEdge[nPE1 - 1][nPE2 - 1] = nV;
		nEdge[nPE2 - 1][nPE1 - 1] = nV;
	}
	int nP = 0;
	queue<int> qV;
	do
	{
		cout << nP + 1 << " ";
		for (int i = 0; i < nVertice; i++)
		{
			if (nEdge[nP][i] > 0 && bCheck[i] == true)
			{
				qV.push(i);
				if (BFS(i, nP, nVertice, nEdge, nTrace, qV) == true)
				{
					nEdge[nP][i]--;
					nEdge[i][nP]--;
					if (nEdge[nP][i] == 0)
					{
						bCheck[i] = false;
					}
					nP = i;
					break;
				}
			}
		}
	} while (nP != 0);
	system("PAUSE");
	return 0;
}

