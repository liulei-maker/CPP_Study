#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int Count = 0;

int Fibonacci(int n)
{
	if (n < 2)
		return n == 0 ? 0 : 1;

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void move(char A, char B)
{
	cout << A << "-->" << B << endl;
}
//汉洛塔问题
void Hanoilmpl(int num, char A, char B, char C)
{
	if (num == 1)
	{
		move(A, C);
	}
	else
	{
		Hanoilmpl(num - 1, A, C, B);
		move(A, C);
		Hanoilmpl(num - 1, B, A, C);
	}
}
//二分法查找
int BinarySearch(const vector<int>& v, int val, int low, int high)
{
	if (v[low] > val || v[high] < val)
		return 0;
	if (v[low] == val)
		return low + 1;
	if (v[high] == val)
		return high + 1;
	if (high == low + 1)
		return 0;
	int mid = (low + high) / 2;
	if (v[mid] == val)
		return mid + 1;
	if (v[mid] > val)
		BinarySearch(v, val, low, mid);
	else
		BinarySearch(v, val, mid, high);
}

bool noDanger(int rowIndex, int colIndex, int (*chess)[8])
{
	for (int i = 0; i < 8; i++)//判断竖边
	{
		if (chess[i][colIndex] == 1)
			return 0;
	}


	int j = 0;

	for (int i = rowIndex, j = colIndex; i >= 0 && j >= 0; i--, j--)//判断左上边
	{
		if (chess[i][j] == 1)
			return 0;
	}

	for (int i = rowIndex, j = colIndex; i >= 0 && j < 8; i--, j++)//判断右上边
	{
		if (chess[i][j] == 1)
			return 0;
	}

	for (int i = rowIndex, j = colIndex; i < 8 && j >= 0; i++, j--)//判断左下边
	{
		if (chess[i][j] == 1)
			return 0;
	}

	for (int i = rowIndex, j = colIndex; i < 8 && j < 8; i++, j++)//判断右下边
	{
		if (chess[i][j] == 1)
			return 0;
	}

	return 1;
}

void EightQueen(int rowIndex, int col, int(*chess)[8])
{
	int chess2[8][8];
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			chess2[i][j] = chess[i][j];
		}
	}
	if (rowIndex == 8)
	{	
		Count++;
		cout << "第" << Count << ":" << endl;
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				cout << chess[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl;
	}
	else
	{
		for (i = 0; i < col; i++)
		{
			if (noDanger(rowIndex, i, chess))
			{
				for (j = 0; j < 8; j++)
				{	
					chess2[rowIndex][j] = 0;
				}
				chess2[rowIndex][i] = 1;
				EightQueen(rowIndex + 1, col, chess2);
			}
		}
		
	}

}
int main()
{
	int chess[8][8];
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			chess[i][j] = 0;
		}
	}
	EightQueen(0, 8, chess);
	return 0;
}

