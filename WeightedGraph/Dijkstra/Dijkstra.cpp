// Dijkstra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> iPair;

int main()
{
	int nVertice;
	int **nEdge;
	int *nTrace;
	int *nFree;
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
	nFree = new int[nVertice];
	for (int i = 0; i < nVertice; i++)
	{
		nEdge[i] = new int[nVertice];
		nWeight[i] = 100;
		nTrace[i] = -1;
		nFree[i] = true;
	}
	nWeight[nStart - 1] = 0;
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
		nEdge[v1 - 1][v2 - 1] = weight;
	}

	//Dijkstra
	priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
	pq.push(make_pair(nWeight[nStart - 1], nStart));
	while (!pq.empty())
	{
		iPair pair = pq.top();
		if (nFree[pair.second] == true)
		{
			nFree[pair.second] = false;
			for (int i = 0; i < nVertice; i++)
			{
				if (nEdge[pair.second][i] < 100 && nWeight[i] > nWeight[pair.second] + nEdge[pair.second][i])
				{
					nWeight[i] = nWeight[pair.second] + nEdge[pair.second][i];
					nTrace[i] = pair.second;
					pq.push(make_pair(nWeight[i], i));
				}
			}
		}
	}

	int nTemp = nEnd - 1;
	do
	{
		cout << nTemp + 1 << " -> ";
		nTemp = nTrace[nTemp];
	} while (nTemp != nStart - 1);
	cout << nStart << endl;
	system("PAUSE");
	return 0;
}


