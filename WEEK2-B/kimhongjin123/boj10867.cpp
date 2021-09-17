#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	vector<int>v;
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		auto s = find(v.begin(), v.end(), num);
	
		if (s==v.end()) 
		{
			v.push_back(num);
		}	

	}
	sort(v.begin(), v.end());

	for(int i=0;i<v.size();i++)
	{
		cout << v[i]<<' ';
		
	}

}


