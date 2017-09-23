#include "stdafx.h"
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long make_change(vector<int> coins, int money) {
	int nNoCoins = coins.size();
	int **nWay = new int*[money+1];
	for (int i = 0; i < money+1; i++)
	{
		nWay[i] = new int[nNoCoins+1];
		for (int j = 0; j < nNoCoins + 1; j++)
		{
			nWay[i][j] = 0;
		}
	}
	for (int i = 0; i < nNoCoins+1; i++)
	{
		nWay[0][i] = 1;
	}
	for (int i = 1; i < money + 1; i++)
	{
		for (int j = 1; j < nNoCoins + 1; j++)
		{
			if (i >= coins[j-1])
			{
				nWay[i][j] = nWay[i][j - 1] + nWay[i - coins[j-1]][j];
			}
			else
			{
				nWay[i][j] = nWay[i][j - 1];
			}
		}
	}
	return nWay[money][nNoCoins];
}

int main() {
	int n;
	int m;
	cin >> n >> m;
	vector<int> coins(m);
	for (int coins_i = 0;coins_i < m;coins_i++) {
		cin >> coins[coins_i];
	}
	cout << make_change(coins, n) << endl;
	return 0;
}
