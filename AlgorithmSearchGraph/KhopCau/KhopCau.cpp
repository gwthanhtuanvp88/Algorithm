// DFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void DFS(int p, int nVertice, int **nEdge, bool *bCheck, int *nNumber, int *nMin, int &nCount, int *nParent)
{
	nNumber[p] = nCount++;
	bCheck[p] = false;
	for (int i = 0; i < nVertice; i++)
	{
		if (nEdge[p][i] == 1)
		{
			nEdge[i][p] = 0;
			if (bCheck[i])
			{
				nParent[i] = p;
				DFS(i, nVertice, nEdge, bCheck, nNumber, nMin, nCount, nParent);
				nMin[p] = fmin(nMin[p], nMin[i]);
			}
			else
			{
				nMin[p] = fmin(nMin[p], nNumber[i]);
			}
		}
	}
}

int main()
{
	int nVertice;
	int nNoEdge;
	int **nEdge;
	int nPE1;
	int nPE2;
	cin >> nVertice;
	cin >> nNoEdge;
	int *nNumber;
	int *nMin;
	int *nParent;
	int *nChild;
	bool *bCheck;
	nEdge = new int*[nVertice];
	nNumber = new int[nVertice];
	nMin = new int[nVertice];
	nParent = new int[nVertice];
	nChild = new int[nVertice];
	bCheck = new bool[nVertice];
	for (int i = 0; i < nVertice; i++)
	{
		nEdge[i] = new int[nVertice];
		nMin[i] = nVertice;
		bCheck[i] = true;
		nParent[i] = -1;
		nChild[i] = 0;
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
	int nCount = 0;
	for (int i = 0; i < nVertice; i++)
	{
		if (bCheck[i])
		{
			DFS(i, nVertice, nEdge, bCheck, nNumber, nMin, nCount, nParent);
		}
	}
	for (int i = 0; i < nVertice; i++)
	{
		nChild[nParent[i]]++;
	}
	cout << "BRIDGE " << endl;
	int nP;
	for (int i = 0; i < nVertice; i++)
	{
		nP = nParent[i];
		if (nP != -1)
		{
			if (nMin[i] >= nNumber[i])
			{
				cout << nP << " -> " << i << endl; 
			}
		}
	}
	cout << "CUT VERTICE" << endl;
	for (int i = 0; i < nVertice; i++)
	{
		nP = nParent[i];
		if (nP != -1)
		{
			if (nMin[i] >= nNumber[nP] && nParent[nP] != -1)
			{
				cout << nP << endl;
			}
		}
		else
		{
			if (nChild[i] >= 2)
			{
				cout << i;
			}
		}
	}
	system("PAUSE");
	return 0;
}

