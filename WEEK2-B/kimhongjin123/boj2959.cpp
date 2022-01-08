#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	vector<int>v;


	for (int i = 0; i < 4; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);

	}
	sort(v.begin(), v.end());

	int answer = v.front() * v[2];
	cout << answer;


	return 0;

}