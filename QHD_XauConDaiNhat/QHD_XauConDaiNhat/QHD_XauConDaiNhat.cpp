// QHD_XauConDaiNhat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

char X[] = "abcdefghi123";
char Y[] = "abc1def2ghi3";

int nSizeX = sizeof(X) - 1;
int nSizeY = sizeof(Y) - 1;

int **nCount;
int **nTrace;

int main()
{
	nCount = new int*[nSizeY + 1];
	nTrace = new int*[nSizeY + 1];
	for (int i = 0; i < nSizeY + 1; i++)
	{
		nCount[i] = new int[nSizeX + 1];
	}
	for (int i = 0; i < nSizeY + 1; i++)
	{
		nTrace[i] = new int[nSizeX + 1];
	}
	for (int i = 0; i < nSizeY + 1; i++)
	{
		for (int j = 0; j < nSizeX + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				nCount[i][j] = 0;
			}
		}
	}
	int nTemp = 0;
	for (int i = 1; i < nSizeY + 1; i++)
	{
		for (int j = 1; j < nSizeX + 1; j++)
		{
			if (X[j - 1] == Y[i - 1])
			{
				nCount[i][j] = nCount[i - 1][j - 1] + 1;
				nTrace[i][j] = 0;
			}
			else
			{
				nTemp = nCount[i][j - 1];
				nTrace[i][j] = -1;
				for (int k = i - 1; k > 0; k--)
				{
					if (X[j-1] == Y[k-1] && nCount[k - 1][j - 1] + 1 > nTemp)
					{
						nTemp = nCount[k - 1][j - 1] + 1;
						nTrace[i][j] = k;
					}
				}
				nCount[i][j] = nTemp;
			}
		}
	}
	cout << nCount[nSizeY][nSizeX] << endl;
	int i = nSizeY;
	int j = nSizeX;
	char szTemp[100];
	char szOutput[100];
	int nPos = 0;
	do
	{
		if (nTrace[i][j] == 0)
		{
			szTemp[nPos++] = X[j - 1];
			i--;
			j--;
		}
		else if (nTrace[i][j] == -1)
		{
			j--;
		}
		else
		{
			szTemp[nPos++] = X[j - 1];
			i = nTrace[i][j];
			i--;
			j--;
		}
	} while (i > 0 && j > 0);
	for (int k = 0; k < nPos; k++)
	{
		szOutput[k] = szTemp[nPos - k - 1];
	}
	szOutput[nPos] = '\0';
	cout << szOutput << endl;
	system("pause");
    return 0;
}

