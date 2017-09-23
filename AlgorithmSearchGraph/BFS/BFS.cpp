// BFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

void BFS(int nVertice, int **nEdge, int *nTrace, queue<int> &qV)
{
	if (qV.empty())
		return;
	int p = qV.back();
	qV.pop();
	for (int i = 0; i < nVertice; i++)
	{
		if (nEdge[i][p] == 1 && nTrace[i] == -1)
		{
			nTrace[i] = p;
			qV.push(i);
		}
	}
}

int main()
{
	int nVertice;
	int nNoEdge;
	int nStart;
	int nEnd;
	int **nEdge;
	int *nTrace;
	queue<int> qV;
	int nPE1;
	int nPE2;
	cin >> nVertice;
	cin >> nNoEdge;
	cin >> nStart;
	cin >> nEnd;
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

	nTrace[nStart - 1] = 0;
	qV.push(nStart - 1);
	BFS(nVertice, nEdge, nTrace, qV);
	if (nTrace[nEnd] == -1)
	{
		cout << "No path from " << nStart << " to " << nEnd;
	}
	else
	{
		int nTemp = nEnd - 1;
		do
		{
			cout << nTemp + 1 << " -> ";
			nTemp = nTrace[nTemp];
		} while (nTemp != nStart - 1);
		cout << nStart;
	}
	cout << endl;
	system("PAUSE");
	return 0;
}

