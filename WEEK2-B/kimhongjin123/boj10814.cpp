
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b)
{
		return a.first < b.first;
}

int main()

{
	vector<pair<int, string>>v;
	string name;
	int old;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> old>> name;
		
		v.push_back(make_pair(old, name));

	}
	
	stable_sort(v.begin(), v.end(),cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}


}
