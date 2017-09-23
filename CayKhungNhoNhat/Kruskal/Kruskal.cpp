// Kruskal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int GetRoot(int *nRoot, int u)
{
	int nTemp = u;
	while (nRoot[nTemp] != -1)
	{
		nTemp = nRoot[nTemp];
	}
	return nTemp;
}

int main()
{
	int nVertice;
	int *nRoot;
	int *nCount;
	int nNoEdge;
	vector < pair<int, pair<int, int>>> vEdge;

	cin >> nVertice;
	cin >> nNoEdge;

	int nWeight = 0;
	
	nRoot = new int[nVertice];
	nCount = new int[nVertice];
	for (int i = 0; i < nVertice; i++)
	{
		nRoot[i] = -1;
		nCount[i] = 1;
	}

	for (int i = 0; i < nNoEdge; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		vEdge.push_back(make_pair(w, make_pair(u-1, v-1)));
	}
	sort(vEdge.begin(), vEdge.end());
	vector < pair<int, pair<int, int>>>::iterator it;
	int u, v;
	int ru, rv;
	for (it = vEdge.begin(); it != vEdge.end(); it++)
	{
		u = it->second.first;
		v = it->second.second;
		ru = GetRoot(nRoot, u);
		rv = GetRoot(nRoot, v);
		if (ru != rv)
		{
			nWeight += it->first;
			cout << u+1 << " " << v+1 << endl;
			if (nCount[ru] >= nCount[rv])
			{
				nCount[ru] += nCount[rv];
				nRoot[rv] = ru;
			}
			else
			{
				nCount[rv] += nCount[ru];
				nRoot[ru] = rv;
			}
		}
	}
	cout << "Total weight " << nWeight << endl;
	system("PAUSE");
    return 0;
}

