#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int** array;
	int length;
	cin >> length;
	array = new int* [length];

	for (int i = 0; i < length; ++i)
	{
		array[i] = new int[10];
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int num = 0;
			cin >> num;
			array[i][j] = num;

		}
		sort(array[i], array[i] + 10);

	}
	for (int i = 0; i < length; i++)
	{

		cout << array[i][7] << '\n';

	}










	return 0;

}