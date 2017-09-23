// DFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

stack<int> stVertice;

void DFS(int p, int nVertice, int **nEdge, bool *bCheck, int *nNumber, int *nMin, int &nCount)
{
	stVertice.push(p);
	nNumber[p] = nCount;
	nMin[p] = nNumber[p];
	nCount++;
	for (int i = 0; i < nVertice; i++)
	{
		if (bCheck[i] == true && nEdge[p][i] == 1)
		{
			if (nNumber[i] == -1)
			{
				DFS(i, nVertice, nEdge, bCheck, nNumber, nMin, nCount);
				nMin[p] = fmin(nMin[p], nMin[i]);
			}
			else
			{
				nMin[p] = fmin(nMin[p], nMin[i]);
			}
		}
	}
	if (nNumber[p] == nMin[p])
	{
		int nTemp;
		do
		{
			nTemp = stVertice.top();
			stVertice.pop();
			cout << nTemp + 1 << " ";
			bCheck[nTemp] = false;
		} while (nTemp != p);
		cout << endl;
	}
}

int main()
{
	int nVertice;
	int nNoEdge;
	int nStart;
	int nEnd;
	int **nEdge;
	bool *bCheck;
	int *nNumber;
	int *nMin;
	int nPE1;
	int nPE2;
	int nCount = 0;
	cin >> nVertice;
	cin >> nNoEdge;
	bCheck = new bool[nVertice];
	nNumber = new int[nVertice];
	nMin = new int[nVertice];
	nEdge = new int*[nVertice];
	for (int i = 0; i < nVertice; i++)
	{
		nEdge[i] = new int[nVertice];
		bCheck[i] = true;
		nNumber[i] = -1;
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
	}
	cout << "......................................" << endl;
	for (int i = 0; i < nVertice; i++)
	{
		if (nNumber[i] == -1)
		{
			DFS(i, nVertice, nEdge, bCheck, nNumber, nMin, nCount);
		}
	}
	system("PAUSE");
	return 0;
}

