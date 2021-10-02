#include <iostream>
using namespace std;

int n, r, c;
int th;

void Z(int y, int x, int size)
{
	if (y == r && x == c)
	{
		cout << th << endl;
		return;
	}

	// r,c�� ���� ��и鿡 ������ ���
	if (r < y + size && r >= y && c < x + size && c >= x)
	{
		// 1��и� Ž��
		Z(y, x, size / 2);
		// 2��и� Ž��
		Z(y, x + size / 2, size / 2);
		// 3��и� Ž��
		Z(y + size / 2, x, size / 2);
		// 4��и� Ž��
		Z(y + size / 2, x + size / 2, size / 2);
	}
	else
	{
		th += size * size;
	}
}
int main()
{
	cin >> n >> r >> c;
	Z(0, 0, (1 << n));
	return 0;
}