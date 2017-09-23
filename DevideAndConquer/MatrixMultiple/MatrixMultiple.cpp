// MatrixMultiple.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CMatrix {
public:
	int m_nSize;
	int **m_nData;
	CMatrix()
	{
		m_nSize = 0;
		m_nData = NULL;
	}
	CMatrix(int nSize)
	{
		m_nSize = nSize;
		m_nData = new int*[m_nSize];
		for (int i = 0; i < m_nSize; i++)
		{
			m_nData[i] = new int[m_nSize];
		}
	}
	CMatrix operator+(CMatrix &m)
	{
		CMatrix mResult(m_nSize);
		for (int i = 0; i < m_nSize; i++)
		{
			for (int j = 0; j < m_nSize; j++)
			{
				mResult.m_nData[i][j] = m_nData[i][j] + m.m_nData[i][j];
			}
		}
		return mResult;
	}
	~CMatrix()
	{
		for (int i = 0; i < m_nSize; i++)
		{
			//delete m_nData[i];
		}
		//delete m_nData;
	}
	CMatrix operator-(CMatrix &m)
	{
		CMatrix mResult(m_nSize);
		for (int i = 0; i < m_nSize; i++)
		{
			for (int j = 0; j < m_nSize; j++)
			{
				mResult.m_nData[i][j] = m_nData[i][j] - m.m_nData[i][j];
			}
		}
		return mResult;
	}
	CMatrix subMatrix(CMatrix &m, int x, int y, int length)
	{
		CMatrix mResult(length);
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				mResult.m_nData[i][j] = m_nData[x+i][y+j];
			}
		}
		return mResult;
	}
	void concat(CMatrix &A11, CMatrix &A12, CMatrix &A21, CMatrix &A22)
	{
		for (int i = 0; i < m_nSize / 2; i++)
		{
			for (int j = 0; j < m_nSize / 2; j++)
			{
				m_nData[i][j] = A11.m_nData[i][j];
			}
		}
		for (int i = 0; i < m_nSize / 2; i++)
		{
			for (int j = m_nSize/2; j < m_nSize; j++)
			{
				m_nData[i][j] = A12.m_nData[i][j-m_nSize/2];
			}
		}
		for (int i = m_nSize/2; i < m_nSize; i++)
		{
			for (int j = 0; j < m_nSize / 2; j++)
			{
				m_nData[i][j] = A21.m_nData[i-m_nSize/2][j];
			}
		}
		for (int i = m_nSize/2; i < m_nSize; i++)
		{
			for (int j = m_nSize / 2; j < m_nSize; j++)
			{
				m_nData[i][j] = A22.m_nData[i-m_nSize/2][j-m_nSize/2];
			}
		}
	}
	void printMatrix()
	{
		for (int i = 0; i < m_nSize; i++)
		{
			for (int j = 0; j < m_nSize; j++)
			{
				cout << m_nData[i][j] << " ";
			}
			cout << endl;
		}
	}
};

