#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#define ll long long
#define pii pair<int, int>
using namespace std;

int sudo[9][9];

bool check(int row, int col, int num)
{
	for (int i = 0; i < 9; i++)
	{
		if (sudo[i][col] == num || sudo[row][i] == num)
			return false;
	}

	int row_sq = (row / 3) * 3;
	int col_sq = (col / 3) * 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (sudo[row_sq + i][col_sq + j] == num)
			{
				return false;
			}
		}
	}

	return true;
}

void dp(int row, int col)
{
	
	if (row > 8)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << sudo[i][j] << " ";
			}
			cout << "\n";
		}
	exit(0);
	}
	
	if (col > 8)
	{
		dp(row + 1, 0);
		return;
	}

	if (!sudo[row][col])
	{
		for (int num = 1; num < 10; num++)
		{
			if (check(row, col, num))
			{
				sudo[row][col] = num;
				dp(row, col + 1);
			}
		}
		sudo[row][col] = 0;
		return;
	}

	dp(row, col + 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	//input
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sudo[i][j];
		}
	}

	dp(0, 0);
}