void MultipleMatrix(CMatrix &A, CMatrix &B, int nLength, CMatrix &C)
{
	if (nLength == 1)
	{
		C.m_nData[0][0] = A.m_nData[0][0] * B.m_nData[0][0];
		return;
	}
	CMatrix A11, A12, A21, A22, B11, B12, B21, B22;
	CMatrix S1, S2, S3, S4, S5, S6, S7, S8, S9, S10;
	CMatrix C11, C12, C21, C22;
	CMatrix P1(nLength/2), P2(nLength/2), P3(nLength/2), P4(nLength/2), P5(nLength/2), P6(nLength/2), P7(nLength/2);
	A11 = A.subMatrix(A, 0, 0, A.m_nSize / 2);
	A12 = A.subMatrix(A, 0, A.m_nSize / 2, A.m_nSize / 2);
	A21 = A.subMatrix(A, A.m_nSize/2, 0, A.m_nSize / 2);
	A22 = A.subMatrix(A, A.m_nSize/2, A.m_nSize/2, A.m_nSize / 2);
	B11 = B.subMatrix(B, 0, 0, B.m_nSize / 2);
	B12 = B.subMatrix(B, 0, B.m_nSize / 2, B.m_nSize / 2);
	B21 = B.subMatrix(B, B.m_nSize / 2, 0, B.m_nSize / 2);
	B22 = B.subMatrix(B, B.m_nSize / 2, B.m_nSize / 2, B.m_nSize / 2);

	S1 = B12 - B22;
	S2 = A11 + A12;
	S3 = A21 + A22;
	S4 = B21 - B11;
	S5 = A11 + A22;
	S6 = B11 + B22;
	S7 = A12 - A22;
	S8 = B21 + B22;
	S9 = A11 - A21;
	S10 = B11 + B12;

	MultipleMatrix(A11, S1, nLength / 2, P1);
	MultipleMatrix(S2, B22, nLength / 2, P2);
	MultipleMatrix(S3, B11, nLength / 2, P3);
	MultipleMatrix(A22, S4, nLength / 2, P4);
	MultipleMatrix(S5, S6, nLength / 2, P5);
	MultipleMatrix(S7, S8, nLength / 2, P6);
	MultipleMatrix(S9, S10, nLength / 2, P7);

	C11 = P5 + P4 - P2 + P6;
	C12 = P1 + P2;
	C21 = P3 + P4;
	C22 = P5 + P1 - P3 - P7;
	C.concat(C11, C12, C21, C22);
}

int main()
{
	CMatrix A(4), B(4), C(4);
	/*A.m_nData[0][0] = 5;
	A.m_nData[0][1] = 2;
	A.m_nData[0][2] = 6;
	A.m_nData[0][3] = 1;

	A.m_nData[1][0] = 0;
	A.m_nData[1][1] = 6;
	A.m_nData[1][2] = 2;
	A.m_nData[1][3] = 0;

	A.m_nData[2][0] = 3;
	A.m_nData[2][1] = 8;
	A.m_nData[2][2] = 1;
	A.m_nData[2][3] = 4;

	A.m_nData[3][0] = 1;
	A.m_nData[3][1] = 8;
	A.m_nData[3][2] = 5;
	A.m_nData[3][3] = 6;


	B.m_nData[0][0] = 7;
	B.m_nData[0][1] = 5;
	B.m_nData[0][2] = 8;
	B.m_nData[0][3] = 0;

	B.m_nData[1][0] = 1;
	B.m_nData[1][1] = 8;
	B.m_nData[1][2] = 2;
	B.m_nData[1][3] = 6;

	B.m_nData[2][0] = 9;
	B.m_nData[2][1] = 4;
	B.m_nData[2][2] = 3;
	B.m_nData[2][3] = 8;

	B.m_nData[3][0] = 5;
	B.m_nData[3][1] = 3;
	B.m_nData[3][2] = 7;
	B.m_nData[3][3] = 9;*/

	A.m_nData[0][0] = 1;
	A.m_nData[0][1] = 2;
	A.m_nData[0][2] = 3;
	A.m_nData[0][3] = 0;

	A.m_nData[1][0] = 4;
	A.m_nData[1][1] = 5;
	A.m_nData[1][2] = 6;
	A.m_nData[1][3] = 0;

	A.m_nData[2][0] = 7;
	A.m_nData[2][1] = 8;
	A.m_nData[2][2] = 9;
	A.m_nData[2][3] = 0;

	A.m_nData[3][0] = 0;
	A.m_nData[3][1] = 0;
	A.m_nData[3][2] = 0;
	A.m_nData[3][3] = 0;


	B.m_nData[0][0] = 9;
	B.m_nData[0][1] = 7;
	B.m_nData[0][2] = 8;
	B.m_nData[0][3] = 0;

	B.m_nData[1][0] = 6;
	B.m_nData[1][1] = 5;
	B.m_nData[1][2] = 4;
	B.m_nData[1][3] = 0;

	B.m_nData[2][0] = 3;
	B.m_nData[2][1] = 2;
	B.m_nData[2][2] = 1;
	B.m_nData[2][3] = 0;

	B.m_nData[3][0] = 0;
	B.m_nData[3][1] = 0;
	B.m_nData[3][2] = 0;
	B.m_nData[3][3] = 0;

	MultipleMatrix(A, B, 4, C);
	C.printMatrix();
	system("PAUSE");
    return 0;
}

